
/* Coded by Darknight : Thane of Nothing, April 95 */

inherit "obj/monster";

void setup() {
  object arm, weap, weapon, weapon1, armour, cloak, armour1;
  set_name("eldevan");
  add_plural("eldevans");
  set_main_plural("eldevans");
  add_alias("smith");
  add_alias("keeper");
  add_alias("shop keeper");
  set_short("Eldevan");
  set_long("This is Eldevan, the smith, and owner of this establishment. "
           "He tends his shop all day and is know to for making "
           "exceptionally good weapons and armour. His weapons and armour "
           "are the only known protection from the attacks of wood-imps. "
           "\n\n");
  set_race("elf");
  set_guild("fighter");
  set_level(20);
  set_random_stats(12,18);
  set_dex(18);
  set_gender(1);
  set_wimpy(0);
  set_al(15);
  new("baseobs/armours/bronzeplate.c")->move(this_object());
  new("baseobs/weapons/scimitar.c")->move(this_object());
  init_equip();
  set_str(20);
  load_chat(50,({
            1,"'Hello Traveler, Welcome to my shop. May I interest you "
              "in some of the finest weapons in this forest?",
            1,"'You have a strange ere about you, perhaps you have a message"
              " for me?",
            1,"'You know, I once had a healthy, young son such as yourself,"
	      " then one day he went into the woods and no one has seen him"
	      " since.",
            1,"'My wife sits far north and weeps everyday for him, I wish "
	      "someone could give her the comfort she needs." }));
}

void init() {
  ::init();
  add_action("do_bong","say");
  add_action("do_bong","'*");
}

int do_bong(string str, object weapon, object armour, object armour1, object cloak) {
  if(str=="geldon") {
    if(this_player()->query_property("elfsmithequip")) {
      do_command("'The equipment I already gave you should suffice.  "
                 "Don't forget to seek out Faen the Treant and ask "
                 "him about the wood imp poison.\n");
      return(1);
    }
    if(!this_player()->query_property("elfsmithequip")) {
      do_command("'Thank you for comforting my poor wife. Here are some "
		 "things that could help you with your quest.\n\n");
      tell_object("Eldevan fetches some equipment for you.\n");
      tell_room(environment(this_player()),"Eldevan gives a ringmail and "
	        "sword to "+this_player()->query_cap_name()+
                "\n\n",({this_player()}));
      new("/baseobs/weapons/long_sword.c")->move(environment(this_object()));
      new("/baseobs/armours/ringmail.c")->move(environment(this_object()));
      new("/baseobs/armours/helmet.c")->move(environment(this_object()));
      new("/baseobs/armours/cloak.c")->move(environment(this_object()));
      this_player()->add_property("elfsmithequip", 1);
      return(1);
    }
  }
}
