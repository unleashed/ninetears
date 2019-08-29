#define MULT 3
/* Pagan and Taniwha, 1996, basic trap spell, all other evil is derived from 
   this 
*/
inherit "/d/gremios/hechizos/base.c";
#define TRAP_GP 15
#define TRAP_LOCKOUT 100
#define SPELLS "/d/gremios/hechizos/"

#define LOCKOUT "trap"
int OK; // NOT nice *sigh*
string item;
string trap = "/d/gremios/hechizos/wizard/maj_missile";
string trap_desc = "Una pequenya caja, cubierta de curiosas runas.\n";
int trap_target;

void setup()
{
    set_spell_name("Trampa");
    set_school("Wizthief");
    set_spell_level(30);

    set_target_type("none");
    set_range(0);
    set_line_of_sight_needed(0);
    set_gp_cost(5);

    add_property_to_check(LOCKOUT);

    set_help_desc("This spell will set a magical trap.  Since whoever "
      "created it hasn't set it up properly, maybe you'd better mention it to the gods.\n");

    set_help_extras("Note: The GP cost of this spell doesn't include the cost "
      "of the spell being \"trapped\", that will also be deducted.\n");

    set_casting_time(2);
    set_rounds( ({ "round1","round2" }) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
	object *list;
   OK = 0;
	if(stringp(item))
	{
                list = find_match(item,caster);
		if(!sizeof(list))
		{
			tell_object(caster,"You don't have the "+item+
			" needed to contain the spell.\n");
			tell_room(environment(caster),caster->query_cap_name()+
			" looks a little puzzled for a few seconds.\n");
   OK = -1;
                        return 0;
		}
                list[0]->move(environment(caster));
		list[0]->dest_me();
		tell_object(caster,"The "+item+" begins to fade as it becomes "
		"infused with power.\n");
			
        }
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
    object ob;
   if(OK == -1) return 0;

    if ( !quiet )
    {
	tell_object(caster, "You chant 'entrapous snarium'.\n");
	if(!this_object()->query_hide_shadow())
	{
	    tell_room(environment(caster),(string)caster->query_cap_name()+
	      " chants, 'entrapous snarium'.\n", ({caster}));
	}
    }

    caster->add_timed_property(LOCKOUT,1,TRAP_LOCKOUT);
    caster->add_timed_property("trap_aware",1,100);
    ob = clone_object("/d/gremios/hechizos/trap.c");
    ob->move(environment(caster));
//   ob->set_trap(trap,trap_target,300,500,trap_desc);
    ob->set_trap(trap,trap_target,MULT * caster->query_int()+caster->query_level(),
      500,trap_desc); 
    tell_object(caster, "You set a magical trap in the shadows.\n");
    if(!this_object()->query_hide_shadow())
    {
	tell_room(environment(caster),
	  (string)caster->query_cap_name()+" sets a trap "
	  "in the shadows.\n",({caster}));
    }
}

