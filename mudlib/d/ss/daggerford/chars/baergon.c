#define SYMBOL "tempus_symbol.c"
/* Baergon Bluesword, the Tempus GuildMaster. */

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
   set_name("baergon");
   add_alias("priest");
   set_main_plural("priests");
   add_plural("baergons");
   set_short("Baergon");
   set_long("Baergon Bluesword is a powerful half-elven priest.\n");
   set_race("half-elf");
   set_class("priest");
   set_guild_ob("/std/guilds/priests/tempus");
   add_property("tempus" ,1);
   set_level(27);
  set_wis(23);
  set_max_gp(300);
  set_gp(300);
   set_wimpy(0);
   set_gender(1);
   set_al(0);
 
   
   new("/items/weapon/long_sword")->move(this_object());
   new("/items/armour/chainmail")->move(this_object());
   init_command("equip");
}
int do_bow(string str)
{
   object holy;
  if ( (int)this_player()->query_level() < 5 )
  {
    write(this_object()->short()+" says: Sorry can't trust you with the power "+
    "of a Symbol yet.\n");
    return 1;
  }
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

