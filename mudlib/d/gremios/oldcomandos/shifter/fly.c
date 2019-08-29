/* coded by Raskolnikov
 * returns the pigeon form to the guild at the cost of all
 * hps and gps
 */
#define GUILD "/d/aprior/guilds/shifter/rooms/entrance.c"

void fly(string str) {
    if(!str || (str != "home")) {
	tell_object(this_player(), "Your only option is to fly home.  "
	  "Try again.\n");
	return 1;
    }

    tell_object(this_player(), "You begin to make the journey home but you "
      "have to try and remember the way...\n");
    call_out("go_home", 60);
    return 1;
}

void go_home() {
    tell_object(this_player(), "Finally remembering the way, you make it back "
      "to your guild feeling quite exhausted.\n\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+" "
      "takes to the air and flies home.\n\n", ({ this_player() }) );
    load_object(GUILD);
    this_player()->move(GUILD);
    tell_room(environment(this_player()), this_player()->query_cap_name()+" "
      "returns home looking quite exhausted.\n\n", ({ this_player() }) );
    this_player()->set_gp(1);
    this_player()->adjust_hp(-(this_player()->query_hp())+1);
    return 1;
}
