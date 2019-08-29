inherit "obj/monster.c";
void setup()
{
set_name("commoner");
set_short("Commoner");
set_long("This is an average commoner found in the Mithril "
    "Mountains.  It appears to be an ordinary person just going "
    "about its own business.\n\n");
set_max_hp(0);
set_dex(10);
set_str(10);
set_con(10);
set_wis(10);
set_int(10);
set_cha(10);
set_level(random(2)+1);
set_al(0);
set_gender(random(2)+1);
clone_object("/d/newbie/gnome/weapons/dagger.c")->move(this_object());
command("equip");
load_chat(40,({
   1, "Commoner says: Good morrow to you fine citizen.",
   1, "The commoner glances around to gather its bearings and then "
         "goes on about its business."
}));
}

