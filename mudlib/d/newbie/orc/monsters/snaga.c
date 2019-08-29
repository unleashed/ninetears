inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("snaga");
	set_short("Snaga");
  set_race("orc");
  set_gender(1);
   set_long("The tall Orc that stands before you is Snaga, "
      "the owner of this equipment.  Due to his unusually extreme height "
      "is rumored that he is half human.  However, he refuses to admit "
      "it, even if it is true.  "
      "\n\n");

  load_a_chat(50,
	({
	1, "'DIE TRAITOR!!!!!",
	1, "'Leave me alone!",
	1, "'Get out of here, NOW!"
	}) );
  set_level(8);
  set_wimpy(0);
   clone_object(WEAPON+"dagger.c")->move(this_object());
    clone_object(ARMOR+"leather.c")->move(this_object());
  command("equip");
} /* setup */



