inherit "/obj/monster.c";

void setup()
{
    set_name("Dread Mordecai");
    add_alias("mordecai");
    add_alias("wizard");
    set_main_plural("Wizards");
   add_alias("Mordecai");
   add_alias("drow");
   add_alias("dread");
   add_alias("mage");
   add_alias("dread mordecai");
   add_adjective("dread");
    add_alias("wizards");
   set_short("%^BLUE%^Dread Mordecai%^RESET%^");
   set_long("Before you stands one of the oldest and frailest drow you "
      "have ever seen, or are likely to see. His tall, slender frame "
      "is shortened somewhat by the rounding of his shoulders, although "
      "you can tell it is extreme age that causes the stoop, rather "
      "than any lessening of pride, or sense of purpose.\n "
      "\n%^BLUE%^For standing before you is Dread Mordecai, the Archmage, a "
      "drow much feared and revered by generations of drow mages as one "
      "of the greatest mages of all time.%^RESET%^\n"
      "\nWhere once he would have scorned to speak to mere youngsters like "
      "you, he now seems ready to tell you a tale, if you are polite and "
      "prepared to listen carefully. "
      "\n\n");
    set_heart_beat(1);
    set_gender(1);
    set_al(1000);
    set_max_gp(100);
    set_gp(100);
    set_max_hp(100);
    set_level(20);
    set_thac0(120);
    set_ac(10);
    set_str(18);
    set_dex(18);
    set_con(18);
    set_wis(18);
    set_int(18);
    set_cha(18);
    set_kill_xp(800);
    load_chat(60, ({
      1,({
      1,"'Banefall, thats the true drow home.",
      1,"'There's nothing so satisfying as watching a room full of paladins going down in a blast of fire.",
      1,":grins evilly",
      1,"'In my time, spells could take down a guard faster than you could say Daggerford.",
      1,"'As for those pesky thieves, a good wilt in the rear is what they need.",
      1,":sighs wearily"
      })
      }));
    load_a_chat(80, ({
	1, "' Wretched heathen!  Now you will perish!",
	1, "' You are already on the path of evil?!",
	1, "' You are lucky these bones of mine are too old to charge!",
	1, ":cries out in foul language calling your family nasty names.",
	1, ":comes charging into you you!",
	1, ":brings down his weapon on your skull!",
      }));
    add_clone("/baseobs/weapons/quarterstaff.c", 1);
    add_clone("/baseobs/armours/cloak.c", 1);
    this_object()->init_equip();
}

void init()
{
    ::init();
    add_action("do_story", "tell");
}

int do_story(string str)
{
    if(str == "tale")
    {
	if(this_object()->query_property("storytelling") == 1)
	{
	    do_command("say I'm already talking. Be quiet!");
	    return 1;
	}
      write("Dread Mordecai, the Archmage, sits down wearily.\n");
      do_command("say Fie, its not as it once was....");
	this_object()->add_property("storytelling", 1);
	call_out("part_one", 5);
	return 1;
    }
}

int part_one()
{
   do_command("say Once upon a time Sorcere was a great school of "
      "magic, and many came to learn under me, and the greater mages under me.");
    do_command("sigh deeply");
    call_out("part_two", 7);
    return 1;
}

int part_two()
{
   do_command("say But times change, and people look to their bodies "
      "and not to their minds for power.");
    do_command("mutter");
    call_out("part_three", 10);
    return 1;
}

int part_three()
{
   do_command("say I could endow one with great power, and in the end be "
      "more powerful than a warrior, assassin or a thief could "
      "ever hope to accomplish.\n"
      "If I had but one pupil with patience that I could train "
      "slowly in battle magic, and once again Sorcere could be great, "
      "as it once was.");
    do_command("smile sadly");
    this_object()->remove_property("storytelling");
    return 1;
}
