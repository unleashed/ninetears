//Valdor '99

inherit "obj/monster";

void setup()
{
  set_name("darhazad");
  add_alias("maestro");//estos dos anteriores siempre en minusculas.
  set_short("Darhazad"); // Ponlo siempre en mayusculas.
  set_long("Este drow de edad inconmensurable parece mas joven que su propio hijo. Nadie mas que el sabe"
		" su secreto. Con una estatura de metro sesenta, pelo blanco y rasgos de nobleza, este drow"
		" ha llegado a ser un ser muy importante politicamente dentro de la sociedad drow. Tambien es el "
		"primer mago guerrero drow que existio, y por lo tanto conoce bastantes secretos de esta antigua"
		" y poderosa formacion. Su propio hijo, Jorbud, no ha llegado ni a sacarle la mas minima pista "
		"de su mas grandioso secreto, la vida eterna."
		".\n");
  set_race_ob("std/races/drow.c");
  set_random_stats(16,24);//stats aleatorios para la fuerza destreza y demas entre 30 y 80..se pueden hacer especificos..como en estigio.
  set_int(30);
  set_dex(27);
  set_str(32);
  set_guild_ob("std/guilds/multi/wizwar");
//  set_guild_ob("std/guilds/wizards/wizard");
  set_level(90+random(10));
  set_max_hp(3000+random(2000));
  set_hp((TO->query_max_hp()),(TO->query_max_hp()));
  set_max_gp(1200+random(800));
  set_gp((TO->query_max_gp()));
  set_main_plural("Darhazades");
  set_ac(-40);
  set_align(10000);//Alineamiento del bicho desde -10000 angelico a 10000 diabolico
  set_gender(1);//Genero del bicho
  load_chat(80,
          ({
	    1,":cruza sus espadas y las hace rechinar con estridencia.\n",
	    1,"'Que haces aqui bastardo??\n",
	    3,"'Siento sed de sangre!!!!\n",
	    1,"'Ni se te ocurra intentar estropear algo de este gremio!!.\n",
	    1,({":suelta un bufido.\n",
		"'parece mentira que estes aqui, oh ser despreciable.\n",
		":te mira con ojos sanguinolentos.\n",
	      }),
	    1,({":junta las palmas de sus manos y se pone a orar en voz baja.\n",
	      "'arxj fehird lozrag psilomv, orma kanun telugah.\n",
	      ":suspira con goze en el momento en que un aura anacarada lo cubre.\n",
	      })  
          }));
  load_a_chat(500,
          ({
	    1,"'Comete esta cobarde!!!.\n",
	    1,({":suelta un rugido inhumano parecido al sonido del metal contra metal.\n",
	        "'Sssssssshink ziiiiiiiiiig shhhhhhhhhank.\n",
	      }),	
	    1,":te empuja de un codazo hacia atras.\n",
	  }));    
 add_property("sharp",60);
   add_property("blunt",50);
   add_property("pierce",40);
  add_property("invulnerable_hechizos",3);
/*
  add_clone("/d/oficios/multi/wizwar/items/es_ant",2);
*/
  
  TO->init_equip();
  
}

void init()
{
 ::init();
add_attack_spell(55,"atake",({"/std/spells/escuelas/wizwar/inferno","cast_spell",2}));
 add_attack_spell(100,"rapidillo",({"/std/commands/surge","surge",3,0}));
  "/std/spells/escuelas/alteracion/piel_piedra"->cast_spell(TO->query_name(),TO,0,1);
} 


int query_res()
{
  return 80;
}



