/* Tenser the Tuff.  Teaches mug to high level thieves, mugs others.
 * --Wonderflug
 */

inherit "/obj/monster";
 
object player;
int action_count;
int countdown;
int interrupt;

setup() {
  set_name("tenser");
  add_alias("tough");
  set_short("Tenser the Tough");
  set_long("\n\nTenser the Tough\n\n"+
	"     Tenser's a small little guy at first glance.  Look closer though, "+
	"and you'll see the muscles rippling along his arms and back.  The "+
	"huge Warhammer that's dragging his belt down.  The quick grace and "+
	"speed of every movement.  This guy's a professional.  And he don't "+
	"really like you staring at him.\n");
  set_race("human");
  set_level(35);
  set_str(30);
  set_dex(30);
  set_al(500);
  set_max_gp(300);
  set_gp(300);
  set_max_hp(150);
  set_hp(150);
  set_kill_xp(2000);
  set_ac(0);
  set_thac0(10);
  set_wimpy(25);
  load_a_chat(100,({
       1, "'Ya really tink dis iz a good idea, punk?",
       1, ":slams his Warhammer into your gut, knocking the breath out of you.",
       1, "'Oh I'm gonna knock ya silly fer that mate.",
       1, "'hehe any bones not broken yet?",
  }));

  add_property("fire", 80);
  add_property("cold", 80);
  add_property("air", 80);
  add_property("magical", 80);
  add_property("poison", 90);
  add_property("electrical", 80);
  add_property("acid", 50);

  clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
  clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
  clone_object("/baseobs/armours/leather.c")->move(this_object());
  
  this_object()->init_equip();

  countdown = 0;
  interrupt = 1;
  set_heart_beat(1);
}

int query_kill_xp()
{  return 5000; }

void init()
{
  ::init();
  add_action("do_search","search");
  add_action("do_teach", "watch");
  add_action("do_teach", "learn");
  add_action("do_teach", "WATCH");
  add_action("do_teach", "LEARN");
   set_gp(300);

  "/std/commands/hide_in_shad.c"->hide_in_shadows("", this_object());
  if ( (int)this_player()->query_level() > 10 && interrupt )
  {
	action_count = 15;
	countdown = 1;
	player = this_player();
  }
}

int do_search( string str )
{
  object s = this_player();
  int boo;

  boo = 0;
  if ( (string)s->query_guild_name() == "thief" )
	if ( (int)s->query_level() >= 12 )
		boo = 1;
	else boo = 2;
  if ( (string)s->query_guild_name() == "wizthief" )
	if ( (int)s->query_level() >= 10 )
		boo = 1;
	else boo = 2;

  switch( boo )
  {
    case 0:
	tell_object(s,"Just as you start to search a really nasty looking "+
	  "fella comes up to you.\n\nTenser says: I'm Tenser.  I'd rather ya "+
	  "didn't do that my friend.  Spoils me business.\n\n"+
	  "Tenser pats his Warhammer suggestively.\n\n");
	return 1;
    case 2:
	tell_object(s,"Just as you start to search a really nasty looking "+
	  "fella comes up to you.\n\nTenser says: I'm Tenser.  You, are an "+
	  "inexperienced punk, and yer spoiling me\nbusiness doin' things "+
	  "like that.  Now scram and tell yer mommy to keep a better eye on "+
	  "ya.\n\n");
	return 1;
    case 1:
	tell_object(s,"Just as you start to search a really nastly looking "+
	  "fella comes up to you.\n\nTenser looks you up and down.\n\nTenser "+
	  "looks around and says quietly: Look, ya better not do that.  You "+
	  "should \nknow how hard it be t'mug someone with gits like you "+
	  "doing stuff like \nthat.  Ah here comes a victim now.. WATCH and "+
	  "you might LEARN something mate.\n\n");
	return 1;
  }

}

int do_teach( string str )
{
  object s = this_player();
  
  if ( ((string)s->query_guild_name() == "thief" && (int)s->query_level() >= 12)
    || ((string)s->query_guild_name() == "wizthief" && 
	(int)s->query_level() >= 12 ) )
  {
	tell_object(s,"You lay low and watch Tenser.\n\nTenser leaps out of "+
	  "and SMACKS a wealthy-looking young lady over the back of the "+
	  "\nhead with his Warhammer, and she drops unconscious.\n\nTenser "+
	  "snags all her jewelry and runs off.\n\nYou feel stupid realizing "+
	  "how simple that is.  Now to just find a victim \nyourself..\n");
	if ( !s->add_known_command("mug") )
	{
	  tell_object(s, "\nYou didn't really learn anything new here.\n");
	  return 1;
	}
	else return 1;
  }
  return 0;
}


void heart_beat()
{
  int i;

  ::heart_beat();

   if(countdown && player)
    switch ( action_count-- )
    {
      case 0:
	"/std/commands/mug.c"->mug(player->query_name(), this_object());
	interrupt = 0;
	break;
      case -5..-1:
	"/std/commands/steal.c"->steal("coins from "+player->query_name(),
	  this_object());
	break;
      case -10..-6:
	this_object()->run_away();
	break;
      case -1000..-11:
	"/std/commands/hide_in_shad.c"->hide_in_shadows("",this_object());
	countdown = 0;
	interrupt = 1;
	this_object()->remove_timed_property("just mugged");
	break;
    }
  set_heart_beat(1);
}
