inherit "/obj/monster";
#include "path.h";

int six = (random(5)+1);
void setup()
  {
	set_name("darklor");
	set_short("Darklor");
  set_race("dwarf");
  set_gender(1);
	set_long("This is Darklor a large and muscular Dwarf.  He is "
		"is quite a sight to see standing in the glow of the "
		"forge.  As you look into his eyes, you can instantly "
		"tell that this Dwarf has gone completely mad.  "
		"He is well known for his abilities in the making of "
		"weapons.  Wonder if he can use them as well.\n");

  load_a_chat(20,
	({
	1, "DIE TRAITOR!!!!!",
	1, "Leave me alone!",
	1, "Get out of here, NOW!",
	}) );
  set_guild_ob("/std/guilds/warriors/fighter");
  set_level(15);
  set_wimpy(0);
   clone_object(WEAPON+"short_sword.c")->move(this_object());
    clone_object(ARMOR+"dwarven_chain.c")->move(this_object());
    clone_object(ARMOR+"dwarven_helm.c")->move(this_object());
    clone_object(ARMOR+"dwarven_gauntlets.c")->move(this_object());
    clone_object(ARMOR+"large_shield.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}

void init() {
  add_action("give_me","give");
  ::init();
}

int give_me(string str) {
  object *stuff;
  int c;
  if(str == "moss to darklor") {
    stuff = all_inventory(this_player());
    for(c=0; c<sizeof(stuff);c++) {
      if(stuff[c]->query_name() == "moss") {
        if(stuff[c]->query_property("MOSS") == six) {
          if(this_player()->query_property("DWARVEN_SMITHY")) {
            write("You give the moss to Darklor and nothing happens.\n");
            return 0;
          }
          else {
            write("Darklor eats the moss and a look of calm comes over "
                  "his face.  He smiles and thanks you for your help.  "
                  "He says, 'Here take this chainmail and shield if ye "
	          "wish!'\n\n");
            new(ARMOR+"dwarven_chain.c")->move(environment(this_player()));
            new(ARMOR+"large_shield.c")->move(environment(this_player()));
            this_player()->add_property("DWARVEN_SMITHY",1);
            write_file("/d/mm/logs/SMITHY_QUEST",
              this_player()->query_cap_name()+" has completed the "
              "SMITHY-QUEST in the Dwarven area.  On: "+
              ctime(time())+"\n");
            stuff[c]->dest_me();
            return 1;
          }
        }
        else {
          write("Darklor takes the moss and eats it.  He does not "
                "seem to be affected by it at all.\n");
          stuff[c]->dest_me();
          return 1;
        }
      }
      else {
        write("You have no moss to give.\n");
        return 1;
      }  
    return(1);
    }
  }
return(0);
}

