/* Added by Galvin 95-06-18 */
inherit "/obj/monster";

void setup()
{
  set_name("orgg");
  set_short("orgg");
  set_long("This is Orgg, the barkeep of Long Tail Tavern. He is a slim "
           "and bitter lizard-man that retired from his former occupation as "
           "a ranger, when he lost his left arm. Orgg is very popular among "
           "his patrons and he seems to know everyone. \n\n");
  set_gender(1);
  set_race("lizard-man");
  set_guild("fighter");
  set_random_stats(9,15);
  adjust_str(4);
  adjust_con(5);
  set_level(15);
  clone_object("/baseobs/weapons/trident.c")->move(this_object());
  init_equip();
}
