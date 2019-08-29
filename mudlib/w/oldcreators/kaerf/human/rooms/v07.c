
#include "path.h"
inherit "/std/room";
int found;
object cask;
void setup()
{
    add_property("no_undead",1);
    set_short("Isla de Havmand: Taberna, sotano.");
    set_light(40);
   set_long("\nIsle of Havmand : Taberna, sotano\n\n"
    "Esta en una oscura diminuta cueva bajo la taberna. Aqui hay un monton de "
    "viejas botellas apiladas en una pared, y varios barriles apilados en el "
    "otro extremo. Las telaranyas cubren todo y el polvo se ha ido posando "
    "acumulandose en todas las superficies. Una estrecha escalera conduce a la taberna. "
    "\n\n");
    add_item("botellas","Viejas botellas conteniendo algun liquido sin identificar, "
    "decides no investigar mas a fondo.\n");
    add_item(({"barriles","toneles"}),"Son barriles de madera y no muy grandes. Algunos contienen "
    "algo que huele a pescado en conserva, pero otros estan vacios.\n");
    add_item("telaranyas","Las aranyas han estado muy ocupadas aqui abajo, al parecer, "
    "sus artesanias estan por todas partes.\n");
    add_item("polvo","Solo es polvo, aunque en cantidades industriales.\n");
    add_feel("polvo","Donde quiera que tocas tus manos se manchan con el suave polvo.\n");
    add_smell("pescado","Realmente aborrecible, apesta como calcetines viejos.\n");
    add_item(({"escalera","escaleras"}),"Una estrecha y pequenya escalera de madera, "
    "que conduce al bar en la taverna de arriba.\n");
//add_item("racks","These serve to hold the wine casks in place, off the ground.  \n");
    add_item(({"pared","paredes"}),"No ves nada especial en estas paredes lisas.\n");


}
void init()
{
    add_exit("arriba",HAVMAND+"v01.c","path");
    add_action("do_take","coger");
    add_action("do_take","agarrar");
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
        write("Encuentras un par de barriles vacios.\n");
        say(this_player()->query_cap_name()+" Encuentra algo en la cueva.\n",this_player());
        found = 1;

        cask = new(OBJ+"cask.c");
        cask->move(this_player());
        cask = new(OBJ+"cask.c");
        cask->move(this_player());

    }
    else
    {
      if(lower_case(str) == "barril")
      {
        write("Parece que alguien se ha llevado todos los barriles vacios.\n"
        "No obstante, con una taberna arriba, pronto volvera a quedar alguno.\n");
      return 1;
      }
    }
    return 0;
}





