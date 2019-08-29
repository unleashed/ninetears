inherit "/obj/monster.c";

void setup() {
    set_name("Whining Wench");
    set_short("Whining Wench");
    set_long("  A lady stands before you...whining.  Whining so much you just wanna "
      "slap the holy piss outta her.  You just wanna do ANYTHING to stop her WHINING!\n");
    add_alias("human");
    add_alias("wench");
    add_alias("woman");
    set_heart_beat(1);
    set_random_stats(16, 17);
    set_level(10+random(3));
    set_guild("fighter");
    set_gender(2);
    init_equip();
    load_chat(500, ({
	1, "'But i don't WANNA listen to reason!",
	1, "'I think that Taniwha is about the most hateful demi i have ever seen!",
	1, "'It's not fair that the scouts aren't super-psychopathic anymore!", 
	1, "'The Fist scouts can't even tell the gender for crying out loud!", 
	1, "'It's all Raisa's damn fault!", 
	1, "'The Fist scouts are too damn weak now...they can't whip the shit out of you anymore!", 
	1, "'Why is it always OUR sig that gets messed with!", 
	1, "'We had to pay so much MORE for our scouts, whats up with the other sigs getting them so cheap!", 
	1, ":pouts and whines loudly!", 
	1, "'I'm telling Baldrick!",
	1, ":Stomps off in a huff.",
	1, ":whines loudly."}));
}

