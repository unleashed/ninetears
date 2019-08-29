//By Taggert.
inherit "/obj/monster.c";
void setup(){
    set_name("hawk");
    set_short("giant hawk");
    set_long("\nThis is one of the largest hawks you have ever seen. "
      "It stands at three feet in height, and has a beak large enough "
      "rip straight through your flesh. It has brown feathers covering "
      "a layer of white down. The hawk glares at you as if you are a "
      "trespasser.\n");
    set_level(7);
    set_random_stats(11, 16);
    set_aggressive(3);
    set_move_after(5, 5);
    set_max_hp(50);
    add_clone("/d/newbie/newelf/obj/sil_leaf.c",1);
}
