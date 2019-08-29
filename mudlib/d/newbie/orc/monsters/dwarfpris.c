inherit "obj/monster.c";
void setup()
{
set_name("dwarf");
set_short("dwarf prisoner");
add_alias("prisoner");
set_long(" He looks old and tired. With a matted long white beard and "
"equally matted hair, this dwarf looks very miserable. He is "
"just the sort of guy you've been looking for to abuse!!\n");

set_race("dwarf");
set_guild("fighter");
set_max_hp(7);
set_dex(12);
set_str(12);
set_con(10);
set_wis(10);
set_int(7);
set_cha(5);
set_level(2);
set_al(0);
set_gender(1);
load_chat(40,({
1," The dwarf grins at you in defiance."
}));

set_aggressive(0);
}
