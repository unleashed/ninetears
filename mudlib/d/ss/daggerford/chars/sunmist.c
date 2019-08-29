#define SYMBOL "lathander_symbol"
inherit "obj/monster";

void init()
{
  ::init();
  add_attack_spell( 95, "flamestrike",
	({ "/std/spells/cleric/flamestrike.c", "cast_spell", 1 }) );
   add_action("do_bow","bow");
}

void setup()
{
set_name("sunmist");
add_alias("priest");
add_adjective("high");
add_alias("liam");
set_main_plural("priests");
set_short("Liam Sunmist");
set_long("Liam Sunmist is the high priest of the Lathander temple in "+
        "Daggerford.\n");
set_race("human");
set_class("cleric");
set_level(20);
set_max_gp(500);
set_gp(500);
set_wis(36);
set_wimpy(0);
set_gender(1);
set_al(500);
}
int do_bow(string str)
{
   object holy;
   if(!(int)this_player()->query_property("holy symbol"))
   {
      holy = new("/std/spells/items/"+SYMBOL);
      holy->move(this_player());
      if(environment(holy) != this_player())
      {
        write("You can't carry the symbol, so it falls to the floor.\n");
         holy->move(environment(this_player()));
      }
      this_player()->add_timed_property("holy symbol",1,1800);
      tell_room(environment(this_object()),(string)this_object()->query_cap_name()+
      " slips "+this_player()->query_cap_name()+" an items, and whispers words you cannot hear.\n",
      ({ this_player() }) );
      write((string)this_object()->query_cap_name()+" hands you a holy item, "+
      "and warns you not to lose it, as it will not be replaced soon.\n");
   }
   else
   {
      write(this_object()->query_cap_name()+" says well ?, what happened to the last one I gave you ?, come back in a day, careless one.\n");
   }
   return 1;
}
