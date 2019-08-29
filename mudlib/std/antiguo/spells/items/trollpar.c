/*** Troll Part ***/
/*** by Wonderflug **/

/* Lets clerics learn regeneration if they're taniwha/hokemj,
 * or withering if they're timion/Cyrcia.  Other guilds get regeneration
 * put on them.
 */

inherit "/std/object";

void setup()
{
  set_name("piece of troll");
  add_alias("piece");
  set_short("Piece of troll");
  set_long("\nPiece of troll\n\n"
	"     This is a small piece of.. something.. that came from a troll. "
	"It's completely covered in disgusting black troll blood, and not "
	"quite recognizable as a part of any body.\n\n");
  set_weight(150);
  set_value(5000);
}

void init()
{
  ::init();
  add_action("do_look", "look");
  add_action("do_look", "l");
  add_action("do_study", "study");
  add_action("do_drink", "drink");
}

int check_guild()
{
  switch( this_player()->query_guild_name() )
  {
    case "grimbrand" :
    case "Cyrcia":
   case "ducky":
    case "timion" :
	if ( (int)this_player()->query_level() >= 12 )
	  return 1;
	else return 0;
    case "taniwha" :
    case "hokemj" :
   case "virga":
	if ( (int)this_player()->query_level() >= 12 )
	  return 2;
	else return 0;
   case "paladin":
      if( (int)this_player()->query_level() >= 18 )
      return 2;
   case "antipaladin":
      if( (int)this_player()->query_level() >= 18 )
      return 1;
    default:
	return 0;
  }
}

int do_look(string str)
{
  if ( str != "blood" )
	return 0;

  write("\nThe blood is a deep black, and is really quite disgusting.  "
	"It seems to flow and move with a life all it's own, however, "
	"never seeming to just stop and congeal.\n\n");
/* do a wisdom check :) */
  if (random(20) < (int)this_player()->query_wis() )
	write("Maybe that's something to do with the way trolls regenerate. "
	  "You scratch your head and think it might need further study.\n\n");
  return 1;
}

int do_study( string str )
{
  if ( str != "blood" && str != "piece" )
	return 0;

  if ( random(20) > (int)this_player()->query_wis() )
  {
	write("\nYou study the troll blood but can't seem to figure anything "
	  "out.\n\n");
	return 1;
  }
  if ( check_guild() == 2 ) 
  {
	if ( !(this_player()->query_spell("regeneration")) )
	  this_player()->add_spell("regeneration","regeneration",12);
	write("You study the way the troll blood moves and reforms intently "
	  "and you soon discover how it works.  Pondering over it, you "
	  "realise a healing spell can be adapted to work much the same way, "
	  "spreading out the power of the heal over a long time.\n\n "
	  "Throwing the troll bit away, you immediately begin praying "
	  "fervantly to "+this_player()->query_guild_name()+
	  " and are soon rewarded.\n\n");
	this_object()->dest_me();
	return 1;
  }
  if ( check_guild() == 1 )
  {
	if ( !(this_player()->query_spell("withering")) )
	  this_player()->add_spell("withering","withering",12);
	write("You study the way the troll blood moves and reforms intently "
	  "and you soon discover how to counteract its movements.  Thinking "
	  "for a while on it, you realise you can adjust a wounding spell to "
	  "block the movements the same way, in effect spreading the wound "
	  "out over a long time.\n\nThrowing the troll bit away, you "
	  "immediately begin praying to "+this_player()->query_guild_name()+
	  " and are soon rewarded.\n\n");
	this_object()->dest_me();
	return 1;
  }
  write("You study the blood and all you can think of is how thirsty you "
	"are.\n");
  return 1;
}

int do_drink( string str )
{
  object ob;

  if ( str != "blood" && str != "piece" )
	return 0;
  if (this_player()->query_property("regen_on") ||
	this_player()->query_mirror_spell() || 
	this_player()->query_armour_spell())
  {
	write("You drink the blood off the Troll body part but nothing "
	  "further happens.\n");
	this_object()->dest_me();
	return 1;
  }

  this_player()->add_timed_property("regen_on",1,50);
  this_player()->add_timed_property("fire", -50, 50);
  ob = clone_object("/std/spells/cleric/regeneration_obj.c");
  ob->set_spell(this_player(), 2);
  ob->set_get();
  ob->move(this_player());
  ob->reset_get();
  ob->reset_drop();
  this_player()->add_extra_look(ob);

  write("You drink the blood and feel health flow through you, but also "
	"feel a curious fear of fire.\n");
  tell_room(environment(this_player()), this_player()->query_cap_name()+
	" drinks some troll blood and seems to glow with health.\n",
	this_player());
  this_object()->dest_me();
  return 1;
}
