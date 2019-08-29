//Vhurkul 21.07.2002
inherit "/std/uwater.c";

void setup()
{
  set_short("Sala bajo el agua");
    set_long("Una sala bajo el agua completamente normal.\n");
  set_light(80);
}

void init()
{
  ::init();
  add_action("descarga","descargar");
}

int descarga() {
	object *todos=all_inventory(TO);
  	if (TP->query_cap_name()!="Vhurkul") {
  	notify_fail("No tienes el conocimiento necesario para utilizar el Cargador.\n");
  	return 0;
 	} else {
  	"/w/vhurkul/maijaus/lvl1"->modify_exit("dentro",({"dest","/w/vhurkul/maijaus/camara"}));
  	"/w/vhurkul/maijaus/lvl1"->renew_exits();
  	for (int i=0;i<sizeof(todos);i++){
  		todos[i]->move("/w/vhurkul/maijaus/camara");
  		tell_object(todos[i],"Te quedas fascinado mirando la Armadura de %^BLACK%^%^BOLD%^Hielo Negro%^RESET%^ de Vhurkul. A traves del reflejo ves como la habitacion donde estabas se desvanece.\n");
  		continue;
  	}
  	return 1;
	}
}
