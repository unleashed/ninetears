#include "path.h"
inherit "obj/monster";

void init() {
   ::init();
   add_action("do_listen","escuchar");
   call_out("first_approach",0,this_player());
}

void setup() {
   set_name("girthwer");
   add_alias("duergar");
   add_alias("maestro");
   set_join_fights();
   set_main_plural("maestros");
   set_short("girthwer, Maestro de Ciencias");
   set_long("   Girthwer Nolen es el Maestro de la escuela de ciencia. "
	    "  El ensenya a los jovenes duergar en su ultima fase de "
	    "entrenamiento.  Con el aprenderas a distinguir las variadas "
	    "razas que pueblan los reinos y como enfrentarte a ellas.\n"
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
   if((int)ob->query_level() != 4) 
     {
      do_command("say Aun no te has ganado el derecho a entrar aqui, "
		 "vete a otro sitio!\n");
      return 1;
     }

   if((int)ob->query_level() == 4) 
     {
      do_command("say Asi que al fin lo has conseguido?  "
		 "Bien, entra pues.  Pero has de saber "
		 "que es un sitio peligroso al que vas.\n");
      return 1;
     }
}

int do_listen(string STR) {
   int lv;
   object me = this_player();
   lv = (int)me->query_level();
   
   if(STR == "girthwer") 
     {
      if(lv==4) 
	{
	 do_command("say  Esta es tu prueba final antes de poder "
		    "salir a los reinos.  Ahora yo no voy a hacer "
		    "que un infernal sol te queme la nariz, como "
		    "se dice por la academia. Estoy aqui para "
		    "prepararte lo mejor que pueda.\n\n"
		    "Hay gente en el exterior que querra matarte. "
		    "porque?  Algunos diran que por ser mago, o "
		    "un guerrero o alguna otra excusa.  Pero el "
		    "motivo real es que ERES UN  DUERGAR!\n\n"
		    "Y, esa gente puede ser de una vasta variedad "
		    "de razas, Orcos, asquerosos humanos, feos elfos, "
		    "incluso nuestra familia lejana, los malvados "
		    " dwarves.\n\n"
		    "Tras de mi hay una puerta, y tras ella hay unos "
		    "prisioneros que he capturado para tu ultima "
		    "prueba en nuestra academia.  Uno de cada raza "
		    "aunque no estan todas.  Asi que quiero que entres "
		    "y les muestres lo que opinamos de sus apestosas "
		    "formas.  Quiero que entres ahi y les demuestres "
		    "como los duergar pueden salir desede las negras "
		    "profundidades y aplastarlos con nuestros pies.\n");
	 do_command("grin evil");
	 do_command("say A proposito, tengo un regalo para ti.  Es "
		    "una llave, para abrirte el camino.\n");
	    if((random(30) == 21) && (!this_player()->query_property("key")))
	      {
	       clone_object(ITEMS+"qkey5")->move(this_player());
	       this_player()->add_property("key",1);
	      } 
	    else 
	      {
	       if(!this_player()->query_property("key"))
		 {
		  clone_object(ITEMS+"newkey")->move(this_player());
		  this_player()->add_property("key",1);
		 }
	      }
	    return 1;     
	}
      do_command("say Bah!  Dejame, ve a hacer malgastar su "
		 "tiempo a algun otro!\n\n");
      return 1;
     }
   return 0;
}
