#include "path.h"
inherit "/std/outside";
int found;
object chain;
object sword;
void setup()
{
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isla de Havmand: Repisa. ");
    set_long("\nIsla de Havmand : Repisa\n\n"
    "   Estas en una estrecha repisa en medio de un profundo foso. Mas abajo "
    "puedes ver agua que surge y se retira de un tunel de forma alarmante. Si "
    "resbalas desde aqui te espera una muerte segura. Sobre ti, algo a la derecha "
    "esta el borde del foso, desde donde has saltado. Te reconforta comprobar que "
    "tu liana sigue firmemente sujeta, ya que es la unica manera de salir de  "
    "aqui.\n"
    "Tendido en la repisa hay el resto esqueletico de un aventurero que no tuvo "
    "mucha suerte. No obstante parte de su equipo parece haber desaparecido. "
    "\n\n");
    set_night_long("\nIsla de Havmand : Repisa\n\n"
    "   Es muy dificil ver en la oscuridad de aqui abajo. Solo aciertas a distinguir "
    "lo que parece un esqueleto reposando en esta repisa. "
    "\n\n");
    add_sound("agua","Puedes oir el ruido del agua golpeando contra las paredes "
    "de roca.\n");
    add_smell("agua","Sientes intensamente el olor a agua salada.\n");
    add_item(({"agua","mar"}),"Espumosas olas se estrellan contra las paredes "
    "del foso, abajo, lanzando nubes de gotas saladas aunque apenas te llegan "
    "a salpicar. \n");
    add_item("borde","Sobre ti, algo a la derecha puedes ver el borde desde el que "
    "has saltado. desde aqui parece mas pequenyo que cuando estabas alli. \n");
    add_item("liana","Esta es la liana que has usado para asegurarte el camino de "
    "vuelta. Esta sujeta al arbol de arriba, por si acaso vuelves a probar que sigue asi. "
    "Es una suerte tenerla, ya que no hay otra forma de subir. \n");
    add_item("arbol","Es el pequenyo pero robusto arbol en donde has atado tu "
    "liana. \n");
    add_item("esqueleto","Huesos blanqueados por el sol es todo lo que queda de algun "
    "pobre aventurero que se quedo aqui atrapado. Resulta raro que no no veas por aqui su equipo, "
    "a menos que este escondido.\n");
}
void init()
{
    add_exit("liana",HAVMAND+"j37.c","path");
    add_action("do_search","buscar");
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
int do_search(string str)
{
    if(! found)
    {
        write("Buscas en el esqueleto y encuentras una cota de malla y una espada bastarda "
        " Ambas cosas necesitan una buena limpieza, pero siendo lo mejor que puedes "
        "encontrar por aqui, te sientas y empiezas a trabajar en su limpieza y pulido"
        ".\n");

        say(this_player()->query_cap_name()+" busca en el esqueleto.\n",this_player());

        found = 1;

      chain = new(ARMOUR+"chainmail");
//        chain->set_short("Rusty chainmail");
//        chain->set_long("This chainmail has a thin coating of rust and it's "
//        "going to be uncomfortable to wear for a while. But time, use and a "
//        "wipe with an oily cloth now and then should clean it up.\n");
        chain->move(this_object());

      sword = new(WEAPON+"bastard_sword");
//        sword->set_short("Rusty Bastard sword");
//        sword->set_long("A large heavy sword, you may have trouble swinging it "
//        "but it isn't going to stop swinging in a hurry. It looks in pretty "
//        "good shape even though it has a patina of rust. A little time "
//        "and tender loving care should restore it nicely.\n");
        sword->move(this_object());
    }
    else
    {
        write("Buscas pero no encuentras nada.\n");
    }
        return 1;
}

