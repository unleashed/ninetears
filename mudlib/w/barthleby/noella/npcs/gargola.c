// Spp Octubre 1997
// Ajustado por Ishmar, feb 98

inherit "/obj/monster";
void setup()
{
  set_name("gargola");
  set_short("Gargola");
  set_long("Ves una gargola fornida, con la piel de apariencia "
           "petrea, alta y enorme. Si miras sus ojos, puedes ver "
           "odio... odio hacia aquellos que tiempo atras ayudaron "
           "a la caza de su especie. No serias capaz de decir que "
           "lo que estas viendo es una gargola...\n");
  set_gender(2);
  set_al(3000);
  //set_ethics(50);
  set_main_plural("gargolas");
  set_race("monster");
  set_wimpy(0);
  set_random_stats(16, 20);
  set_cha(roll(10,9));
  //set_guild_ob("/std/guilds/rogues/assassin.c");
  load_a_chat(30,
      ({
            1, ":te mira y se relame los labios...\n",
            1, ":mueve sus alas de forma amenazadora.\n",
            1, ":se siente agitada por tu presencia.\n",
            1, "'Grrrrrhhhhh Guuurrrraghhaa!!!!.\n"
       }));
  //set_level(GARGOLA);
}
