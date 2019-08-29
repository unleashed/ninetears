inherit "/std/room";
#include "../path.h"

object borracho;

void setup()
{
   
   set_short("Casa en el arbol");
   set_long("Tras seguir subiendo el arbol descubres que el inmenso arbol "
   "sube hasta gran altura la suficiente para poder ver ramas que se "
   "pasan por encima de todas las casas de la ciudad, uniendose con otros "
   "arboles de la misma, proporcionando sombra a muchas zonas de la ciudad "
   "y dando proteccion a muchos animales en ellas.\n");
   add_exit("abajo"   ,ANDUAR"casa.c","road");
   
   set_light(60);
}

int BORRACHO()
{
  object *lista;
  int i;
  if (!borracho) return 0;

  lista=borracho->query_attacker_list();
  for(i=0;i<sizeof(lista);i++)
   if (environment(lista[i])==this_object()) return 0;
  return 1;
}               
   
 void reset()
{
  ::reset();
  if (!borracho)
  {
    borracho=new("/d/anduar/anduar/ciudad/npcs/borracho.c");
    borracho->move(this_object());
  } 
}

void dest_me()
{
 if (borracho) 
    borracho->dest_me();
}


void init()
{
  ::init();
  add_action("do_dar","dar");
}

void borracho_habla(object ob)
{
  write("Hace muchos muchisimos anyos, tantos que solo los mas viejos "
  "recuerdan, un viejo clerigo de Gestur renego de su dios pasando a adorar "
  "a su mayor enemigo, Oskuro el dios le prometio grandes poderes, a cambio "
  "de la destruccion de la ciudad de Anduar, entonces un gran ejercito se "
  "creo, destinado a destruir el lugar donde habitaba el clerigo, tras muchos "
  "esfuerzos el ejercito logro encerrar al clerigo en su fortaleza "
  "derrumbando su entrada, pero con la construccion del Real camino, el mal "
  "fue desenterrado, convertido en un NoMuerto, de un poder y odio infinito "
  "que solo piensa en cumplir su promesa.\n");
  tell_room(TO,"El borracho acaba de contar su historia a "+ob->query_short()+".\n");
}
  
  
int do_dar(string str)
{
  object cerveza;
  
  if(!str) return 0;
  if(!borracho) return 0;
  if(str == "cerveza a borracho")
  {
    if(!cerveza=find_match("cerveza",TP)) 
    {
      notify_fail("El borracho te dice una cerveza o no hay trato.\n");
      return 0;
    }
    tell_room(TO,"El borracho acepta la cerveza que le tiende "+
    TP->query_cap_name()+" y le susurra algo al oido.\n",TP);
    tell_object(TP,"El borracho acepta la cerveza y empieza a contarte la "
                   "historia.\n");
    cerveza->dest_me();
    call_out("borracho_habla",5,TP);
  }
  return 1;
}
