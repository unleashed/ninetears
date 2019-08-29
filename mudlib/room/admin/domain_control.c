/* domain administration room */
#include "access.h"
inherit "/std/room";
#define MASTER "/secure/master"

void setup() {
  	set_short("Despacho de control de %^BOLD%^Dominios%^RESET%^");
  	set_long(query_short()+"\nEn este despacho los Inmortales pueden dar forma al plano material creando nuevos mundos para los mortales, asi que si tienes ideas para un dominio y ganas de trabajar, comunicaselo a un Dios para que te conceda ese nuevo dominio.\n"
		"Comandos:\n"
		"  %^YELLOW%^listar%^RESET%^ORANGE%^                       %^RESET%^: Muestra un resumen de todos los dominios.\n"
		"  %^YELLOW%^listar%^RESET%^ORANGE%^ <dominio>             %^RESET%^: Muestra los miembros de un dominio.\n"
		"  %^YELLOW%^crear%^RESET%^ORANGE%^ <dominio>              %^RESET%^: Crea un dominio (contigo como Thane).\n"
		"  %^YELLOW%^crear%^RESET%^ORANGE%^ <dominio> <thane>      %^RESET%^: Crea un dominio para alguien.\n"
		"  %^YELLOW%^a�adir%^RESET%^ORANGE%^ <creador> <dominio>   %^RESET%^: Anyade un creador a uno de tus dominios.\n"
		"  %^YELLOW%^borrar%^RESET%^ORANGE%^ <creador> <dominio>   %^RESET%^: Elimina a un creador de uno de tus dominios.\n"
		"  %^YELLOW%^proyecto%^RESET%^ORANGE%^ <cre> <dom> <pro>   %^RESET%^: Establece el proyecto de un creador en un dominio.\n");
	add_exit("fuera","/d/heaven/admin3","door");
  	seteuid("Root");
	} /* setup() */

void init() {
  	::init();
  	add_action("list", "listar");
  	add_action("create_domain", "crear");
  	add_action("add_creator", "anyadir");
	add_action("add_creator", "a�adir");
  	add_action("delete_creator", "borrar");
  	add_action("do_project", "proyecto");
	} /* init() */

int list(string arg) {
  	string *members, *domains, mast;
  	int i, cols;

  	if (this_player() != this_player(1)) return 0;

	domains = get_dir("/d/");
  	if(!sizeof(domains)) return notify_fail("No hay dominios.\n");

  	if(arg) {
    		if(member_array(arg, domains) == -1) return notify_fail("No existe un dominio llamado "+capitalize(arg)+".\n");
		else {
      			mast = "/d/" + arg + "/master";
      			write(capitalize((string)mast->query_dom_lord()) + " es Thane de " + capitalize(arg) + ".\n%^BOLD%^Miembros        Proyecto%^RESET%^\n");
      			members = (string *)mast->query_members();
      			cols = (int)this_player()->query_cols();
      			for (i=0;i<sizeof(members);i++) printf("%-15s %*-=s\n", capitalize(members[i]), cols-16, mast->query_project(members[i]));
      			return 1;
    			}
  		}
  	tell_object(TP,"%^BOLD%^Actualmente existen los siguientes Dominios:%^RESET%^\n");
  	for(i=0; i<sizeof(domains); i++) {
    		mast = "/d/" + domains[i] + "/master";
    		members = (string *)mast->query_members(arg);
    		printf("%12s tiene %2d miembro(s) y es propiedad de %s.\n", capitalize(domains[i]), sizeof((string *)mast->query_members()), capitalize((string)mast->query_dom_lord()));
  		}
  	return 1;
	} /* list() */

int create_domain(string arg) {
  	string dom, lord;

  	if (this_player() != this_player(1)) return 0;
  	if(!arg) return notify_fail("Uso:   crear <dominio>\n       crear <dominio> <thane>\n");

  	if(!((MASTER->high_programmer(geteuid(previous_object()))) && (previous_object()->query_god()))) return notify_fail("Comienzas a dar forma a la nada, creando la materia necesaria para tu deseado dominio a partir del vacio estelar, pero te das cuenta de que es mas poder del que puedes controlar sin deformar la Realidad y te detienes justo a tiempo.\n");

  	if(sscanf(arg, "%s %s", dom, lord) != 2) {
    		dom = arg;
    		lord = (string)this_player()->query_name();
  	} else lord = (string)this_player()->expand_nickname(lord);

  	if (!MASTER->create_domain(dom, lord)) return notify_fail("Fallo al crear el dominio " + capitalize(dom) + ".\n");

  	tell_object(TP,"Creas el Dominio " + capitalize(dom) + " para " + capitalize(lord) + ".\n");
  	return 1;
	} /* create_domain() */

int add_creator(string arg) {
  	string dom, cre, mast;

  	if (this_player() != this_player(1)) return 0;
  	if (!arg || sscanf(arg, "%s %s", cre, dom) != 2) return notify_fail("Uso: anyadir <creador> <dominio>\n");

	if(file_size("/d/" + dom) != -2) return notify_fail("No existe el dominio "+capitalize(dom)+".\n");

  	cre = (string)this_player()->expand_nickname(cre);
  	mast = "/d/" + dom + "/master";
  	if(!mast->query_dom_manip()) return notify_fail("Ese dominio no te pertenece.\n");
  	if(!mast->add_member(cre)) return notify_fail("Error al anyadir a " + capitalize(cre) + " al dominio "+capitalize(dom) + ".\n");
	tell_object(TP,capitalize(cre) + " anyadido al dominio " + capitalize(dom) + ".\n");
  	return 1;
	} /* add_creator() */

int delete_creator(string arg) {
  	string cre, dom, mast;

	if (this_player() != this_player(1)) return 0;
  	if (!arg || sscanf(arg, "%s %s", cre, dom) != 2) return notify_fail("Uso: borrar <creador> <dominio>\n");

  	if(file_size("/d/" + dom) != -2) return notify_fail("No existe el dominio "+capitalize(dom)+".\n");

  	cre = (string)this_player()->expand_nickname(cre);
  	mast = "d/" + dom + "/master";
	if(!mast->query_dom_manip()) return notify_fail("Ese dominio no te pertenece.\n");
  	if (!mast->remove_member(cre)) return notify_fail("Error al borrar a " + capitalize(cre) + " del dominio " + capitalize(dom) + "\n");
	tell_object(TP,capitalize(cre) + " borrado del dominio " + capitalize(dom) + ".\n");
	return 1;
	} /* delete_creator() */

int do_project(string arg) {
  	string cre, dom, project, mast;

  	if (this_player() != this_player(1)) return 0;
  	if (!arg || sscanf(arg, "%s %s %s", cre, dom, project) != 3) return notify_fail("Uso: proyecto <creador> <dominio> <proyecto>\n");

  	if(file_size("/d/" + dom) != -2) return notify_fail("No existe el dominio "+capitalize(dom)+".\n");

  	cre = (string)this_player()->expand_nickname(cre);
  	mast = "d/" + dom + "/master";
	if(!mast->query_dom_manip()) return notify_fail("Ese dominio no te pertenece.\n");

  	if (!mast->set_project(cre, project)) return notify_fail("Error al establecer el proyecto de " + capitalize(cre) + " en el dominio " + capitalize(dom) + "\n");
	tell_object(TP,"Establecido proyecto de "+capitalize(cre) + " en el dominio " + capitalize(dom) + ".\n");
  	return 1;
	} /* do_project() */
