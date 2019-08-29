/* cloud of confusion object, actually a "dead" invisible NPC 
 * Effects based on level and con, once cast this isn't a spell 
 * rather local air pollution
 * caster gets a bonus 10:1 chance of not being affected
 */ 
#include "tweaks.h"
#include "useful_stuff.c"
inherit "/obj/monster";
int hb;
object mycaster;
int mycount;
void do_spell(object ob);
int dispell_me()
{
   tell_room(ETO,"The cloud dissapates leaving you puzzled.\n",({ }));
   this_object()->dest_me();
   return 1;
}
void do_death(object ob) { }
void attack_by(object ob)
{
   ob->stop_fight(this_object());
   tell_room(ETO,(string)ob->query_cap_name()+
      " bravely, but futilely, attacks a cloud of confusion, "
      "an effort reminiscent of Don Quixote de la Mancha.\n");
   do_spell(ob);
}
void init()
{
   ::init();
   set_heart_beat(1);
}
void do_spell(object ob)
{
   int odds;
   object *olist;
   if(ob == this_object()) return;
   if(IMMORTLOCK) if(ob->query_creator()) return;
   if(find_living((string)ob->query_name()) )
   {
       if(ob == mycaster) odds = 10 * (int)ob->query_level();
       else odds = (int) ob->query_level();
       switch(random(odds) )
       {
       case 0:   
	  tell_object(ob,"A wave of confusion rolls over you.\n");
      tell_room(ETO,(string)ob->query_cap_name()+" looks confused.\n",({ob}));
	  ob->set_wimpy(100);
	  force_unhold_weapons(ob);
       break;
       case 1:
	 tell_object(ob,"You wonder what you were doing?\n"); 
	 tell_room(ETO,(string)ob->query_cap_name()+" looks puzzled.\n");
	 ob->stop();
      break;
       case 2:
	  tell_object(ob,"A wave of confusion rolls over you.\n");
      tell_room(ETO,(string)ob->query_cap_name()+" looks confused.\n",({ob}));
	  force_unwear_armour(ob);
       break;
      case 3:
	 olist = all_inventory(ETO);
	 tell_object(ob,"Rage overcomes you!\n");
	 tell_object(ETO,(string)ob->query_cap_name()+" goes berserk!\n",({ob}));
	 ob->attack_by(olist[random(sizeof(olist))]);
      break;
       case 9: /* will only get players L9 or greater */
       case 10:
	  tell_object(ob,"A wave of confusion rolls over you.\n");
      tell_room(ETO,(string)ob->query_cap_name()+" looks confused.\n",({ob}));
      force_drop_one(ob);
       break;
      }
   }
}
void set_spell(object ob,int length)
{
	mycaster = ob;
	mycount = length;
}
void setup()
{
   set_name("cloud of delusion");
   set_short("cloud of delusion");
   set_race("monster");
   add_alias("cloud");
   set_long("\nA sweet smelling haze which fills the room and smells..odd?"
     "\n");
   set_spell(this_object(),10);
}
void heart_beat()
{
     object *olist;
     object ob;
     int i;
      hb++;
     if(!mycaster) 
     {
        dispell_me();
     }
     if(hb > mycount)
     {
        dispell_me();
         return;
     } 
     olist = all_inventory(ETO);
     for(i = 0; i < sizeof(olist); i++)
     {
        do_spell(olist[i]);
     }
}
     
