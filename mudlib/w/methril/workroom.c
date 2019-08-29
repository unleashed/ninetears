/** Methril Ethril 2002 **/
#define CREATOR "Methril"

inherit "/std/room.c";
int pasillo = 0;

void setup() {
   	set_short("Recepcion de la %^BOLD%^%^RED%^Casa%^RESET%^ de %^BOLD%^%^WHITE%^"+capitalize(CREATOR)+"%^RESET%^");

   	set_long(query_short()+"
"+
   		"   Estas en una amplia sala mal iluminada. Tan solo un candelabro ilumina un vieja e incomoda silla "+
   		"situada junto a una puerta cerrada. Un escalofrio recorre tu espalda y el temor de romper la paz de este "+
   		"lugar te hace estremecerte.
"+
   		"   Este austero lugar de recepcion no invita a quedarse durante mucho tiempo, seria mejor continuar o "+
   		"salir rapidamente de aqui.

");

   	add_item("silla","Junto a una puerta, justo debajo del candelabro, puedes ver una vieja y destartalada silla.
 Esta cubierta por una gruesa capa de polvo, dando la impresion de no haberse usado en mucho mucho tiempo.
");
   	
   	add_item("puerta","Parece estar cerrada.
 Te preguntas hacia donde conducira.1n");
   	
   	add_item("candelabro","Un candelabro sencillo colgado de una pequenya estanteria chorrea cera por los cuatro costados. Es el unico punto de luz de esta inmensa sala, lo que te impide ver los rincones mas alejados.
");

   	add_item(({"pared","sala"})," Grandes ladrillos de piedra  %^BOLD%^%^BLACK%^negra%^RESET%^ revisten las paredes de este lugar austero y sencillo.

 Una desagradable sensacion inunda tu corazon y te hace inquietarte.
");

   	add_item("mobiliario","El mobiliario es escaso, o eso parece, ya que tan solo puedes ver la puerta de entrada y una pequenya puerta junto a la silla.
");

   	add_item("techo","La escasa luz que ilumina la estancia impide ver mas arriba de tu cabeza.
");

   	add_smell(({"habitacion","sala","aire"}),"La usencia de olor demuestra la limpieza y el orden que reinan en el lugar.
");

   	add_feel("pared","El ladrillo esta frio como el hielo, y al tocarlo parece absorver el calor de tu cuerpo, es como si tomara vida propia.
");

   	add_sound(({"habitacion","sala","aire"}),"Tan solo el sonido del viento filtrandose por viejas ventanas es lo unico que logran percibir tus torpes oidos.
");

	//add_clone("/obj/misc/candelabro.c",1);

   	add_exit("comun","/w/common","door");

   	"/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
}
   	
void init(){
	::init();
	add_action("get_cand","coger");
	add_action("abrir_puerta",({"abrir","empujar"}));
}

int get_cand(string str) {
	if (str == "candelabro") {
		tell_object(TP,"Cuando coges el candelabro notas un chasquido. Te da la sensacion de que algo ha sucedido, pero no logras saber que es.
Tienes la impresion de que la puerta ha sido desbloqueada.
");
		tell_room(TO,TP->query_cap_name()+" coge el unico punto de luz de la sala.
");
		add_clone("/w/methril/candelabro.c",1)->move(TO);
		pasillo = 1;
		return 1;
	}
	notify_fail("Que pretendes coger?
Si apenas hay cosas que coger.
");
	return 0;
}
int abrir_puerta(string str) {
	if ( (str == "puerta") ) {
		if ( (pasillo == 0) ) {
			tell_object(TP,"Con un esfuerzo sobrehumano logras habrir la puerta.

Eres absorvido por extranyas fuerzas hacia su interior y no consigues percibir haci donde te diriges.
");
			tell_room(TO,TP->query_cap_name()+" desaparece sin dejar rastro, dejando la sala completamente a oscuras.
");
			TP->move("/w/methril/pasillo.c");
			return 1;	
		} else {
			tell_object(TP,"La puerta esta bloqueada, no parece que se abra.
");
			return 0;
		}
	}
	notify_fail("Abrir? Que es lo que estas intentando abrir?");
	return 0;
}

