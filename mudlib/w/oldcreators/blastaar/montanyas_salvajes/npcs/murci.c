inherit "/obj/monster";
void setup() { 
set_name("murcielago");
set_short("murcielago");
set_long("Un murcielago corriente revoloteando por toda la estancia.\n");
set_main_plural("murcielagos"); 
add_plural("murcielagos");
set_gender(1);
set_random_stats(3,7);
set_str(10+random(3));
set_xp(200);
set_level(6+random(5));
set_wimpy(0);
}
