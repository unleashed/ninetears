inherit "obj/monster.c";
void setup()
{
set_name("wolf");
set_short("Wolf");
set_long("This is a fierce looking back wolf that wanders the Mithril Mountains. "
   "It has very thick fur that is currently raised all along its back.  "
    "Its evil green eyes sends chills up your back as it stares you down.\n\n");
set_max_hp(0);
set_dex(18);
set_str(14);
set_con(15);
set_wis(8);
set_int(8);
set_cha(8);
set_level(4);
set_al(0);
set_gender(random(2)+1);
}

