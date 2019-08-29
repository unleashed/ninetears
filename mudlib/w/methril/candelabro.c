/** Methril Ethril 2002 **/
#define CREATOR "Methril"

inherit "/obj/misc/torch.c";
int encendido = 0;

void setup() {
	set_name("candelabro");
	set_short("Candelabro");
	set_long("query_short()+"
"+
		"  Un humeante candelabro que te permite ver en los mas oscuros rincones.
Varios "+
		"hilos de cera recorren su superficie, quemando tus manos de vez en cuando. "+
		"Parece tener un texto en la base.

");
	set_plural("candelabros");
	add_alias("luz");
	add_plural("luces");
	
	add_item("texto","Se puede encender y apagar el candelabro pronunciando un \"encantamiento\".
");
	
}

void init() {
	::init();
	add_action("conmuta_luz","encantamiento");
}

int conmuta_luz(){
	if (encendido == 0) {
		encendido = 1;
		//modificacion de la luz de la habitacion (+10)
		return 1;
	} 
	if (encendido == 1) {
		encendido = 0;
		//modificacion de la luz de la habitacion (-10)
		return 1;
	}
	notify_fail("Que estas intentando hacer?
");
	return 0;
}
