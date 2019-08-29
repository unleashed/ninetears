/* Gareth 14.1.2002
Bosque de Wayreth, quest Khurgar */

inherit "/std/bosque";
#define ROOMS "/w/gareth/comandos/"

void setup() {
	set_short("%^GREEN%^Bosque de Wayreth%^RESET%^");
	set_long(query_short()+"\n\n    Te encuentras en un bosque muy denso, "
		"repleto de arboles con aspecto retorcido y de copas altas"
		" y puntiagudas. Los arboles no dejan pasar ni un rayo de"
		" sol, lo que hace que el bosque este sumido en la oscuridad."
		" Los ruidos y movimientos de los arbustos y la maleza te "
		"producen una sensacion de peligro que te hace estar alerta.\n\n");
   	add_sound(({"bosque","animales","aire"}),"El sonido de los pajaros y "
   		"animales que habitan el bosque en la oscuridad le da un aire"
   		" siniestro que te pone los pelos de punta.\n");
   	add_exit("norte",ROOMS+"bosque09","plain");
   	add_exit("noreste",ROOMS+"bosque10","plain");
   	add_exit("este",ROOMS+"bosque07","plain");
   	add_exit("oeste",ROOMS+"bosque08","plain");
   	add_exit("sudeste",ROOMS+"bosque02","plain");
   	
   	add_clone(ROOMS+"bichos.c",random(4));
}