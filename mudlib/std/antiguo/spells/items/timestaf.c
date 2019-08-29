/*** Time Staff ***/
/*** by Wonderflug **/
/*** Part of the 'Slow' spellquest ***/

inherit "/std/item";
#define HASTE_SPELL "/std/spells/wizard/haste.c"
#define SLOW_SPELL "/std/spells/wizard/slow.c"

void setup()
{
  set_name("staff of time");
  add_alias("staff");
  set_short("Staff of Time");
  set_long("\nStaff of Time\n\n"
	"     This staff is about 5 feet long, and made of some weird "
	"shiny blue wood.  Two small bands of black iron circle the top "
	"of it, and the butt is adorned with a cap of ivory.  Palely "
	"glowing yellow runes are carved along its length.\n\n");
  set_read_mess("\n'zap <target>' to alter time for something.\n\nNote, the "
	"staff channels power from the user to produce its effects.\n\n");
  set_weight(350);
  set_value(5000);

  add_property("num_uses", random(2)+1 );
}

void init()
{
  ::init();
  add_action("do_zap", "zap");
  add_action("do_readrunes", "read");
  add_action("do_readrunes", "l*ook");
}

string enchant_string()
{
  switch( this_object()->query_property("num_uses") )
  {
	case 1:
	  return "The staff radiates a pale aura of enchantment.\n";
	case 2:
	  return "The staff glows with power.\n";
	case 3:
	  return "The brilliance of the staff's power aura blinds you.\n";
	default:
	  return "A faint remnant of an aura remains in the staff.\n";
  }
}

int check_guild()
{
  switch( this_player()->query_guild_name() )
  {
      case "bard":
      case "wizthief":
     case "wiz-war":
     case "wizard":
     case "drow_wizard":
     case "necromancer":
     case "conjurer":
     case "abjurer":
     case "enchanter":
     case "illusionist":
     case "invoker":
     case "transmuter":
	if ( (int)this_player()->query_level() >= 9 )
	  return 1;
	else return -1;
     default:
	return 0;
  }
}

int do_zap( string str )
{
  if (this_object()->query_property("num_uses") <= 0 )
  {
	tell_object(this_player(), "You try to invoke the staff but nothing "
	  "happens.\n");
	tell_room(environment(this_player()), this_player()->query_cap_name()+
	  " tries to invoke a Staff of Time but it just fades away into "
	  "nothing.\n", this_player() );
	this_object()->dest_me();
	return 1;
  }
  this_object()->add_property("num_uses", 
	(int)this_object()->query_property("num_uses") - 1 );

  tell_object(this_player(), "You invoke the power of the staff.\n");
  tell_room(environment(this_player()), "\n"+this_player()->query_cap_name()+
	" invokes the power of a Staff of Time.\n\n", this_player() );

  switch( random(2) )
  {
	case 0:
	  HASTE_SPELL->cast_spell( str );
	  break;
	default :
	  SLOW_SPELL->cast_spell( str );
	  break;
  }
  return 1;
}

int do_readrunes(string str)
{
  if ( str != "runes" && str != "runes on staff" )
	return 0;
  switch( check_guild() )
  {
	case 1:
	  write("\nYou decipher the runes on the staff, and realize it's "
	    "the words to a magic spell!  You study them and soon gain "
	    "some small mastery over time.\n\nThe staff fades into another "
	    "reality as its purpose here is done.\n\n");
	  if ( !this_player()->query_spell("slow") )
		this_player()->add_spell("slow", "slow", 9);
	  this_object()->dest_me();
	  return 1;
	case -1:
	  write("\nTry as you might, you cannot understand the runes.\n");
	  return 1;
	default:
	  write("\nThey're just a swirling, jumbled mess and make you "
	    "dizzy looking at them.\n\n");
	  return 1;
  }
  return 1;
}

