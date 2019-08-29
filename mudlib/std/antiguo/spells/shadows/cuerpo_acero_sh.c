// Paris. Jun'98

#include <spells.h>
#define STEEL_BODY_PROP "Cuerpo de Acero"
#define ARCHIVO "/std/spells/shadows/cuerpo_acero_sh.c"
#define	BONUS	MAX(myplayer->query_sphere("wizwar"),myplayer->query_sphere("wizwar"));

int check_off=0;
object myplayer;

void setshadow(object ob) 
{
  object *obs,*obs2;
  int i;
  
  shadow(ob,1);
  myplayer = ob;
  myplayer->add_extra_look(ARCHIVO);
  
  obs = myplayer->query_worn_ob();
  obs2 = myplayer->query_held_ob();
  for(i=0;i<sizeof(obs);i++)
  {
    tell_object(myplayer,"No puedes llevar nada cuando el efecto del Cuerpo de Acero esta actuando.\n");
    myplayer->unwear_ob(obs[i]);
    
  }
  for(i=0;i<sizeof(obs2);i++)
  {
    tell_object(myplayer,"No puedes llevar nada cuando el efecto del Cuerpo de Acero esta actuando.\n");
    myplayer->unhold_ob(obs2[i]);
  }
       
}

void dispell_me()
{
  myplayer->remove_extra_look(ARCHIVO);
  destruct(TO);
}

int check_duration()
{
  return (myplayer->query_dead() || myplayer->query_timed_property(STEEL_BODY_PROP));
}

void destruct_steel_skin_shadow()
{
  if(!check_duration())
    if(!myplayer->query_dead())
    {
      tell_room(ENV(myplayer),"La piel de "+myplayer->query_cap_name()+" retorna a "
                              "su estado natural.\n",({ myplayer }));
      tell_object(myplayer, "Tu piel retorna a su estado normal.\n");
      myplayer->remove_extra_look(ARCHIVO); 
      destruct(TO);
    }
}

varargs mixed move_player(string dir, string dest, mixed message,object followee, mixed enter )
{
  mixed kk=myplayer->move_player(dir,dest,message,followee,enter);
  if (check_duration()) destruct_steel_skin_shadow();
  return kk;
}

int query_str()
{
  if (check_duration()) return 30;
  else 
  {
    call_out("destruct_steel_skin_shadow",0,0);
    return myplayer->query_str();
  }
}


int query_damage_bonus()
{
  int dados;
  
  dados = roll(2,8)+6;
  if (check_duration()) return dados;
  else 
  {
    call_out("destruct_steel_skin_shadow",0,0);
    return myplayer->query_damage_bonus();
  }
}

int query_total_ac()
{
  int ac=100-myplayer->query_body_ac()-20*BONUS-myplayer->QL*BONUS-myplayer->query_spell_bonus();

  if (check_duration()) call_out("destruct_steel_skin_shadow",0);
  return ac;
}

int query_steel_skin_shadow()
{
  return 1;
}

int do_hold(string boo)
{
  tell_object(myplayer,"No puedes empu�ar nada mientras estes bajo los "
                       "efectos del hechizo Cuerpo de Acero.\n");
  return 0;
}
status hold_ob(object ob)
{
  tell_object(myplayer,"No puedes llevar arma alguna mientras estes bajo el "
                       "efecto del hechizo Cuerpo de Acero.\n");
  return 0;
}

status wear_ob(object ob)
{
    tell_object(myplayer,"No puedes equipar mientras estes bajo los "
                         "efectos del hechizo Cuerpo de Acero.\n");
    return 0;
}    
int query_res()
{
  if (check_duration()) return 30;
  else 
    call_out("destruct_steel_skin_shadow",0,0);
    return myplayer->query_res();
}

string extra_look()
{
  return "Su cuerpo esta convertido en acero.\n";
}
