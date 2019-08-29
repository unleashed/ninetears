
/***************************************************************************
         Ranged weapon code ... should include _all_ fired weapons
 	 Radix - March 3, 1996
         Khelben - Juny 23, 1996
****************************************************************************/
 
inherit "/obj/weapon.c";
 
#include "path.h"
#define RANGE "/obj/handlers/range.c"
// info[] 0- range 1- speed 2- accuracy 3-container 4-ammo 5-hands  
 
mixed info,tmp;
string wtype;
object ammo, me, him, env;
int round;
string firemess, readymess; 
 
object get_ammo();
int do_hit(object me, object him, object ammo);
void do_random_target(object me, object him, object ammo);
void missed_shot(object me, object him, object ammo);
void lose_concentration();
 
void set_readymess(string arg) { readymess = arg; }
void set_firemess(string arg) { firemess = arg; }
 
create()
{
   ::create();
   info = allocate(6);
   if(wtype)
      info = TABLE->get_info(wtype);
   ammo, me, him = ({ });
   round = 0;
   if ( !readymess )
      readymess = "Skillfully, you draw the bow ready and aim at";
   if ( !firemess )
      firemess = "Finishing your aim, you shoot off an arrow at";
// Why this?  Doesn't need to be in base object - Radix
// add_property("guild","ranger");   This must be put in every weapon.
   set_holdable(1);
   if ( (int)info[5] == 2 )
   {   set_twohanded(1); }
}
 
void init()
{
    ::init();

      add_action("ranged_shot","shoot");
}
 
void set_ranged_weapon(string t) 
{
    wtype = TABLE->look_up(t);
    info = TABLE->get_info(wtype);
}
 
int ranged_shot(string victim)
{
    object old = him;
    
    if(!this_object()->query_in_use())
    {
       write("You must be holding this weapon to use it!\n");
       return 1;
    }
    if(!victim || !stringp(victim))
    {
       write("Syntax: "+query_verb()+" <target>\n");
       return 1;
    }
    if(environment()) me = environment(this_object());
    if(info[4] != "itself" && sizeof(me->query_attacker_list()))
    {
       write("You cannot load your "+query_short()+
          " while in combat!\n");
       return 1;
    }
    victim = me->expand_nickname(victim);
    him = find_living(victim);
    if(!me || !him)
    {
       write(capitalize(victim)+" does not exist or is a ghost.\n");
       return 1;
    }
    if(him && him == me)
    {
       write("Suicide is not possible, try to kill something else.\n");
       return 1;
    }
    if(him->query_property("dead"))
    {
       write(him->query_cap_name()+" is a ghost.\n");
       return 1;
    }
    if(!RANGE->check_line_of_sight(me,him,info[0]) && ENV(me) != ENV(him))
    {
       write("Could not find "+him->query_cap_name()+" in range.\n");
       return 1;
    }
    if(him->query_hidden()||him->query_invis()||him->query_hide_shadow())
    {
       write("Could not find "+him->query_cap_name()+" in range.\n");
       return 1;
    }

    ammo = get_ammo();
    if(!ammo)
    {
       write("Could not find "+info[4]+" in "+info[3]+".\n");
       return 1;
    }
    if(!round)
       write(readymess+" "+him->query_cap_name()+".\n");
    else
    {
       if(him == old)
          write("You hesitate and aim at "+him->query_cap_name()+
             " again.\n");
       else
          write("You change aim from "+old->query_cap_name()+" to "+
             him->query_cap_name()+".\n");
    }
    env = environment(me);
    round = 0;
    set_heart_beat(1);
    return 1;
}
 
heart_beat()
{
   int hit;

   if(!him || !me)
   {
      if(!me)
      {
          // die in horror
          dest_me();
          return;
      }
      tell_object(me,"You lost sight of "+him->query_cap_name()+".\n");
      me, him, ammo = 0;
      round = 0;
      set_heart_beat(0);
      return;
   }   
   if(env != environment(me))
      lose_concentration();
      
   if(!this_object()->query_in_use())
   {
     tell_object(me,"As you low your weapon you lose your target.\n");
     set_heart_beat(0);
     return;
   }
   if(him->query_property("dead"))
   {
      write(him->query_cap_name()+" is a ghost.\n");
      set_heart_beat(0);
      return;
   }
   if(!RANGE->check_line_of_sight(me,him,info[0])&& env != environment(him))
   {
      tell_object(me,him->query_cap_name()+" is out of range!\n");
      me, him, ammo = 0;
      round = 0;
      set_heart_beat(0);
      return;
   }
   if(him->query_hidden() || him->query_invis() || him->query_hide_shadow())
   {
      tell_object(me,"Could not find "+him->query_cap_name()+" in range.\n");
      me, him, ammo = 0;
      round = 0;
      set_heart_beat(0);
      return;
   }
 
   if(round == info[1])
   {
      tell_object(me,firemess+" "+him->query_cap_name()+".\n");

      tell_room(ENV(me), me->query_cap_name()+" holds a "+query_short()+
                " and shoot off a projectile.\n", ({me}));
      if(!do_hit(me,him,ammo))
         missed_shot(me,him,ammo);   // Wrong the shot. 
      
      me, him, ammo = 0; 
      round = 0;
      set_heart_beat(0);
      return;
   }
   
   round++;
   tell_object(me,"You continue your aim at "+him->query_cap_name()+".\n");
}
 
void lose_concetration()
{
   tell_object(me,"Moving, you lose your concentration and begin "
      "again aiming at "+him->query_cap_name()+".\n");
   env = environment(me);
   round = 0;
}
 
// May give this a number arg to return *objs.. fire more than one arrow?
object get_ammo()
{
   object *all;
   int i;
   
 
   // missiles from containers...
   all = find_match(info[4], find_match(info[3], me)); 
   for(i=0; i<sizeof(all); i++) 
      if(all[i]->query_ranged_ammo()) 
         return all[i];
 
   return 0;
}
 
int check_accuracy(object archer, object enemy, object proj, int tmp)
{
   int bonus, malus, ac, thac0, acc, distance, dex;
   int needed, shoot;

   if( enemy->query_property("NOBUDGE") ||
        environment(enemy)->query_static_property("noguild") ||
        environment(enemy)->query_static_property("nocast") )
    {
    	return -1;    // We'll do them lose ammo.
    }
    if( environment(archer)->query_static_property("noguild") ||
        environment(archer)->query_static_property("nocast") )
    {
    	return -1;    // We'll do them lose ammo.
    }
   ac = enemy->query_total_ac();
   thac0 = archer->query_thac0();
   acc = info[2];
   distance = tmp*2;   // Will be hardest if the target is far 
   distance *= 10;
   dex = (int)archer->query_dex()-16;
   dex *= 10;   
   bonus = acc + dex - distance;
   needed = thac0 - bonus - acc;
   shoot = random(200);
   if ( shoot >= needed )
   	return 1;   
   else
   	return 0;
}
 
 
void missed_shot(object me, object him, object proj)
{
   int bad;

    if(!ammo)
   {  
      return;
   }
   
   tell_object(me,"You missed "+him->query_cap_name()+"!\n"); 
   bad = random(200);
   
   switch (bad)
   {
      case 0..10:
		    ammo->move(environment(him));
		    break;

      case 11..198: 
	      	    ammo->dest_me();
      		    break;
   
      default:     // 199 
   		    do_random_target(me,him,proj);     // Now we can hit 
   		    				       // another target 
   		    break;		
    }   		    
}
 
int do_hit(object archer, object enemy, object proj)
{
   int damage,i, dest;
   int shoot;
   
   tmp = RANGE->get_direction_delta(enemy, archer);
   
   if(!proj)
   {  
      return 1;
   }
   
   shoot = check_accuracy(archer, enemy, proj, tmp[1]);
   
   if ( shoot == -1)
   {
      tell_object(me,"You missed "+enemy->query_cap_name()+"!\n"); 
      proj->dest_me();
      return 1;     // In this way We'll avod the miss_shoot function.
   }
      
   if(shoot == 1)
   {
      damage = proj->do_ranged_weapon_damage(archer,enemy,tmp,info[4]);
      tell_object(archer,"You hit "+enemy->query_cap_name()+" with your "+
                  proj->query_short()+" doing "+damage+"!\n");
 
      tell_object(enemy,"You have been struck by a flying "+proj->query_short()+
                  " from the "+tmp[0]+" doing "+damage+"!\n");
      tell_room(ENV(enemy), enemy->query_cap_name()+" is hited by a "
                "projectile from the "+tmp[0]+".\n", ({archer,enemy}));
                
      if ( !userp(enemy) )   
      {
         switch((string)proj->query_proj_name())
         {
            case "arrow":
            		    dest = ARROW_BREAK; break;
            		    
            case "bolt":
            		    dest = BOLT_BREAK; break;
            		    
            case "needle":
		            dest = NEEDLE_BREAK; break;
         
            default:
            		    dest=200; break;
         }		            
         if ( random(100) <= dest )
         {
            proj->dest_me();
         }
         else
            proj->move(enemy); 
      }
      return 1;
   }
   else if( shoot == 0)
   	return 0;    // Wrong the shoot 
}

void do_random_target(object archer, object enemy, object proj)
{ 
   int damage, j, i, dest;
   int deb=0, di;
   object *all;
   
   all = all_inventory(environment(enemy));
   j = sizeof(all); 
   if ( j == 1 && ENV(archer) != ENV(enemy) )  
   {
        // Only our target is in the room 
      	
      	proj->dest_me();
   }
   
   else if ( j == 2 && ENV(archer) == ENV(enemy) )    
   {   
        // Only our target and the archer are in the room 
      	
      	proj->dest_me();
   }
   
   else
   {
   	for(di=0; di<sizeof(all); di++)
   	i = random(sizeof(all));
   	while ( all[i] == enemy  || all[i] == archer ) 
   	{
           i = random(sizeof(all));  
           deb++;
        }   
   }
   
   if ( userp(all[i]) || all[i]->query_npc() )
   {
      damage = proj->do_ranged_weapon_damage(archer,all[i],tmp,info[4]);
      tell_object(archer,"Opps...you wrong the shot and you now "+
                  "hit "+all[i]->query_cap_name()+" with your "+
  	          proj->query_short()+" doing "+damage+"!\n");
      tell_object(all[i],"You have been struck by a flying "+proj->query_short()+
                  " from the "+tmp[0]+" doing "+damage+"!\n");
      tell_object(all[i],"Ahora se te clona una flecha clavada.\n");
      tell_room(ENV(enemy), enemy->query_cap_name()+" is hited by a "
                "projectile from the "+tmp[0]+".\n", ({archer,enemy}));
   }
   
   else
      proj->dest_me();
      
   if ( !userp(all[i]) )
   {
      switch((string)proj->query_proj_name())
      {
         case "arrow":
         		    dest = ARROW_BREAK; break;
            		    
         case "bolt":
            		    dest = BOLT_BREAK; break;
            		    
         case "needle":
		            dest = NEEDLE_BREAK; break;
      }
      if ( random(100) <= dest )
      {
         proj->dest_me();
      }
      else
         proj->move(enemy); 
   }
}

