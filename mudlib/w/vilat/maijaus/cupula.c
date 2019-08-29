//Vilat 20.07.2002
inherit "/std/room.c";

void setup() {
  set_short("%^BLACK%^BOLD%^%^Cupula de la Torre de Vilat%^RESET%^");
  set_long("Has alcanzado la parte mas alta de la Torre de Vilat. Esta estancia tiene toda la pinta de ser un gigantesco observatorio, debido a las cripticas inscripciones del suelo, que se iluminan con un brillo verde segun se desplazan los astros. Pero sobre todo te llama la atencion el inmenso ventanal que se abre en el hielo negro, desde el cual pueden verse a lo lejos los Reinos de los mortales.\n");
  set_light(100);

  add_item(({"pared","hielo"}),"La estancia esta construida en frio hielo negro, finamente labrado. Las antorchas de fuego azul le arrancan caprichosos destellos.");
  add_item(({"antorcha","antorchas"}),"Numerosas antorchas iluminan la estancia formando un estremecedor espectaculo. Curiosamente, el fuego es de un extranyo azul claro.");
  add_sound("habitacion","Escuchas el crepitar de las antorchas y el aterrador fluir de la sangre.");
  add_feel(({"antorcha","antorchas","fuego","llama","llamas"}),"El fuego azul de las antorchas no desprende calor alguno.");
  add_item(({"inscripcion","inscripciones","suelo"}),"Extranyas runas grabadas en el hielo negro. Algunas brillan con un antinatural fulgor verdoso.");
  add_item(({"ventanal","reinos","reino"}),"Desde el ventanal hay una imponente vista de los Reinos de Leyenda.");
  
  add_exit("abajo","/w/vilat/maijaus/lvl1","stair");
}