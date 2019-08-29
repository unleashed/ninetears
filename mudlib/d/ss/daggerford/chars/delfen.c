inherit "obj/monster";
void init()
{
  ::init();
  add_attack_spell( 70, "horrid wilting", ({ "/std/spells/wizard/horrid_wilting.c", "cast_spell", 0 }) );
   add_attack_spell(70,"cone of cold", ({ "/std/spells/wizard/conecold.c","cast_spell",0}) );

}

void setup() {
   set_name("delfen");
   add_alias("wizard");
   set_main_plural("wizards");
   add_property("determinate","");
   set_short("Delfen");
   set_long(
          "Delfen Yellowknife was born in the city of Waterdeep long ago..."+
          "so long ago that no one remembers him as a child, which is just "+
          "the way Delfen likes it.  As rumor would have it, he was "+
          "discovered at an early age to have an alarming intellect, "+
          "coupled with a detached and noble personality that set him apart "+
          "from the other youths in the back streets of the big city.  He "+
          "was taken in by an influential wizard (several elderly mages have "+
          "tried to take credit for being his mentor) and taught the ways "+
          "of the Art.\n\n"+
          "Delfen Yellowknife has grown and developed into one of the most "+
          "powerful mage/scholars ever to roam the Realms.  You would be "+
          "most wise not to provoke him in any way.  Seek his knowledge, "+
          "not his wrath.\n");
   set_race("human");
   set_class("wizard");
   set_level(21);
  set_max_gp(300);
  set_gp(300);
  set_int(25);
  set_dex(18);
   set_wimpy(0);
   set_gender(1);
   set_al(-200);

   //add_attack("spell", 0, 50, 300, 0, 0, "magic");
}

void reset()
{
  "/std/spells/wizard/mirror.c"->cast_spell("delfen",this_object());

}
