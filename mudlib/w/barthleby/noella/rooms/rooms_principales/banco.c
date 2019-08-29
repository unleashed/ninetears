#include "/w/barthleby/path.h"

inherit "/std/bank";

//inherit "/std/room";

object ban, segurata, placa, *clientela;
int init=0, clientes=0;

/*
// AQUI EMPIEZA EL TEST //
// Modo de Usarla:
//
// object ob -> Jugador que llega al nuevo banco.
// string viejo -> Property del viejo banco (bank + path)
// string nuevo -> Property del nuevo banco (bank + path)
//
// Ejemplo:
//
// Se anyade un enmascaramiento del event_enter().
// Los defines son por comodidad.
//
#define OLD "bank /w/aokromes/nueva.anduar/raise"
#define NEW "bank /d/anduar/anduar/ciudad/banco"
//
int transferir(object ob,string viejo,string nuevo)
{
 int viejac,nuevac;

 viejac=ob->query_property(viejo); // Toma el valor de la cuenta vieja.

 if(viejac)                        // Comprueba que habia algo.
 {
  nuevac=ob->query_property(nuevo); // Toma el valor de la cuenta nueva.
  nuevac=nuevac+viejac;             // Una ambos valores.
  ob->remove_property(viejo);       // Elimina la propiedad vieja.
  ob->add_property(nuevo,nuevac);   // Actualiza la nueva.
 }
 return 1;
}

void event_enter(object guest, string mess, object from)
{
if(interactive(guest)>0)    // Es un jugador, no un npc o un objeto.
transferir(guest,OLD,NEW);
::event_enter(guest,mess,from);
}

// AQUI ACABA EL TEST //
*/
void setup()
{
   set_light(80);
   set_short("%^YELLOW%^Banco de Anduar%^RESET%^");
   set_long("Estas en el banco de Noella. No parece que tenga muchos clientes. "
            "Por su aspecto no parece de los mas importantes. El mostrador es "
            "mas bien pequenyo y no hay mucha gente por aqui. Desde aqui no "
            "ves ninguna caja fuerte, parece que esta escondida en algun lugar "
            "seguro.\n");

add_exit("sudeste", PRINCIPALES+"banco", "path");

   /* add_sign("Pequenya placa.\n",
      "Bienvenido al banco de Anduar.\nPuedes usar los comandos "+
      "\"open\" para crear una cuenta, \"close\" para cerrarla, \"deposit\" "+
      "meter dinero, \"withdraw\" sacar dinero y \"balance\" para ver tu cuenta.  El "+
      "banco tiene un recargo del 95% en el deposito.\n");
   */
   placa=clone_object("std/object");
   placa->set_name("placa");
   placa->set_short("pequenya placa");
   placa->set_long("Es una bonita placa de metal.\n");
   placa->set_read_mess("\n  Bienvenido al banco de Noella.\n\n  Puedes usar"
      "los comandos \"crear\" para crear una cuenta, \"cancelar\" para cerrarla,"
      " \"depositar\" meter dinero, \"sacar\" sacar dinero y \"balance\" "
      "para ver tu cuenta.\n\n  NOTA: El banco aplica una deduccion del 5% en concepto "
      "de tasas, es decir, si depositas 100 monedas te quedaran 95.\n");
   placa->move(this_object());
   placa->reset_get();

   set_percentage(95);
   set_save_file(PRINCIPALES+"banco");
   set_heart_beat(1);
}

void reset()
{
   if(!ban)
   {
       ban=clone_object(NPC+"banquero");
       ban->move(this_object());
   }

   if(!segurata)
   {
       segurata=clone_object(NPC+"segurata");
       segurata->move(this_object());
   }

   if (!init)
   {
      clientela=allocate(11);
      init=1;
   }
}

void dest_me()
{
   int i;

   if (ban)
      ban->dest_me();

   if (segurata)
      segurata->dest_me();

   for (i=0; i<=10; i++)
   {
      if (clientela[i]) clientela->dest_me();
   }

   ::dest_me();
}

// Efecto de la clientela saliendo y entrando al banco
// Gestur 19/6/97. NOTA: Pal que no lo sepa la funcion heart_beat se llama
// cada 2 segundos. Es komo un timer (un poco lento pero bueno...)

void heart_beat()
{
   int i, tipo;

   if (random(20)<4)
   {
      if (random(2))
      {
         if (clientes>0)
         {
            if (clientela[0])
            {
               tell_room(this_object(), clientela[0]->query_cap_name()+
               " se despide del banquero y se va.\n");
               clientela[0]->dest_me();
            }
            for (i=0; i<clientes-1; i++)
            {
               clientela[i]=clientela[i+1];
            }
            clientes--;
         }
      }
      else
      {
         if (clientes<10)
         {
            tipo=random(3);
            switch(tipo)
            {
               case 0: clientela[clientes]=new(NPC+"senyor_gordo.c");
                       clientela[clientes]->move(this_object()); break;
               case 1: clientela[clientes]=new(NPC+"noellita_banco.c");
                       clientela[clientes]->move(this_object()); break;
               case 2: clientela[clientes]=new(NPC+"noble.c");
                       clientela[clientes]->move(this_object()); break;
            }
            tell_room(this_object(), clientela[clientes]->query_cap_name()+
            " ha entrado al banco y se ha puesto a la cola.\n");
            clientes++;
         }
      }
   }
   return 1;
}
