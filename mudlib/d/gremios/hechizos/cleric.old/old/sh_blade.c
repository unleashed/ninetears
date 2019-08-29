/* Shadow for flame-blade */

inherit "std/shadow";
static object sh;

void start()
{
 shadow (sh, 1);
 call_out("wear_off", 50, sh);
 sh->add_attack("flame", 0, 100, 100, 0, 0, "burn");
 tell_object(sh, "Your weapon-hand sprouts a flaming blade.\n");
}

query_short()
{
 return "A Flaming Blade";
}

void set_shadowed(object obj)
{
 sh = obj;
}

void wear_off(object me)
{
 remove_call_out("wear_off");
 me->remove_attack("flame");
 tell_object(sh, "The Flame Blade retracts into your hand.\n");
 destruct(this_object());
}

dispel()
{
 tell_object(sh, "Your Flame Blade is Dispelled.\n");
 tell_object(environment(sh), sh->query_cap_name()+"'s Flame Blade is dispelled.\n");
 end();
 return 1;
}