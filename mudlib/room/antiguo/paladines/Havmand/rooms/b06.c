#include "standard.h"
#include "path.h"
inherit HAVMAND+"beach.c";
object dan;

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsla de Havmand : Playa\n\n"
    "   La pequenya playa termina aqui. Desde aqui ves la inmensidad del mar "
    "extendiendose al norte y oeste. Hay arboles al sur, pero desde donde estas no "
    "hay forma de tomar esa direccion. Este podria ser un buen lugar para un descanso. "
    "\n\n");
    add_item("arboles","Los arboles crecen muy juntos unos de otros y muchas de sus ramas "
    "mas bajas se entrecruzan haciendo muy dificil encontrar la forma de internarse.\n");

}
void init()
{
    add_exit("este",HAVMAND+"b07.c","path");

    add_action("do_raft","hacer");
    add_action("do_raft","construir");
   ::init();
}
void reset()
{
   if(!dan) 
   {
      dan = new(CHARS+"dan.c");
      dan->move(this_object());
   }
   ::reset();
}

int do_raft(string str)
{
   int i;
   object *ob;
   if(!stringp(str)) 
   {
      write("construir que?\n");
      return(1);
   }
   str = lower_case(str);
   if(str != "balsa") return 0;
   if(!dan)
   {
      write("Parece que no hay nadie que pueda ayudarte a construir una balsa.\n");
      return 1;
   }
// 2 casks
   ob = find_match("casks",TP);
   if(sizeof(ob) >2)
    {
        write("Pirata Dan dice: No se puede hacer una balsa sin algo que la haga flotar, unos barriles acoplados podrian servir.\n");
        return 1;
    }
//  vine
    ob = find_match("liana",TP);
    if(!sizeof(ob))
    {
       write("Pirata Dan dice: Necesitamos algo para amarrar los barriles "+CNAME+" no tienes una cuerda o algo parecido?.\n");
       return 1;
    }
// door
    ob = find_match("puerta",TP);
    if(!sizeof(ob))
    {
        write("Pirata Dan dice: Una superficie plana donde poder descansar es importante, busca una tabla.\n");
        return 1;
    }
// baccy
   ob = find_match("tabaco",TP);
   if(!sizeof(ob))
   {
       write("Pirata Dan dice: Necesitaremos repeler a los tiburones, el tabaco de mascar serviria, lo odian.\n");
       return 1;
   }
// level check here
    if(TP->query_level() < 5)
    {
        write("Pirata Dan dice: Lo siento "+CNAME+" no sobrevirias al viaje, y me sentiria culpable "
        "si te murieras. Vuelve cuando tengas mas experiencia.\n");
        return 1;
    }

   write("El viejo Dan te sonrie. Rapidamente amarra los toneles unos con otros y sujeta la hoja de "
   "la puerta a ellos formando una tosca balsa. Tu le ayudas a empujarla hasta el agua y subes a bordo.\n");
   say("El viejo Dan amarra rapidamente una puerta a unos barriles construyendo asi una balsa. "+
   CNAME+" le ayuda a llevar la balsa hasta el agua y se sube a bordo. Le ves alejarse muy contento, aunque "
   "corrieras a subirte no hay bastante sitio para ti.\n");
   if(!find_object(HAVMAND+"raft")) clone_object(HAVMAND+"raft.c");
    TP->move(SHIP+"havmand_belaern");
   TP->look_me();
// clean up
// 2 casks
    ob = find_match("barril",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
//  vine
    ob = find_match("liana",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
// door
    ob = find_match("puerta",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
// baccy
   ob = find_match("tabaco",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
    environment(TP)->do_voyage();
    dan->dest_me();
    return 1;
}
void dest_me()
{
   if(dan) dan->dest_me();
   ::dest_me();
}

