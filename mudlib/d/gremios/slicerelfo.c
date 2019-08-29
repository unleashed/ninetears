//Modificado by Kivara para cumplir especificaciones Vilat'2002
//Tb he retocado los titulos, ke me parecieron provisionales :P
//Los otros estan aun por ahi, pero comentados, por si no os molan los mios

// Tyrael - ReDesign :) - Ene '02
//
// Este gremio NO sera sliceador.
// Se le dara el acelerarse y otros comandos de rangers. (rastrear p.e.)
// El invocar estara listo cuando se arreglen bugs.
//
// Modificar QUEST slice para no dar slice a lefos.

inherit "/std/guild";

int query_skill_cost(string skill)
{
 return 0;  /* Need a list of possible skills first.  Awaiting Dank */
}

void setup() 
  {
  set_name("guerrero elfo");
  set_short("Guerrero Elfo");
  set_long(
     "Los Guerreros Elfos son aquellos guerreros que usan su destreza "
     "para sorprender con mortal rapidez a sus enemigos mediante "
     "golpes a la velocidad de la luz.\n");
  reset_get();
  set_needed_align( ({1,0}) , ({1,1}) ); 
  add_guild_command("juzgar", 1);
  add_guild_command("centrar", 1);//??
  add_guild_command("fix", 1);
  add_guild_command("esconderse",1);
  add_guild_command("sigilar", 1);
	add_guild_command("fuegofatuo", 1); //??
	add_guild_command("cazar", 1);
	
	add_guild_command("detectar", 1); // ??
	
	
	set_xp_cost(2000);
	set_thac0_step(5); //si los barbaros tienen 6... estos entre 4 i 5, no?
	set_clase("Guerrero");
	
	//add_guild_command("explorar", 1); <-- por nivel (se evitan pj's espias)
	//add_guild_command("acelerarse", 1); <---por nivel
	
	//add_guild_command("invocar", 1); eliminar bugs
	//	add_guild_command("vigilar", 1); hay que eliminar bugs
	//add_guild_command("slice",1); -> por quest! NEW: quedara eliminado
}



//int query_dice()         { return 10;   }
int query_hp_dice(object myp)         { return 5;   }
int query_hp_min(object myp)         { return 5;   }
int query_gp_dice(object myp)         { return 5;   }
int query_gp_min(object myp)         { return 6;   }
int query_ep_dice(object myp) 	{ return 3; } //etto ke es?
int query_ep_min(object myp)  	{ return 4; }
int query_sp_dice(object myp) 	{ return 3; }//social points?
int query_sp_min(object myp)  	{ return 4; }

int query_legal_race(string race) {
	race=capitalize(race);
	switch(race) {
		case "Elfo":
		case "Immortal":
		case "Inmortal":
			return 1;
		default:
			return 0;
	}
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la raza '"+race+"'.\n");
	return 0;
}

//ke usen lo ke kieran ,no?
int query_legal_weapon(string ignore) { return 1; }

int query_legal_armour(string str) {
	str=lower_case(str);
	switch (str) {
		case "yelmo":
		case "casco":
		case "yelmo_grande":
		case "brazal_metal":
		case "guantelete":
		case "greba_metal":
		case "botas_metal":
		case "cota":
    		case "malla":
    		case "cota_elfica":
    		case "cota_reforzada":
		case "coraza":
    		case "placas_bronce":
		case "placas":		
			return 1;
			//estilo 23
		case "campanya":		
		case "completa":			
    default:    		
    		return 0;
    		}
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la armadura '"+str+"'.\n");
	return 0;
}

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()*2.4; //el multi-arma es su especialidad
  if (bon<0) bon=0;
  return bon;
}

void new_levels(int lvl,object ob) {
  if(lvl==12) {
   add_guild_command("explorar", 1);
   tell_object(ob,"Tu experiencia te permite utilizar la habilidad explorar.");
   //me molaria mas algo del palo: guildmaster te ense�a la habilidad tal i tal
   //pero como no se ke npc es.. pos nada :(
  }else if(lvl==20){
 		add_guild_command("acelerarse", 1);
 		tell_object(ob,"Sientes como has adquirido la habilidad para acelerarte.");
  }
  ::new_levels(lvl,ob); // Esta linea es imprescindible <-- si vilat lo dice...
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Aprendiz de Guerrero";
			case 11..15:
				return "Protector de la Naturaleza";
			case 16..20:
				return "Guerrero Elfo";
			case 21..25:
				return "Lider de la Patrulla de los Bosques";
			case 26..30:
				return "Sombra de los Bosques";
			case 31..35:
				return "Experto Cazador de los Bosques";
			case 36..40:
				return "Protector de la Dama de los Bosques";
			case 41..45:
				return "Lider de los Guerreros Elfos";
			case 46..50:
				return "Hijo de la Naturaleza";
			case 51..55:
				return "Legendario combatiente de la Naturaleza";
			case 56..60:
				return "%^BOLD%^%^WHITE%^Maestro de Armas de los %^GREEN%^Bosques%^RESET%^";
			case 61..1000:
				return "%^BOLD%^El senyor de los %^GREEN%^Bosques";
			default:
				return "Guerrero Elfo Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Aprendiz de Guerrera";
			case 11..15:
				return "Protectora de la Naturaleza";
			case 16..20:
				return "Guerrera ElfaLider de la Patrulla de los Bosques";
			case 21..25:
				return "Lider de la Patrulla de los Bosques";
			case 26..30:
				return "Sombra de los Bosques";
			case 31..35:
				return "Experta Cazadora de los Bosques";
			case 36..40:
				return "Protectora de la Dama de los Bosques";
			case 41..45:
				return "Lider de los Guerreros Elfos";
			case 46..50:
				return "Hija de la Naturaleza";
			case 51..55:
				return "Legendaria combatiente de la Naturaleza";
			case 56..60:
				return "%^BOLD%^%^WHITE%^Maestra de Armas de los %^GREEN%^Bosques%^RESET%^";
			case 61..1000:
				return "Lady de la Guerra de la Dama de los Bosques";
			default:
				return "Guerrera Elfa Erronea";
		}
	}
}
/* titulos viejos
string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Estudioso de las Artes del Combate";
			case 11..15:
				return "Guerrero de la Patrulla de los Bosques";
			case 16..20:
				return "Lider de la Patrulla de los Bosques";
			case 21..25:
				return "Guerrero Elfo";
			case 26..30:
				return "Guerrero de la Dama de los Bosques";
			case 31..35:
				return "Senyor de la Guerra de la Dama de los Bosques";
			case 36..40:
				return "Protector de la Dama de los Bosques";
			case 41..45:
				return "Lider de los Guerreros Elfos";
			case 46..50:
				return "Brazo Ejecutor de la Dama de los Bosques";
			case 51..55:
				return "%^BOLD%^%^BLACK%^Slicer %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 56..60:
				return "%^BOLD%^Lider %^RESET%^de los %^BOLD%^%^BLACK%^Slicers %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^YELLOW%^Humilde %^WHITE%^Maestro de Armas de los %^GREEN%^Bosques%^RESET%^";
			default:
				return "Guerrero Elfo Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Estudiosa de las Artes del Combate";
			case 11..15:
				return "Guerrera de la Patrulla de los Bosques";
			case 16..20:
				return "Lider de la Patrulla de los Bosques";
			case 21..25:
				return "Guerrera Elfa";
			case 26..30:
				return "Guerrera de la Dama de los Bosques";
			case 31..35:
				return "Lady de la Guerra de la Dama de los Bosques";
			case 36..40:
				return "Protectora de la Dama de los Bosques";
			case 41..45:
				return "Lider de los Guerreros Elfos";
			case 46..50:
				return "Brazo Ejecutor de la Dama de los Bosques";
			case 51..55:
				return "%^BOLD%^%^BLACK%^Slicer %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 56..60:
				return "%^BOLD%^Lider %^RESET%^de los %^BOLD%^%^BLACK%^Slicers %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^YELLOW%^Humilde %^WHITE%^Maestra de Armas de los %^GREEN%^Bosques%^RESET%^";
			default:
				return "Guerrera Elfa Erronea";
		}
	}
}
*/
//esta funcion creo ke se tiene ke eliminar
/*void create()
  {
  ::create();
}*/

/*
int query_extr_str()    { return 1;    }
int query_bing()    { return 1;    }
int query_extra_con_bonus() { return 1; }
*/

/*
void set_gp(object ob)
{ 
  ob->set_max_gp(level+(((int)ob->query_str()+(int)ob->query_con())/2));
}

void set_hp(object ob)
{ 
 int lvl;
 lvl = (int)ob->query_level();
 ob->set_max_hp(query_dice()*lvl);
 }
*/



/*
void on_death(object player, object killer) {
}
*/

