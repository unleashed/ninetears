inherit "/std/room";

void setup() {
   set_zone("cienaga");
   set_exit_color("green");
   set_light(50);
   set_short("%^BOLD%^%^GREEN%^Arbol de Ameline%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^Arbol de Ameline%^RESET%^\n\n"
   "Ante ti tienes un gigantesco arbol de una especie que desconoces, nunca habias visto un arbol tan bello, "
   "y te preguntas que estara haciendo aqui en medio de la cienaga donde no crece ni la hierba, con sus fuertes "
   "ramas cargadas de hojas verdes en flor. La respuesta esta ante ti, en un pequenyo cartel que dice lo siguiente:\n\n"
   "             Aqui yace la princesa Ameline\n"
   "             hija unica del poderoso Hahn,\n"
   "             muerta en la gran batalla de Hahn\n"
   "             contra las poderosas ordas\n" 
   "             orcas del general Khashjedith.\n\n"
   "No se sabe muy bien por que el arbol florece bello aqui en medio "
   "de la nada, quizas el espiritu de la bella Ameline resida aun en el...\n\n");
add_item("arbol","Cuando te fijas en el arbol notas como una brisa calida te acaricia el rostro, "
                 "y un escalofrio te recorre el cuerpo, tienes la impresion de que hay algo extranyo en el, "
                 "como si estubiera observando cada movimiento que haces, como si alguien estubiera intentando "
                 "decirte algo...\n\n");

add_exit("norte","/d/driade/shimmer/hahn/cienagap/ciep0.c","standard");
add_exit("sur","/d/driade/shimmer/hahn/cienaga/cie69.c","standard");
add_exit("este","/d/driade/shimmer/hahn/cienaga/cie32.c","standard");
add_exit("oeste","/d/driade/shimmer/hahn/cienaga/cie33.c","standard");

}