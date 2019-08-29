//Kivara 1-11-2002
//Guerreros de Faeleen

inherit "/std/guild";

string help() {
    	return "Este es el gremio de los Guerreros de Faeleen. Conocidos "
    	"por la magn�fica descripci�n que se hizo de ellos. Por desgracia "
    	"esta descripci�n se perdi� en el olvido.\n";
    	reset_get();
	}
	
void setup(){
		set_name("guerfaeleen");
		set_short("Guerreros de Faeleen");
		set_long("Este es el gremios de los diestros Guerreros de Faeleen, " 
		"conocidos por sus grandes habilidades en el combate cuerpo a cuerpo "
		"y sus poderosos golpes dobles\n");
		reset_get();
		set_needed_align(({1,0,-1}),({1,0}));//(({1},{0},{-1}),({1},{0}));
		
		add_guild_command("dobleg",1);
	  add_guild_command("codazo",1);
	//	add_guild_command("bloquear",1);
	//	add_guild_command("empujar",1);
		
		set_xp_cost(2000);
		set_thac0_step(5);
		set_clase("Guerrero");
}

int query_legal_race(string raza){
	raza=capitalize(raza);
	switch(raza){
		case "Humano":
		case "Inmortal":
			return 1;
		default:
			return 0;
	}
	//esto no se pa ke lo pongo
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la raza '"+raza+"'.\n");
	return 0;
}
	
int query_legal_armour(string objeto){
	objeto=lower_case(objeto);
	switch(objeto){		
		case "campanya":
		case "completa":		
		case "yelmo_grande":
		case "guantelete":
		case "greba_metal":
		case "botas_metal":
		case "brazal_metal":
			return(0);
		default:
			return(1);
	}
	//?
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la armadura '"+objeto+"'.\n");
	return;
}

int query_hp_dice(object myp) 	{ return 5; }
int query_hp_min(object myp)  	{ return 7; } //8-12
int query_gp_dice(object myp) 	{ return 3; }
int query_gp_min(object myp)  	{ return 6; } //7-9
int query_ep_dice(object myp) 	{ return 3; }
int query_ep_min(object myp)  	{ return 4; } 
int query_sp_dice(object myp) 	{ return 3; }
int query_sp_min(object myp)  	{ return 4; }

int query_dual_wield_penalty(object me, object w1, object w2) {
  	int bon;

  	bon = 50 - (me->query_level()*2.1);
  	if (bon<0){
  		bon=0;
  	}
  	return bon;
}

string query_title(object ob){
	if(ob->query_gender()==1){
		switch(ob->query_level()){
			case 0..10:
				return "Aprendiz de Guerrero";				
			case 11..15:				
			case 16..20:
				return "Protegido de Guildmaster";				
			case 21..25:				
				return "Defensor de Faeleen";
			case 26..30:
			case 31..35:
			case 36..40:				
			case 41..45:
				return "Hermano de batalla de GuildMaster";
			case 46..50:
			case 51..55:
			case 56..60:
				return "General de las tropas de Faeleen";
			case 61..1000:
			default:
				return "El %^RED%^%^BOLD%^Bug %^RESET%^con Patas";
		}
	}else{
		switch(ob->query_level()){
			case 0..10:
				return "Aprendiz de Guerrera";				
			case 11..15:				
			case 16..20:
				return "Protegida de Guildmaster";				
			case 21..25:				
				return "Defensora de Faeleen";
			case 26..30:
			case 31..35:
			case 36..40:				
			case 41..45:
				return "Hermana de batalla de GuildMaster";
			case 46..50:
			case 51..55:
			case 56..60:
				return "General de las tropas de Faeleen";
			case 61..1000:
			default:
				return "La %^RED%^%^BOLD%^Bug %^RESET%^con Patas";
		}
	}
}