// Aokromes
#include "../../path.h"
inherit "/d/anduar/cantera/sub2/cofradia.c";

void setup()
{
   set_short("%^CYAN%^BOLD%^Real cantera de Anduar: Cofradia de ladrones"
   "%^RESET%^");
   set_long("Estas en unos pasillos reforzados por unas placas de madera en "
   "las cuales aparece tallada una mano abierta, del techo cuelgan unas "
   "sencillas lamparas de aceite, las cuales dan la escasa iluminacion del "
   "lugar, por lo que ves las estructuras dedicadas a extraer la roca han "
   "sido totalmente retiradas.\n");
   add_exit("sur"      ,COFRADIA"pasadizo13.c","road");
   add_exit("este"     ,COFRADIA"pasadizo20.c","road");
   modify_exit("este", ({"function", "entrar"}));
   add_exit("norte"    ,COFRADIA"pasadizo11.c","road");
   set_zone("cofradia");
   crea_bichos();
}

void dest_me()
{
   ::dest_me();
   destruye_bichos();
}

int puerta = 0;
int query_puerta_abierta(){ return puerta;}
void set_puerta(int i) { puerta=i; }

void init(){
    ::init();
    add_action("abrir","abrir");
    add_action("cerrar","cerrar");
}

int puerta(){   return puerta; }
void abrir_puerta() { puerta=1;}
void cerrar_puerta(){ puerta=0;}
int abrir(){
    notify_fail("La puerta ya esta abierta.\n");
    if (puerta) return 0;
    tell_object(TP,"Abres la puerta que te da paso a otra estancia.\n");
    tell_room(environment(TP),"La puerta hacia el norte se abre.\n", TP);
    (NA+"a15.c")->abrir_puerta();
    return (puerta=1);
}
int cerrar(){
    notify_fail("La puerta ya esta cerrada.\n");
    if (!puerta) return 0;
    tell_object(TP,"Cierras la puerta que te da paso a otra estancia.\n");
    tell_room(environment(TP),"La puerta hacia el norte se cierra.\n", TP);
    (NA+"a15.c")->cerrar_puerta();
    return (puerta=0);
}
int entrar()
{
    notify_fail("Hay una puerta y esta cerrada.\n");
    return puerta;
}
