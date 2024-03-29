/*** Spider summoning -- for Cyrcia's Symbol spell ***/
/*** By Wonderflug ***/
/*** Spider tweaked to be useful by Santino ***/

#define BASE_THACO 150
#define HP_PER_LEVELX 5
#define ROUNDS_PER_LEVELX 20
#define CYRCIA_SYMBOL "/d/gremios/hechizos/items/medallon_aranya.c"
inherit "/obj/monster.c";
#include "unarmed_combat.h";
#define NUMATTACKS 2


int base_hb;
int end_hb;
object myp;

void setup()
{
  set_name("aranya gigante");
  add_alias("aranya");
  set_short("Aranya Roja Gigante");
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
	set_guild_ob("/d/gremios/guerreros/paladin.c");
  set_race("human");
  /*  Need anything else here? I don't think so */

}

void init()
{
  ::init();
	add_attack_spell(20, "estallido de fuego", ({"/d/gremios/hechizos/paladin/estallido_fuego.c",
		"cast_spell", 0, 2}));
  add_action("do_dismiss", "despedir");
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
  clone_object(CYRCIA_SYMBOL)->move(myp);
   call_out("dest_me",0);
  return 1;
}
void setup_spell(object caster)
{
  int level;

  myp = caster;
  level = (int)caster->query_level();

	set_level( level );
  set_max_hp(level*HP_PER_LEVELX);
  set_hp(level*HP_PER_LEVELX, this_object());
   set_max_gp((int)caster->query_max_gp());
   set_gp((int)caster->query_max_gp());
  set_str((int)caster->query_str());
  set_dex((int)caster->query_dex());
  set_int((int)caster->query_int());
  set_wis((int)caster->query_wis());
  set_con((int)caster->query_con());
  set_thac0( BASE_THACO - (2 * level ));
  set_ac(50 - level );
  base_hb = myp->query_hb_counter();
  end_hb = base_hb + ( level*ROUNDS_PER_LEVELX );

  this_object()->move(environment(myp));
  /* messages */
  tell_object(myp, "Suddenly Cyrcia's medallion starts to feel incredibly "
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
    tell_room(environment(this_object()), "The spider clicks confusedly "
      "and goes *pop* "
      "into a zillion little bits.\n");
   call_out("dest_me",0);
    return;
  }
  if ( (int)myp->query_hb_counter() >= end_hb )
  {
    tell_object(myp, "The spider shimmers and reverts back into an "
    "amulet.\n\n");
    clone_object(CYRCIA_SYMBOL)->move(myp);
    tell_room(environment(myp), "The spider suddenly shimmers and "
      "morphs into a Spider Medallion.\n", myp);
   call_out("dest_me",0);
  }

  ::heart_beat();
}

int query_kill_xp() { return 0; }

int unarmed_attack(object him, object me)
{
	object* att;
	object ob;
	int i;

	att = (object*)me->query_attacker_list();
	for(i=0; i<NUMATTACKS; i++)
	{
		ob = att[random(sizeof(att))];
		if(ob) monster::unarmed_attack(ob, me);
	}
}
