#include "path.h";

inherit "/std/bank";

object ban, segurata, placa;

void setup() 
{
   set_light(80);
   set_short("%^YELLOW%^Banco del grupo comercial Comellas%^RESET%^");
   set_long("Estas en el banco de Anduar. No parece que tenga muchos "
            "clientes. Por su aspecto no parece de los mas importantes. El "
            "mostrador es mas bien pequenyo y no hay mucha gente por aqui. "
            "Desde aqui no ves ninguna caja fuerte, parece que esta escondida "
            "en algun lugar seguro.\n");

   add_exit("noreste",CARRETERA"pos_5.c","door");

   placa=clone_object("std/object");
   placa->set_name("placa");
   placa->set_short("pequenya placa");
   placa->set_long("Es una bonita placa de metal.\n");
   placa->set_read_mess("\n  Bienvenido al banco de Anduar.\n\n  Puedes usar"
   "los comandos \"crear\" para crear una cuenta, \"cancelar\" para cerrarla," 
   " \"depositar\" meter dinero, \"sacar\" sacar dinero y \"balance\" "
   "para ver tu cuenta.\n\n  NOTA: El banco aplica una deduccion del 5% en "
   "concepto de tasas, es decir, si depositas 100 monedas te quedaran 95.\n");
   placa->move(this_object());
   placa->reset_get();   
   
   set_percentage(95);
   set_save_file(CARRETERA + "banco");
   set_heart_beat(1);
}

void reset()
{
   if(!ban)
   {
        ban=clone_object(CARRETERA"npcs/banquero");
       ban->move(this_object());
   }

   if(!segurata)
   {
        segurata=clone_object(CARRETERA"npcs/segurata");
       segurata->move(this_object());
   }
}

void dest_me()
{
   int i;
   
   if (ban)
      ban->dest_me();
   
   if (segurata)
      segurata->dest_me();
   ::dest_me();
}

