#define DOM_TITLE "dominio de Ciudades"
#define DOM_LORD "Vilat"
#define DOMAIN "ciudades"
/* PLEASE re-describe me */
inherit "/std/dom/cmn_mas";
object board;

void setup() {
	string *cius=get_dir("/d/ciudades/control/");
	string com;
	int i;
	set_dom(DOMAIN);
    	add_exit("mapamundi", "/room/admin/mapamundi", "plain");
  	set_short("Sala comun del "+DOM_TITLE);
  	set_long(query_short()+"\nLa sala comun del "+DOM_TITLE+" esta compuesta por una gran mesa donde sus miembros se reunen a debatir el destino de este dominio. Un tablon adorna una de las paredes, y en la opuesta hay un retrato de "+DOM_LORD+", Thane de este dominio.\n");
	add_cartel();
  	board = clone_object("/obj/misc/board");
  	board->set_datafile(DOMAIN);
  	board->move(this_object());
	for(i=0;i<sizeof(cius);i++) {
		com="/d/ciudades/control/"+cius[i];
		if (file_size(com)<1) continue;
		add_exit(cius[i][0..sizeof(cius[i])-3],com,"plain");
		}
	}

void dest_me() {
  	if(board) board->dest_me();
  	::dest_me();
	}

void init() {
	::init();
	add_action("nuevaciu","crear");
	}

int nuevaciu(string str) {
	string tmp;
	if(TP->QCN!=DOM_LORD) return notify_fail("Solo el Thane de Ciudades, "+DOM_LORD+", puede crear ciudadanias nuevas.\n");
	if(!str) return notify_fail("Por favor indica el nombre de la ciudadania que quieres crear.\n");
	if(sizeof(explode(str," "))>1) return notify_fail("No utilices espacios en el nombre de la ciudadania.\n");
	str=lower_case(str);
	if(file_size("/d/ciudades/"+str+".c")>0) return notify_fail("La ciudadania ya esta en uso o el nombre no es valido.\n");
	tmp="inherit \"/std/ciudadania\";\nvoid setup();\n";
	write_file("/d/ciudades/"+str+".c",tmp);
	if(file_size("/d/ciudades/control")!=-2) mkdir("/d/ciudades/control");
	tmp="inherit \"/d/ciudades/base_control\";\n";
	write_file("/d/ciudades/control/"+str+".c",tmp);
	tell_object(TP,"Ok, Ciudadania "+CAP(str)+" creada.\n");
	return 1;
	}
