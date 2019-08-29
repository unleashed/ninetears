# include "path.h"
inherit "/std/room";
int found;
object door;
void setup()
{
    add_property("no_undead",1);
    set_short("Isla de Havmand: Vivienda.");
    set_light(60);
   set_long("\nIsla de Havmand : Vivienda\n\n"
    " Esta miserable casita es basicamente una ruina. Tiene boquetes por las paredes "
    "y el techo, algunos muy grandes, la puerta cuelga a punto de soltarse de sus bisagras, "
    "y el suelo esta cubierto de hojas muertas y ramas arrastradas hasta aqui por el viento. "
    "Puedes ver el cielo mirando hacia arriba desde aqui. "
    "\n\n");
    add_item("boquetes","Puedes ver, a traves de los agujeros del techo el cielo, y "
    "por los de las paredes ves la jungla de afuera.\n");
    add_item("cielo","Ves el cielo y algun ave volando en lo alto.\n");
    add_item("jungla","Montones de arboles que crecen en casi toda la isla.\n");
    add_item("techo","El techo no parece ser muy solido, en varias partes ha cedido "
    "dejando grandes boquetes.\n");
    add_item("pared","Las paredes son de madera, algunas de las tablas estan rotas "
    "y por el hueco entra el aire del exterior.\n");
    add_item("puerta","Una puerta de madera que se sostiene a duras penas en su quicio. Un simple tiron "
    "seria suficiente para arrancarla de las fragiles bisagras.\n");
    add_item("bisagras","Las bisagras estan hechas de cuero.\n");
    add_item(({"hojas","ramas","suelo","hojarasca"}),"El suelo esta cubierto de hojarasca "
    "de la jungla, arrastrada por el viento.  \n");

}
void init()
{
    add_exit("este",HAVMAND+"t08.c","path");
add_action("do_take","tirar");
add_action("do_take","arrancar");
    ::init();
}
void reset()
{
    found = 0;
}
void dest_me()
{
    ::dest_me();
}
int do_take(string str)
{
    if(!found)
    {
        write("Das un fuerte tiron y las bisagras ceden dejando suelta la puerta.\n");
        say(this_player()->query_cap_name()+" arranca una puerta de la vivienda.\n",this_player());
        found = 1;
door=new(OBJ+"door.c");
        door->move(this_object());
        return 1;
    }
    return 0;
}



