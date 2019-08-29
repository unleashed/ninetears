#define SYMBOL "tymora_symbol"
inherit "/obj/monster.c";

void init()
{
  ::init();
  add_attack_spell( 90, "cause critical", 
	({ "/std/spells/cleric/cause_cr.c", "cast_spell", 0 }) );
  add_attack_spell( 90, "cure critical", 
	({ "/std/spells/cleric/cure_cr.c", "cast_spell", 3 }) );
   add_action("do_bow","bow");
}

void setup() 
   {
   set_name("marovyna");
   add_alias("cleric");
   set_main_plural("clerics");
   set_short("Marovyna");
   set_long("Marovyna is a motherly cleric of Tymora.\n");
   set_race("human");
   set_class("cleric");
   set_guild_ob("/std/guilds/priests/tymora");
   add_property("tymora" ,1);
   set_level(35);
  set_wis(20);
   set_max_gp(500);
  set_gp(500);
   set_wimpy(0);
   set_gender(2);
   set_al(0);
   
   new("/items/weapon/mace")->move(this_object());
   command("equip");
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
