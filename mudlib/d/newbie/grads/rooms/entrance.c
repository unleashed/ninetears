inherit "/std/room";
object wizard;

void reset()
{
    if(!wizard)
    {
	wizard=clone_object("/d/newbie/grads/npcs/wizard.c");
	wizard->move(this_object());
    }
}


void setup()  
{set_light(90);
    set_short("Glowing Cave");
    set_long("\nThis dark cave is glowing with radiance from a large globe in the center of the room.  The onyx "+
      "walls absorb the glaring light as it radiates towards the side of the room creating "+
      "a blure towards to side.  Small ruins are carved around the glowing stone globe.  It is set into a large stone encasing around "+
      "the bottom of the globe.  It is built into the very earth here.\n");
    add_item("walls", "The walls of this cavernous room glow a bright red, "+
      "magically illuminating the room with a bloody radiance.\n");

    add_exit("north", "/w/balo/workroom.c", "door");
    modify_exit("north", ({ "function", "exit_func" }) );

}

int exit_func() {
    int hp, damage;
    hp=(int)this_player()->query_hp();
    damage=hp/3;
    if(this_player()->query_level() >=10) {
	write_file("/d/newbie/grads/log/bigplayer", "Level: "+this_player()->query_level()+
	  "L, Name: "+this_player()->query_cap_name()+
	  "\n");
	this_player()->adjust_hp(-damage);
	write("Unbearable heat stabs through your body as you leap through "+
	  "the Fire Gate, landing on the other side writhing in pain, skin "+
	  "sizzling, your eyelashes and eyebrows charred into dust.\n");
	return 1;
    }
    else { 
	write_file("/d/newbie/grads/log/Lplayer", "Level: "+this_player()->query_level()+
	  "levels, who: "+this_player()->query_cap_name()+
	  "\n");
	write("A hectic sensation takes hold of your mind as "+
	  "your bodey begins to break down into small "+
	  "pieces and magically re-assemble elsewhere.\n");
	write("You made it safely!\n");
	return 1;
    }
}
dest_me()
{
    if(wizard)
	wizard->dest_me();
    ::dest_me();
}
