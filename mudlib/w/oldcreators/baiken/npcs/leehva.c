//Hecho por Paris en Mar'98
//Paris. Resistencias a pinyon y cambio de hechizo. Sept'98

inherit "/obj/monster";
#include "../path.h"

int query_res(string str)
{
	return 25;
}
int query_total_ac(){ return -24; }

void setup()
{
	set_name("Leehva");
	set_short("Leehva, Miembro distinguido del Circulo Interno");
	set_long("Leehva, el primer elfo que pudo entrar en este gremio."
	         " Fue el precursor de los Magoguerreros elfos y como tal "
	         "fue, es y seguira siendo respetado en el gremio. Hoy por hoy "
	         "se encarga de vigilar la sala de reuniones del Circulo. Darhazad "
	         "lo odia, pero el lo odia aun mas a darhazad por su condicion"
		 " de necesario.\n");
	set_living_name("leehva");
	add_alias("leehva");
	set_main_plural("Leehvas, Miembros del Circulo Interno");
	add_plural("leehvas");
	
	set_race_ob("/std/races/elf.c");
	set_guild_ob("/std/guilds/multi/wizwar");
        set_random_stats(20,25); 
	adjust_money(30,"platinum");
	
        add_clone(ITEMS+"esp_astral",1);
//	add_clone(ITEMS+"astshld",1);
//	add_clone(ITEMS+"ar_ast",1);
	
        set_level(58+random(7));
    
        set_max_gp(800);
        set_max_hp(800);
        TO->set_hp(800);
        TO->set_gp(800);
    
        set_al(200);
        set_alignment(200);
        set_gender(1);
        
        load_chat(40,
        ({
                1,":coge su espada y traza un circulo en el aire.\n",
		1,"'Ser miembro del Circulo es un orgullo.\n",
		1,":ensaya algunos pases de un nuevo hechizo",
	}));
	this_object()->init_equip();

	load_a_chat(60,({
		1,"'No tolerare una ofensa de esta magnitud !!",
		1,":hace unos giros con la espada\nUn rayo de agua sale de la espada" 
		    " hacia ti, impactandote con gran estruendo !!\n",
		1,"'Si quieres sangre, la tendras !",
	}));

}
void init()
{
	::init();
	add_attack_spell(21,"relampago",({"/std/spells/wizard/inferno",
		"cast_spell",2}));

/*
        "/std/spells/wizard/stoneskin"->cast_spell(TO->query_name(),TO,0,1);
*/


}
	
/*
void attack_by(object ob)
{
 if((ob->query_timed_property("Combate")||(ob->query_timed_property("Combate2"))))
 {
  tell_object(ob,"Atacando a quien no debes eh??.\n");
 }
 else
 {
  ob->add_timed_property("Combate",1,200);
  tell_object(ob,"Pagaras cara esta afrenta!!!!."
              "\n No saldras con vida de aqui!!\n");
 }
}
*/

