
inherit "/std/object.c";
#define CLERICSPELL "/std/spells/cleric/powr_die.c"
#define WIZARDSPELL "/std/spells/wizard/finger_death.c"

int deathly(string str);

void setup()
{
   set_name("skull");
   set_short("Skull of the Deathmaster");
   set_long("\n"
   "A small polished skull, the top is inset with a crown of Onyx, and large "
   "rubies are set into each eyesocket. The skull radiates evil and power "
   "in almost equal quantities. For, whatever else this is, it is surely an "
   "item of power. The teeth glitter brightly as you look at the skull. "
   "The skull burns in your hand as you hold it, and you feel that it is "
   "willing you to unlock it's terrible secret. "
   "\n\n");
   set_value(10000);
}
void init()
{
   ::init();
   add_action("do_look","look");
   add_action("do_look","l");
   add_action("do_skull","skull");
}

int do_look(string str)
{
   if(str == "teeth")
   {
      write("\nThe teeth are inset with diamonds, you have trouble making out the words, but they seem to be.\n"
      "\"S_ul_ H_l_\"\n"
   "At least what you can read.\n");
      return 1;
   }
}
int add_spell()
{
   if(this_player()->query_level() < 20)
   {
      write(sprintf("%*|s",this_player()->query_cols(),
      "\nThe Skull throbs in your hand and you hear a voice say "
      "\"Damnnation to you, you are too weak in power from me to corrupt!\""
      "\n"));
      return 1;
   }
   switch(this_player()->query_guild_name())
   {
      case "timion":
      case "Cyrcia":
   case "ducky":
   case "virga":
      case "hokemj":
      case "Grimbrand":
      case "taniwha":
         write("\nA cloud of dark smoke pours from the skull and surrounds your head.");
         if(!this_player()->query_spell("power word kill") )
         {
         this_player()->add_spell("power word kill","powr_die",20 );
         write("\nYou feel wiser, but somehow unclean.\n");
         }
         else
         {
            write("\nVoices echo in your head "
            "\n\"Greedy fool\nMay your last mortal feeling be dispair\"\n"
            );
            this_player()->do_death();
         }
      break;
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
         write("\nA cloud of dark smoke pours from the skull and surrounds your head.");
         if(!this_player()->query_spell("power word kill") )
         {
         this_player()->add_spell("finger of death","finger_death",20);
         write("\nYou feel wiser, but somehow unclean.\n");
         }
         else
         {
            write("\nVoices echo in your head "
            "\n\"Greedy fool\nMay your last mortal feeling be dispair\"\n"
            );
            this_player()->do_death();
         }
      break;
      default:
         write("\nThe Skull screams:\"You lack the powers I seek to pervert!\"");
      break;
      }
}
int do_skull(string str)
{
   switch(str)
   {
   case "help":
      write("\nThe eyes in the skull glow brightly and words enter you head "
      "\n\"Woe unto the being that requests death upon another, for in my "
      "presence, such a wish may well be granted.\"\n"
      "\"Those glutted with power wishing for more power "
      "may corrupt their very souls.\"\n"
      "Invoke me with skull \"target\", if you dare.\n"
      "\nThe eyes fade again."
      "\n");
   return 1;
   break;
   default:
      if(str == (string)this_player()->query_name()) add_spell();
      else deathly(str);
         if(str != "")
      {
      write("\nThe Skull burns within your hands, then goes.... elsewhere, "
      "leaving only a foul stench and a few bad dreams.\n");
   this_object()->dest_me();
      return 1;
      }
   break;
   }
}
int deathly(string str)
{
  if ( this_player()->query_property("nocast") ||
	environment(this_player())->query_property("nocast") )
  {
	tell_object(this_player(), "You try to invoke the skull but something blocks the skull's power!\n");
	return 0;
  }
   if(this_player()->query_int() > this_player()->query_wis())
   {
      WIZARDSPELL->cast_spell(str);
   }
   else
   {
      CLERICSPELL->cast_spell(str);
   }
   return 0;
}
 
