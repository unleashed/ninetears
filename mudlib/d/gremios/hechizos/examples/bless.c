/*** Bless Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Cleanup by Wonderflug ***/

inherit "/d/gremios/hechizos/base.c";

void setup()
{
    set_spell_name("Bless");
    set_sphere("all");
    set_spell_level(1);

    set_target_type("one");
    set_range(0);
    set_line_of_sight_needed(0);

    set_help_desc("This spell grants the target a +1 to hit in battle for "
      "a limited duration.");

    set_gp_cost(2);
    set_casting_time(1);
    set_rounds( ({ "round1" }) );
   allow_on_ghosts(1);
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
    int resist_value;
    int level, duration;
    string deity;

    if ( wrong_alignment(caster) )
    {
        punish_align(caster);
        return 0;
    }

    if (!target)
    {
        tell_object(caster,
          "Your spell failed ... there is no one of that name here.\n");
        return -1;
    }

    if (target->query_property("bless_on"))
    {
        tell_object(caster,
          "The target is already under the effects of a Bless.\n");
        return -1;
    }

    if ( !quiet )
    {
        tell_room(environment(caster),(string)caster->query_cap_name()+
          " chants, 'bleiso umanos'.\n", ({target,caster}));
        tell_object(target, "You chant, 'bleiso umanos'.\n");
    }

    if(target == caster)
    {
        tell_object(caster, "You cast Bless upon yourself.\n");
        tell_room(environment(caster),(string)caster->query_cap_name()+
          " casts a spell upon "+caster->query_objective()+"self.\n",caster);
    }
    else
    {
        tell_object(target, (string)caster->query_cap_name()+
          " kneels over you and Blesses you.\n");

        tell_object(caster, "You kneel over "+
          (string)target->query_cap_name() + " and bless "+
          target->query_objective()+".\n");

        tell_room(environment(caster),(string)caster->query_cap_name()+
          " kneels over "+target->query_cap_name()+" chanting softly.\n",
          ({target,caster}) );
    }

    switch ( caster->query_sphere_power("all") )
    {
    case "minor": 
        level = 5; 
        break;
    case "major": 
        level = 15; 
        break; 
    default: 
        level = 10;
    }

    target->adjust_tmp_tohit_bon(level);
    target->add_static_property("bless_on", 1);
    duration = 100+((int)caster->query_level()*10);
    deity = caster->query_deity();
    target->add_timed_property(deity+"bless", 1, duration);

    call_out("wear_off", duration, target, level);
    return 0;
}

void wear_off(object target, int level)
{
    if(target)
    {
        target->adjust_tmp_tohit_bon(-level);
        target->destruct_bless_shadow();
        target->remove_static_property("bless_on");
tell_object(target, "%^BOLD%^Your blessing wears off.\n");
    }
}
