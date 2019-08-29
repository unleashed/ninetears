inherit "/std/room.c";

void setup ()   {

set_short("%^BLUE%^BOLD%^Encrucijada de Caminos");
set_long("Ante ti se exponen varias celdas de hierro "
"forjado oxidado por el paso del tiempo.En su "
"interior antanyo humanos, ahora huesos sin piel "
"devorados por buitres y demas animales carronyeros "
"que relucen blancos al sol.Antes esta era una zona "
"en la que ladrones y asesinos de poca monta se "
"exhibian encarcelados como advertencia a cualquier "
"criminal humano que quisiese cometer un delito en la "
"ciudad mas proxima,pero ahora, el poder de los "
"oscuros demonios campera a sus anchas por aqui, "
"y se ven pocos humanos merodeando por el lugar.\n");

add_item("celdas","Las celdas que puedes ver estan "
"llenas de oxido y herrumbre...no ves nada fuera de lo normal.\n");
set_light(50);
add_exit("norte","/w/blastaar/montanyas_salvajes/rooms/cm9.c","door");
add_exit("sur","/w/blastaar/montanyas_salvajes/rooms/cm10.c","door");
add_exit("este","/w/blastaar/montanyas_salvajes/rooms/bs1.c","door");
add_exit("oeste","/w/blastaar/montanyas_salvajes/rooms/pr1.c","door");
}

