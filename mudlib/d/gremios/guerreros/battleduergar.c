/* Baldrick: Added stat modifier for extreme strength */

inherit "/std/guild";

string help() {
	return "Los Battle Ragers son aquellos guerreros que usan su furia para "
     "eliminar a sus enemigos. Esta puede llegar a un estado en que "
     "el Battle Rager pierde el control de sus actos y se deja llevar "
     "por su ira en una orgia de sangre y destruccion. Ademas, son "
     "conocidos por su grito de guerra, con el cual intimidan a sus "
     "adversarios.\n";   	
    	reset_get();
	}

void setup() 
  {
  set_name("battle rager duergar");
  set_short("Battle Rager Duergar");
  set_long(
     "Los Battle Ragers son aquellos guerreros que usan su furia para "
     "eliminar a sus enemigos. Esta puede llegar a un estado en que "
     "el Battle Rager pierde el control de sus actos y se deja llevar "
     "por su ira en una orgia de sangre y destruccion. Ademas, son "
     "conocidos por su grito de guerra, con el cual intimidan a sus "
     "adversarios.\n");
  reset_get();
  set_needed_align(({-1}),({-1}));
  add_guild_command("juzgar", 1);
  add_guild_command("centrar", 1);
  add_guild_command("fix", 1);
  // add_guild_command("bash",1); pedirselo al guildmaster!
  add_guild_command("rabia",1);
  set_xp_cost(2000);
  set_thac0_step(6);
  set_clase("Guerrero");
}

int query_legal_race(string race) {
	race=capitalize(race);
    	switch(race) {
    		case "Duergar":
		case "Duergar":
    		case "Immortal":
    		case "Inmortal":
		return 1;
    		default:
		return 0;
    		}
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la raza '"+race+"'.\n");
	return 0;
	}

int query_hp_dice(object myp)         { return 4;   }
int query_hp_min(object myp)         { return 6;   }
int query_gp_dice(object myp)         { return 6;   }
int query_gp_min(object myp)         { return 6;   }
int query_ep_dice(object myp) 	{ return 3; } //etto ke es?
int query_ep_min(object myp)  	{ return 4; }
int query_sp_dice(object myp) 	{ return 3; }//social points?
int query_sp_min(object myp)  	{ return 4; }

//pueden llevar de todo?
int query_legal_armour(string ignore) { return 1; }
int query_legal_weapon(string ignore) { return 1; }

void new_levels(int lvl,object ob) {
  if(lvl==12) {
   add_guild_command("bash", 1);
   tell_object(ob,"Largos dias de entrenamiento te permiten utilizar la habilidad bash."); 
   //me molaria mas algo del palo: guildmaster te ense�a la habilidad tal i tal
   //pero como no se ke npc es.. pos nada :(. Ahora ta mu cutre,lo se
  }
  ::new_levels(lvl,ob); // Esta linea es imprescindible <-- si vilat lo dice...
}

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()*2;
  if (bon<0) bon=0;
  return bon;
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Aprendiz de Khuthul";
			case 11..15:
				return "Discipulo de Khuthul";
			case 16..20:
				return "Soldado de Bendorf";
			case 21..25:
				return "Patrullero de Bendorf";
			case 26..30:
				return "Protector de Bendorf";
			case 31..35:
				return "Senyor de la Batalla";
			case 36..40:
				return "Temido Guerrero de la Batalla";//no me gusta
			case 41..45:
				return "Guerrero del Caos"; //Gran Guerrero del Caos
			case 46..50:
				return "Sangriento Destripador de Enanos";
			case 51..55:
				return "%^BOLD%^General de los Ejercitos %^RESET%^de %^BOLD%^%^BLUE%^Bendorf%^RESET%^";
			case 56..60:
				return "%^BOLD%^Caudillo de los Ejercitos %^RESET%^de %^BOLD%^%^BLUE%^Bendorf%^RESET%^"; //tampoco me gusta :(
			case 61..1000:
				return "%^BOLD%^%^CYAN%^Primer Enemigo %^RESET%^de %^BOLD%^%^GREEN%^Kheleb-Dum%^RESET%^";
			default:
				return "Battle Rager Duergar Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Aprendiz de Khuthul";
			case 11..15:
				return "Seguidora de Khuthul";
			case 16..20:
				return "Soldado de Bendorf";
			case 21..25:
				return "Patrullera de Bendorf";
			case 26..30:
				return "Protectora de Bendorf";
			case 31..35:
				return "Lady de la Batalla";
			case 36..40:
				return "Temida Guerrera de la Batalla";
			case 41..45:
				return "Guerrera del Caos";//Gran Guerrera de...
			case 46..50:
				return "Sangrienta Destripadora de Enanos";
			case 51..55:
				return "%^BOLD%^General de los Ejercitos %^RESET%^de %^BOLD%^%^BLUE%^Bendorf%^RESET%^";
			case 56..60:
				return "%^BOLD%^Caudillo de los Ejercitos %^RESET%^de %^BOLD%^%^BLUE%^Bendorf%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^CYAN%^Primer Enemigo %^RESET%^de %^BOLD%^%^GREEN%^Kheleb-Dum%^RESET%^";
			default:
				return "Battle Rager Duergar Erronea";
		}
	}
}

/* cosas viejas ke ya taban aki
void create()
  {
  ::create();
  set_main_skill("str");
}


string query_main_skill() {return "str";}
int query_advance_cost() { return  500; }
//int query_xp_cost()      { return 2000; }
//int query_dice()         { return 10;   }


int query_thac0_step()   { return 6;    }
int query_extr_str()    { return 1;    }
int query_bing()    { return 1;    }
int query_extra_con_bonus() { return 1; }
*/

/*
int query_skill_cost(string skill)
{
 return 0;  // Need a list of possible skills first.  Awaiting Dank 
}
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


void on_death(object player, object killer) {
}
*/
