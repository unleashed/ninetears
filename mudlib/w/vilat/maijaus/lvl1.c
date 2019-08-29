//Vilat 20.07.2002
inherit "/std/room.c";

void setup() {
  set_short("%^CYAN%^Primer piso de la Torre de Vilat%^RESET%^");
  set_long("Este piso es similar a los demas de la torre, iluminado por el fuego azul el hielo negro te produce una sobrecogedora sensacion. Hay una puerta con un rotulo grabado sobre ella.\n");
  set_light(80);

  add_item(({"pared","suelo","hielo"}),"La estancia esta construida en frio hielo negro, finamente labrado. Las antorchas de fuego azul le arrancan caprichosos destellos.");
  add_item(({"antorcha","antorchas"}),"Numerosas antorchas iluminan la estancia formando un estremecedor espectaculo. Curiosamente, el  fuego es de un extranyo azul claro.");
  add_sign("Un rotulo brillante.\n","Camara de Supresion","Rotulo","rotulo");
  add_sound("habitacion","El fuego azul crepita en la inmensidad de la Torre.");
  add_feel(({"antorcha","antorchas","fuego","llama","llamas"}),"El fuego azul de las antorchas no desprende calor alguno.");
  
  add_exit("abajo","/w/vilat/maijaus/lvl0","stair");
add_exit("arriba","/w/vilat/maijaus/cupula","stair");
  add_exit("dentro","/w/vilat/maijaus/camara","door");
}
