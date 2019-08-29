/*  Text alterations and additions by Grimbrand 2-11-96                 */

#include "path.h"
inherit "obj/monster";
object *obs;

void init() {
  ::init();
    call_out("first_approach",0,this_player());
    add_action("do_listen","escuchar");
}

void setup() {
   set_name("duggan");
   add_alias("maestro");
   add_alias("duergar");
   set_join_fights();
   set_main_plural("maestros");
   set_short("duggan, Maestro de Aprendices");
   set_long("  \n"
            "   Duggan Bloodaxe es el Maestro de Aprendices"
            " en Dendall.  Los jovenes duergar vienen a el "
            "para informarse en como adquirir experiencia."
            "\n\n");
   set_race("duergar");
   set_guild("fighter");
   set_join_fight_mess("Los ojos de Duggan brillan con anticipacion."
                       " Sin mediar palabra, ataca!\n");
   set_level(55 + random(10));
   set_thac0(-4);
   set_max_hp(1500);
   set_max_gp(1000);
   adjust_gp(1000);
   set_heart_beat(1);
   set_gender(1);
   set_al(0);
   set_random_stats(20, 28);
        
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/armours/chainmail.c")->move(this_object());
   init_equip();
}

int first_approach(object ob) {
   if( (int)ob->query_level() <=1 )
     {
      do_command("say Deberas visitar la Oficina del Maestro Minero. "
                 "El te entrenara para tu primer nivel aqui, en la  "
                 "academia de Dendall."
                 "\n\n");
      return 1;
     }

   if( (int)ob->query_level() ==2 )
     {
      do_command("say Ve a la Oficina de Exploraciones de superficie, "
                 "alli el Maestro te mostrara las distintas criaturas "
                 "de la superficie.  pocos duergar se quedan con ganas "
                 "de volver despues de su visita a ese sitio."
                 "\n\n");
      return 1;
     }

   if( (int)ob->query_level() ==3 )
     {
      do_command("say Bien, ve ahora a la oficina del Maestro de la "
                 "Caverna. El te mostrara las diferentes razas que "
                 "habitan la suboscuridad.  Esta sera tu tercera fase "
                 "de entrenamiento en la academia.\n");
      return 1;
     }

   if( (int)ob->query_level() ==4 )
     {
      do_command("say Veo que has llegado a la fase final de aprendizaje "
                 "en la academia. Visita la oficina del Maestro de Ciencias, "
                 "alli seras instruido sobre las variadas razas que has "
                 "de encontrar en tus aventuras por el exterior. Suerte."
                 "\n\n");
      return 1;
     }

   if((int)ob->query_level() >=5) 
     {
      do_command("say Debes irte ya. Tu ya no tienes nada que hacer aqui. "
                 "Asi que adios, no me obligues a hecharte."
                 "\n\n");
      return 1;
     }
}

int do_listen(string STR) {
   if(STR == "duggan") 
     {
      do_command("say Grimbrand nos ampare!  Otro jovencito de sangre "
                 "ardiente que quiere entrar a la academia, no?\n\n"
                 "Puedes entender la eleccion que estas haciendo?  Al "
                 "entrar a esta escuela, estas ofreciendo toda tu  "
                 "devocion a Grimbrand, Dios de los  Duergar.\n\n"
                 "Sabes acaso, que tal vez no acabes el curso de una "
                 "pieza?  He visto muchos jovenes duergar llegar aqui, "
                 "confiados como tu, para acabar muertos o lisiados "
                 "de por vida.  Las pruebas aqui estan disenyadas para "
                 "seleccionar solo a los mejores,y son ejercicios "
		 "reales, asi que ten cuidado!\n\n"
                 "Si crees que realmente estas preparado para esta "
                 "tarea, entonces que Grimbrand este contigo!  Vas "
                 "a necesitar su ayuda para acabar con vida los test."
                 "\n\n");
//      do_command("cackle");     ***pendiente traducir los souls***
      return 1;
     }
return 0;
}
