#include "path.h"
inherit "/std/outside";
int found;
object axe;
void setup()
{
   found = 1;
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isla de Havmand: Portal.");
    set_long("\n   Isla of Havmand: Portal.\n"
    "Estas frente a un enorme portal de madera construido en el muro del castillo. "
    "Parece una entrada trasera al castillo, podria ser que fuera usada por los "
    "pueblerinos que por una u otra razon necesitaban entrar al castillo, o para "
    "la entrada y salida de mercancias. Esta firmemente cerrada y las barras de acero "
    "que la refuerzan estan enmohecidas. A tu izquierda hay una pila de madera. "
    "\n\n");
    set_night_long("\n   Isla de Havmand: Portal.\n"
    "El muro del castillo se presenta oscuro ante ti. Una forma rectangular mas oscura "
    "se perfila en el muro, parece un gran puerta. Te golpeas la espinilla al moverte "
    "y tropezar con algo que parece madera. "
    "\n\n");
    add_item("portal","Un enorme portal, bandas de acero le refuerzan, es imposible "
    "abrirlo desde aqui.\n");
    add_item(({"muro","castillo","muralla"}),"Un inmenso muro se levanta frente a ti, "
    " en el han construido un gran portal.\n");
    add_item(({"madera","pila","pila de madera"}),"Una pila de madera cortada para hacer "
    "fuego esta amontonada junto al muro. Hay un hacha clavada en un tocon.\n"
    "Para examinarla mejor tendrias que desclavarla o arrancarla de donde esta.\n");
    add_feel("espinilla","Ouch! esto duele.");
    add_item("hacha","El hacha esta clavada en el tocon usado para hacer astillas. \n");

    add_exit("este",HAVMAND+"t09.c","path");
}
void init()
{
    ::init();
    add_action("do_take","desclavar");
    add_action("do_take","arrancar");
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
write("Le das un tiron al hacha y la desclavas, con el impulso pierdes el equilibrio y sueltas el hacha para no caerte.\n");
say(this_player()->query_cap_name()+" desprende el hacha del tocon de un fuerte tiron, pero la suelta al perder el equilibrio con "
"tanto impulso .\n",this_player());

    found = 1;
   axe = new(WEAPON+"wood_axe.c");
    axe->move(this_object());
    }
    return 0;
}
