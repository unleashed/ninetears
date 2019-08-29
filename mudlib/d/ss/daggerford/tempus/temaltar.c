inherit "/std/guildroom";
#include "path.h"
#define MAX 10
object baergon, sign, *helpers;
int learn_spell(string name, string file, int min, string type);
int making_helper;
init()
{
::init();
}

void setup() 
  {
   set_short("Altar Room of Tempus");
   set_long(
"This is a large room filled with row after row of heavy wooden pews.  As "+
"you walk around this room, "+ 
"you see several stain glassed windows.  A large altar is set against the "+
"north wall.  This section of the church also works as the Priest's guild.  "+
"This guild "+
"offer training in both fighting and magic, but having to divide "+
"their attention to both, they just can not teach you as much about "+
"either as they can in the pure guilds. Magic and occultism are "+
"banned here. Type \"info\" to get information about the guild, or "+
"\"pray\" to pray for a new spell.  To the south, is the bulletin board "+
"for Tempus.  The Priest's guild armory is to the west.\n");
   set_light(100);
   sign=clone_object("/std/object");
   sign->set_name("sign");
   sign->set_short("sign");
   sign->set_long(
      "A decorative sign hangs on the wall by the entrance.  There is " +
      "some writing on it, like most signs.\n");
   sign->set_read_mess(
      "      _______________________________________________________    \n"+
      "     |\\_____________________________________________________/|   \n"+
      "     | |                                                   | |   \n"+
      "     | |   WELCOME TO THE PRIESTS GUILD OF TEMPUS          | |   \n"+
      "     | |                                                   | |   \n"+
      "     | |  - Type 'join' to become a member of this guild   | |   \n"+
      "     | |  - Type 'info' to get some guild-information      | |   \n"+
      "     | |  - Type 'advance <skill>' to advance your levels  | |   \n"+
      "     | |  - Type 'cost all' to see how much it will cost   | |   \n"+
      "     | |    to improve skills, or 'cost <skill>            | |   \n"+
      "     | |  - Type 'pray' to get a list of spells you can    | |   \n"+
      "     | |    pray for, or pray <spell> to get a spell       | |   \n"+
      "     | |  - Type 'specialize' to specialize on this God.   | |   \n"+
      "     | |  - Type 'convert' to convert to Tempus. This must | |   \n"+
      "     | |    be done to learn spells here if you are not a  | |   \n"+
      "     | |    member of this guild. If you have already      | |   \n"+
      "     | |    converted to another God you can't do this     | |   \n"+
      "     | |___________________________________________________| |   \n"+
      "     |/_____________________________________________________\\|\n\n");
   sign->move(this_object());
   sign->reset_get();
   hidden_objects += ({ sign });
   add_exit("west", ROOM+"temarmor", "door");
   modify_exit("west", ({"function", "go_west"}) );
   add_exit("south", ROOM+"tempusbb", "door");
   add_exit("east",ROOM+"peace.c","door");
   modify_exit("east", ({"function", "go_east"}));
   add_exit("slide", ROOM+"director", "road");
   modify_exit("slide", ({"message",
      "N$N slides the altar and enters the room hidden by the altar.",
      "function", "go_in", "obvious", 0}) );
   add_alias("altar", "slide altar");
   add_alias("pews", "pew");
   add_alias("windows", "window");
   add_item("pew",
            "The ends of the pews have the likeness of famous Priests, "+
            "their mouths open in prayer.\n");
   add_item("altar",
            "The altar looks large and ancient, looking much older "+
            "than the church around it.  Yet, there are strange marks on the "+
            "floor by it.\n");
   add_item("window",
            "Valiant deeds are depicted on the brightly colored glass, "+
            "some a bit gruesome.\n");
   add_item("marks",
            "Looks like these marks are made from someone sliding the altar "+
            "over this section of the floor.\n");

   set_teaching_person("baergon");
   set_guild("priests/tempus");
   add_specialization("tempus");
   set_co_ord( ({ -2, -1, 0 }) );
}

void reset() 
  {
   if (!baergon) {
      baergon = clone_object(CHAR +"baergon");
      baergon->move(this_object());
     }
   if (!helpers) helpers = ({ });
  }

void event_fight_in_progress(object ob1, object ob2) {

   int i;
   if (making_helper) return ;
   if (random(100) > 80) {
      call_out("create_helper",0);
      making_helper = 1;
   }

   for (i=0; i<sizeof(helpers); i++)
   if (helpers[i] && environment(helpers[i]) == this_object()) {
      if (ob1 != baergon)
         if ((string)ob1->query_name() != "priest")
            helpers[i]->attack_ob(ob1);
      if (ob2 != baergon)
         if ((string)ob2->query_name() != "priest")
            helpers[i]->attack_ob(ob2);
   }

}

void create_helper() {
   object h;
   if (sizeof(helpers) > MAX) return;
   h = clone_object("/obj/monster");
   h->set_name("priest");
   h->set_long(
      "A cleric who has been roused from hard studies by a fight.\n");
   h->set_race("human");
   h->set_gender(1+random(2));
   h->set_class("priest");
   h->set_guild_ob("/std/guilds/priests/tempus");
   h->add_property("tempus" ,1);
   h->set_level(random(10)+5);
   h->init_equip();
   helpers += ({ h });
   call_out("run_in", 3, h);
   remove_call_out("still_fighting");
   call_out("still_fighting", 240);
}

void run_in(object h) {

   int i, j;
   object *obs;
   making_helper = 0;
   h->move(this_object());
   say(capitalize((string)h->short()) + " stops studying and joins the "+
      "fight.\n");
   h->init_command("' Protect Baergon!!!");
   h->init_command("guild Help, someone is attacking Baergon."); 
   if (baergon) {
      obs = (object *)baergon->query_attacker_list();
      for (j=0; j<sizeof(obs); j++)
      h->attack_ob(obs[j]);

   }

for (i=0; i<sizeof(helpers); i++)

   if (helpers[i]) {
      obs = (object *)helpers[i]->query_attacker_list();
      for (j=0;j<sizeof(obs);j++)
      h->attack_ob(obs[j]);
   } /* if */

}

 

int still_fighting() {

   int s, i;

   if (baergon)
      s += sizeof((mixed *)baergon->query_attacker_list());
   for (i=0; i<sizeof(helpers); i++)
   if (helpers[i])
      s += sizeof((mixed *)helpers[i]->query_attacker_list());
   if (!s) {
      for (i=0;i<sizeof(helpers);i++)
      call_out("leave_room", 5+random(20), helpers[i]);
      helpers = ({ });
    } /* if */
 
}

 

void leave_room(object ob) {

   if (!ob) return ;
   say(capitalize((string)ob->short())+" senses that there is no danger " +
      "to Baergon anymore, and returns to do some studying.\n");
   ob->dest_me();
}
 

void dest_me () {

   int i;

   for (i=0;i<sizeof(helpers);i++)
   if (helpers[i])
      helpers[i]->dest_me();
   if (baergon)
      baergon->dest_me();
   if (sign)
      sign-> dest_me ();
   ::dest_me ();
}

 
int go_east()
   {if((string)(this_player()->query_guild_ob()) == "/std/guilds/priests/tempus")
      return 1;
    if(!baergon)
      return 1;
    notify_fail("You attempt to enter the candle lit room, but Baergon stops you.\n\n"+
        "Baergon tells you:  You are not permitted in that area.\n\n");
    say(this_player()->query_cap_name()+" attempts to go east, but "+
        "Baergon intervenes, disallowing entrance.\n\n");
     return 0;
    }

int go_west() {

   if((string)this_player()->query_guild_ob() == "/std/guilds/priests/tempus")
      return 1;
   if (!baergon)
      return 1;
   notify_fail("Baergon stops you.\nBaergon says: You can't go in there " +
      "without being a member of the priests guild.\n");
   say(this_player()->query_cap_name() + " tried to go west, but Baergon " +
      "stops " + this_player()->query_objective()+".\n");
   return 0;
}

 

int go_in() 
   {
/* new test 
*    if (((string)this_player()->query_guild_ob() == "/std/guilds/priest")
*    && ((int)this_player()->query_skill("faith.spells.offensive") > 119)
*    && ((int)this_player()->query_skill("fighting.combat.melee.unarmed")
*       > 90)) 
The new one will test on property for directorate, not the skills and guild. */
  if (this_player()->query_property("directorate"))
{
  write("Your faith in Tempus gave you the strength to slide the altar.\n\n ");
    return 1;
      } /* if */
  else 
   {
   notify_fail("It don't seems like you are able to slide the altar " +
       "maybe you don't have " +
       "enough faith in Tempus\n");
/* fix the desc & words as you like. Baldrick */ 
   return 0;
   }
}
