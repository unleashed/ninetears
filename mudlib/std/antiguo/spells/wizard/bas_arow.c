
/*** Arrow Spell ***/
/*** Done like a dogs diner Taniwha 1995 made an inherited base ***/
/*** ->base spell, Wonderflug.  I blame *cough* er, credit, Taniwha fully.***/
inherit "/std/spells/base.c";
#define RANGE "/obj/handlers/range"
#define DDIV 4 // Players move real fast now, it'll hit if < 3 rooms and the throw has dropped a lot
string SP_NAME = "Flame Arrow";
int GP_COST = 6;
string SPELLTYPE  = "offensive";
string TYPE = "fire";
string save_type = "fire";
int LEVELS_PER_ARROW = 1;
int LEVELS_PER_BONUS = 5;
int SIZE_OF_DICE = 4;
void setup()
{
  set_spell_name(SP_NAME);
  set_spell_level(3);
  set_sphere("conjuration");
  set_target_type("one");
  set_range(100);
  set_line_of_sight_needed(0);
  set_help_extras(
    "Damage Type: "+TYPE+"\n"
    "Saving Throw: Special");
  set_help_desc("This spell will hurl "+TYPE+" bolts at a single target.  The "
    "caster gets 1 arrow per level of experience, to a maximum of 20 "
    "arrows.  In addition, you will get up to 5 extra or less. Several arrows "
    "will be shot each round, until all have been shot.  Each arrow "
    "does 1-"+SIZE_OF_DICE+" hp of damage, with a +1 damage bonus per "+
    LEVELS_PER_BONUS+" levels of the caster.  If the target leaves the room, "
    "then once a saving throw is made following that, no further arrows "
    "will hit.");
  set_gp_cost(GP_COST);
  set_casting_time(2);
  set_rounds( ({ "round1", "round2" }) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if(!quiet)
  {
    tell_object(caster, "A magic-looking bow appears in your hands.\n");
    tell_room(environment(caster), "A magic-looking bow suddenly "
      "appears in "+caster->query_cap_name()+"'s hands!\n", caster);
  }
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int num_arrows;
  int damage_bonus;
  int maxarrows;
  num_arrows = (int)caster->query_level() / LEVELS_PER_ARROW;
  num_arrows = num_arrows > 20 ? 20 : num_arrows;
  num_arrows += random(10)-5;
  num_arrows = num_arrows <=0 ? 1 : num_arrows;
  maxarrows = random((int)caster->query_level()/6) + 1;
  damage_bonus = (int)caster->query_level() / LEVELS_PER_BONUS;
  if ( !target )
  {
    tell_object(caster, "Your target seems to have disappeared!\n");
    return -1;
  }
  if ( !quiet )
  {
    tell_object(caster, num_arrows+" bolts of "+TYPE+" explode into existence "
      "and float in the air around you.\n");
    tell_room(environment(caster), "The air itself bursts into "+
      num_arrows+" bolts of "+TYPE+", floating around "+
      caster->query_cap_name()+".\n", caster);
  }
  caster->add_spell_effect(num_arrows, "spell", SP_NAME,
    this_object(), "hb_arrow", 
    ({ num_arrows, target, damage_bonus, environment(caster), quiet,maxarrows }) );
  return 0;
}
int hb_arrow(object caster, mixed *params, int time)
{
  int damage,i;
  object env;
  int quiet;
  int difroom;
  int rvictim,rcaster;
  quiet = params[4];
  env = params[3]; // place we started from
  if (!params[1] || params[1]->query_dead() )
  {
    tell_object(caster,  "Your fiery bow goes up in smoke "
      "as your target is no more.\n");
    call_out("end_spell",0,caster);
    return 0;
  }
  damage = random(SIZE_OF_DICE)+1+params[2];
  damage = wiz_fix_damage(caster,params[1],damage,save_type);
  params[1]->attack_by(caster);
  tell_object(caster, "You shoot "+params[5]+"  "+TYPE+" bolts at "+
    params[1]->query_cap_name()+".\n");
  tell_object(params[1], TYPE+" arrows come streaking at you!\n");
  if(environment(params[1])->query_property("nocast") ||
     environment(caster)->query_property("nocast") ||
     caster->query_property("nocast") ) 
    damage = 0;
  if( environment(params[1]) != environment(caster) )
  {
    difroom = 1;
    rvictim =       ( (RANGE->calc_distance(caster,params[1])/DDIV )* ((int)params[1]->query_dex() + (int)params[1]->query_level()) );
    rcaster =       ( (int)caster->query_int() + (int)caster->query_level() );
  }
  else difroom =0;

  for(i = 0; i < params[5]; i++)
  {
   if(!params[1] || params[1]->query_dead() ) break;
    if(difroom && (random(rvictim) > random(rcaster)) ) damage = 0;
    params[1]->spell_damage(params[1],damage,TYPE,caster);
    switch( damage )
    {
    case 1:
      tell_object(caster, "Your arrow singes "+params[1]->query_cap_name()+
        ".\n");
      tell_object(params[1], "You are singed as the "+TYPE+" arrow grazes "
        "you.\n");
      break;
    case 2..4:
      tell_object(caster, "You burn "+params[1]->query_cap_name()+".\n");
      tell_object(params[1], "The "+TYPE+" arrow hits you.\n");
      break;
    case 5..7:
      tell_object(caster, "You burn "+params[1]->query_cap_name()+
        " severely.\n");
      tell_object(params[1], "The "+TYPE+" arrow damages you severely.\n");
      break;
    case 8..100:
      tell_object(caster, "Your arrow explodes into "+
        params[1]->query_cap_name()+".\n");
      tell_object(params[1], "The "+TYPE+" arrow explodes as it flies "
        "into you!\n");
      break;
    default:
      tell_object(params[1], "You narrowly avoid the "+TYPE+" missile.\n");
      tell_object(caster, "Your "+TYPE+" arrow whizzes by "+
        params[1]->query_cap_name()+" harmlessly.\n");
      break;
    }
  }
  params[0] -= params[5];
  if ( time == 1 || params[0] <= 0)
  {
    tell_object(caster, "Your bow dies away into a puff of smoke "
      "as you use up the last arrow.\n");
    call_out("end_spell",0,caster);
    return 0;
  }
  if ( environment(params[1]) != environment(caster) )
  {
    if(!quiet)
    {
        tell_room(environment(caster), caster->query_cap_name()+" pulls "+
          caster->query_possessive()+" bow back, and shoots "+params[5]+
          " of the "+TYPE+" bolts floating around "+caster->query_objective()+
          "off into the distance.\n", caster);
    }
    tell_room(environment(params[1]), params[1]->query_cap_name()+" is "
      "struck by several "+TYPE+" arrows!\n", params[1]);
// Taniwha, only lose track if THEY leave the room
    if( env != environment(caster) &&
        ( random((int)params[1]->query_dex() + (int)params[1]->query_level()) ) >
        random( (int)caster->query_int() +    (int)caster->query_level() )
      )
    {
      tell_object(caster, "You lose track of "+params[1]->query_cap_name()+
        ", and your bow dies into smoke.\n");
      call_out("end_spell",0,caster);
      return 0;
    }
  }
  else 
    if(!quiet) 
      tell_room(environment(caster), caster->query_cap_name()+" pulls back "+
        caster->query_possessive()+" bow and blasts several arrows at "+
        params[1]->query_cap_name()+".\n", ({ caster, params[1] }) );
   
  return 0;
}
void end_spell(object caster)
{
  caster->remove_spell_effect(SP_NAME);
}

