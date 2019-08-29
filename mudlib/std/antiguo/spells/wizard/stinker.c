#include <player.h>
/* stinking cloud object, actually a "dead" invisible NPC 
 * Effects based on level and con, once cast this isn't a spell 
 * rather local air pollution
 * caster gets a bonus 10:1 chance of not being affected
 */ 
#include "tweaks.h"
#include "useful_stuff.c"
inherit "/std/object";

int hb;
object mycaster;
int mycount;

void do_spell(object ob);

int dispell_me()
{
  tell_room(ETO,"The stinking cloud dissipates, leaving only an "
    "unpleasant memory.\n",({ }));
  this_object()->dest_me();
  return 1;
}

void do_death(object ob) { }

void attack_by(object ob)
{
  ob->stop_fight(this_object());
  tell_room(ETO,(string)ob->query_cap_name()+
    " bravely, but futilely attacks a stinking cloud.\n");
  do_spell(ob);
}

void init()
{
  ::init();
  reset_get();
  set_heart_beat(1);
}

void do_spell(object ob)
{
  int odds;
  if (ob == this_object() || ((IMMORTLOCK) && ob->query_creator()) ||
       ob->query_dead() || !living(ob) || ob->query_property("poison") > 50 ) 
    return;

  odds = 0;
  if (ob == mycaster) 
    odds = 10 * (int)ob->query_level();
  else 
    odds = (int) ob->query_level();
   odds += ob->query_property("poison");
  switch(random(odds) )
  {
    case 0:
      case 3:
      if(random((int)ob->query_con()) < 6)
      {
        tell_object(ob,"The cloud make you vomit and you drop "
          "everything.\n");
        tell_room(ETO,"The cloud makes "+(string)ob->query_cap_name()+
          " vomit.\n", ({ob }));
        force_unwear_armour(ob);
        ob->set_wimpy(99);
      }
      break;
    case 1: /* partly wasted, forced to "stop" */
   case 5:
   case 7:
   case 11:
      ob->add_timed_property("nocast",1,odds);
         ob->add_timed_property("noguild",1,odds);
         ob->add_timed_property(PASSED_OUT_PROP,1,3);
    case 2:
      tell_object(ob,"Your coughing forces you to stop what you are "
   	"doing.\n"); 
      tell_room(ETO,(string)ob->query_cap_name()+" starts coughing.\n");
      ob->stop();
      break;
  }

}


void set_spell(object ob,int length)
{
  mycaster = ob;
  mycount = length *3;
}

void setup()
{
  set_name("stinking cloud");
  set_short("stinking cloud");
  add_alias("cloud");
  add_property("dead",1);
  set_long("\nA greenish haze which fills the room and smells, well, "
   "indescribably bad.\n");
  set_spell(this_object(),10);
}

void heart_beat()
{
  object *olist;
  int i;

  if(!mycaster || ++hb > mycount)
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

