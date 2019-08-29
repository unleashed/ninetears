
inherit "/obj/monster";

void setup()
  {
  set_name("father bonamie");
  set_short("Father Bonamie");
add_alias("father");
add_alias("bonamie");
set_long("Standing in front of you is Father Bonamie, a high "
         "priest of Reorx.  His basic purpose is to tend to "
         "casualties of battle and to give forrgiveness to "
         "those who have wronged others.  He should be happy "
         "with this type of position, but there is no expression "
         "on his face to tip you off either way.\n");
   set_race("/std/races/newbie/gnome/");
  set_gender(1);
  set_guild("timion");
  set_level(9);
clone_object("/d/newbie/gnome/items/robe.c")->move(this_object());
clone_object("/d/newbie/gnome/items/sandals.c")->move(this_object());
command("equip");
} /* setup */

void dest_me()
  {
  ::dest_me();
}
