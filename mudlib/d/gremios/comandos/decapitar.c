//Gareth 15.12.02
//Decapitar, para los Khurgars

#define HEAD "/d/gremios/comandos/cabeza.c"
#define EP_COST 20 - me->query_habilidad("decapitar") / 8

string help()
{
    return
	"Nombre del Comando: Decapitar\n"
	"Coste en Energia: Variable\n"
	"Sintaxis: decapitar cuerpo\n"
	"Descripcion:\n"
	"    Este comando te permite decapitar "
	"cualquier cadaver, pudiendo guardar la"
	" cabeza para conservarla como trofeo, "
	"o depositarla en la Sala de Trofeos de"
	"l gremio Khurgar.\n\n";
}

int inicio(string str,object x) {
    object me;
    mixed ob;
    object* weap;
    int noweap;
    object head;
	
    if(x) me = x;
    else me = this_player();
	
    if(!str || str == "") str = "cuerpo";
	
    if(me->query_dead())
  {
      return notify_fail("Eres un espiritu, no puedes decapitar a nadie.\n");
  } 

       if (ob==me)
  {
      return notify_fail("Eso no es una buena idea\n");
  }
   
   
    if ( me->adjust_ep(-EP_COST) < 0 ) 
  {
      return notify_fail("Te encuentras demasiado cansado como para decapitar a alguien.\n");
  }  
 
    noweap=1;
    
    weap = me->query_held_ob();
    if ( weap[0] && (int)weap[0]->query_attack_type() != 2 ) noweap=0;
    else if ( weap[1] && (int)weap[1]->query_attack_type() != 2 ) noweap=0;
    
    if ( noweap )
  {
      return notify_fail("Seria dificil decapitar a alguien sin un arma cortante.\n");
  }
  
    
    ob = find_match(str, environment(me));
    if ( sizeof(ob) != 1 )
  {
      return notify_fail("Que quieres decapitar?\n");
  }
  
    ob = ob[0];
    
    if(living(ob))
  {
      return notify_fail(ob->query_cap_name()+" esta vivo, no puedes decapitarlo.\n");
  }
  

    if (!ob->query_corpse())
  {
      return notify_fail("No puedes decapitar eso!!\n");
  }
  
   
    if (ob->query_property("decapitado"))
  {
      return notify_fail("Este cuerpo ya ha sido decapitado por alguien.\n");
  }


    tell_object(me, "Arrancas la cabeza de el "+ob->short()+".\n");
    tell_room(environment(me), me->query_cap_name()+" arranca la cabeza "
      "del "+ob->short()+".\n", me);

    ob->add_property("decapitado",1);
    ob->set_long(ob->query_long()+"\nParece que alguien le ha arrancado "
    				    "la cabeza.\n");

    head = clone_object(HEAD);
    head->set_head_name(ob->query_owner());
    head->add_property("owner", ob->query_owner());
    head->move(environment(me));
    return 1;
  }