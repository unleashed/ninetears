/* BERSERK O RABIA deben tener una forma de que las stats queden
   modificadas (bug demostrado en pusa con newbies de lvl 5 metiendo
   pinyos de mas de 100 pvs sin estar siquiera en bk). */

/* 1er bug. Al salir el flipped no se va. Deberia ser static. */
/* 2o bug. Al morir no se quita el aumento de danyo etc etc,
   por lo que podemos estar en bk3 sin atacar a all y empezar */

/*  Adapted from the original Berserk command, coded by Timion.
 *  Marauder, 11/14/95/
 */
#include "tweaks.h"
#define LOCK_PROP "flipped"
void attack_all(object ob);
int allow_attack(object who, object me);


int berserk(string str,object x)
{
   object me; 
   int BONUS, i;
   int ACBONUS;
   int COUNT;
   int TIME;
   if(x) me = x;
   else me = this_player();

   COUNT = me->query_property(LOCK_PROP);
   if(me->query_gp() <= 1)
   {
    tell_object(me,"Te encuentras demasiado cansado.\n");
    return 1;
   }
   switch(COUNT)
   {
   case 0:
       BONUS=((int)me->query_level()/3)+1;
    ACBONUS = (BONUS - ((me->query_dex())/3));
    me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
      me->adjust_tmp_damage_bon(BONUS);
      me->adjust_tmp_tohit_bon(BONUS*2);
      me->adjust_tmp_ac_bon(-ACBONUS);
if(me->query_gp() >= 25)
  {
   me->adjust_gp(-25);
   TIME = 25;
  }
else {
  TIME = me->query_gp();
   me->adjust_gp(-TIME);
 }
      me->add_timed_property(LOCK_PROP,1,TIME);
      attack_all(me);
   break;
   case 1:
   if((me->query_gp()) >= 50)
   {
       BONUS=((int)me->query_level()/2)+2;
    ACBONUS = (BONUS - ((me->query_dex())/2));
    me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
       me->adjust_gp(-50);
       me->adjust_tmp_damage_bon(BONUS);
       me->adjust_tmp_tohit_bon((int)BONUS*2);
       me->adjust_tmp_ac_bon(-ACBONUS);
       me->add_timed_property(LOCK_PROP,2,40);
    }
    else tell_object(me,"Estas demasiado cansado como para enfurecerte mas.\n");
    break;
    case 2:
    if((me->query_gp()) >= 100)
    {
        BONUS=((int)me->query_level()/1.75)+5;
     ACBONUS = (BONUS - (me->query_dex()) );
    me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
        me->adjust_gp(-100);
        me->adjust_tmp_damage_bon(BONUS);
        me->adjust_tmp_tohit_bon(BONUS*2);
        me->adjust_tmp_ac_bon(-ACBONUS);
        me->add_timed_property(LOCK_PROP,3,100);
     write("\nPierdes completamente el control, atacando incluso a tus amigos."
      "\n\n");
     tell_room(environment(me),"\n"+me->query_cap_name()+" pierde "+
      "totalmente el control.  %^BOLD%^%^RED%^Deberias irte rapido.%^RESET%^"
      "\n\n",me);
    }
    else tell_object(me,"Careces de la fuerza necesaria para enfurecerte mas.\n");
    break;
    default:
        tell_object(me,"Estas completa y totalmente enfurecido! Tu cuerpo "
         "no da mas de si.\n");
    break;
    }
    return 1;
}
int allow_attack(object who, object me)
{
     if(who == me) return 0;
//     tell_object(me,"checking "+(string)who->query_cap_name()+" ");
     if(!who->query_alive() ) return 0;
//     tell_object(me,"alive ");
     if((int)me->query_property(LOCK_PROP) == 0 ) return 0;
//     tell_object(me,"I'm berserked ");
    if(who->query_property("no_guild")) return 1;
     if(who->query_pacify_spell()) return 0;
//     tell_object(me,"not pacified ");
     if(who->query_invis()) return 0;
//     tell_object(me,"not invis ");
     if( (int)who->query_hide_shadow() > ((int)me->query_level()/2 + (int)me->query_int()) ) return 0;
//     tell_object(me,"and not hidden, kill it ");
     if((int)me->query_property(LOCK_PROP) == 3 ) return 1;
// If you are frothing, even the people you protect get it.
     if(who->query_protector() == me) return 0;
//     tell_object(me,"not being protected ");
     return 1;
}

attack_all(object ob)
{
  object *cows;
  object *guards;
  int y;
  int x;
  int COUNT;

   if(!ob) return;

   ob->set_wimpy(0);

   if((int)environment(ob)->query_property("noguild")) return;
   if((ob->query_dead())) return;
 
   cows=all_inventory(environment(ob));
 
   for(x=0; x <sizeof(cows); x++)
   {
        if(allow_attack(cows[x],ob)) ob->attack_ob(cows[x]);
   }
   COUNT = ob->query_property(LOCK_PROP);
   if(ob->query_attacker_list())
   {
       switch(COUNT)
       {
       default:
            end_berserk(ob);
            return;
       break;
       case 1:
            tell_room(environment(ob),ob->query_cap_name()+" hacks and flails "
            "about in an incredible rage.\n",ob);
            tell_object(ob,"You go berserk, hacking and flailing at everything "
            "that moves.\n");
        break;
        case 2:
            tell_room(environment(ob),ob->query_cap_name()+" attacks "
            "everything in a red rage, doing incredible damage.\n",ob);
            tell_object(ob,"You are in a red rage, and do massive damage to "
            "those around you.\n");
        break;
        case 3:
            tell_room(environment(ob),ob->query_cap_name()+" is foaming at the "
            "mouth in an unstoppable Berserker rage.\n",ob);
            tell_object(ob,"You wreak havok on everything in your path, as the "
            "rage overcomes you.\n");
        break;
        }
    }
    call_out("attack_all",5,ob);
}
 
end_berserk(object ob)
{
    tell_object(ob,"You become exhausted and are no longer berserk.\n");

    ob->adjust_tmp_ac_bon(-(ob->query_tmp_ac_bon()));
    ob->adjust_tmp_damage_bon(-(ob->query_tmp_damage_bon()));
    ob->adjust_tmp_tohit_bon(-(ob->query_tmp_tohit_bon()));
    if((int)ob->query_con() > 1) ob->adjust_tmp_con(-1);
    ob->remove_timed_property(LOCK_PROP);
}
 
