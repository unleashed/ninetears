inherit "obj/monster.c";
void setup()
{
add_alias("king");
set_name("aldinanachru");
set_short("Aldinanachru");
set_long("Aldinanachru is a little larger, and a lot stouter than "
        "any other gnome you have ever seen.  You can tell that he "
        "a little disturbed at something.  As you stand and think, "
        "a rumor of the lost Greystone of Reorx is refreshed in "
        "your memory.\n");
set_max_hp(1000);
set_str(50);
set_dex(25);
set_con(25);
set_wis(25);
set_int(25);
set_cha(25);
set_level(73);
set_thac0(-20);
set_damage_dice(6,10);
set_al(-100);
set_gender(1);
}

