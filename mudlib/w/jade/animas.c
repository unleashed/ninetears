inherit "std/room";
#define PATH "/doc/razas/"
#define PATH2 "/doc/align/"

setup() 
{
  string humano,semielfo,elfo,halfling,orco,hlagarto,gnomo,enano,goblin,drow,duergar;
  string lb,nb,cb,ln,nv,cn,lm,nm,cm;

// added by Radix for "no new" players from the site.
// REAL ugly but works  (:   2-20-95
   //clone_object("/room/start/nonew")->move(this_object());


  add_property("no_undead",1);
  set_light(75);
  set_short("Sala de las Animas");
  set_long(
"Esta es la sala donde las almas toman forma corporea. Puedes ver imagenes de las "
"distintas deidades a lo largo de la sala, en bovedas, arcos e incluso en los "
"mosaicos del suelo. Tambien observas estatuas representando cada una de las razas "
"de Driade. Estandartes, tapices, emblemas y escudos decoran las paredes de la sala, "
"encarnando las fuerzas de Driade.\n\n"
"Una vez hayas sospesado todas las posibilidades, deberas elegir en primer lugar "
"el alineamiento que pretendes seguir.\n\n"
"Para ello deberas escribir:\n\n"
"elegir <alineamiento>		Ejemplo: elegir lb\n\n");
//"hacerse <raza>       Por Ejemplo: hacerse human\n\n");
add_item("estatuas","Las estatuas estan bellamente esculpidas en granito puro,cada una "
"representando a una raza a la que puedes elegir pertenecer. Si quieres saber mas sobre "
"una raza en particular debes examinar una estatua en concreto,"
"Por ejemplo: exa humano    -o-   exa drow.\n");
add_item(({"escudos","estandartes","emblemas","tapices"}),
"Representan las distintas fuerzas de Driade.\n"
"Los alineamientos disponibles son:\n"
"Legal Bueno, Neutral Bueno, Caotico Bueno, Legal Neutral, Neutral Verdadero, "
"Caotico Neutral, Legal Malvado, Neutral Malvado y Caotico Neutral.\n"
"Para ver mas informacion sobre cada alineamiento escribe:\n\n"
"exa <alineamiento>		Ejemplo: exa lm\n\n"
"NOTA: Se usaran las abreviaturas de los alineamientos usando la primera letra de "
"cada palabra, p.ej.:\n\n"
"Legal Bueno -> lb	   -o-	  	Neutral Malvado -> nm");

  humano = read_file(PATH+"humano");
  semielfo = read_file(PATH+"semielfo");
  elfo = read_file(PATH+"elfo");
  drow = read_file(PATH+"drow");
  enano = read_file(PATH+"enano");
  gnomo = read_file(PATH+"gnomo");
  halfling = read_file(PATH+"halfling");
  orco = read_file(PATH+"orco");
  goblin = read_file(PATH+"goblin");
  hlagarto = read_file(PATH+"hombre-lagarto");
  duergar = read_file(PATH+"duergar");
  lb = read_file(PATH2+"lb");
  nb = read_file(PATH2+"nb");
  cb = read_file(PATH2+"cb");
  ln = read_file(PATH2+"ln");
  nv = read_file(PATH2+"nv");
  cn = read_file(PATH2+"cn");
  lm = read_file(PATH2+"lm");
  nm = read_file(PATH2+"nm");
  cm = read_file(PATH2+"cm");
  
  add_item("humano", humano);
  add_item("semielfo", semielfo);
  add_item("elfo", elfo);
  add_item("drow", drow);
  add_item("enano", enano);
  add_item("gnomo", gnomo);
  add_item("halfling", halfling);
  add_item("orco", orco);
  add_item("goblin", goblin);
  add_item("hombre-lagarto", hlagarto);
  add_item("duergar",duergar);
  add_item("lb", humano);
  add_item("nb", semielfo);
  add_item("cb", elfo);
  add_item("ln", drow);
  add_item("nv", enano);
  add_item("cn", gnomo);
  add_item("lm", halfling);
  add_item("nm", orco);
  add_item("cm", goblin);
  }

int no_kill(string str) { return 1; }

void init()
{
  ::init();
  add_action("do_align","elegir");
  add_action("do_become", "hacerse");
  add_property("nocast",1);
  add_property("noguild",1);
  /* Mask the action rearrange */
  add_action("do_rearrange", "ajustar");
  add_action("no_kill","attack");
  add_action("no_kill","kill");
  add_action("no_kill","matar");
   
}

int do_align(string str)
{
 object me;
 string align;
 string opcr;
 string elfo,semielfo,enano,gnomo,halfling,humano,hlagarto,duergar,goblin,orco,drow,demonio;
 me = this_player();
 str = lower_case(str);
 switch(str)
   {
   case "lb":
   case "nb":
   case "cb":
   case "ln":
   case "nv":
   case "cn":
   case "lm":
   case "nm":
   case "cm":
   
   align = str;
   break;
	case "lb":
		align = "Legal Bueno";
		opcr = elfo,semielfo,enano,gnomo,halfling,humano;
		break;
	case "nb":
		align = "Neutral Bueno";
		opcr = elfo,semielfo,enano,gnomo,halfling,humano;
		break;
	case "cb":
		align = "Caotico Bueno";
		opcr = elfo,semielfo,enano,gnomo,halfling,humano;
		break;
	case "ln":
		align = "Legal Neutral";
		opcr = elfo,semielfo,enano,gnomo,halfling,humano,hlagarto;
		break;
	case "nv":
		align = "Neutral Verdadero";
		opcr = elfo,semielfo,enano,gnomo,halfling,humano,hlagarto;
		break;
	case "cn":
		align = "Caotico Neutral";
		opcr = elfo,semielfo,enano,gnomo,halfling,humano,hlagarto;
		break;
	case "lm":
	        align = "Legal Malvado";
	        opcr = humano,hlagarto,duergar;
		break;
	case "nm":
	        align = "Neutral Malvado";
	        opcr = humano,hlagarto,duergar,goblin,orco,drow;
		break;
	case "cm":
		align = "Caotico Malvado";
		opcr = humano,hlagarto,duergar,goblin,orco,drow,demonio;
		break;
     return 0;
  }
}
int do_rearrange()
  {

   tell_object(this_player(),"No puedes hacer eso aqui, intentalo despues de la creacion de tu personaje.\n");
   return 1;
} /* do rearrange */

int do_become(string str)
{
 object me;
 string race;
 string startplace;
int i; 
me = this_player();
 str = lower_case(str);

   switch(str)
   {
   case "humano":
   case "semielfo":
   case "halfling":
   case "enano":
   case "drow":
   case "duergar":
   case "elfo":
   case "orco":
   case "hombre-lagarto":
   case "gnomo":
   case "goblin":
 //     race = str;
   break;
	case "humano":
		race = "humano";
		break;
	case "elfo":
		race = "elfo";
		break;
	case "semielfo":
		race = "semielfo";
		break;
	case "hombre-lagarto":
		race = "hombre-lagarto";
		break;
	case "gnomo":
		race = "gnomo";
		break;
	case "enano":
		race = "enano";
		break;
	case "goblin":
		race = "goblin";
		break;
	case "orco":
		race = "orco";
		break;
	case "halfling":
		race = "halfling";
		break;

   default:
      return 0;
   break;
 }

   if ((string)me->query_race_ob() != "/std/races/unknown")
   {	// UFFFS xD esto peligroso xD
	startplace = "/room/start/"+race+".c";

	if (me->query_level() > 5) {
   		notify_fail("Tu raza no ha sido alterada.\n");
		startplace = "/room/entryroom.c";
	}
   	me->move(startplace);
   	this_player()->look_me();
    	return 0;
   } /* in (me */

 
 if(race) // comprobaciones chorras, ia sabemos que race esta ok
 {
   say(this_player()->query_cap_name()+" toca la estatua "+race+" y "
    "desaparece.\n", this_player());
   me->set_race_ob("/std/razas/"+race);
   startplace = "/room/start/"+race+".c";
   tell_object(me,
	"\nHas elegido tu raza, disfruta de tu caracter de mortal...\n"
	 "Como un regalo especial *POR AHORA*, ya que no hay zonas,"
	 " has sido agraciado por los Dioses con 75 millones XP.\n"
	 "Tus caracteristicas seran 18 18 18 18 18 18, *PERO* tu extrema"
	 " NO se cambiara, la que salga sera :)\n\n");
	me->set_xp(75000000); // adjust_xp a veces falla al poner esto �?
	me->set_max_social_points(1000);
	me->set_social_points(1000);
   switch(race)
   {
      case "half-elf":
         me->add_language("humano");
         me->add_language("elfo");
      break;
      case "half-orc":
         me->add_language("humano");
         me->add_language("orco");
      break;
      case "half-drow":
         me->add_language("humano");
         me->add_language("drow");
      break;
      default:
         me->add_language(race);
      break;
   }
   me->move(startplace);
   startplace->add_equipment();
   this_player()->look_me();

   return 1;
 }

 notify_fail("No existe esa raza, prueba de nuevo.\n");
 return 0;
}
