
inherit "/obj/monster";
#include "path.h";

void setup()
{
add_alias("guard");
   set_name("orc");
   set_race("orc");
   set_gender(1);
set_main_plural("orcs");
   add_plural("angry orcs");
add_plural("guards");
   set_al(100);
   set_aggressive(0);
   set_random_stats(10,15);
   set_con(18);
   set_level(3+random(2));
   set_wimpy(0);
set_short("Orc Guard");
set_long(" Your mind is over power by the shear number of adjectives that "
"describe his smell alone. But at any rate, he is here to protect "
"the orcish mobs from raiders while the warriors go and raid other "
"near-by towns.\n\n");
   load_chat(100,
      ({
1,"'STOP LOOKING AT ME!!!.'\n\n",
1,":shifts his bulk from one leg to the next.\n\n",
1,":peers out into infinity, wondering if life is really composed of small particles of matter called atoms or is it just the food he eat that is upsetting his thoughts.\n\n",
         1,":growls at you.",
         1,":says 'LEAVE!'"
      }));

   clone_object(WEAPON+"short_sword.c")->move(this_object());
   clone_object(ARMOR+"leather.c")->move(this_object());
   clone_object(ARMOR+"leather_cap.c")->move(this_object());
   command("equip");
}
void init()
{
   add_action("do_kill","kill");
   ::init();
}

int do_kill(string str)
{
   if(str == "orc")
   {
write("The orc grins and prepares himself for battle.\n");
   }
   else
   {
      return 0;
   }
}
