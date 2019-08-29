inherit "/std/outside.c";

void setup()

{
    set_short("Camino a lo desconocido: Frente al Castillo");
     set_long("Camino a lo desconocido: Frente al Castillo\n\n"+
      "Ante ti aparece como de la nada un castillo de tamanyo medio "+
	"envuelto en una fastuosa aura oscura.\n\n");

    set_light(40);
add_item("castillo","Te acercas un poco a la entrada y observas un " + 
	"aviso escrito en rojo: \"Peligro\".\n");
add_item("camino", "Lugar por el cual la mayoria de los mortales se " +
	"deberian volver llegados aqui.\n");
add_exit("este","/room/castillo_drakull/entrada","road");
add_exit("noroeste","/room/camino/caminito01","road");
add_exit("sur", "/room/templo_bien.c", "road");
}
