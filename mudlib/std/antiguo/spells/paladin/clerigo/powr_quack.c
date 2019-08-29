/* Power word Die.
  Made by Baldrick June 1993.
    Mods for FR jan '95, by the same nerd.
    Uses saving throw to balance the spell. But it should be *very* high level
  To get it:
  Have fun with it.

  Wonderflug's mods:
  --Magic resistance done.   	
  --Check for pacified target.
  --Added a casting delay, some new fancy messages. 
  --Basically rewrote it.
 
  96, -> base spell.  Wonderflug again

  Taniwha grins
  -- Took that and totally screwed it up, if the God's a Duck, he's a Duck
  
*/

#define TYPE "evil"
#define SAVE_TYPE "evil"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Power Word Quack");
  set_spell_level(7);
  set_sphere("necromantic");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell summons the little ceramic ducks of death, "
    "incarnations of the evil God Ducky, these cause such pain to the "
    "soul of those with GOOD taste that they suffer massive "
    "internal damage as their eyes try to retreat through their brain.\n"
    "The soul of an older player having more value, this spell does "
    "damage in proportion to the level of the victom");

  set_gp_cost(10);
  set_casting_time(4);
  set_rounds( ({ "round1", "round2", "round3", "round4" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You begin to chant, and as you do so, your "
  	"voice changes pitch. "
    "\n");
  tell_room(environment(caster), caster->query_cap_name()+" chants "
    "in a harsh quacking voice.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "Your chanting becomes a loud chaotic "
    "quacking !.\n");
  tell_room(environment(caster), caster->query_cap_name()+"'s chant "
    "grows louder, into a loud chaotic quacking!.\n", caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "The sound of your quacking fades and is repalced "
    "by a multitude of higher pitched quacks.\n");
  tell_room(environment(caster), caster->query_cap_name()+" stops chanting "
    "but the sound is taken up by a multitude of smaller voices.\n", caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int skill;
  int check;
  int cost;
  int c_roll, t_roll;

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is nobody of that name here.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " looks very confused and quacks angrilly.\n", caster);
    return -1;
  }


  if (target->query_dead())
  {
    tell_object(caster, (string)target->query_cap_name()+
      " is already dead.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " looks very confused and curses.\n", caster);
    return -1;
  }

  if (target->query_pacify_spell())
  {
    tell_object(caster, "You don't feel like harming "+
      (string)target->query_cap_name()+", seeing how peaceful "+
      target->query_pronoun()+" is.\n");
    return -1;
  }

  /* 100% save on protection from evil */

  if( ( (int)target->query_property(SAVE_TYPE)) )
  {
    tell_object(target, "You hear "+(string)caster->query_cap_name()+
      " quack once angrilly and a funny clattery sound "
      " like one wing clapping, a few quiet angry quacks "
      " and silence reigns. "
      "\n");
    caster->attack_ob(target);
    tell_object(caster, "Your quack fails.\n");
    tell_room(environment(caster), caster->query_cap_name()+" quacks "
      "something at "+target->query_cap_name()+" "
      "and there's a rattling sound and a few quiet but angry "
      "departing quacks.\n",
      caster);
    return 0;
  }

  if(target->query_property("pacify_on"))
  {
    tell_room(environment(caster),"The Gods step in to save the life of "+
      target->query_cap_name()+" who is harmless.\n");
    return 0;
  }
  tell_object(caster,"%^BOLD%^The sound of quacking fills the air "
  "as you avert your eyes from the vision of horror forming before you !"
  "%^RESET%^.\n");
  tell_room(environment(caster),(string)caster->query_cap_name() + 
    " Quacks once in the silence. A flutter of wings and many strident quacks "
    "reply, you recoil and your eyes slam shut, barely in "
    "time to save your life from the vision of evil (and extreeme bad taste) "
    "flying in.\n", ({ caster }) );
  tell_object(target, "\n%^BOLD%^Your eyes try to shut, but the sight of small "
  "badly painted ceramic ducks flying towards you is too much !\n"
  "%^RED%^A massive stabbing pain engulfs you as evil overwhelms you and your "
  "eyes try to burrow into your brain to escape the horror.%^RESET%^\n");
  target->attack_by(caster);
  target->spell_damage(target,(int)target->query_level()*2,"evil",caster);
  return 0;
}
