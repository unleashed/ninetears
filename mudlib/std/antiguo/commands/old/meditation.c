/* Meditation by Greymist */
#define TRANCE "/d/gremios/comandos/meditation_sh.c"

string help()
{
  return
        "\n\n"
        "Ability Name:  Meditation \n\n"
        "Command: Meditate"
        "\n\n"
        "  This powerful talent allows the disciple to "
        "focus the body and mind toward restoration of their "
        "full potential.  The disciple must concentrate, and "
        "destractions will cause them to break out of their "
        "trance, shattering the focus.\n\n";
}


int meditate(string str)
{
  object ob;
  object *stuff;
  int c;
  object disc = this_player();
  object env=environment(disc);

  if ( disc->query_trance() )
  {
    tell_object(disc, "You come out of your meditative trance.\n");
    tell_room(env, disc->query_cap_name()+" comes out of a meditative trance and stands up.\n",
      disc );
    disc->dest_trance();
    return 1;
  }

  if ( env->query_property("noregen") )
  {
    notify_fail("For some reason you cannot attain the meditative state "
      "here.\n");
    return 0;
  }
  if ( sizeof( disc->query_attacker_list() ) ||
       sizeof( disc->query_call_outed() ) )
  {
    tell_object(disc,"You cannot meditate in the middle of a fight!\n");
    return 1;
  }                
   if((disc->query_property("meditation-good"))>2)
    {
    if(!env->query_outside()||(env->query_light())<80)
     {
     tell_object(disc,"You can only achieve the proper mindset in a "
          "place with good chi.  Sunlight might be helpfull.\n");
     return 1;
     }
    }
   if((disc->query_property("meditation-evil"))>2)
    {
    if(env->query_outside()||(env->query_light())>30)
     {
     tell_object(disc,"You can only achieve the proper mindset in a "
          "place with evil chi.  Somewhere dark and dank would be "
	  "ideal.\n");
     return 1;
     }
    }
  tell_object(disc, "You chant 'mindus es magnificus' and enter a "
	"trance.\n\n");
  tell_room(environment(disc),(string)disc->query_cap_name()+
        " chants, 'mindus es magnificus' and "
	"enters a trance.\n\n", ({ disc }));

  stuff=all_inventory(disc);
  for(c=0;c<sizeof(stuff);c++)
  {
  string nme=stuff[c]->query_name();
  if(nme=="meditation_obj")
   return 1;
  }
         ob = clone_object(TRANCE);
         ob->setup_shadow(disc);

  return 1;
}                 
