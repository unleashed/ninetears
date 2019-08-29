#define CIUDADANIA file_name(TO)[20..]
#define POSICIONES ({"guerra","hostilidad","neutralidad","amistad","alianza"})
#include <money.h>
inherit "/std/room";
object board;

void setup() {
    	add_exit("ciudades", "/d/ciudades/common", "plain");
  	set_short("Sala de control de "+CAP(CIUDADANIA));
  	set_long(query_short()+"\nEsta es la sala de control de "+CAP(CIUDADANIA)+", donde su regente, "+CAP("/d/ciudades/master"->query_regente(CIUDADANIA))+", realiza su labor de organizacion de la ciudad.\n");
  	board = clone_object("/obj/misc/board");
        board->set_datafile("ciu_"+CIUDADANIA);
  	board->move(this_object());
	add_sign("Un cartel con los comandos de este lugar.\n",
		"Para administrar la ciudadania de "+CAP(CIUDADANIA)+", su regente puede:\n"
		" %^ORANGE%^informacion%^BOLD%^       %^RESET%^       :    Muestra el estado de la ciudad\n"
		" %^ORANGE%^civiles%^BOLD%^ <numero>%^RESET%^         :    Pone el numero de civiles viviendo en la ciudad\n"
		" %^ORANGE%^posicion%^BOLD%^ <ciudad> <tipo>%^RESET%^ :    Establece la relacion respecto a una ciudad\n"
		" %^ORANGE%^inicio%^BOLD%^ <archivo>%^RESET%^         :    Establece la room de inicio de la ciudad\n\n"
		" %^ORANGE%^comandante%^BOLD%^ <nombre>%^RESET%^      :    Pone a <nombre> como Comandante\n"
		" %^ORANGE%^consejero%^BOLD%^  <nombre>%^RESET%^      :    Pone a <nombre> como Consejero\n"
		" %^ORANGE%^miliciano%^BOLD%^  <nombre>%^RESET%^      :    Pone a <nombre> como Miliciano\n\n"
		" %^ORANGE%^iventas%^BOLD%^ <numero>%^RESET%^         :    Establece el impuesto de ventas\n"
		" %^ORANGE%^icivil%^BOLD%^ <oros>%^RESET%^            :    Establece el impuesto civil\n"
		" %^ORANGE%^gasto%^BOLD%^ <platino>%^RESET%^          :    Establece el gasto mensual\n"
		" %^ORANGE%^gastar%^BOLD%^ <platino>%^RESET%^         :    Descuenta monedas al tesoro\n"

		,"cartel","cartel");
	}

void dest_me() {
  	if(board) board->dest_me();
  	::dest_me();
	}

void init() {
	::init();
	add_action("posicion","posicion");
	add_action("inicio","inicio");
	add_action("general","comandante");
	add_action("consejero","consejero");
	add_action("miliciano","miliciano");
	add_action("info","informacion");
	add_action("iventas","iventas");
	add_action("icivil","icivil");
	add_action("civiles","civiles");
	add_action("gastar","gastar");
	add_action("gasto","gasto");
	}

int posicion(string str) {
	int i;
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str||sizeof(explode(str," "))!=2) return notify_fail("Uso: posicion <ciudad> <tipo>\n");
	str=lower_case(str);
	if(member_array(explode(str," ")[1],POSICIONES)==-1) return notify_fail("Las posiciones validas son: "+implode(POSICIONES,", ")+"\n");
	for(i=0;i<sizeof(POSICIONES);i++) if(explode(str," ")[1]==POSICIONES[i]) break;
	i-=2;
	("/d/ciudades/"+CIUDADANIA)->establecer_relacion(explode(str," ")[0],i);
	tell_object(TP,"Ok, establecida posicion de "+CAP(CIUDADANIA)+" respecto a "+CAP(explode(str," ")[0])+" como "+CAP(POSICIONES[i+2])+".\n");
	return 1;
	}

int inicio(string str) {
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: inicio <archivo>\n");
	str=lower_case(str);
	if(file_size(str)<1&&file_size(str+".c")<1) return notify_fail("El archivo no existe.\n");
	("/d/ciudades/"+CIUDADANIA)->establecer_inicio(str);
	tell_object(TP,"Ok, a partir de ahora la room de inicio de "+CAP(CIUDADANIA)+" sera "+str->query_short()+".\n");
	return 1;
	}

int general(string str) {
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: comandante <nombre>\n");
	str=lower_case(str);
	("/d/ciudades/"+CIUDADANIA)->poner_comandante(str);
	tell_object(TP,"Ok, "+CAP(str)+" es ahora Comandante de los Ejercitos de "+CAP(CIUDADANIA)+".\n");
	return 1;
	}

int consejero(string str) {
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: consejero <nombre>\n");
	str=lower_case(str);
	("/d/ciudades/"+CIUDADANIA)->poner_consejero(str);
	tell_object(TP,"Ok, "+CAP(str)+" es ahora miembro del Consejo de "+CAP(CIUDADANIA)+".\n");
	return 1;
	}

int miliciano(string str) {
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: miliciano <nombre>\n");
	str=lower_case(str);
	("/d/ciudades/"+CIUDADANIA)->poner_miliciano(str);
	tell_object(TP,"Ok, "+CAP(str)+" pertenece ahora a la Milicia de "+CAP(CIUDADANIA)+".\n");
	return 1;
	}

int info() {
	string ret;
	ret="\n\t%^BOLD%^Informacion de la Ciudadania "+CAP(CIUDADANIA)+":%^RESET%^\n"
	 "Actualmente estan viviendo en la ciudad "+(string)("/d/ciudades/"+CIUDADANIA)->query_civiles()+" civiles.\n"
	 "El tesoro se valora en "+MONEY_HAND->money_value_string(("/d/ciudades/"+CIUDADANIA)->query_tesoro())+", con un gasto mensual de "+
	MONEY_HAND->money_value_string(("/d/ciudades/"+CIUDADANIA)->query_gasto())+" y unos ingresos basicos por impuestos de "+
	MONEY_HAND->money_value_string(("/d/ciudades/"+CIUDADANIA)->query_civiles()*("/d/ciudades/"+CIUDADANIA)->query_impuesto_civil())+".\n"
	"Ademas se cobra un impuesto de ventas del "+("/d/ciudades/"+CIUDADANIA)->query_impuesto_ventas()+"%\n"+
	("/d/ciudades/"+CIUDADANIA)->query_descontento_name()+"\n\n";
	tell_object(TP,ret);
	return 1;
	}

int iventas(string str) {
	int n;
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: iventas <numero>\n");
	n=atoi(str);
	if(!intp(n)||n<0||n>100) return notify_fail("El impuesto no es valido.\n");
	("/d/ciudades/"+CIUDADANIA)->poner_impuesto_ventas(n);
	tell_object(TP,"Impuesto de ventas: "+(string)n+"%\n");
	return 1;
	}

int icivil(string str) {
	int n;
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: icivil <oro>\n");
	n=atoi(str);
	if(!intp(n)||n<0) return notify_fail("El impuesto no es valido.\n");
	n*=100;
	("/d/ciudades/"+CIUDADANIA)->poner_impuesto_civil(n);
	tell_object(TP,"Impuesto civil: "+MONEY_HAND->money_value_string(n)+" per capita\n");
	return 1;
	}

int civiles(string str) {
	int n;
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: civiles <numero>\n");
	n=atoi(str);
	if(!intp(n)||n<0) return notify_fail("Numero no valido.\n");
	("/d/ciudades/"+CIUDADANIA)->poner_civiles(n);
	tell_object(TP,"Actualmente viven en "+CAP(CIUDADANIA)+" "+(string)n+" civiles.\n");
	return 1;
	}

int gastar(string str) {
	int n;
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: gastar <platino>\n");
	n=atoi(str);
	if(!intp(n)||n<0) return notify_fail("El numero de platinos no es valido.\n");
	n*=500;
	if(n>("/d/ciudades/"+CIUDADANIA)->query_tesoro()) return notify_fail(CAP(CIUDADANIA)+" no tiene tanto dinero para gastar.\n");
	("/d/ciudades/"+CIUDADANIA)->ajustar_tesoro(-n);
	tell_object(TP,"Gastados "+MONEY_HAND->money_value_string(n)+", el tesoro queda en "+MONEY_HAND->money_value_string(("/d/ciudades/"+CIUDADANIA)->query_tesoro())+".\n");
	return 1;
	}

int gasto(string str) {
	int n;
	if(TP->QCN!=CAP("/d/ciudades/master"->query_regente(CIUDADANIA))) return notify_fail("No eres regente de "+CAP(CIUDADANIA)+".\n");
	if(!str) return notify_fail("Uso: gasto <platino>\n");
	n=atoi(str);
	if(!intp(n)||n<0) return notify_fail("El numero de platinos no es valido.\n");
	n*=500;
	("/d/ciudades/"+CIUDADANIA)->poner_gasto(n);
	tell_object(TP,"Establecido gasto en "+MONEY_HAND->money_value_string(n)+".\n");
	return 1;
	}
