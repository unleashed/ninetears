//kivara 27/10/2002 (a las 3 am xD) 
//Actualizado para cumplir con estandar internacional sobre gremios Vilat-IE02

/* Baldrick: Added stat modifier for extreme strength */

inherit "/std/guild";



void setup() 
  {
  set_name("guerrero drow");
  set_short("Guerrero Drow");
  set_long(
     "Los Guerreros Drow son aquellos guerreros que usan su destreza "
     "para sorprender con mortal rapidez a sus enemigos mediante "
     "golpes a la velocidad de la luz.\n");
  reset_get();
  set_needed_align(({-1}),({-1}));
  add_guild_command("juzgar", 1);
  add_guild_command("centrar", 1);
  add_guild_command("fix", 1);
  //add_guild_command("slice",1); //-> por quest! //kiv -> por nivel

  add_guild_command("esconderse",1);
  add_guild_command("sigilar", 1);
  add_guild_command("globooscuro", 1);
  add_guild_command("fuegofatuo", 1);
  
  set_xp_cost(2000);
	set_thac0_step(5); 
	//add_guild_command("twirl",1); -> por quest! de momento rula bugeado
  // y... es una dopada, no creo que se ponga jamas.
	// jiasjias, el surge se supone ke es de wdrow xDDD
//	add_guild_command("acelerarse", 1);
}

void create()
  {
  ::create();
 // set_main_skill("str");
}


//int query_dice()         { return 10;   }
int query_hp_dice(object myp) { return 5;   }
int query_hp_min(object myp)  { return 5;   }
int query_gp_dice(object myp) { return 5;   }
int query_gp_min(object myp)  { return 6;   }
int query_ep_dice(object myp) 	{ return 3; } 
int query_ep_min(object myp)  	{ return 4; }
int query_sp_dice(object myp) 	{ return 3; }
int query_sp_min(object myp)  	{ return 4; }

int query_legal_race(string race) {
	switch(race) {
		case "drow":
		case "Inmortal":
			return 1;
		default:
			return 0;
	}
}

void new_levels(int lvl,object ob) {
  if(lvl==12) {
   add_guild_command("slice", 1);
   tell_object(ob,"Tu experiencia te permite utilizar la habilidad rebanar.");
   //me molaria mas algo del palo: guildmaster te ense�a la habilidad tal i tal
   //pero como no se ke npc es.. pos nada :(
  }
  ::new_levels(lvl,ob); // Esta linea es imprescindible <-- si vilat lo dice...
}

int query_legal_armour(string ignore) { return 1; }
int query_legal_weapon(string ignore) { return 1; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()*2.4;
  bon = ( bon<0 ? 0 : bon );

  return bon;
}



string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Estudioso de las Artes del Combate";
			case 11..15:
				return "Guerrero de la Patrulla de la Suboscuridad";
			case 16..20:
				return "Lider de la Patrulla de la Suboscuridad";
			case 21..25:
				return "Guerrero Drow";
			case 26..30:
				return "Guerrero de la Dama Oscura";
			case 31..35:
				return "Senyor de la Guerra de la Dama Oscura";
			case 36..40:
				return "Protector de la Dama Oscura";
			case 41..45:
				return "Lider de los Guerreros Drow";
			case 46..50:
				return "Brazo Ejecutor de la Dama Oscura";
			case 51..55:
				return "%^BOLD%^%^BLACK%^Slicer %^RESET%^de la %^BOLD%^%^RED%^Muerte%^RESET%^";
			case 56..60:
				return "%^BOLD%^Lider %^RESET%^de los %^BOLD%^%^BLACK%^Slicers %^RESET%^de la %^BOLD%^%^RED%^Muerte%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^RED%^Despiadado %^WHITE%^Maestro de Armas de la %^BLACK%^Suboscuridad%^RESET%^";
			default:
				return "Guerrero Drow Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Estudiosa de las Artes del Combate";
			case 11..15:
				return "Guerrera de la Patrulla de la Suboscuridad";
			case 16..20:
				return "Lider de la Patrulla de la Suboscuridad";
			case 21..25:
				return "Guerrera Drow";
			case 26..30:
				return "Guerrera de la Dama Oscura";
			case 31..35:
				return "Lady de la Guerra de la Dama Oscura";
			case 36..40:
				return "Protectora de la Dama Oscura";
			case 41..45:
				return "Lider de los Guerreros Drow";
			case 46..50:
				return "Brazo Ejecutor de la Dama Oscura";
			case 51..55:
				return "%^BOLD%^%^BLACK%^Slicer %^RESET%^de la %^BOLD%^%^RED%^Muerte%^RESET%^";
			case 56..60:
				return "%^BOLD%^Lider %^RESET%^de los %^BOLD%^%^BLACK%^Slicers %^RESET%^de la %^BOLD%^%^RED%^Muerte%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^RED%^Despiadada %^WHITE%^Maestra de Armas de la %^BLACK%^Suboscuridad%^RESET%^";
			default:
				return "Guerrera Drow Erronea";
		}
	}
}
/*
void on_death(object player, object killer) {
}
*/
/*
int query_thac0_step()   { return 5;    }
int query_extr_str()    { return 1;    }
int query_bing()    { return 1;    }
int query_extra_con_bonus() { return 1; }

*/
/*
string query_main_skill() {return "str";}
int query_advance_cost() { return  500; }
int query_xp_cost()      { return 2000; }
int query_skill_cost(string skill)
{
 return 0;  // Need a list of possible skills first.  Awaiting Dank 
}
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

