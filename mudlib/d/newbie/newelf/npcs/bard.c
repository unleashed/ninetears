inherit "/obj/monster";

void setup()
{
    set_name("Llyr");
    set_main_plural("bards");
    set_guild("bard");
    set_short("bard");
    set_long("\nThis is Llyr Darkblade. She is renowned throughout the realms"
      " as the only 'evil' bard. She looks you up and down grinning."
      " Everything about her makes you want to kill her. There is even an "
      "evil glint in her eyes.\n\n");
    add_alias("evil bard");
    add_alias("llyr");
    add_alias("llyr darkblade");
    add_alias("darkblade");
    add_alias("bard");
    add_plural("bards");
    set_gender(2);
    set_str(13+random(3));
    set_dex(12+random(3));
    set_int(12);
    set_alignment(0);
    set_con(12+random(5));
    set_wis(12);
    set_level(10+random(5));
    add_clone("/baseobs/weapons/dagger.c",1);
    add_clone("/baseobs/armours/leather.c",1);
    init_equip();
    set_xp(500);
    add_attack_spell(20,"cure light wounds",({"/std/spells/cleric/cure_lt","cast_spell",3}));
    add_attack_spell(20,"cause light wounds",({"/std/spells/cleric/cause_lt","cast_spell",4}));
    add_attack_spell(20,"haste",({"/std/spells/bards/haste","cast_spell",3}));
}
