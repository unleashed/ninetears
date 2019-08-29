//Hecho por Paris en Mar'98
//Paris. Resistencias a pinyon y cambio de hechizo. Sept'98

inherit "/obj/monster";
#include "../path.h"

int query_res(string str)
{
	return 35;
}
int query_total_ac(){ return -64; }

void setup()
{
	set_name("Jorbud");
	set_short("Jorbud, Maestro del Circulo Interno");
	set_long("Jorbud es una leyenda dentro del Guild de los Magos Guerreros"
	         ", lo ha conseguido casi todo incluyendo acceder al pretigioso "
	         "Circulo Interno. Es un drow, y como buen drow odia a todo lo "
	         "que no pertenezca a su raza y aun asi hay que tener cuidado "
	         "con el.\n");
	set_living_name("jorbud");
	add_alias("jorbud");
	set_main_plural("Jorbuds, Maetros del Circulo Interno");
	add_plural("jorbuds");
	
	set_race_ob("/std/races/drow.c");
	set_guild_ob("/std/guilds/multi/wizwar");
        
        set_max_gp(1000);
    set_max_hp(3000);
        TO->set_hp(1500);
        TO->set_gp(1000);
        
        set_random_stats(20,25); 
	adjust_money(30,"platinum");
	
        add_clone(ITEMS+"lanza_cel",1);
//	add_clone(ITEMS+"astshld",1);
//	add_clone(ITEMS+"ar_ast",1);
	
        set_level(58+random(7));
        set_al(200);
        set_alignment(200);
        set_gender(1);
        
        load_chat(20,
        ({
                1,":coge su lanza y la mira con desden.\n",
                1,"'Esta lanza me la dio un elfo el dia de su muerte...jajajajajaja.\n",
                1,"'Si le sacais alguna informacion a mi padre Darhazad, la pagare bien.\n",
                1,":te mira con fiereza y confianza. Parece que te este considerando.\n",
                1,"'Aquel que matara a Elkhar se ganaria mi gratitud eterna.\n",
		1,"'Cuando tu poder sea lo suficientemente fuerte podras formar parte del Circulo Interno",
		1,":ensaya algunos pases de un nuevo hechizo",
		1,"'Tu equipo pertenecera a ti cuando lo ganes, pero cuidado, porque seras envidiado",
	}));
	this_object()->init_equip();

	load_a_chat(20,({
		1,"'No tolerare una ofensa de esta magnitud !!",
		1,":hace unos pases magicos\nUna bola de color negro" 
		    " impacta en tu pecho !!\n",
		1,"'Si quieres sangre, la tendras !",
	}));

}
void init()
{
	::init();
	add_attack_spell(21,"relampago",({"/std/spells/wizard/inferno",
		"cast_spell",2}));

/*
          "/std/spells/wizars/stoneskin"->cast_spell(TO->query_name(),TO,0,1);
*/

}
	
/*
void attack_by(object ob)
{
 if(ob->query_timed_property("Combate"))
 {
  tell_object(ob,"Atacando a quien no debes eh??.\n");
  ob->attack_by(TO);
 }
 else
 {
  ob->add_timed_property("Combate",1,200);
  tell_object(ob,"Jajajajaja tenia ganas de pelearme con alguien!!!!."
              "\n No saldras con vida de aqui!!\n");
   ob->attack_by(TO);
 }
}
*/

