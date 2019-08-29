#include "/w/barthleby/path.h"

inherit "/std/room";


object placa, quien, tendero;

void setup()
{
   set_short("%^BOLD%^%^GREEN%^Florister�a de Eun Hae%^RESET%^");
     set_long("%^BOLD%^%^GREEN%^Florister�a de Eun Hae%^RESET%^\n\n"+
      "Has entrado en un lugar impregnado del agradable olor de las flores con las que trabajan. " +
      "Tal vez sea �ste un buen momento para comprarle un ramo a tu pareja o para alg�n " +
      "funeral.\n\n");
   
   placa=clone_object("std/object");
   placa->set_name("placa");
   placa->set_short("pequenya placa");
   placa->set_long("Es una bonita placa de metal.\n");
   placa->set_read_mess("\n  Bienvenido a la Floristeria de Eun Hae.\n\n"
   "Si desea mandar unas flores con una tarjeta escrita por usted solo debe "
   "comprar un ramo para un jugador dado. Solo se le efectuar� la entrega "
   "cuando este jugador est� en el mundo de Ninetears. El coste por "
   "entrega es de 2 monedas de platino por ramo (independientemente del tipo "
   "de flores).\n\n\tComando: comprar ramo para <jugador>\n");
   placa->move(this_object());
   placa->reset_get();
   set_light(65);
   exit_color="%^MAGENTA%^";
add_exit("fuera", MURALLAS_NOELLA+"muralla43","road");
}

void init()
{
   ::init();
   add_action("comprar", "comprar");
   add_action("comprar", "buy");
}

void reset()
{
   if(!tendero)
   {
      tendero=new(NPC+"florista.c");
      tendero->move(this_object());
   }
   ::reset();
}

void dest_me()
{
   if(tendero) tendero->dest_me();
   ::dest_me();
}

void comprar(string str)
{
  int numero;
  int coste= 1000;
  string *lista;
  object flor;

  if(!tendero)
  {
     notify_fail("No se encuentra nadie aqui para atenderte.\n");
     return 0;
  }
  
  if(!str)
  {
     notify_fail("Comprar ramo para <jugador>.\n");
     return 0;
  }
  lista = explode(str," ");
  numero = member_array("para" ,lista);
  if(numero > 0)
  {
      if(((lista[0] != "flor") && (lista[0] != "ramo")) || (sizeof(lista) <= 2))
      {
        notify_fail("Comprar que para quien?.\n");
        return 0;
      }
      
      quien = find_living(lista[numero+1]);
      if(!quien || quien->query_invis() >0)
      {
         notify_fail(capitalize(lista[numero+1])+" no est� conectada en este momento.\n");
         return 0;
      }
      else
      {
         if(lista[numero+1] == this_player()->query_name())
         {
             notify_fail("No crees que te pasas un poco mandandote flores a ti mismo?.\n");
             return 0;
         }
         coste=1000;  /* 2 monedas de platino */
 	 if(coste > (int) this_player()->query_value())
 	 {
   	    tell_object(this_player(),"Eres demasiado pobre para comprar un ramo de flores.\n");
   	    return 1;
         }
 	 else
           this_player()->pay_money(({"copper", coste}));

         tell_object(this_player(),"Eun Hae elige un ramo de flores y te lo da.\n");
      	 tell_object(this_player(),"Eun Hae dice: Escribe el mesaje que aparecera en la "
      	 "tarjeta, junto a las flores.\nTexto:\n");
         input_to("mail" ,0);
         return 1;
      }
   }
   else
     return 0;
}

void mail(string str)
{
 int i;
 object flor;
 string tipo;

 flor=new(ITEMS+"ramo.c");
 i = random(2);
 switch(i)
 {
     case 0:
         tipo = "rosas rojas";
         break;
     case 1:
         tipo = "rosas blancas";
         break;
     case 2:
         tipo = "rosas rosas";
         break;
     case 3:
         tipo = "tulipanes";
         break;
     case 4:
         tipo = "petunias";
         break;
     case 5:
         tipo = "margaritas";
         break;
 }
 
 if(str == "")
 {
     flor->set_long("Se trata de un precioso y magn�fico ramo de "+tipo+" enviado por "+
     this_player()->query_cap_name()+".\n");
 }
 else
 {
     flor->set_long("Se trata de un precioso y magn�fico ramo de "+tipo+" enviado por "+
     this_player()->query_cap_name()+". En ellas hay una tarjeta en la que "
     "puedes leer:\n\n"+str+"\n\t\t\t\t\tFlorister�a de Eun Hae (Noella).\n");
 }

 tell_room(environment(this_player()), this_player()->query_cap_name()+"Env�a "
 "un ramo de flores a "+quien->query_cap_name()+".\n", this_player());
 tell_object(this_player(),"Env�as un ramo de flores a "+quien->query_cap_name()+".\n");
 flor->move(quien);
 tell_object(quien, "Aparece frente a t� un repartidor oficial de la Florister�a de "
 "Eun Hae.\nEl repartidor dice: Tengo un encargo para usted de parte de "+this_player()->query_cap_name()+".\n"
 "Repartidor te da un Ramo de Flores.\nEl repartidor desaparece rapidamente.\n");
 tell_room(environment(quien),"Un repartidor oficial de la Floristeria de Eun Hae le da "
 "a "+quien->query_cap_name()+" un Ramo de Flores, y desaparece velozmente.\n", quien);

 return;
}
