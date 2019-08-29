// Valar


inherit "/obj/guardian";
#include "/d/keroon/path.h"

void setup() {
	

	set_name("guardia duergar");
	set_short("guardia duergar");
	set_long(query_short()+"\nEste un joven duergar que forma parte de uno de los mucho "
		"grupos que patrullan estas grutas.\n");
	
	set_main_plural("guardias duergars");
	
	add_alias("duergar");
	add_alias("guardia");
	add_plural("duergars");
	add_plural("guardias");
	
	set_gender(1);
	set_guild_ob("/rol/gremios/khurgar.c");	
        set_ciudadania("Keroon");
	
        set_level(15+random(5));
	
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
	
        add_clone(ITEMSCAMINO +"hacha_guardia",2);
        add_clone(ITEMSCAMINO +"cota_guardia.c",1);
        add_clone(ITEMSCAMINO +"yelmo_patrulla.c",1);	
        add_clone(ITEMSCAMINO +"brazaletes_guardia.c",1);
        init_equip();
	
	load_chat(50,({
	           1,":escupe.",
                   1,":mira hacia los lados nerviosamente.",
          	}));
      		
	init_equip();
	

	
	adjust_money(20,"plata");
	set_move_after(8,10);
        add_move_zone("camkeroon");	
        
	}

