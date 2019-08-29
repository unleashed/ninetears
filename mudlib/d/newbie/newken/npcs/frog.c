inherit "obj/monster.c";
void setup()
{
    set_main_plural("Frogs");
    set_name("frog");
    set_short("Frog");
    set_long("You see before you a small bright green frog. "
      "It is rare to see them in the forests. "" You can hear it "
      "croaking rather loudly, and you can see its throat moving in "
      "time with it's croaks.\n\n");
    set_level(2);
    set_al(0);
set_move_after(8,8);
    set_gender(random(2)+1);
    load_chat(40,({
	1, "The frog looks at you intently, almost with what appears to be 'human' intelligence.",
	1, "The frog shifts slightly on the limb that it is sitting on.",
      }));
}

