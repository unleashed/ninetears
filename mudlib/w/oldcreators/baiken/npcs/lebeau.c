
#include "../path.h"

inherit "obj/monster";

void setup()
{
  set_name("lebeau");
  add_alias("humano");
  set_short("%^BOLD%^%^BLACK%^L%^RESET%^%^MAGENTA%^ebea%^BOLD%^%^BLACK%^u%^RESET%^"); 
  set_long("Tienes ante ti al Protector del Trono del %^BOLD%^%^CYAN%^Viento%^RESET%^ un joven humano de "
	   "mediana estatura. Al mirarle a la cara ves que tiene una melena corta "
	   "a la altura de los hombros, su pelo es liso y de color casta�o, sus "
	   "rasgos son suaves y atractivos por lo que est�s seguro de que entre "
	   "las mujeres seguro que tendr�a �xito. Pero lo que mas te llama la "
	   "atenci�n de su rostro es su mirada. Los ojos de Lebeau son totalmente "
	   "negros excepto la pupila que resalta como una gota de sangre justo en "
	   "el centro, tiene una mirada enigmatica pero a la vez p�cara que no te "
	   "quita de encima, como si te estuviese evaluando antes de empezar a "
	   "jugar contigo. Por la pose de su cuerpo y su gracilidad al moverse con "
	   "unos movimientos suaves pero firmes, bien equilibrados igual que un "
	   "felino, te das cuenta de que seguramente sea tambi�n un poderoso "
	   "contrincante en combate.\n");
set_main_plural("Personas que se parecen a %^BOLD%^%^BLACK%^L%^RESET%^%^MAGENTA%^ebea%^BOLD%^%^BLACK%^u%^RESET%^");
add_alias("lebeau");
add_alias("humano");
set_level(50);
set_guild_ob("/std/guilds/wizards/general_mage.c");
  set_str(20);
  set_dex(20);
  set_con(18);
  set_int(20);
  set_wis(14);
  set_cha(18);
  set_align(10000);
  set_gender(1);
  set_max_hp(750);
  
  set_join_fight_mess("Lebeau sonrie maliciosamentea al unirse al combate con una mirada asesina.\n");
  load_chat(50,
            ({
              1,":se ajusta sus guantes con un sutil movimiento.\n",
              1,"'Mon ami, protegere este trono con mi vida si es necesario.\n",
              1,"'Ni se os ocurra pensar que podeis tocar los libros.\n",
              1,":juguetea con sus cartas mientras te mira fijamente.\n",
	      1,":se frota el menton y sonrie con picard�a.\n",
             }));
  load_a_chat(90,
              ({
	       1,":coje unas cuantas cartas de su baraja y comienza a entonar un hechizo.\n",
               1,"'Mon frere esto es lo que necesitaba, algo de acci�n!!.\n",
               1,"'Je, en serio pensais que podeis vencerme??.. ilusos...\n",
               1,"'Pense que alguien con valor para atacar el trono ser�a mas habil.\n",
             }));
this_object()->add_clone(SOBJ+"tramposo.c",1);
this_object()->add_clone(SOBJ+"guantes_tr.c",1);
this_object()->add_clone(SOBJ+"capucha_tr.c",1);
this_object()->add_clone(SOBJ+"metalicas.c",1);
this_object()->add_clone(JOBJ+"armadura_elf.c",1);
this_object()->add_clone(SOBJ+"capa_tr.c",1);
this_object()->add_clone(SOBJ+"pantalon_c.c",1);
this_object()->add_clone(SOBJ+"baraja.c",1);
  this_object()->init_equip();
   
}

void event_enter(object ob, string msg, object donde)
{
  if (living(ob)) {
    if (ob->query_cap_name() == "Sirio")
   {
   tell_object(ob, "Lebeau te dice: he mantenido el Trono a salvo mi se�or Sirio.\n");
   tell_room(environment(ob), "Lebeau hinca su rodilla en el suelo como reverencia ante el Inmortal Sirio del Viento.\n", this_player());
   }
 else
   {
   tell_room(environment(this_player()), "Lebeau pregunta: Quien osa entrar en estos dominios?.\n");
   }
}   
}

void init()
{
 ::init();   
 
   add_attack_spell(100,"misiles guais",({"/std/spells/wizard/proy_magico_mayor.c","cast_spell",0}));
   add_attack_spell(100,"minimisiles guais",({"/std/spells/wizard/proy_magico_menor.c","cast_spell",0}));
   
}


