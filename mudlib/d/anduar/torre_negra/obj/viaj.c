// Sinister 29-06-00

inherit "/obj/monster";

void setup()
{
        set_name("Viajero");
        add_alias("viajero");
        set_main_plural("viajeros");
	set_short("Viajero");
        set_long("Cuando te paras a ver a este hombre, te das cuenta "
	"que las cuencas de sus ojos estan vacias y negras, no crees "
	"que lo que tengas delante este muy vivo\n");
	
	set_level(10);
        set_max_hp(35);
        set_hp(35, this_object());
        add_clone("/d/anduar/torre_negra/obj/diario.c",1);
	init_equip();

}

