// Thalos
// Guardia al servicio capitan

#include "duergar.c"
#include "../../path.h"

void setup()
{
    set_name("Guardia duergar");
    set_short("guardia");
    add_alias("duergar");
    set_long("Este un joven duergar que forma parte de uno de los mucho "
		"grupos que patrullan estas grutas.\n");
    set_main_plural("Guardias Duergars");
    add_plural("guardia");
    add_plural("duergars");
    set_guild_ob("/std/guilds/warriors/battleduergar");
    set_race_ob("/std/races/duergar.c"); 
    set_random_stats(15,17);
    set_str(24);
    adjust_money(20,"plata");
    set_gender(1);  
	
    add_clone(ITEMSCAMINO +"hacha_guardia",2);
    add_clone(ITEMSCAMINO +"cota_guardia.c",1);
    add_clone(ITEMSCAMINO +"yelmo_patrulla.c",1);	
    add_clone(ITEMSCAMINO +"brazaletes_guardia.c",1);
    init_equip();

    load_chat(50,({
        1,":escupe.",
        1,":mira hacia los lados nerviosamente.",
    }));
    
    set_level(15+random(5));
    set_al(700);
    set_alignment(700);
    
}
