/*** Spider summoning -- for Lolth's Symbol spell ***/
/*** By Wonderflug ***/

#define BASE_THACO 30
#define HP_PER_LEVEL 5
#define ROUNDS_PER_LEVEL 20
#define LOLTH_SYMBOL "/std/spells/items/lolth_symbol.c"
inherit "/obj/monster.c";

int base_hb;
int end_hb;
object myp;

void setup()
{
  set_name("giant spider");
  add_alias("spider");
  set_short("Giant Red Spider");
  set_long("Giant Red Spider\n\n"
    "  This is a huge spider, almost as big as a small horse.  "
    "Its body is shielded by a blood-red chitinous "
    "shell, which seems hard and smooth as marble.  "
    "Its legs, thick as a grown man's thigh each, are "
    "covered in short, bristly red hairs, and end in "
    "a single sharp claw, so it makes disturbing "
    "clicking and scratching sounds as it moves. "
    "Huge multifaceted glowing green eyes dominate the head, "
    "but the seeming glimmer of intelligence there startles "
    "you the most.  Of course, "
    "those razor-sharp mandibles dripping with blood are "
    "fairly startling too.\n\n");
  set_level(5);
  set_race("spider");
  /*  Need anything else here? I don't think so */

}

void init()
{
  ::init();
  add_action("do_dismiss", "dismiss");
}

int do_dismiss( string str )
{
  if ( this_player() != myp )
    return 0;
  if ( str != "spider" )
    return 0;

  tell_object(myp, "You dismiss the spider and it reverts back into a "
    "Spider Medallion.\n");
  tell_room(environment(myp), myp->query_cap_name()+" gestures at "
    "the "+this_object()->short()+" and it shimmers and morphs into "
    "a small Spider Medallion.\n", myp);
  clone_object(LOLTH_SYMBOL)->move(myp);
  this_object()->dest_me();
  return 1;
}
void setup_spell(object caster)
{
  int level;

  myp = caster;
  level = (int)caster->query_level();

  set_level(0);
  set_max_hp(level*HP_PER_LEVEL);
  set_hp(level*HP_PER_LEVEL, this_object());
  set_str((int)caster->query_str());
  set_dex((int)caster->query_dex());
  set_int((int)caster->query_int());
  set_wis((int)caster->query_wis());
  set_con((int)caster->query_con());
  set_thac0( BASE_THACO - level );
  set_ac(5);
  base_hb = myp->query_hb_counter();
  end_hb = base_hb + ( level*ROUNDS_PER_LEVEL );

  this_object()->move(environment(myp));
  /* messages */
  tell_object(myp, "Suddenly Lolth's medallion starts to feel incredibly "
  "hot, and \nyou drop it on the ground.\n");
  tell_room(environment(myp), myp->query_cap_name()+" drops a  "
    "Spider Medallion and shakes "+myp->query_possessive()+
    " hand as if burned.\n", myp);
  tell_room(environment(myp), "The Spider Medallion glows with an "
    " evil red light, and suddenly the spider on it steps "
    "off and grows enormously!\nThe Huge Red Spider clicks and "
    "scuttles over to "+myp->query_cap_name()+".\n");

  do_command("protect "+myp->query_name());
  do_command("follow "+myp->query_name());
}

void heart_beat()
{
  if ( !myp )
  {
  tell_room(environment(this_object()), "The spider clicks confusedly and goes *pop* "
      "into a zillion little bits.\n");
    this_object()->dest_me();
  return;
  }
  if ( (int)myp->query_hb_counter() >= end_hb )
  {
    tell_object(myp, "The spider shimmers and reverts back into an "
    "amulet.\n\n");
  clone_object(LOLTH_SYMBOL)->move(myp);
  tell_room(environment(myp), "The spider suddenly shimmers and "
      "morphs into a Spider Medallion.\n", myp);
    this_object()->dest_me();
  }

  ::heart_beat();
}

int query_kill_xp() { return 0; }
