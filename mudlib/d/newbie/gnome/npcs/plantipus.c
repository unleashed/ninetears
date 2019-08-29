inherit "obj/monster.c";
void setup()
{
    set_name("plantipus");
    set_short("plantipus");
    set_long("This is a cross between a vine-like plant and your worst nightmare.  It has "
      "sharp thorns all over its vines and a 'Mouth' with several rows of VERY sharp teeth.\n");
    set_level(8);
    set_str(12);
    set_dex(5);
    set_max_hp(30);
    set_damage_dice(2,2);
    set_al(0);
    set_gender(random(2)+1);
}
