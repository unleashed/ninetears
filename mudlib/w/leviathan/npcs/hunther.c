inherit "/obj/henchman.c";

void setup() {

set_join_room_mess("$N llega desde el $T");
set_leave_room_mess("$N sigua a su duenyo hacia el $T");
set_join_me_mess("join me mess ??");
set_follow_owner(1);
//set_protect_owner(1);

      set_name("hunther");
      set_short("hunther");
      set_al(60);
      set_race("duergar");
      set_gender(1);
      set_level(128);
      set_wimpy(0);
      set_max_hp(query_level() * 5000);
      set_hp(query_max_hp());
      set_max_gp(query_level() * 8000);
      set_gp(query_max_gp());
      set_random_stats(90, 98);
      set_long("Un pedazo de bug con patas\n\n");
} /* setup */

void init()
{
	::init();
	add_action("prohibido", ({"call","goto","kill","matar","formular","trans","dest","cre","say","'","quit","golpear","bash","rabia","berserk","cargar","carga"}));
} /* init */

void prohibido()
{
	notify_fail("Nephilim susurra a tu oido: Tu poder no sirve de nada bajo mi presencia...\n");
//        this_player()->do_death();
}
