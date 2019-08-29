//bichos para todos, modificacion del road_animal.c ya metere mas :-)
#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_al(-150);

        set_gender(random(2)+1);
   	if (query_gender()==1)
	{
	set_name("ciudadano");
        set_short("ciudadano de Noella");
        set_main_plural("ciudadanos de Noella");
        switch(random(9))
      {
        case 0:
        add_alias("drow");
        add_plural("drows");
   	set_race_ob("/std/races/drow");
   	set_random_stats(15, 19);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 1:
        add_alias("enano");
        add_plural("enanos");
   	set_race_ob("/std/races/dwarf");
   	set_random_stats(12, 18);
   	set_cha(12+random(5));
   	set_level(5+random(15));
         break;
        case 2:
        add_alias("elfo");
        add_plural("elfos");
   	set_race_ob("/std/races/elf");
   	set_random_stats(14, 18);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 3:
        add_alias("elfo");
        add_plural("elfos");
   	set_race_ob("/std/races/goblin");
   	set_random_stats(8, 19);
   	set_cha(12+random(5));
   	set_level(3+random(15));
         break;
        case 4:
        add_alias("medio-elfo");
        add_plural("medio-elfos");
   	set_race_ob("/std/races/half-elf");
   	set_random_stats(14, 18);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 5:
        add_alias("medio-orco");
        add_plural("medio-orcos");
   	set_race_ob("/std/races/half-orc");
   	set_random_stats(8, 19);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 6:
        add_alias("halfling");
        add_plural("halflings");
   	set_race_ob("/std/races/halfling");
   	set_random_stats(10, 18);
   	set_cha(12+random(5));
   	set_level(3+random(15));
         break;
        case 7:
        add_alias("humano");
        add_plural("humanos");
   	set_race_ob("/std/races/human");
   	set_random_stats(12, 18);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 8:
        add_alias("hombre-lagarto");
        add_plural("hombres-lagarto");
   	set_race_ob("/std/races/lizard-man");
   	set_random_stats(16, 19);
   	set_cha(12+random(5));
   	set_level(6+random(15));
         break;
        case 9:
        add_alias("orco");
        add_plural("orcos");
   	set_race_ob("/std/races/orc");
   	set_random_stats(14, 19);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        }
        }
  	 else
   	{
          set_name("ciudadana");
          set_short("ciudadana de Noella");
          set_main_plural("ciudadanas de Noella");
          add_plural("ciudadanas");
        switch(random(9))
      {
        case 0:
        add_alias("drow");
        add_plural("drows");
   	set_race_ob("/std/races/drow");
   	set_random_stats(15, 19);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 1:
        add_alias("enano");
        add_plural("enanos");
   	set_race_ob("/std/races/dwarf");
   	set_random_stats(12, 18);
   	set_cha(12+random(5));
   	set_level(5+random(15));
         break;
        case 2:
        add_alias("elfo");
        add_plural("elfos");
   	set_race_ob("/std/races/elf");
   	set_random_stats(14, 18);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 3:
        add_alias("elfo");
        add_plural("elfos");
   	set_race_ob("/std/races/goblin");
   	set_random_stats(8, 19);
   	set_cha(12+random(5));
   	set_level(3+random(15));
         break;
        case 4:
        add_alias("medio-elfo");
        add_plural("medio-elfos");
   	set_race_ob("/std/races/half-elf");
   	set_random_stats(14, 18);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 5:
        add_alias("medio-orco");
        add_plural("medio-orcos");
   	set_race_ob("/std/races/half-orc");
   	set_random_stats(8, 19);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 6:
        add_alias("halfling");
        add_plural("halflings");
   	set_race_ob("/std/races/halfling");
   	set_random_stats(10, 18);
   	set_cha(12+random(5));
   	set_level(3+random(15));
         break;
        case 7:
        add_alias("humano");
        add_plural("humanos");
   	set_race_ob("/std/races/human");
   	set_random_stats(12, 18);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        case 8:
        add_alias("hombre-lagarto");
        add_plural("hombres-lagarto");
   	set_race_ob("/std/races/lizard-man");
   	set_random_stats(16, 19);
   	set_cha(12+random(5));
   	set_level(6+random(15));
         break;
        case 9:
        add_alias("orco");
        add_plural("orcos");
   	set_race_ob("/std/races/orc");
   	set_random_stats(14, 19);
   	set_cha(12+random(5));
   	set_level(4+random(15));
         break;
        }
   	}

      add_alias("noellita");
      add_plural("ciudadanos");
      add_plural("noellitas");
      set_long("Es uno de los habitantes de Noella. Podria estar haciendo la compra o "
              "dirigiendose al trabajo, pero seguramente estara de camino a alguna taberna.\n");
      set_wimpy(0);
      set_aggressive(0);
      adjust_money(random(4), "silver");
      load_chat(30,
      ({    1, "'Pareces simpatico, ven conmigo a la teberna y te invito a un trago.",
            1, "'Nunca esta de mas una buena borrachera.",
            1, "'El alcohol es un gran amigo. Hace mas llevadero el dia a dia.",
            1, ":echa un vistazo a las monedas que le quedan.",
       }));
      load_a_chat(80,
      ({    1, "@No permitere que salgas de esta con vida!",
            1, "@Pagaras por esto!",
            1, ":da una voltereta hacia atras tratando de evitar tus ataques.",
       }));
       
   objeto=new(ARMA+"baston");
   objeto->set_name("vara");
   objeto->add_alias("vara fina");
   objeto->set_short("vara fina de roble");
   objeto->set_main_plural("varas finas de roble");
   objeto->add_plural("varas");
   objeto->set_long("La t�pica vara utilizada por los habitantes de la ciudad. Hecha de roble "
           "y con una tira de cuero para poder agarrarla mejor, sirve las veces de simple apoyo "
           "o como defensa contra indeseables.\n");
   objeto->move(this_object());
   TO->init_equip();
   add_move_zone("noella");

} /* setup() */
