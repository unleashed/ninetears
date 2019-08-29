inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(6))
  {
  
   case 0:
      set_name("serpiente");
      set_short("Serpiente");
      set_main_plural("Serpientes");
      set_random_stats(6,10);
      set_long("Serpiente\n\nEste pequenyo reptil se arrastra por el suelo "
               "lentamente. No parece ser agresivo, tampoco tiene pinta de , "
               "ser muy fuerte. Al mirarle los ojos, observas, no tiene. "
               "En su lugar, la zona parece haber sido quemada.\n");
      set_aggressive(0);
      set_race("monster");
      set_level(1+random(6));
      set_gender(1);
      load_chat(50,
      ({
        1, ":sisea levemente.",
        1, ":se arrastra lentamente por el suelo.",
      }));
      break;
    case 1:
      set_name("lobo");
      set_short("Lobo");
      set_main_plural("Lobos");
      set_random_stats(14,18);
      set_long(query_short()+"\n"+"Un temible lobo hambriento, es grande y fuerte y "
      "tiene una mirada fiera. Su piel es de color negra, anda sigiloso en busca de "
      "alguna presa que echarse a la boca, te mira fijamente parece como si ya hubiera "
      "encontrado su presa.\n");
      set_aggressive(0);
      set_race("monster");
      set_level(10+random(10));
      set_gender(1);
      load_chat(10,
      ({
        1, ":grunye.",
	1, ":te mira fijamente.",
      }));
      break;
    case 2:
      set_name("murcielago");
      set_short("Murcielago");
      set_long(query_short()+"\n"+"Es una rata-voladora, mas conocida como "
	  "murcielago.\n");
      add_alias("murcielago");
      set_main_plural("murcielagos");
      add_plural("murcielagos");
      set_gender(1);
      ataque1="clava sus colmillos en tu cuello";
      ataque2="aranya una mano";
      ataque3="muerde la pierna";
      set_level(4+random(2));
      set_max_hp(query_level() * 8);
      break;
    case 3:
      set_name("aranya");
      set_short("Aranya");
      set_long(query_short()+"\n"+"Es una pequenya aranya, aunque su cuerpo "
	  "negro y rojo no te inspira mucha confianza.\n");
      set_main_plural("aranyas");
      add_plural("aranyas");
      set_gender(2);
      set_level(5+random(3));
      set_max_hp(query_level() * 8);
      ataque1="se lanza e inyecta su veneno en la pierna";
      ataque2="expulsa seda y te dificulta los movimientos";
      ataque3="muerde un pie";
      break;
    case 4:
      set_name("sombra");
      set_short("Sombra");
      set_long(query_short()+"\n"+"Vemos a una sombra amenazante, es incorporea "
	  " no tiene los rasgos definidos, ni piernas, en su lugar tiene una especie "
	  "de bruma algo rara, sus manos son garras afiladas, y no tiene expresion de "
	  "querer hacer amigos. Tiene unos ojos rojos fuertes, parecen estar echos de "
	  "sangre, es lo �nico que puedes divisar en la bruma.\n");
      set_main_plural("sombras");
      add_plural("sombras");
      set_gender(2);
      set_level(7+random(3));
      set_max_hp(query_level() * 8);
      ataque1="te desgarra la piel";
      ataque2="hunde las garras en un brazo";
      ataque3="te raja el brazo haciendo dificultosos sus movimientos";
      break;
    case 5:
      set_name("cuervo");
      set_short("Cuervo");
      set_main_plural("Cuervos");
      set_random_stats(6,14);
      set_long(query_short()+"\n"+"Es un cuervo de un oscuro plumaje, que vive de los "
         "restos descompuestos de los seres del bosque. No "
         "obstante. Una escalofriante sensacion te recorre la "
         "espina dorsal al fijarte en los ojos de la criatura, "
         "que te escudrinyan, y parecen leerte el alma. Te preguntas "
         "si este cuervo esconde dentro de si algo mas que lo que "
         "aparenta.\n");
      set_aggressive(0);
      set_race("monster");
      set_level(2+random(4));
      set_gender(1);
      set_wimpy(30);
      load_chat(80,
      ({
        1, ":mordisquea los ojos del cadaver de un pequenyo animal.",
        1, ":revolotea entre los arboles, desprendiendo una sinietra sombra sobre tu cabeza.",
        1, ":grazna vilmente.",
      }));
      set_move_after(20+random(10), 20+random(10));
      break;
  }
  set_random_stats(7,17); 
  set_al(50+random(-100));
  set_wimpy(0+random(20));
  set_move_after(20+random(10), 20+random(10));
}
 /* setup */
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
} 


valid_attack() 
{
   return([
      "kick"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "knee"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "punch"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"})]);


}