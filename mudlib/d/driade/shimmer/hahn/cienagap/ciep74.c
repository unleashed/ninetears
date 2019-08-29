/* By Shimmer */

inherit "/std/room";

void setup() {
   set_zone("cienagaprofunda");
   set_exit_color("blue");
   set_light(40);
   set_short("%^ORANGE%^Entrada a la Cripta%^RESET%^");
   set_long("%^ORANGE%^Entrada a la Cripta%^RESET%^\n\n"
   "Te encuentras ante la puerta de lo que parece una tumba o panteon antiguo, ves numerosas "
   "inscripciones a los lados pero no puedes descifrar lo que pone debido a lo gastada que esta "
   "la pared en esa zona, del techo del panteon cualgan muchas hiedras que lo cubren casi por "
   "completo.\n\n");
add_item("puerta","Es una gran puerta de madera medio podrida con ribetes dorados y numerosas inscripciones, "
   "parece no tener ninguna cerradura ni pomo y no sabes como podrias abrirla.");

add_clone("/d/driade/shimmer/hahn/npcs/guardian_cripta.c",2);

add_exit("oeste","/d/driade/shimmer/hahn/cienagap/ciep72.c","standard");
add_exit("empujar puerta","/d/driade/shimmer/hahn/cienagap/cripta1.c","standard");

}