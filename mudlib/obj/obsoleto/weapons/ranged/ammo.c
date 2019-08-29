
/******************************************************************************
		 Shoot weapon ammo base object
		 
	 Radix - February 23, 1996
         Khelben - Juny 23, 1996
*******************************************************************************/
 
 
#include "path.h"

inherit "/obj/weapon.c";
 
private int *ranged_damage;
object shadow;
string ammo;
 
void anger_npc(object a, object e, mixed tmp);   // Will do NPCs attack
					         //   players. 

void set_proj_name(string arg) { ammo = arg; } 

string query_proj_name() { return ammo; }
 
 

void init()
{
   
   
   if ( (int)this_object()->query_property("cursed") == 100 && !(shadow) )
   {
      if( (string)this_player()->query_cap_name() == 
          (string)this_object()->query_property("stiked") )
      {
         // This clone the arrow shadow when the player log off with a 
         // stinking arrow. With the property "cursed" we are sure that 
         // he cannot drop the arrow.    
      
         shadow = clone_object(SHOOT_SHADOW);
         shadow->setup_shadow(this_player() , this_object());
         this_player()->add_extra_look(shadow);
      }
      else
      {
         this_object()->remove_property("cursed");
         this_object()->remove_property("stiked");      
      }
   } 
   add_action("extract_proj","extract");
   ::init();
}
 
int *query_weapon_damage() { return ranged_damage; }
 
int query_ranged_weapon_ammo() { return 1; }
int query_ranged_ammo() { return 1; }
 
void set_weapon_damage(int *dam) 
{ 
   if(!dam || !sizeof(dam)) return;
   ranged_damage = dam;
   return;
}

int do_ranged_weapon_damage(object archer, object enemy, mixed tmp, 
    string proj)

{
   int dam;

   ammo = proj;
   
   if(!archer || !enemy) return 0;
   if ( sizeof(ranged_damage) != 3 )   // Not necessary. Can be erased 
      ranged_damage = ({ 1, 5, 0 });
    
   dam = roll(ranged_damage[0],ranged_damage[1])+ranged_damage[2];
   dam = dam + this_object()->query_enchant();
 
   if(dam < 0) dam = 1;
   if(dam > 20) dam = 20;
 
   if(environment(enemy) == environment(archer)) 
   {
      if(archer->query_hidden_shadow() || archer->query_hidden())
      {
         dam *= 2;
         archer->destruct_hide_shadow();
         archer->set_hidden(0);
      }
      else
         dam *= 1.3;
   }
   else
   {
      if(tmp[0] == "down") dam *= 2;
      if(tmp[0] == "up") dam /= 2;
   }
      
   enemy->adjust_hp(-dam,archer);
   if(!userp(enemy))     		  // If he is a NPC will move him. 
         anger_npc(archer, enemy, tmp);
   enemy->attack_by(archer);                 
   if (userp(enemy))   // We'll not slay NPCs because they are fools 
   {
      this_object()->add_property("cursed",100);
      this_object()->add_property("stiked",enemy->query_cap_name());      
      shadow = clone_object(SHOOT_SHADOW);
      shadow->setup_shadow(enemy , this_object());
      enemy->add_extra_look(shadow);
      this_object()->move(enemy);
   }
   
   dam = (dam * (100 - (int)enemy->query_property("missile")))/100; 
   return dam;
}
 
void anger_npc(object archer, object enemy, mixed tmp)
{
   if ( enemy->query_hp() >= 0 )
   {
      while(environment(archer) != environment(enemy))
         enemy->do_command(tmp[0]);
   }
}

int extract_proj(string str)
{
   object arrow;
   ammo = (string)this_object()->query_proj_name();
   
   if ( ( str == ammo || str == (string)this_object()->query_name() ||    
          str == (string)this_object()->query_short() ) &&
          (int)this_object()->query_property("cursed") == 100 )
   {
      if ( random(100) > ((int)this_player()->query_dex() * 5) )
      {
         // The player cannot extract the arrow because he is clumsy 
         
              tell_object(this_player(), "You try extract the stinking "+this_object()->query_name()+" "+
                     "but you only remove it into your flesh.\n");
	 this_player()->adjust_hp(-1,this_object());         
         return 1;
      }
      shadow->destruct_me();
      if ( ammo == "arrow")
      {
         if( random(100) <= ARROW_BREAK )
         {
      	    arrow = clone_object(BROKEN_MISSILE);
      	    arrow->set_name("broken arrow");
            arrow->set_short("broken arrow");
            arrow->set_long("This is a broken arrow stained with blood at "
               "the point.\n");
            arrow->add_alias("arrow");
      	    arrow->move(this_player());
      	    tell_object(this_player(), "As you extract the arrow you feel a "
      	                "deep pain across all your body as you hear the "
      	                "click of the arrow breaking.\n");
      	    this_object()->dest_me();  
      	    return 1;
      	 }
      	 else
      	    tell_object(this_player(), "As you extract the arrow you feel a "
      	                "deep pain across all your body, but now you're "
      	                "better.\n");
      }
      
      else if ( ammo == "bolt")
      {
         if( random(100) <= BOLT_BREAK )
         {
            arrow = clone_object(BROKEN_MISSILE);
            arrow->set_name("broken bolt");
            arrow->set_short("broken bolt");
            arrow->set_long("This is a broken bolt stained with blood at "
               "the point.\n");
            arrow->add_alias("bolt");
            arrow->move(this_player());
      	    tell_object(this_player(), "As you extract the bolt you feel a "
      	                "deep pain across all your body as you hear the "
      	                "click of the bolt breaking.\n");
      	    this_object()->dest_me();  
      	    return 1;
      	 }
      	 else
      	    tell_object(this_player(), "As you extract the bolt you feel a "
      	                "deep pain across all your body, but now you're "
      	                "better.\n"); 
      }
      
      else if ( ammo == "needle")
      {
         if( random(100) <= NEEDLE_BREAK )
         {
            arrow = clone_object(BROKEN_MISSILE);
            arrow->set_name("broken needle");
            arrow->set_short("broken needle");
            arrow->set_long("This is a broken needle stained with blood at "
                           "the point. \n");
      	    arrow->move(this_player());
      	    tell_object(this_player(), "As you extract the needle you feel a "
      	                "deep pain across all your body as you hear the click "
      	                "of the needle breaking.\n");
      	    this_object()->dest_me();  
      	    return 1;
      	 }
      	 else
      	    tell_object(this_player(), "As you extract the needle you feel a "
      	                "deep pain across all your body, but now you're "
      	                "better.\n"); 
      }
      
      this_object()->remove_property("cursed");	   
      return 1;
   }
   else
      return 0;
}




