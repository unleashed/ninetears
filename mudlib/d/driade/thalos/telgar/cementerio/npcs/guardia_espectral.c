// Made by Thalos  22/03/02
// Guardia espectral

#include "../../path.h"
inherit "/obj/monster";
object ob1,ob2,ob3;
int i;
void setup() {
      set_name("Guardia espectral");
      set_short("Guardia espectral");
      set_al(100);
      set_main_plural("Guardias espectrales");
	add_plural("guardias");
	add_plural("duergars");
	add_alias("espectral");
        add_alias("guardia");
        add_alias("duergar");
	add_alias("espectrales");
	add_alias("guardias");
	add_alias("duergars");
      set_race("undead");
      //set_race_ob("/std/races/duergar");
      //set_race("undead");
	set_gender(1);
      set_level(20+random(10));
	set_thac0(0);
	set_ac(-100);
      set_wimpy(0);
	set_max_hp(500);
      set_hp(500);
      set_max_gp(300);
      set_gp(300);
      set_random_stats(17, 19);
      set_long("Guardia espectral.\n\n"
		"Antanyo era un poderoso guerrero, que se ha visto obligado a volver a la vida por una fuerza maligna");
      set_aggressive(1);
       
	ob1=clone_object(ITEMSCEMENTERIO+"hacha_espectral");
	ob1->move(TP);
       	ob2=clone_object(ITEMSCEMENTERIO+"armadura_espectral.c");
	ob2->move(TP);
	ob3=clone_object(ITEMSCEMENTERIO+"yelmo_espectral.c");	
	ob3->move(TP);
	init_equip();
      add_move_zone("cementerio");
      set_move_after(20+random(10), 20+random(10));
}

void do_death(object ob)
{
 ob1->dest_me();
 ob2->dest_me();
 ob3->dest_me();
return ::do_death(ob);
}