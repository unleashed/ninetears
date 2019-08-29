inherit "/obj/monster.c";

void setup()
{
    set_name("Sir Rodion");
    add_alias("rodion");
    add_alias("knight");
    set_main_plural("Knights");
    add_alias("knights");
    set_short("Sir Rodion the Shipwrecked Knight");
    set_long("Before you stands one of the bravest Knights in all the "
      "realms, Sir Rodion.  Long ago while on a dangerous mission "
      "for Tinalis, Rodion and his shipmates ran into a terrible "
      "storm.  Their ship was ripped in two by the pounding waves "
      "and brave Rodion was the only one to survive.  He longs to "
      "see his guild and fellow Paladin Brethren once more but in "
      "meantime he might have a story or two to tell you if you "
      "ask kindly.\n\n");
    set_heart_beat(1);
    set_guild_ob("/std/guilds/warriors/paladin.c");
    set_race("human");
    set_gender(1);
    set_al(-1000);
    set_max_gp(100);
    set_gp(100);
    set_max_hp(100);
    set_level(20);
    set_str(18);
    set_dex(18);
    set_con(18);
    set_wis(18);
    set_int(18);
    set_cha(18);
    set_kill_xp(800);
    load_chat(70, ({
	1, "' I wish I could see my brethren once more.",
	1, "' Hail Virga and her Mighty Paladins!",
	1, ":looks longingly out across the Ocean.",
      }));
    load_a_chat(80, ({
	1, "' Wretched heathen!  Now you will perish!",
	1, "' You are already on the path of evil?!",
	1, "' You are lucky these bones of mine are too old to charge!",
	1, ":cries out in foul language calling your family nasty names.",
	1, ":comes charging into you you!",
	1, ":brings down his weapon on your skull!",
      }));
    add_clone("/baseobs/weapons/broad_sword.c", 2);
    add_clone("/baseobs/armours/chainmail.c", 1);
    this_object()->init_equip();
}

void init()
{
    ::init();
    add_action("do_story", "tell");
}

int do_story(string str)
{
    if(str == "story")
    {
	if(this_object()->query_property("storytelling") == 1)
	{
	    do_command("say I'm already telling a story!");
	    return 1;
	}
	do_command("say Ahh so you would like to hear a story?  Let me "
	  "tell you the history of the famous Paladin Guild.");
	this_object()->add_property("storytelling", 1);
	call_out("part_one", 5);
	return 1;
    }
}

int part_one()
{
    do_command("say Long ago the Mighty Goddess of Love and Harmony, Virga, "
      "sought out the most brave and strong of all her followers "
      "to form an Elite Group of Warriors to help her spread her "
      "goodness throughout the Realms.");
    do_command("sigh deeply");
    call_out("part_two", 7);
    return 1;
}

int part_two()
{
    do_command("say These Elite Warriors were given special powers to "
      "help Virga achieve her goal.  They were given the power "
      "to charge into battle when forced to defend themselves, "
      "lay their healing hands on the wounded, and the most "
      "powerful and adventurous were given the ability to "
      "silence their foes and call upon Virga for a special "
      "weapon.");
    do_command("beam");
    call_out("part_three", 10);
    return 1;
}

int part_three()
{
    do_command("say The way of the Paladin is not easy.  One must "
      "be Honorable, Lawful, and Good.  The knight is forced to travel the "
      "realms in search of the tower where the knight can learn "
      "skills, and the cost of advancement is not cheap.  "
      "The Knight must be very strong and very wise with a good "
      "consitution and quick, agile reflexes.  "
      "The Knight is hunted by the evil powers because of the knight's Virtuosity, and his "
      "rivals, the Anti-Paladins, are just as powerful.  But if "
"the knight is persistant the knight will one day be a part of "
      "the most powerful Guild in the Realms, the Paladins!");
    do_command("smile broadly");
    this_object()->remove_property("storytelling");
    return 1;
}
