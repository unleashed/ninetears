
inherit "/obj/monster";
#include "path.h";

void setup()
{
   set_name("orc");
   set_race("orc");
   set_gender(1);
   set_main_plural("orcs");
   add_plural("angry orcs");
   set_al(100);
   set_aggressive(0);
   set_random_stats(10,15);
   set_con(18);
   set_level(3+random(2));
   set_wimpy(0);
   set_short("Orc Torturer");
   set_long("  This smelly Orc is quite large and is using his "
            "size and stregnth to beat some information out of a "
            "small Dwarf that is hanging from the wall.  "
            "\n\n");
   load_chat(200,
      ({
         1,"'Where is that bloody treasure.\n\n",
         1,":cracks the whip across the prisoners face.\n\n",
         1,":slaps the prisoner.",
         1,":growls at you.",
         1,":says 'LEAVE!'"
      }));
   load_a_chat(200,
      ({
            1,":cracks his whip in midair and lashes it towards you.",
            1,":tries to trip you.",
            1,":screams, 'HELP!"
      }));

   clone_object(WEAPON+"whip.c")->move(this_object());
   clone_object(ARMOR+"leather.c")->move(this_object());
   clone_object(ARMOR+"leather_cap.c")->move(this_object());
   clone_object(ARMOR+"gloves.c")->move(this_object());
   command("equip");
this_object()->init_command("protect orcs");
}
void init()
{
   add_action("do_kill","kill");
   ::init();
}

int do_kill(string str)
{
   if(str == "prisoner")
   {
      write("The orcs attack in an attempt to keep the prisoner "
            "alive.");
   }
   else
   {
      return 0;
   }
}
