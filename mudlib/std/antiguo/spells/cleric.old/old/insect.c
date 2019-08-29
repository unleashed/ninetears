#define MIN_LVL 40
#define GP_COST 200

mixed spell(string str, int skill, int cast);
void attack(object devil);

int cast_spell(string str)
{
 int skill;
 mixed ret;

 str = (string)this_player()->expand_nickname(str);

 skill = (int)this_player()->query_skill_bonus("faith.spells.offensive.target");

 if (skill < MIN_LVL)
 {
  notify_fail("You are not skilled enough to cast Insect Plague.\n");
  return 0;
 }

 ret = spell(str, skill, 1);
 if (stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write("You begin your summoning.\n");
 return 1;
}

mixed spell(string str, int skill, int cast)
{
 mixed ob;
 if ((int) this_player()->query_spell_effect("offensive"))
  return "You are already casting an offensive spell.\n";

 ob = find_match(str, environment(this_player()));

 if(sizeof(ob))
  ob = ob[0];

 else
  ob = 0;

 this_player()->add_spell_effect(1, "offensive", "Insect Plague", this_object(),
  "hb_spell", ({ skill,ob,cast }));

 return 1;
}

int hb_spell(object caster, mixed *params)
{
 int skill, light;
 mixed who;
 object devil;
 skill = params[0];

 if(!params[1])
 {
  tell_object(previous_object(), "Your insect swarm disperses, failing to "
   "find its intended target.\n");
  return 0;
 }

 if(params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Not enough GP too complete spell.\n");
  return 0;
 }

 if (params[1] == previous_object())
 {
  tell_object(previous_object(),"The insect swarm buzzes towards you.\n");
  say((string)previous_object()->query_cap_name() +
   " mumbles some strange words, and is attacked by a swarm of little insects.\n", params[1]);
 }

 else
 {
  tell_object(previous_object(),"You cast Insect Plague on "+
   (string)params[1]->query_cap_name()+".\n");
  say((string)previous_object()->query_cap_name()+ " mumbles something and a "
   "swarm of insect buzzes towards "+(string)params[1]->query_cap_name()+".\n",
    params[1]);
  tell_object(params[1], (string)previous_object()->query_cap_name()+
   " mumles something and you are attacked by a swarm of insects.\n");
 }

 devil = clone_object("/std/spells/cleric/insect_obj");
 devil->move(environment(params[1]));
 tell_room(environment(devil), "A "+devil->query_short()+
  " quickly gathers in the room.\n");
 call_out("attack", 5, ({params[1], devil}));

 return 200;
}

void attack(mixed *params)
{
 params[1]->attack_ob(params[0]);
 params[1]->set_target(params[0]);
}
