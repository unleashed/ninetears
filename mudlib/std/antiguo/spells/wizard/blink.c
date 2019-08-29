
/*** Blink ***/
/*** Created by Taniwha 1996 ***/
inherit "/std/spells/base.c";
#define BEAST "/baseobs/monsters/displacer"
#define BLINKROOM "/room/blinkroom"

void setup()
{
  set_spell_name("Blink");
  set_school("wizard-thief");
  set_spell_level(10);
  set_target_type("none");
  set_range(100000);
  set_line_of_sight_needed(0);
  set_help_extras("This spell makes the caster oscillate between "
    "this dimension and another "
    "duration is roughly 20 rounds.\n"
    "Note: Interdimensional travel has risks.\n");
  add_property_to_check("blinked");
  set_casting_time(24);
  set_gp_cost(8);
  set_rounds( ({ "round0","round1","round2","round1","round2","round2","round1","round2",
                 "round1","round2","round1","round2","round2","round1","round1","round2",
                 "round1","round2","round1","round2","round2","round1","round1","round3"
                }) );
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet);


int round0(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if(caster->query_property("blink"))
  {
    tell_object(caster,"Oops, you really screwed up last time didn't you ?\n");
    round2(caster,caster,out_range,time,quiet);
    return 0;
  }
  tell_room(environment(caster),(string)caster->query_cap_name()+" mutters something "
  " and starts to leave without going anywhere.\n",({ caster }) );
  caster->add_timed_property("blinked",1,200);
  return 1;
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int j;
  string room;
  object *atts_list;
  //  check to see if we move them
  if(find_object(BLINKROOM) == environment(caster)) return 1;
  tell_object(caster, "You fade from view.\n");
  atts_list = caster->query_attacker_list();


  caster->add_property("blink",(string)file_name(environment(caster)));
  caster->move(BLINKROOM);
  caster->look_me();
  for (j=0;j<sizeof(atts_list);j++)
    if(atts_list[j])
    {
    caster->stop_fight(atts_list[j]);
    atts_list[j]->stop_fight(caster);
    }

  atts_list = caster->query_call_outed();
  for (j=0;j<sizeof(atts_list);j++)
    if(atts_list[j])
    {
        caster->stop_fight(atts_list[j]);
        atts_list[j]->stop_fight(caster);
    }
  return 1;
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  string room;
  room = (string)caster->query_property("blink");
  if(!room)
  {
//    caster->move("/room/raceroom");
    return 0;
  }
  tell_object(caster, "You reappear.\n");
  caster->move(room);
  tell_room(environment(caster),"Ping!\n");
  caster->look_me();
  return 1;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object beast,victim;
  object *olist;
  string room;
  room = (string)caster->query_property("blink");
  if(!room)
  {
//    caster->move("/room/raceroom");
    return 0;
  }
  if(find_object(room) == environment(caster)) return 1;
  tell_object(caster, "You reappear.\n");
  caster->move(room);
  tell_room(environment(caster),(string)caster->query_cap_name()+" seems to "
  "stabilize at last.\n");
  if(interactive(caster) && !random((int)caster->query_cha()))
  {
    if(stringp(BEAST))
    {
        beast = clone_object(BEAST);
        if(beast)
        {
            olist = all_inventory(environment(caster));
            victim = olist[random(sizeof(olist))];
            beast->move(room);
            if(victim->query_alive())
            {
                if(random((int)victim->query_cha()) > 10)
                {
                    victim->add_follower(beast);
                    beast->do_protect(victim->query_name());
                }
                else victim->attack_by(beast);
            }
            tell_object(caster,"Oops, something seems to have followed you home.!\n");
            tell_room(environment(caster),"Oops something seems to have followed "+
            caster->query_cap_name()+" home!.\n",({caster}));
        }
     }
  }
  caster->look_me();
  caster->remove_property("blink");
  return 1;
}


