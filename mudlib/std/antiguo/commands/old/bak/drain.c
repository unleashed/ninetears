/*** Drain Ability ***/
/*** By Wonderflug ***/
/*** For Anti-Paladins, Dark kuhniggets whatever you wanna call them ***/

#define SP_NAME "Drain"
#define SPELLTYPE "anti-paladin drain"
#define DRAIN_LOCKOUT "drain_done"
#define DRAIN_LOCKOUT_TIME 600

inherit "/std/spells/patch.c";

mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);

 /*** help file ***/
string help() 
{
  return
    "\n\n"
    "Command Name: "+SP_NAME+"\n"
    "Syntax: drain <target>\n"
    "Description: \n"
    "     This ability lets an infernal knight draw from the power of "
    "of the Oaths to Evil that he has sworn, to draw the life force of "
    "an opponent into himself.  A maximum of 2hp per level of the Knight "
    "of Darkness can be drained.  Since the control over the Negative "
    "Material Plane granted by this ability is tenuous at best, not all of the "
    "life force drained shall go to the Anti-Paladin;  indeed the Lord "
    "of Death, Cyric himself, demands half in payment.  This ability will "
    "heal a creature of undeath, but beware, for then the Knight himself "
    "shall have to make Cyric's dread payment.\n\n";  
       

}


mixed spell(string str, object caster);

int drain(string str,object cast)
{
  mixed ret;
  object caster;
	
  caster = cast ? cast : this_player();
  if(interactive(caster))
	  str = (string)caster->expand_nickname(str);

  if ( wrong_alignment(caster) )
    return punish_align(caster);

  ret = spell(str, caster);
  if (stringp(ret))
  {
	 notify_fail(ret);
	 return 0;
  }

  tell_object(caster,"You chant in a twisted, foul language "
    "and glorious evil pervades the air.\n");
  tell_room(environment(caster),caster->query_cap_name()+" chants a foul, "
    "twisted rite, filling the air with a pall of evil.\n", caster);

  return 1;
}


mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Thou art already busy draining a life force, and 'twould "
      "be suicide to attempt to open two conduits to the Negative "
      "Material plane!\n";

  if ((int)caster->query_property(DRAIN_LOCKOUT))
    return "Thou hast already drained life force recently, milord, and "
      "twould not be wise to attempt another so soon.\n";

  ob = find_unique_match(str, environment(caster));

  if (!sizeof(ob) || !living(ob=ob[0]) || ob->query_property("dead") )
    return "Twould be wise to find thyself a living target NEARBY "
     "an thee open thy channel to the Negative Material Plane, milord.\n";

  if ( ob==caster )
    return "Draining thyself would be to no purpose!\n";

  caster->add_spell_effect(2, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob }));
  return 1;
}


int hb_spell(object caster, mixed *params, int time)
{
  int damage, drained;
  int eff_damage;
 
  if (!params[0] || environment(params[0]) != environment(caster))
  {
    tell_object(caster, "Thy target has cowered and cravenly ran from "
      "thy evil might!\n");
    return 0;
  }
  if ( time == 2)
  {
    tell_object(caster, "The area flickers with absolute darkness, and "
      "thy hands be shrouded in mists of evil.\n");
    tell_room(environment(caster), "The area flickers into absolute darkness "
      "and back, as "+caster->query_cap_name()+"'s hands become shrouded "
      "\nin darkness.\n", caster);
    return 0;
  }
  
  if(params[0]->query_property("dead"))
  {
    tell_object(caster, "Thy target has expired!\n");
    return 0;
  }

  caster->add_timed_property(DRAIN_LOCKOUT, 1, DRAIN_LOCKOUT_TIME);

  damage = (int)caster->query_level() * 2;
  damage = cleric_fix_damage(caster,params[0],-damage,"magical");
  damage = -damage;
  if ( params[0]->query_property("undead") )
  {
    params[0]->adjust_hp(random(damage/2));
    caster->adjust_hp(-damage, caster);
    tell_object(caster, "The creature of undeath looks refreshed as you "
      "touch it with thy shrouded hands!\n\nCyric rips out a part of thy "
      "lifeforce in payment!\n");
    tell_object(params[0], "You fell refreshed as "+
      caster->query_cap_name()+" touches you with hands shrouded "
      "in darkness!\n\n"+caster->query_cap_name()+" is suddenly "
      "wracked with pain.\n");
    tell_room(environment(caster), caster->query_cap_name()+" touches "+
      caster->query_possessive()+" hands to "+params[0]->query_cap_name()+
      ", who looks refreshed.\n\n"+caster->query_cap_name()+" is wracked "
      "with pain and looks weaker.\n", ({ caster, params[0] }) );
    return 0;
  }

          
  /* We only give the amount based on what was actually drained, not
   * what COULD have been drained.  So have to check hp before and after
   */
  tell_object(caster, "You touch your hands to "+
    params[0]->query_cap_name()+", draining "+params[0]->query_possessive()+
    " life force into you.\n\n"+params[0]->query_cap_name()+" shudders "
    "and screams in pain as Cyric rips the life from "+
    params[0]->query_objective()+".\n");
  tell_object(params[0], caster->query_cap_name()+" touches darkness-"
    "enshrouded hands to you, and starts to look refreshed.\n\n"
    "You shudder and scream in pain, feeling life force ripped out of "
    "you by some\nunseen force!\n");
  tell_room(environment(caster), caster->query_cap_name()+" touches "
    "darkness-enshrouded hands to "+params[0]->query_cap_name()+".\n\n"+
    params[0]->query_cap_name()+" screams and shudders in pain as "+
    caster->query_cap_name()+" looks refreshed.\n", 
    ({ caster, params[0] }) );



  eff_damage = (int)params[0]->query_hp(); 
  params[0]->adjust_hp(-damage,caster);
  eff_damage -= (int)params[0]->query_hp();
  eff_damage = eff_damage < 0 ? 0 : eff_damage;

  caster->adjust_hp(random(eff_damage/2),caster);
  params[0]->attack_by(caster);

  return eff_damage;

}
