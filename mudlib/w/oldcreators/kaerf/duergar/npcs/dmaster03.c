#include "path.h"
inherit "obj/monster";

void init() {
  ::init();
    add_action("do_listen","escuchar");
    call_out("first_approach",0,this_player());
}

void setup() {
   set_name("caradoc");
   add_alias("duergar");
   add_alias("maestro");
   set_join_fights();
   set_short("Caradoc, Maestro de cavernas");
   set_long("   Caradoc Zarokov es el Maestro de cavernas.  Lleva muchos "
	    "anyos aqui impartiendo sus clases a jovenes alumnos duergar. "
	    "Su mision aqui es ensenyarte sobre los peligros de la "
	    "suboscuridad.\n"
	    "\n");
   set_race("duergar");
   set_guild("fighter");
   set_level(35 + random(10));
   set_thac0(6);
   set_max_hp(600);
   set_max_gp(1000);
   adjust_gp(1000);
   set_heart_beat(1);
   set_gender(1);
   set_al(35);
   set_random_stats(20, 28);
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/armours/chainmail.c")->move(this_object());
   init_equip();
}

int first_approach(object ob) {
   if( (int)ob->query_level() !=3 )
     {
      do_command("say Largo de aqui, no tienes nada que hacer "
		 "en este lugar... y no vuelvas!\n\n");
      return 1;
     }

   if( (int)ob->query_level() ==3 )
     {
      do_command("say Vamos pasa, estaba esperando por ti.\n\n");
      return 1;
     }
}

int do_listen(string STR) {
   int lv;
   object me = this_player();
   lv = (int)me ->query_level();

   if(STR == "caradoc") 
     {
      if(lv == 3) 
	{
	 do_command("say Asi que quieres oir hablar de los tuneles "
		    "de la suboscuridad, no?  Bien ,has venido al "
		    "lugar adecuado.\n"
		    "Humm...espera que me siente... Bien!\n\n"
		    "La suboscuridad, la puedes encontrar en cualquier "
		    "sitio, fuera de las areas civilizadas de Dendall. "
		    "Un lugar en el que la vida es dura.\n\n"
		    "Escucha, nosotros compartimos ese submundo con "
		    "otros seres. Viven en el numerosas criaturas "
		    "peligrosas, que aprovecharan cualquier excusa "
		    "para tratar de matarte.\n\n"
		    "Dicho esto, tras pasar esa puerta al noreste, "
		    "podras ver de cerca algunos de los seres que te "
		    "encontrarias vagando por la suboscuridad. Aunque "
		    "muchos de ellos no estaran en las mismas condiciones "
		    "fisicas que cuando los capture, te daran una idea "
		    "de lo que te puede esperar fuera de Dendall. "
		    "Cosas como Hell Hounds, Hook horrors, Humber hulks "
		    "y esos malditos drow...  "
		    "Pero los drow son materia aparte, ya te tocara "
		    "aprender sobre ellos en su momento, a no mucho "
		    "tardar.\n");
	 if(this_player()->query_guild_name() == "Abbathor") 
	   {
	    if((int)this_player()->query_property("CARGOT")!=1)
	      {
	       this_player()->add_property("CARGOT",1);
	       this_player()->adjust_money(1,"platino");
	       this_player()->adjust_money(5,"oro");
	      }
	   }
	 return 1;
	}
      do_command("say No tengo tiempo que desperdiciar, LARGO!\n");
      return 1;
     }
   return 0;
}
