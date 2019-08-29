//Kryger 2003//


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(8))
  {
  
    case 0:
      set_name("rata");
      set_short("Rata");
      set_long(query_short()+"\n"+"Es la rata mas grande que has visto en tu vida, "
	  "pero supones que para sobrevivir en un lugar asi tienes que ser muy "
	  "fuerte y muy grande.\n");
      add_alias("rata");
      set_main_plural("ratas");
      add_plural("ratas");
      set_gender(1);
      ataque1="muerde";
      ataque2="clava sus garras";
      ataque3="salta hacia ti y te muerde la oreja";
      set_level(5+random(2));
      set_max_hp(query_level() * 8);
      break;
    case 1:
      set_name("vibora");
      set_short("Vibora");
      set_long(query_short()+"\n"+"Ves una vibora de un metro de longitud, que "
	  "sisea amenazadoramente levantando su cabeza"
	"y sacando la lengua, en busca de una futura presa.\n");
      set_main_plural("viboras");
      add_alias("viboras");
	add_alias("vibora");
	add_plural("viboras");
      set_gender(1);
      ataque1="se lanza e inyecta su veneno en la pierna";
      ataque2="lanza su veneno a la cara";
      ataque3="clava sus colmillos en una pierna";
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      set_aggressive(1);
      break;
    case 2:
      set_name("babosa");
      set_short("Babosa");
      set_long(query_short()+"\n"+"Es una pequenya babosa que se arrastra por "
	  "las paredes, comiendo hongos y liquenes.\n");
      add_alias("babosa");
      set_main_plural("babosas");
      add_plural("babosas");
      set_gender(2);
      ataque1="babosea";
      ataque2="expulsa seda y te dificulta los movimientos";
      ataque3="hace cosquillas en la pierna";
      set_level(1+random(2));
      set_max_hp(query_level() * 8);
      break;
    case 3:
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
    case 4:
      set_name("polilla");
      set_short("Polilla");
      set_long(query_short()+"\n"+"Es una polilla de color grisaceo que busca "
	  "algo de comida.\n");
      add_alias("polilla");
      set_main_plural("polillas");
      add_plural("polillas");
      set_gender(2);
      ataque1="aranya el rostro";
      ataque2="aranya una mano";
      ataque3="hace cosquillas en la nariz";
      set_level(1+random(2));
      set_max_hp(query_level() * 8);
      break;
    case 5:
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
	case 6:
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
