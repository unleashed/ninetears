inherit "/std/spells/base";

void setup()
{
  set_spell_name("Holy Word");
  set_spell_level(18);
  set_sphere("protection");
  set_target_type("all");
  set_range(0);
  set_help_desc(
   "This spell channels part of the force of the caster's god through\n"
   "a mighty shout.  All those within range will be stunned and incapcitated\n"
   "for some time.\n");
  set_gp_cost(35);
  set_casting_time(1);
  set_rounds( ({"round1"}) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level, i;
  object shadow;
  if(sizeof(target) < 2)
  {
    tell_object(caster,
      "There are no living beings here to be affected by Holy Word.\n");
    return -1;
  }
  if(!quiet)
  {
    tell_object(caster,
      "You clutch your holy symbol tightly, and take a deep breath.\n"
      "Holding the symbol aloft, you exhale with a mighty shout.  The \n"
      "name of your god resounds through the realms, knocking those \n"
      "around you senseless.\n"
      "You stagger and sway, dizzy and stunned from the enormous amount\n"
      "of power that has just passed through you. \n");
    tell_room(environment(caster),
      caster->query_cap_name()+
      " clutches "+caster->query_possessive()+" holy symbol, and brandishes\n"
      "it for all to see.  "+caster->query_pronoun()+" breathes in deeply, \n"
      "and closes "+caster->query_possessive()+" eyes.  Suddenly, an ear-"
      "splitting shout of \n"+
      capitalize(caster->query_guild_name())+
      "! fills the area.  The force of the sound knocks you off your feet.\n"
      "You slowly stagger back up, but are stunned and dazed.\n", caster);
  }

  for(i=0;i<sizeof(target);i++)
  {
    level = (int)target[i]->query_level();
    target[i]->clear_attackers();
    if(!target[i]->query_creator())
    {
    shadow = clone_object("/std/spells/cleric/h_word_sh1.c");
    shadow->setshadow(target[i],caster);
    if(target[i] == caster)
      call_out("hw1_wear_off", 12, target[i]);
    else
      call_out("hw1_wear_off", 20, target[i]);
    }
  }
  return 0;
}

void hw1_wear_off(object target)
{
  if(target)
  {
    target->destruct_hw1_shadow();
  }
}
