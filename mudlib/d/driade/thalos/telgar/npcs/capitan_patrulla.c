// Thalos

#include "duergar.c"
#include "../path.h"
int contador=0;

void setup()
{
    set_name("Capitan de Patrulla");
    set_short("capitan");
    add_alias("duergar");
    set_long("Este duergar dirige a un grupo de valerosos guerreros  a traves de estas grutas "
            "en busca de algun enemigo. Es bastante mas fuerte que los demas duergars que van con el.\n");
    add_adjective("de Patrulla");
    set_main_plural("Capitanes de Patrulla");
    add_plural("capitanes");
    add_plural("duergars");
    add_alias("capitan");    
    set_race_ob("/std/races/duergar.c"); 
    set_gender(1); 
    set_guild_ob("/d/gremios/guerreros/battleduergar");

    set_random_stats(12,16);
    set_str(28);
    set_con(17);
    set_dex(17);
    
    adjust_money(10,"oro");
    
    set_level(20+random(10));
    add_move_zone("camkeroon");
    set_move_after(8,10);
    add_clone("/d/driade/thalos/telgar/npcs/equipo/hacha_guardia.c",2);
    add_clone("/d/driade/thalos/telgar/npcs/equipo/armadura_capitan.c",1);
    add_clone("/d/driade/thalos/telgar/npcs/equipo/yelmo_patrulla.c",1);
    add_clone("/d/driade/thalos/telgar/npcs/equipo/capa_capitan.c",1);
    add_clone("/d/driade/thalos/telgar/npcs/equipo/brazalete_guardia.c",1);
    init_equip();
    set_al(779);
    set_alignment(779);
    
    set_heart_beat(1);
    
    load_chat(50,
         ({
               1, "'Es aburrido patrullar todo el dia, pero alguien tiene que hacerlo.",
               1, ":observa el corredor buscando algo.",
               1, ":pasa su lengua por el filo de su arma.",
               1, "'No has venido a buscar problemas, verdad?.",
         }));
}
void hacer_palurdos()
{
	int i;
	
	tell_room(environment(TO),TO->query_name()+" llama a sus "
	          "subordinados para empezar la ronda.\n");
	for(i=0;i<3;i++)
	{
		object ob;
			
		ob=clone_object(NPCS+"guardia_patrulla.c");
		ob->move(environment(TO));
		ob->do_command("seguir capitan");
		ob->do_command("protect capitan");
	}
	
	return 1;
}
		

void heart_beat()
{
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
	
	return 1;
}
