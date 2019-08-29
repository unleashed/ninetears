#include "../path.h";


inherit "/std/bank";

object ban, segurata, placa, *clientela;
int init=0, clientes=0;

void setup() 
  {
   set_light(80);
   set_short("Banco de Zhyrkh");
   set_long("You are in Daggerford Bank. The bank is filled with friendly "+
      "looking people, standing behind a polished bench, eagerly awaiting "+ 
      "the pleasure of serving you. There is a sign hanging on the "+
      "wall.\n");
   
   add_exit("sur", CAMSUR+"cam65", "door");
   set_percentage(95);
   set_save_file(ZHYRKH + "banco");
   set_heart_beat(1);





}

void reset()
{
   if(!ban)
   {
       ban=clone_object(NPCS+"banquero");
       ban->move(this_object());
   }

   if(!segurata)
   {
       segurata=clone_object(NPCS+"segurata");
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
               case 0: clientela[clientes]=new(NPCS+"senyor_gordo.c");
                       clientela[clientes]->move(this_object()); break;
               case 1: clientela[clientes]=new(NPCS+"granjero.c");
                       clientela[clientes]->move(this_object()); break;
               case 2: clientela[clientes]=new(NPCS+"noble.c");
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
