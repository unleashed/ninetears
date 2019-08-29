
//Rathburn.  For the Priests of Virga.
 //And Tek, the Dwarf
   //based on the cyrcia symbol. by Wonderflug

#define BASE_THACO 150
#define HP_PER_LEVELX 6
#define ROUNDS_PER_LEVELX 20
#define VIRGA_SYMBOL "/std/spells/items/virga_symbol.c"
inherit "/obj/monster.c";

int base_hb;
int end_hb;
object myp;

void setup()
{
  set_name("avatar");
  add_alias("virga");
  add_alias("avatar of virga");
  set_short("Avatar of Virga");
  set_long("Avatar of Virga\n\n"
      "    This is a humanoid figure of metallic nature. It seems to "
      "glow with a Holy light that hurts your eyes. The light "
      "from it seems to go right through you and penetrate "
      "your soul. It seems really wierd but you can feel a "
      "great goodness but at the same time feel a tinge of Anger. "
      "\n\n");
  set_level(5);
  set_race("avatar");
  call_out("add_spells",0);
}

void init()
{
  ::init();
  add_action("do_dismiss", "dismiss");
}

int do_dismiss(string str)
{
  if(this_player() != myp)
    return 0;
  if(str != "avatar")
    return 0;
   tell_object(myp, " You say a small prayer of thanks to Virga "
     "and dismiss the Avatar. It shrinks back down into a mithril anvil "
    "and you bend down and pick it up. "
    "\n\n");
  tell_room(environment(myp), myp->query_cap_name()+" says a small prayer"
      " to Virga and the Avatar shrinks down into a small mithril "
       "anvil.\n\n",myp);
  clone_object(VIRGA_SYMBOL)->move(myp);
  call_out("dest_me",0);
  return 1;
}

void setup_spell(object caster)
{
  int level;
  myp = caster;
  level = (int)caster->query_level();
  set_level(level);
  set_max_hp(level*HP_PER_LEVELX);
  set_hp(level*HP_PER_LEVELX, this_object());
  set_str((int)caster->query_str());
  set_dex((int)caster->query_dex());
  set_int((int)caster->query_int());
  set_wis((int)caster->query_wis());
  set_con((int)caster->query_con());
  set_thac0( BASE_THACO - level );
  set_ac(50);
  base_hb = myp->query_hb_counter();
  end_hb = base_hb + ( level*ROUNDS_PER_LEVELX );
  this_object()->move(environment(myp));
 //messages
  tell_object(myp, " As you finish your prayer, the anvil starts to glow "
      "and you place it on the ground. It then glows brightly and melts "
    "into a small pool of mithril. The pool of mithril suddenly forms "
     "into an Avatar of Virga.\n");

  tell_room(environment(myp), myp->query_cap_name()+
     " places a glowing anvil on the ground. It then glows very brightly "
     "and melts into a pool of mithril.\n ",myp);

    tell_room(environment(myp), " The pool of mithril suddenly forms. "
      "into a glowing Avatar of Virga.\n"
     "The Avatar turns to "+myp->query_cap_name()+" as "
      "if waiting for orders.\n\n");
  do_command("protect "+myp->query_name());
  do_command("follow "+myp->query_name());
}

void heart_beat()
{
  if(!myp)
  {
    tell_room(environment(this_object()), "The Avatar pauses, looks "
      "around, then glows very brightly and starts to "
       "fade into nothingness.\n The Avatar disappears.\n");
   call_out("dest_me",0);
    return;
  }
  if((int)myp->query_hb_counter() >= end_hb )
  {
    tell_object(myp, "The Avatar glows brightly and forms "
	             "back into an anvil\n\n");
    tell_room(environment(myp), "The Avatar of Virga pauses and "
    "glows brightly, it then forms back into a mithril anvil.\n",
	      myp);
  clone_object(VIRGA_SYMBOL)->move(myp);
   call_out("dest_me",0);
  }
  ::heart_beat();
}

void add_spells()
{
  switch(this_object()->query_level())
  {
    case 14..17:
      add_attack_spell(40, "burning hands",
                      ({"/std/spells/wizard/burnhand.c", 
			"cast_spell",0}));
    break;
    case 18..21:
      add_attack_spell(40, "shocking grasp",
		      ({"/std/spells/wizard/shock_grasp.c", 
			"cast_spell",0}));
    break;
    case 22..25:
      add_attack_spell(40, "major missle",
		      ({"/std/spells/wizard/maj_missle.c", 
		        "cast_spell",0}));
    break;
    case 26..30:
      add_attack_spell(40, "flame arrow",
		      ({"/std/spells/wizard/flame_arrow.c",
			"cast_spell",0}));
    break;
    case 31..35:
      add_attack_spell(40, "lightning bolt",
		      ({"/std/spells/wizard/lightning.c",
			"cast_spell",0}));
    break;
    case 36..99:
      add_attack_spell(40, "fireball",
		      ({"/std/spells/wizard/fireball.c",
			"cast_spell",1}));
    break;
  }
}

int query_kill_xp() { return 0; }
