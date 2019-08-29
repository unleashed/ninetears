/*** Great Hammer of Timion -- For timion's symbol spell ***/
/*** By Wonderflug ***/

inherit "/obj/weapon.c";
#define LEVELX_ADJ 1/6

int my_dice, my_rolls;
int my_enchant;

void recalc_stuff();

void setup()
{
  set_name("great hammer of timion");
  add_alias("hammer");
  add_alias("great hammer");
  set_short("Great Hammer of Timion");
  set_long("Great Hammer of Timion\n\n"
    "     This must be the finest hammer you've ever laid eyes upon.  "
    "The haft is a good 2 feet long, with a grip that seems to suck "
    "the sweat away from your hands.  The head is a block "
    "of solid black metal, emblazoned with mystical "
    "runes, and ready to crush anything "
    "in its path.  The whole is surprisingly light, but "
    "would pack a viscious punch indeed.\n\n");
  set_base_weapon("flail");
  set_twohanded(1);
  set_weight(50);
}


int set_in_use(int i)
{
  if (!living(environment(this_object())) )
    return ::set_in_use(i);
  if ( i == 1 )
  {
    if ((string)environment(this_object())->query_guild_name() == "timion" )
    {
      recalc_stuff();
      set_enchant(my_enchant);
      dice = my_dice;
      rolls = my_rolls;
      tell_object(environment(this_object()), "You heft the Great "
        "Hammer of Timion and feel the closeness of your diety.\n");
      return ::set_in_use(i);
    }
    else 
    {
      set_enchant(-3);
      dice = 5;
      rolls = 1;
    }
  }

  return ::set_in_use(i);
}

void recalc_stuff()
{
  object ob = environment(this_object());
  int level = (int)ob->query_level();
  my_dice = level/4 + random(level/8);
   if(my_dice>9)
      my_dice=9;
  my_rolls = level/12;
   if(my_rolls>3)
      my_rolls=3;
  my_enchant = level*LEVELX_ADJ;
}

void setup_spell(object ob)
{
  tell_room(environment(ob), ob->query_cap_name()+" completes the "
    "spell and "+ob->query_possessive()+" Small Bronze Hammer "
    "\nglows with a blindingly bright light.\n\nWhen the light "
     "fades, a massive Hammer is in "+ob->query_possessive()+
    " hands.\n", ob);
  tell_object(ob, "You complete the spell and suddenly your holy "
    "symbol starts to glow \nwith a blindingly bright light.\n\n "
    "You feel the power of Timion roar through you into the symbol, "
    "feel it \ngrow heavy in your hands.\n\nWhen the glow fades you "
    "see the symbol is gone, replaced by a huge Hammer.\n");
  this_object()->move(ob);
  return;
}

int query_auto_load() { return 1; }

void write_message(string happen, int dam, string wtype, object me, object him)
{
  string h, m;
  h = (string)him->query_cap_name();
  m = (string)me->query_cap_name();
  switch( dam )
  {
    case 1..2:
      tell_object(him, m+" strikes you a glancing blow.\n");
      tell_object(me, "You strike a glancing blow to "+h+".\n");
      tell_room(environment(me), m+" strikes a glancing blow to "+h+".\n",
        ({ him, me }) );
      break;
    case 3..6:
      tell_object(him, m+" hits you with a Great Hammer of Timion.\n");
      tell_object(me, "You hit "+h+" with your Great Hammer of Timion.\n");
      tell_room(environment(me), m+" hits "+h+" with a Great Hammer of "
        "Timion.\n", ({ him, me }) );
      break;
    case 7..10:
      tell_object(him, m+" nails you with a Great Hammer of Timion.\n");
      tell_object(me, "You nail "+h+" with a Great Hammer of Timion.\n");
      tell_room(environment(me), m+" nails "+h+" with a Great Hammer of "
        "Timion.\n", ({ him, me }) );
      break;
    case 11..15:
      tell_object(him, m+" pounds you with a Great Hammer of Timion.\n");
      tell_object(me, "You pound "+h+" with a Great Hammer of Timion.\n");
      tell_room(environment(me), m+" pounds "+h+" with a Great Hammer of "
        "Timion.\n", ({ me, him }) );
      break;
    case 16..20:
      tell_object(him, m+" pummels you with blows from a Great Hammer of "
        "Timion.\n");
      tell_object(me, "You pummel "+h+" with blows from your Great Hammer of "
        "Timion.\n");
      tell_room(environment(me), m+" pummels "+h+" with blows from a Great "
        "Hammer of Timion.\n", ({ me, him }) );
      break;
    case 21..28:
      tell_object(him, m+" crushes into you with a Great Hammer of Timion.\n");
      tell_object(me, "You crush "+h+" into the ground with a Great Hammer "
        "of Timion.\n");
      tell_room(environment(me), m+" crushes "+h+" into the ground with a "
        "Great Hammer of Timion.\n", ({ me, him }) );
      break;
    case 29..36:
      tell_object(him, m+" mashes you into a bloody mess with a Great "
        "Hammer of Timion.\n");
      tell_object(me, "You mash "+h+" into bloody pulp with your Great "
        "Hammer of Timion.\n");
      tell_room(environment(me), m+" mashes "+h+" into a bloody pulp with a "
        "Great Hammer of Timion.\n", ({ him, me }) );
      break;
    case 37..1000:
      tell_object(him, m+"'s Great Hammer of "
        "Timion glows with a blinding blue \nlight before "
        "slamming into you, devastating you.\n");
      tell_object(me, "%^BOLD%^%^BLUE%^The Great Hammer of "
        "Timion glows with a holy blue light \nbefore slamming "
        "into "+h+", devastating "+ him->query_objective()+".%^RESET%^\n");
      tell_room(environment(me), m+"'s Great Hammer "
        "of Timion glows with a blinding blue light \nbefore slamming "
        "into "+h+", devastating "+him->query_objective()+".\n",
        ({ him, me }) );
      break;
    default:
      tell_object(him, m+" narrowly misses you with a Great Hammer of "
        "Timion.\n");
      tell_object(me, "You narrowly miss "+h+" with your Great Hammer of "
        "Timion.\n");
      tell_room(environment(me), m+" narrowly misses "+h+" with a Great "
        "Hammer of Timion.\n", ({ him, me }) );
      break;
  }

}
