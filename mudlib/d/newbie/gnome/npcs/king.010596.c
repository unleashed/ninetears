inherit "obj/monster.c";
inherit "/std/basic/respond_give";
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
set_cha(25);
set_level(25);
set_thac0(-20);
set_damage_dice(6,10);
set_al(-100);
set_gender(1);
   respond_give("give_me","greystone of reorx");
}
void init()
{
   ::init();
   give_init();
}
void give_me(object player,object *item)
{
   object amulet;
   write("You give the Greystone of Reorx to Aldinanachru.\nAldinanachru gets "
      "an amulet from his pocket and hands it to you.\n\n");
   amulet = new("/d/newbie/gnome/armour/amulet.c");
   amulet->move(this_player());
   this_player()->add_property("GNOME_NEWBIE",1);
}


