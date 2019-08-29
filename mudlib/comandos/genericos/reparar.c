//Gareth 13.1.03, comando Reparar

string help()
{
    return
	"Nombre del Comando: Reparar\n"
	"Coste en Energia: 10\n"
	"Sintaxis: reparar <objeto>\n"
	"Descripcion:\n"
	"    Este comando te permite reparar "
	"cualquier objeto que tengas y que se"
	" encuentre en mal estado.\n\n";
}

int inicio(string str, object me)
{
   int chance;
   object *list;
   object target;
   if(!me) me = this_player();
   if(sizeof(me->query_attacker_list()))
   {
      notify_fail("Estas demasiado ocupado como para reparar algo ahora.\n");
      return 0;
   }
   if(me->query_ep()<10)
   {
      notify_fail("No tienes suficiente energ�a para reparar ahora, "
      		  "debes descansar un poco.\n");
      return 0;
   }
   list=find_match(str, me);
   if(!sizeof(list))
   {
      return notify_fail("Reparar qu�?\n");
   }
   target=list[0];
   if(target->query_max_cond()==target->query_cond())
   {
   	tell_object(me, target->query_short()+" no necesita reparacion.\n");
   	return 1;
   }
   chance=random(me->query_dex()+me->query_level())+random(me->query_habilidad("reparar"));
   target->adjust_cond(chance/20);
   me->adjust_ep(-10);
   if(chance<20) 
   {
   	tell_object(me, "Por mas que te esfuerzas no logras reparar "+target->query_short()+".\n");
   	return 1;
   }
   tell_object(me,"Reparas tu "+target->query_short()+".\n");
   return 1;
   }