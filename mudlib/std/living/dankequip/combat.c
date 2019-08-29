inherit "/std/weapon_logic";
int *weapon_attack_out, *attack_out;                //dk
static object attackee;
static object *attacker_list,
              *call_outed,
              protector;
//              weapon,
//dk I allow 2-weapons combat, so equip.c defines held_ob[0] as the primary
//weapon, if any, and held_ob[1] as the secondary weapon, if any.

static int concentrate;
static int att_level, dodging;

#define DIV_NUM 6
#include "money.h"

void set_weapon_attack_out(int mess, object *held_ob) { }

int query_dodging() { return dodging; }
int query_my_att_level() { return (int)this_object()->query_level(); }
void set_concentrate(int i) { concentrate = i; }
int query_concentrate() { return concentrate; }
object set_protector(object ob) { return (protector = ob); }
object query_protector() { return protector; }
void actual_death();

void create() 
  {
  attacker_list = ({ });
  call_outed = ({ });
  weapon_logic::create();
}

void combat_commands() 
  {
  add_action("do_protect", "protect");
}

int do_death(object killed_by) 
  {
  int i, xp, aln, tot;
  mapping damage_done;

  damage_done = (mapping)this_object()->query_damage_done();
  if (!damage_done)
    damage_done = ([ ]);
  for (i=0;i<sizeof(attacker_list);i++) 
    {
    attacker_list[i]->stop_fight(this_object());
    tot += damage_done[attacker_list[i]];
    }
  for (i=0;i<sizeof(call_outed);i++)
    call_outed[i]->stop_fight(this_object());
  xp = (int)this_object()->query_xp();
  if (!tot) tot = 1;
  aln = (int)this_object()->query_align();
  for (i=0;i<sizeof(attacker_list);i++) 
    {
    attacker_list[i]->adjust_xp(((xp * damage_done[attacker_list[i]]/tot)
      * att_level) / (DIV_NUM *
      ((int)attacker_list[i]->query_level())));
    attacker_list[i]->adjust_align(aln);
    }
  if (killed_by)
    say(killed_by->query_cap_name()+" dealt the death blow to "+
        this_object()->query_cap_name()+".\n");
  else
    say(this_object()->query_cap_name()+" died horribly.\n");
  if (environment())
    event(environment(), "death", attacker_list, killed_by);
  actual_death();
  return 0;
}

object make_corpse() 
  {
  object corpse, money, *obs, ob;
  int i;
  corpse = clone_object("/obj/corpse");
  corpse->set_owner(this_object()->short(0));
  corpse->set_race_name(this_object()->query_race());

//? corpse->add_alias((string)this_object()->query_name());
//? corpse->add_alias((string *)this_object()->query_aliases());
//? corpse->add_plural((string *)this_object()->query_plurals());

  corpse->start_decay();
  corpse->add_adjective(this_object()->query_adjectives());
  if (!this_object()->query_race_ob())
    if (file_size("/std/races/"+this_object()->query_race()+".c") >= 0)
      corpse->set_race_ob("/std/races/"+this_object()->query_race());
    else
      corpse->set_race_ob("/std/races/unknown");
  else
    corpse->set_race_ob(this_object()->query_race_ob());

//dk Until we make an informed decision here, I'm going to have corpses
//unhold, unwear and unwield everything.  Otherwise, since some items have a
//special effect on the room only if they're worn or held by a living
//creature, creators would have to code each such item carefully to
//distinguish the effects when worn or held by a corpse...we probly don't
//want to do this, but even if we do, I don't want to deal with it right now.

  tell_room(environment(),this_object()->query_cap_name()+" drops everything, and "+
    this_object()->query_possessive()+" armor eerily hops off "+this_object()->query_possessive()+
    " body and falls to the floor.\n", this_object());
  tell_object(this_object(),"You drop everything, and your armor eerily hops"
    " off your body and falls to the floor.\n");
  for (i=0; i<2; i++)
    if (ob=(object)this_object()->query_held_ob(i)) {
      if (!ob->query_weapon())
        ob->set_held(0);
      else
        ob->set_wielder(0);
      ob->set_drop();
      ob->move(environment());
    }
  weapon_attack_out = ({ });

  obs = this_object()->query_armors();
  for (i=0; i<sizeof(obs); i++) {
    ob = obs[i];
    ob->set_wearer(0);
    ob->set_drop();
    ob->move(environment());
  }
  this_object()->equip_create();

  obs = all_inventory(this_object());
  for (i=0; i<sizeof(obs); i++)
    obs[i]->move(environment());
  corpse->move(environment());
  return corpse;
}

//? shouldnt need to call this... so make it static, just in case 
static void actual_death() {
  object ob, ob2;
//dw if second_life returns false... do stupid things... 
  if (!((int)this_object()->second_life())) {
    make_corpse()->move(environment());
//dw dest the ones that stick around... 
    ob = first_inventory(this_object());
    while(ob) {
      ob2 = next_inventory(ob);
      ob->dest_me();
      ob = ob2;
    }
    this_object()->dest_me();
  }
}

object query_attackee() { return attackee; }

void attack() 
  {
  int i, dam, his_att_lvl;
  string his_name;
  object *obs,ob,weapon;

  if (!attacker_list)
   attacker_list = ({ });

  while (i<sizeof(attacker_list)) {
    if (!attacker_list[i])       //dw have they died unexpecedaly? 
      attacker_list = delete(attacker_list,i,1);
    else
//dw    I will put all the ones not in the correct environ in a new list.
      if (environment(attacker_list[i]) != environment()) {
        write("You are hunting "+attacker_list[i]->short()+"\n");
/* this call out would be nice to get rid of...
 * Baldrick
 */
        call_out("check_stop_fight",600,attacker_list[i]);
        if (!call_outed)
          call_outed = ({ attacker_list[i] });
        else
          call_outed += ({ attacker_list[i] });
        attacker_list = delete(attacker_list,i,1);
      } else
        i++;
  }

//dw check the not correct environ list to see if any one has come back.  
  i = 0;
  while (i<sizeof(call_outed))
    if (!call_outed[i])
      call_outed = delete(call_outed,i,1);
    else if (environment() == environment(call_outed[i])) {
      attacker_list += ({ call_outed[i] });
      call_outed = delete(call_outed,i,1);
    } else
      i++;
//dw not hitting anyone... do spell effects anyway... 
  if (!sizeof(attacker_list)) {
// this_object()->do_spell_effects(0);  (dk: ducky moved this to hb)
    attackee = 0;
    return;
  }
//dw choose a random person from the attacker list; they're in correct env.
  if (concentrate)
    attackee = attacker_list[0];
  else
    attackee = attacker_list[random(sizeof(attacker_list))];

//dw Check to see if they are being protected.
//   Should we use a skill here?  Hmm....  To slow probably, will make it
//   a fixed 80% chance for now.  First check to make sure that the
//   protector isnt in the attacker list

  if (protector && member_array(protector, attacker_list) != -1) {
    tell_object(this_object(), protector->query_cap_name()+
                " turns against you and starts fighting you.\n");
    tell_object(protector, "You start fighting "+
                this_object()->query_cap_name()+" and stop protecting "+
                this_object()->query_objective()+".\n");
    say(protector->query_cap_name()+" turns against "+
        this_object()->query_cap_name()+" and starts attacking him.\n",
        ({ protector, this_object() }));
  }
  if ((ob = (object)attackee->query_protector()) &&
    environment(ob) == environment(attackee) && random(100) >= 20) {
    tell_object(attackee, ob->query_cap_name()+
                " valiantly protects you.\n");
    tell_object(ob,"You valiantly protect "+attackee->query_cap_name()+".\n");
    say(ob->query_cap_name()+" valiantly protects "+
        attackee->query_cap_name()+".\n", ({ attackee, ob }));
    attackee = ob;
  }
  his_att_lvl = maxi(({ (int)attackee->query_level(), 1 }) );
  his_name = (string)attackee->query_name();

//dk ducky removed the following line and uses "time effect" in hb instead:
//  if(!this_object()->do_spell_effects(attackee)) {   

  attackee->attack_by(this_object());

//dw   Ok, do the damage to the person we are attacking.  This has already
//dw   been wombled to get the attackee to be the right person (ie being
//dw   protected).

//dk the combat damage needs to be worked out here...not finished yet,
//   cause it needs the guild to define set_weapon_attack_out

//dk so ducky removed this next line too
//  }
 /*
 * Ok, do the damage to the person we are attacking.  This has already
 * been wombled to get the attackee to be the right person (ie being
 * protected).
 *
 * This didn't work at all so I changed it.... -Aragorn
 * Old code:
 * weapon = this_object()->query_held_ob(0);
 * if(weapon && !weapon->query_weapon()){
 * weapon = this_object()->query_held_ob(1);
 * if (!weapon->query_weapon()) weapon ="";
 * }
 */
  weapon = this_object()->query_held_ob(0);
  if(weapon && !weapon->query_weapon())
    {
    weapon = this_object()->query_held_ob(1);
    if (weapon && !weapon->query_weapon()) weapon = 0;
    }

    if (weapon)
      dam = (int)weapon->weapon_attack(attackee,this_object());
    else
      dam = weapon_attack(attackee,this_object());
 /* }
 */
 
  if (!attackee) 
    {
    tell_object(this_object(),"You killed "+his_name+"\n");
    say(this_object()->query_cap_name()+" killed "+his_name+"\n");
    }
  if (!att_level)
    att_level = this_object()->query_level();
     /* Added By Asmodean to stop the fatal error on 0 level players
     When the use the follow adjust_xp line. Division by 0 would always occur
      */
    if (att_level == 0)
       att_level = 1;
  this_object()->adjust_xp(dam*his_att_lvl/att_level);
  event(environment(), "fight_in_progress", attackee);
}

void attack_by(object ob) 
  {
  if (ob == this_object())
    return ;
  if (!attacker_list)
    attacker_list = ({ });
  if (!sizeof(attacker_list)) 
    {
    att_level = (int)this_object()->query_level();
    dodging = (int)this_object()->query_level();
    }
  if (member_array(ob, attacker_list) == -1 &&
      member_array(ob, call_outed) == -1) 
    {
    attacker_list += ({ ob });
    }
  set_heart_beat(1);
}

void attack_ob(object ob) 
  {
  if (ob == this_object())
    return;
  if (!attacker_list)
    attacker_list = ({ });
  if (!sizeof(attacker_list)) 
    {
    att_level = (int)this_object()->query_level();
    dodging = (int)this_object()->query_level();
    }
  if (member_array(ob, attacker_list) == -1 &&
      member_array(ob, call_outed) == -1) 
    {
    attacker_list += ({ ob });
    }
  if (ob)
    ob->attack_by(this_object());
}

void check_stop_fight(object ob) 
  {
  int i;
  if ((i=member_array(ob,call_outed)) != -1)
    call_outed = delete(call_outed,i,1);
}

int stop_fight(object ob) 
  {
  int i;
  if ((i=member_array(ob,call_outed)) != -1) {
    tell_object(this_object(),"You stop hunting "+call_outed[i]->short(0)+
      ".\n");
    call_outed = delete(call_outed, i, 1);
  }
  if ((i=member_array(ob,attacker_list)) != -1)
    attacker_list = delete(attacker_list,i,1);
}

mixed *query_attacker_list() { return attacker_list; }
mixed *query_call_outed() { return call_outed; }


//dw   Sets up protection matrixes.
int do_protect(string str) 
  {
  object *obs, *ok; int i;
  if (!str) 
    {
    notify_fail("Syntax: protect <objects>\n");
    return 0;
    }
  obs = find_match(str, environment());
  if (!sizeof(obs)) 
    {
    notify_fail("Protect what?\n");
    return 0;
    }
//dk added member_array to this next line:
  if (member_array(this_object(), obs))
//dk I changed this next line from this_player() to this_object():
    obs -= ({ this_object() });
  ok = ({ });
  for (i=0; i<sizeof(obs); i++)
    if (obs[i]->set_protector(this_object()))
      ok += ({ obs[i] });
  if (!sizeof(ok)) 
    {
    notify_fail(query_multiple_short(obs)+
      (sizeof(obs)==1?" doesnt":" don't")+" want your protection.\n");
    return 0;
    }
  if (sizeof(obs) != sizeof(ok))
    write("You fail to protect "+query_multiple_short(obs - ok)+".\n");

  write("You protect "+query_multiple_short(ok)+".\n");
  say(this_object()->query_cap_name()+" protects "+query_multiple_short(ok)+
      ".\n", ok);
  for (i=0; i<sizeof(ok); i++)
    tell_object(ok[i], this_object()->query_cap_name()+" protects "+
                query_multiple_short(({ "you" }) + (ok - ok[i..i]))+".\n");
  return 1;
}

mixed stats() 
  {
  int i; object ob; mixed *ret;
  if (ob=this_object()->query_held_ob(0) && ob->query_weapon())
    ret += ({ ({ "Weapon", ob->short() }) }) + (mixed)ob->weapon_stats();
  if (ob=this_object()->query_held_ob(1) && ob->query_weapon())
    ret += ({ ({ "Secondary weapon", ob->short() }) });
  for (i=0; i<sizeof(attack_out); i+=7) 
    ret += ({ ({ "If",    attack_out[i], }), 
              ({ "Rate",  attack_out[i+1], }), 
              ({ "Attack", attack_out[i+2], }), 
              ({ "Tohit", attack_out[i+3], }), 
              ({ "Number of damage dice", attack_out[i+4], }), 
              ({ "Die size", attack_out[i+5], }), 
              ({ "Addend", attack_out[i+6], }), 
          }); 
  return ret;
}
