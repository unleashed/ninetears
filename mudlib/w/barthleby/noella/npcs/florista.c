// Editado por Lummen 9.2.98

#include "/w/barthleby/path.h"
inherit "/obj/monster";

void event_enter(object ob, string mensaje, object donde)
{
   string sexo, fem;
   
   if ((int)ob->query_timed_property("guardias_noella"))
   {
      if (ob->query_dead())
         do_command("'Nunca te deber�as haber enfrentado a la furia del Consejo de Noella.");
      else
         do_command("'Ahora ser�s perseguido por toda Noella, para hacerte pagar tu osad�a.");
   }
   else
   {
     if (!ob->query_dead())
     {
       if(ob->query_gender() == 2)
       {
          sexo = "se�ora";
          fem = "a";
       }
       else
       {
          sexo = "maese";
          fem = "o";
       }
       do_command("'Bienvenid"+fem+" a mi Floriester�a "+sexo+" "+ob->query_cap_name()+".");
     }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/

void setup()
{
      set_name("eun");
      set_short("Eun Hae");
      set_main_plural("floristas");
      set_long("La peque�a Eun Hae es una hermosa y h�bil vendedora. Podr�a vender "
      "cualquier cosa a quien fuera. Su aspecto fragil y su sempiterna sonrisa "
      "le permiten crear un ambiente cordial entre sus clientes.\n");
      add_alias("eun hae");
      add_alias("eun");
      add_alias("Eun");
      load_chat(50,
         ({
               1, ":te saluda cordialmente.",
               1, "'Yo solo vendo calidad, calidad al mejor precio.",
               1, "'Puedo ver en tus ojos que no has venido unicamente a mirar.",
               1, ":Te regala una amplia sonrisa.",
               1, ":coloca las cosas en su sitio.",
          }));
      set_race("human");
      set_level(random(2)+7);
      set_gender(1);
      set_random_stats(6, 15);
      adjust_money(5+random(6), "gold");
      new(ARMA+"daga")->move(this_object());
      init_equip();
}

