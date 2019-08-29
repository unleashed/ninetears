//Editado por Dagda 12/02
 
inherit "std/OSO";
#include "pub.h"
#include "/d/abarrach/path.h"
 
object barman,globo,tablon;
 
//nombre.tipo.coste.heal.volumen.intox
 
void setup()
{
   add_menu_item("Cerveza", ALCOHOL, 100, 2, 10, 10,"bebes toda la cerveza", "se bebe una jarra de Cerveza");
   add_menu_item("Casera", SOFTDRINK, 125, 2, 7, 0,"bebes una gaseosa, *buurrrrp*", "se bebe una refrescante gaseosa");
   add_menu_item("Zumo de Naranja", SOFTDRINK, 75, 1, 5, 0,"bebes un delicioso vaso de zumo de naranja","se bebe un vasito de zumo");
   add_menu_item("Zumo de Limon", SOFTDRINK, 225, 3, 5, 0,"bebes un acido zumo de limon","se bebe un vasito de zumo");
   add_menu_item("Mejillones flambeados", FOOD, 225, 5, 100, 0,"comes un negro mejillon","se come un mejillon de un mordisco");
   add_menu_item("Pote de Abarrach", FOOD, 1125, 15, 100, 0,"comes un delicioso pote al estilo Abarrach","se come un delicioso pote al estilo Abarrach");
   add_menu_item("Murcielago estofado", FOOD, 1500, 20, 100, 0,"comes un trozo murcielago estofado","se come un trozo de murcielago estofado");
   add_menu_item("Sopa de gorrion", FOOD, 2625, 35, 100, 0,"Tomas una sopa de gorrion, Ummm!",
   "se toma una sopita de gorrion");
   add_menu_item("Pulpo a feira", FOOD, 1125, 15, 100, 0,"comes unas sabroso pulpo a feira",
   "se come una tapa de pulpo a feira");
  
   add_menu_alias("cerveza", "Cerveza");
   add_menu_alias("naranja", "Zumo de Naranja");
   add_menu_alias("limon", "Zumo de Limon");
   add_menu_alias("zumo de naranja", "Zumo de Naranja");
   add_menu_alias("zumo de limon", "Zumo de Limon");
   add_menu_alias("casera", "Casera");
   add_menu_alias("mejillones", "Mejillones flambeados");
   add_menu_alias("pote", "Pote de Abarrach");
   add_menu_alias("murcielago", "Murcielago estofado");
   add_menu_alias("estofado", "Murcielago estofado");
   add_menu_alias("sopa", "Sopa de gorrion");
   add_menu_alias("pulpo", "Pulpo a feira");
   
   set_short("%^GREEN%^Taberna de Abarrach%^RESET%^");
   set_long(" Este es el tipico sitio que vienes porque te lo conto un amigo, es "
   	    "un sitio bastante desordenado, y con apariencia de llevar abierto muchos "
   	    "anyos sin haberse arreglado nunca, sin embargo, los manjares que aqui "
   	    "se ofrece, no se pueden encontrar en ningun otro lugar conocido, "
   	    "la comida de Abarrach, aunque desconocida, es una de las mejores que se "
   	    "puede encontrar en los reinos.\n");
   
   add_exit("out", CIUDAD"ao1007.c");
   add_exit("abajo","/d/oficios/bardos/anduar/animacion.c","hidden");
   modify_exit("abajo",({"function", "entrar"}));
   set_light(50);
   
   add_item("barra",
      " Por esta barra han pasado mas bebidas en un dia que todas "
      " las que has podido beber en tu vida.\n");       
   add_item("cartel","En el cartel pone : \n"
        " Este establecimiento no tiene libro de reclamaciones ,"
        " si lo solicita igual le cortan el cuello " 
        " %^BOLD%^Armandin%^RESET%^.\n");
   add_clone("/d/oficios/bardos/npcs/trobador.c",1);
   set_open_condition("BARMAN");
}
 
int BARMAN()
{
  object *lista;
  int i;
  if (!barman) return 0;
  lista=barman->query_attacker_list();
  for(i=0;i<sizeof(lista);i++)
   if (environment(lista[i])==this_object()) return 0;
  return 1;
}               
   
void reset()
{
  ::reset();
  if (!barman)
  {
    barman=new(NPCGE+"barman.c");
    barman->move(this_object());
  } 
 if(!globo)
 {
   globo=new("/obj/misc/globe");
   globo->move(this_object());
 }
 if(!tablon)
 {
    tablon=new("/obj/misc/board");
    tablon->set_datafile("playerinfo");
    tablon->move(this_object());
 }  
}
 
void dest_me()
{
 if (barman) 
    barman->dest_me();
 if (globo) 
    globo->dest_me();
 if (tablon)
    tablon->dest_me();
 ::dest_me();
}
 
int entrar(string str)
{
if (!TP->query_property("enemigo_bardos"))
        {
        notify_fail("Aun no estas proscrito por bardos... este no es tu sitio??\n");
        return 0;
        }
if (sizeof(TP->query_attacker_list())  >0)
        {
        tell_object(TP,"La adrenalina aun corre por tus venas y no eres capaz de acertar a abrir la puerta.\n");
return 0;
        }
if ((TP->query_property("autorizadoporbardos")) == 1 || (TP->query_guild_ob()=="/std/guilds/rogues/bard"))
{
    if (TP->query_guild_ob()=="/std/guilds/rogues/bard")
  {
    if (TP->query_level()<15)
        {tell_object(TP,"Intentas abrir la trampilla, pero la magia que la proteje aun no te reconoce, espera a ganar mas renombre como bardo.\n");        
        return 0;}
     tell_object(TP,"Colocas tu mano en el pomo de cristal y la trampilla se abre.\n");
  }
  else
  {
       tell_object(TP,"Colocas tu mano en el pomo de cristal y la trampilla se abre.\n");
     }
tell_room(ENV(TP),TP->query_cap_name()+" abre con cuidado una trampilla y baja por ella.\n",TP);
}
else {
notify_fail("Una voz suena en tu mente... Tu no estas autorizado a entrar aqui.\n");
        return 0;}
return 1;
}
