//Editado por Oneex 2-10-97

inherit "std/OSO";
#include "pub.h"
#include "../path.h"

object barman,globo,tablon;

//nombre.tipo.coste.heal.volumen.intox

void setup()
{
   add_menu_item("Cerveza", ALCOHOL, 100, 2, 10, 10,
      "bebes toda la cerveza", "se bebe una jarra de Cerveza");
   add_menu_item("Casera", SOFTDRINK, 125, 2, 7, 0,
      "bebes una gaseosa, *buurrrrp*", "se bebe una refrescante gaseosa");
   add_menu_item("Zumo de Naranja", SOFTDRINK, 75, 1, 5, 0,
     "bebes un delicioso vaso de zumo de naranja","se bebe un vasito de zumo");
   add_menu_item("Zumo de Limon", SOFTDRINK, 225, 3, 5, 0,
     "bebes un acido zumo de limon","se bebe un vasito de zumo");
   add_menu_item("Asado de Rata", FOOD, 225, 5, 100, 0,
  "comes una insipida rata asada","se come una rata de un bocado");
   add_menu_item("Asado de Pollo", FOOD, 1125, 15, 100, 0,
  "comes un delicioso pollo asado","se come un muslo de pollo");
   add_menu_item("Asado de Ciervo", FOOD, 1500, 20, 100, 0,
  "comes un trozo asado de ciervo","se come un trozo asado de ciervo");
   add_menu_item("Asado de Jabali", FOOD, 2625, 35, 100, 0,
   "comes una sabrosa pata de jabali asada, Ummm!",
   "se come las costillas asadas de jabali");
   add_menu_item("Varitas de Pescado", FOOD, 1125, 15, 100, 0,
   "comes unas crujientes varitas de pescado",
   "se come un plato de varitas de pescado");
  
   add_menu_alias("cerveza", "Cerveza");
   add_menu_alias("naranja", "Zumo de Naranja");
   add_menu_alias("limon", "Zumo de Limon");
   add_menu_alias("zumo de naranja", "Zumo de Naranja");
   add_menu_alias("zumo de limon", "Zumo de Limon");
   add_menu_alias("casera", "Casera");
   add_menu_alias("asado de pollo", "Asado de Pollo");
   add_menu_alias("pollo", "Asado de Pollo");
   add_menu_alias("asado de jabali", "Asado de Jabali");
   add_menu_alias("jabali", "Asado de Jabali");
   add_menu_alias("asado de ciervo", "Asado de Ciervo");
   add_menu_alias("ciervo", "Asado de Ciervo");
   add_menu_alias("asado de rata", "Asado de Rata");
   add_menu_alias("rata", "Asado de Rata");
   add_menu_alias("varitas", "Varitas de Pescado");
   add_menu_alias("pescado", "Varitas de Pescado");
   
   set_short("%^GREEN%^Taberna de Anduar%^RESET%^");
   set_long(" Has entrado en la taberna mas afamada de todo Anduar."
            " Sientes el inconfundible aroma de la comida asada que reina por"
            " todo el local. Rapidamente te fijas en la barra del bar y"
            " localizas el menu de la casa. Este bar tiene un cocinero"
            " especialista en asados, si quieres comer en abundancia has"
            " venido al lugar perfecto. Acaba de instalarse un horno donde "
            "por un precio modico puede asarte trozos de carne.\n");
   
   add_exit("out", ANDUAR"ao1007.c");
   add_exit("abajo","/d/oficios/bardos/anduar/animacion.c","hidden");
   modify_exit("abajo",({"function", "entrar"}));

   set_light(60);
   
   add_item("barra",
      " Por esta barra han pasado mas bebidas en un dia que todas "
      " las que has podido beber en tu vida.\n");       
   add_item("cartel","En el cartel pone : \n"
        " Este establecimiento no tiene libro de reclamaciones ,"
        " si lo solicita no lo tendra a su disposicion " 
        " %^BOLD%^Koskar%^RESET%^.\n");
   add_clone(ANDUAR+"npcs/ciudadano", 2);
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
    barman=new(NPC+"barman.c");
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


void init()
{
  ::init();
 add_action("do_dar","entregar");
// add_action("borracho","comprar");
}

void koskar_vuelve(object ob)
{
  object carne;
  
  barman = clone_object(NPC"barman");
  carne = clone_object("/d/anduar/anduar/quest/asado");
  tell_room(TO,"Koskar vuelve del Horno de la Taberna llevando un pedazo de "
               "carne asada en las manos.\n");
  barman->move(TO);
  carne->move(ob);
  tell_room(TO,"Koskar da un pedazo de buey asado a "+ob->query_short()+".\n");
}
  
  
int do_dar(string str)
{
  object carne;
  
  if(!str) return 0;
  if(!barman) return 0;
  if(str == "carne a koskar")
  {
     if(TP->query_value()<5)
    {
      notify_fail("Koskar te dice: No tienes bastante dinero par pagarme el "
      "servicio.\n");
      return 0;
    }
    if(!carne=present("trozo de carne",TP)) 
    {
      notify_fail("Koskar te dice: No es un trozo de carne... no lo puedo "
      "asar.\n");
      return 0;
    }
    tell_room(TO,"Koskar acepta un pedazo de carne que le tiende "+
    TP->query_cap_name()+" y se marcha al horno de la Taberna para "
    "cocinarlo.\n",TP);
    tell_object(TP,"Koskar acepta el trozo de carne que le tiendes y se va "
                   "al horno de la taberna a cocinarlo.\n");
    barman->dest_me();
    carne->dest_me();
    TP->pay_money(({"platinum",5}));
    call_out("koskar_vuelve",5,TP);
  }
  return 1;
}
int borracho(string str)
{
  object cerveza;
  
if(str == "cerveza")
  {
tell_room(TO,"Koskar le sirve una cerveza a "+TP->query_cap_name()+
" y limpia la barra.\n",TP);
    tell_object(TP,"Koskar te sirve una cerveza.\n");
   cerveza = clone_object("/d/anduar/objetos/cerveza.c");
cerveza->move(TO);
  }
  return 1;
}

int entrar(string str)
{
if (TP->query_property("enemigo_bardos"))
        {
        notify_fail("Eres un proscrito para los bardos... como piensas entrar ahi??\n");
        return 0;
        }

if (sizeof(TP->query_attacker_list())  >0)
        {
        tell_object(TP,"El fragor de tus luchas recientes te impiden mantener el estado mental adecuado para entrar ahi.\n");
        return 1;
        }


if ((TP->query_property("autorizadoporbardos")) || (TP->query_guild_ob()=="/std/guilds/rogues/bard"))
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
// TP->move("/d/oficios/bardos/anduar/animacion.c");
// tell_room(ENV(TP),TP->query_cap_name()+" llega de arriba.\n",TP);
// TP->look_me();
}
else {
notify_fail("Una voz suena en tu mente... Tu no estas autorizado a entrar aqui.\n");
        return 0;}
return 1;
}


