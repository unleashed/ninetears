#include "path.h"
inherit "/std/outside";
int found;
object vine;
void setup()
{
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isla de Havmand : Cima en la colina");
    set_long("\nIsla de Havmand : Cima en la colina\n\n"
      "   Esta es la cima de la colina, por encima de la linea de arboles por fin. "
      "Miras abajo por encima de las copas de arboles de la jungla por la que has "
      "llegado aqui. El suelo aqui es rocoso y seco, pero aun asi hay algun arbol "
      "que intenta enraizar en este claro. "
      "\n\n");
    set_night_long("\nIsla de Havmand: Cima en la colina.\n"
      "   Todo esta muy oscuro y las pocas formas que distingues estan llenas "
      "de misterio. Lejos, en el horizonte ves una luz que destellea intermitentemente. "
      " En la oscuridad la forma de algun arbol se eleva enorme ante ti. "
      "\n\n");
    add_item("jungla","Puedes ver abajo las copas de los arboles, desde aqui "
      "parecen incluso mas grandes que cuando te abriste paso entre ellos"
      ".\n");
    add_item(({"arbol","arboles"}),"En esta zona hay pocos arboles, aunque se ven "
      "sanos no obstante, y tienen largas lianas enredadas en sus troncos. \n");
    add_item(({"hebra","lianas"}),"Fuertes lianas cuelgan de los arboles. "
      "En caso de necesitar una cuerda, estas lianas podrian ser utiles.\n");
    add_item(({"luz","destello","flash"}),"Lejos hay una luz que se enciende y "
      "apaga, piensas que tal vez sea algun tipo de sistema de alarma, "
      "como uno de esos faros de los que has oido hablar.\n");

    add_exit("sudeste",HAVMAND+"j29.c","path");
}

void init()
{
    add_action("do_cut","cortar");
    add_action("do_cut","rajar");
    add_action("do_cut","sajar");
    ::init();
}
int do_cut(string str)
{
    if (!str)
    {
	write("Cortar que?");
	return 1;
    }
    if(str == "liana")
    {
	object *ob;
	ob = find_match("hacha",TP);
if(sizeof(ob) <1)
	{
write("No tienes la herramienta con la que cortar la fuerte liana.  \n");
return 0;
}
else
{
	    vine = new(OBJ+"vine.c");
	    vine->move(this_object());
write("Con un golpe limpio cortas la liana, la ves caer del arbol amontonandose "
"sobre si misma en el suelo.\n");
	    return 1;
	}
    }
    else
    {
	write("Cortar que?\n");
    }
}
