inherit "/obj/monster.c";


void setup()
{
   set_name("bird");
   set_short("Bird");
   set_long("A small tiny coloured bird\n");

    set_main_plural("Birds");
    add_plural("birds");
    set_gender(0);    
    set_str(6);

    set_level(1);
    set_max_hp(5);
    set_wimpy(0);
    load_chat(20,({
      1,"@moves from branch to branch while whistling",
     1,"@snaps at a worm crawling nearby",
      1,"@looks at you with curiosity",
    }));
}

           
