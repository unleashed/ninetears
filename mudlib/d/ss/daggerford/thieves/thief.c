inherit "/std/guildroom";
#include "path.h"

object trap;

void setup()
{
   set_short("Thieves guild");
   set_long("This is the entrance to the thieves guild. They are now"+
      " looking for promising new thieves. If you want to learn more type"+
      " 'Info'. To join all you have to do is 'Join'.\n");
   set_light(40);
  add_exit("north", DAGG+"river2", "path");
   add_exit("down", ROOM +"under.c", "door");
   modify_exit("down", ({"function", "go_down", "message",
            " $N mumbles something at the trap door and goes down.\n"}));
   set_guild("rogues/thief");
}

int go_down() {
/*  Whoever put this line in is gonna get a real flaming from me if I find out who it was ... IT DOESN'T WORK you bloody moron, theres no such function */
/*
   if ((string)this_player()->query_guild() == "thief")
*/
  if((string)this_player()->query_guild_ob()=="/std/guilds/rogues/thief")
      return 1;
   /*
   if (!trap)
      return 1;
   */
   notify_fail("Since you do not know the password you can not enter the "+
         "trap door.\n");
   say(this_player()->query_cap_name()+" tries to guess the password"+
      " but is laughed at by someone under the trapdoor.\n");
   return 0;
}

void reset() {
/*
   if (!trap)
      {
      trap = clone_object("/d/ss/daggerford/thieves/trapdoor.c");
      trap->move(this_object());
   }
   */
}

void enter(object ob)
{
   object weath;
}
