// Valar


inherit "/obj/guardian";
#include "/d/keroon/path.h"

void setup() {
	

	set_name("capitan de patrulla");
	set_short("capitan de patrulla");
	set_long(query_short()+"\nEste duergar dirige a un grupo de valerosos guerreros  a traves de estas grutas "
        "en busca de algun enemigo. Es bastante mas fuerte que los demas duergars que van con el.\n");
	
	set_main_plural("capitanes de patrulla");
	
	add_alias("duergar");
	add_alias("capitan");
	add_plural("duergars");
	add_plural("capitanes");
	
	set_gender(1);
	set_guild_ob("/rol/gremios/khurgar.c");	
        set_ciudadania("Keroon");
	
        set_level(20+random(10));
	
        add_move_zone("camkeroon");
        set_move_after(8,10);
	set_random_stats(18, 20);
	set_race("duergar");
	set_wimpy(0);
	
	set_max_hp(query_level() * 50);
      	set_hp(query_max_hp());
      	set_max_gp(query_level() * 60);
      	set_gp(query_max_gp());
	set_max_ep(query_level() * 20);
      	set_gp(query_max_ep());
	
	add_clone(ITEMSCAMINO+"hacha_guardia.c",2);
        add_clone(ITEMSCAMINO+"armadura_capitan.c",1);
        add_clone(ITEMSCAMINO+"yelmo_patrulla.c",1);
        add_clone(ITEMSCAMINO+"capa_capitan.c",1);
        add_clone(ITEMSCAMINO+"brazalete_guardia.c",1);
        init_equip();
	
	load_chat(50,({
	       1, "'Es aburrido patrullar todo el dia, pero alguien tiene que hacerlo.",
               1, ":observa el corredor buscando algo.",
               1, ":pasa su lengua por el filo de su arma.",
               1, "'No has venido a buscar problemas, verdad?.",
          	}));
      		
	init_equip();
	
	set_heart_beat(1);
	
	adjust_money(5,"oro");
	set_move_after(8,10);
        add_move_zone("camkeroon");	
        
	}

void hacer_palurdos()
{
	int i;
	
	tell_room(environment(TO),TO->query_name()+" llama a sus "
	          "subordinados para empezar la ronda.\n");
	for(i=0;i<3;i++)
	{
		object ob;
			
		ob=clone_object(NPCSCAMINO+"guardia_patrulla.c");
		ob->move(environment(TO));
		ob->do_command("seguir capitan");
		ob->do_command("protect capitan");
	}
	
        return;
}
		
void heart_beat()
{
int contador=0;
	if (contador == 4)
	{  
	  hacer_palurdos();
	  contador = 5;	
	}
	else if(contador > 4)
		contador = 5;
	      else
	  	contador++;
	::heart_beat();
	
        return;
}


