#define WEATHER  "/obj/handlers/weather.c"
#include "path.h"

#include "senda.h"

inherit "/std/outside";

int open;

void setup()
{
   set_long("Te hallas en una senda que hay en las colinas de "+COLINAS+"."
   " La montanya no es excesivamente alta, pero su pendiente "
   "es bastante pronunciada. Abajo al norte continua la senda y al horizonte "
   "se ve una gran fortaleza. Parece que este camino lleva hacia alli. "
   "Por lo que parece esta senda es de uso comun, ya que el terreno sobre "
   "el cual anda la gente esta totalmente falto de vegetacion.\n");
   add_exit("sudoeste", SENDA+"s54", "plain");
   add_exit("abajo", SENDA+"s56", "plain");
   TRAMO4->comun(TO);
   TRAMO4->npcs(2, TO);
   open=0;
   WEATHER->notify_me(TO);
   call_out("event_weather",0);
}

void event_weather()
{
   mixed cosa=WEATHER->query_type_rain(TO);

        if(!open)
        {
          if(cosa[0]==1 && WEATHER->query_moon()==0 && !WEATHER->query_day(TO))
          {
             open=1;
             add_exit("este",SENDA+"cuevaluna","hidden");
             set_long("Te hallas en una senda que hay en las colinas de "+COLINAS+"."
                " La montanya no es excesivamente alta, pero su pendiente "
                "es bastante pronunciada. Abajo al norte continua la senda y al horizonte "
                "se ve una gran fortaleza. En la pared este de la montanya, debido a la lluvia "
                "que ha limpiado de barro la roca, se ve una piedra algo suelta con "
                "una luna llena brillando sobre ella.\n");
             renew_exits();
          }
        }
        if(open && (cosa[0]!=1 || WEATHER->query_moon()!=0 || WEATHER->query_day(TO)))
        {  
             open=0;
             remove_exit("este");
             set_long("Te hallas en una senda que hay en las colinas de "+COLINAS+"."
                " La montanya no es excesivamente alta, pero su pendiente "
                "es bastante pronunciada. Abajo al norte continua la senda y al horizonte "
                "se ve una gran fortaleza. Parece que este camino lleva hacia alli. "
                "Por lo que parece esta senda es de uso comun, ya que el terreno sobre "
                "el cual anda la gente esta totalmente falto de vegetacion.\n");
             renew_exits();
         }
}
