// Taniwha 1995. Odds of stealing an item, and the XP for it.
// Factors to consider. Weight loss on victim.
// Value
// Relative level and dex
// For XP calcs. Take relative level, weight and value into account
//
// Cleanup by Wonderflug
// Also redid success calcs.

#include "tweaks.h"
#define CAUGHT "caught_stealing"
#define STOLEN "stolen"
#define VMOD 1000 // XP divider on value

int steal_succeed(object me, object her,object it)
{
  int base_chance, mult, chance;
  int v, xp;
  float ratio;

  if(it->query_property("stolen")) 
    return 1;
  if(it->query_property("nosteal")) 
    return 0;
  if ( her->query_property("steal at will") )
    return 1;

  if ( me->query_guild_name() == "Ladron" )
    mult = 2;
  else
    mult = 4/3;

  base_chance = 20 + me->query_level()*mult + me->query_dex();
  base_chance -= her->query_level();
  if ( me->query_hide_shadow() )
    base_chance += 10;
  base_chance = ( base_chance > 95 ? 95 : base_chance );
 
  // The amount that the container gets adjusted by removing the item
  // should be taken into account.  RELATIVE amount, not absolute.
  // I use environment(it) to allow stealing from containers in the future.
  ratio = it->query_weight() + 0.0;
  if ( ratio > 0 )
    ratio /= environment(it)->query_loc_weight();
  // Smaller ratios increase chance, larger lower chance
  // We allow 0.05 adjustment to be no penalty, and max penalty is
  // is 75%
  ratio = 1.05 - ratio;
  ratio = ( ratio < 0.25 ? 0.25 : ( ratio > 1.0 ? 1.0 : ratio ));

  // Minimum 10% chance always
  chance = base_chance * ratio;
  chance = ( chance < 10 ? 10 : chance );

  if ( me->query_creator() )
    write("Base base: "+base_chance+"\nRatio: "+ratio+"\n"
      "Adjusted chance: "+chance+"\n");

  // The roll, anticlimactic isn't it?
  if ( random(100) > chance )
    return 0;

  // They succeeded, calculate some xp to give them.
  v = it->query_value()/VMOD;
  xp = (v*(100-chance));
  xp += 1;

  if(xp > 150) 
    xp = 50+random(150);
  xp *= ((her->query_level() - me->query_level())/3);
  if(xp <= 0) 
    xp = 1;
  if( xp > (100* her->query_level())) 
    xp = 100* her->query_level();
  if(me->query_creator()) 
    write("Xp = "+xp+".\n");

  return xp;
}

void fail(object me,object who, int cost);

int steal(string str,object thief)
{
  object me,*vat,*hoo;
  int cost, vic_lev,diff, thief_lev,xp;
  int i,v;
  string what, who;
  mixed thwap;

  if(thief) 
    me = thief;
  else 
    me = this_player();

  str = me->expand_nickname(str);

  if (me->query_level()<=2) 
  {
    tell_object(me,"Tienes que ser nivel 2 para poder robar!.\n");
    return 1;
  }

  if(me->query_dead())
  {
    tell_object(me,"Un muerto que roba? donde se ha visto eso?.\n");
    return 1;
  }
  notify_fail("Uso: robar <objeto> a <persona/monstruo>.\n");
  if (!str)
    return 0;
  if (sscanf(str,"%s a %s",what,who)!=2)
    return 0;

  /* Checks on me */
  if( (int)me->query_property(CAUGHT) == 1 )
  {
    tell_object(me,"Aun te tiemblan las manos de la excitacion de la "
      "ultima vez que te pillaron.\n");
    return 1;
  }
  if( (int)me->query_property(CAUGHT) == 2 )
  {
    tell_object(me,"Estas tan intranquilo de la ultima vez que no puedes "
      "volver a robar aun.\n");
    return 1;
  }

  /* Checks on him */
  hoo=find_match(who,environment(me));
  if (!sizeof(hoo))
  {
    tell_object(me,"No puedes ver a "+who+" aqui.\n");
    return 1;
  }
  if(!living(hoo[0]) || hoo[0]->query_dead())
  {
    tell_object(me,"Eso no esta vivo.\n");
    return 1;
  }
  if ( hoo[0] == me )
  {
    tell_object(me, "Intentas robarte a ti mismo, pero eres tan malo que "
      "te das cuenta.\n");
    return 1;
  }
  if (hoo[0]->query_creator()) /* are we currently in a creator char :)*/
  {
    tell_object(me,"No te gustaria que el inmortal se diese cuenta verdad?\n");
    return 1;
  }
  if ( environment(hoo[0])->query_property("nosteal") )
  {
    tell_object(me,"Hay un lugar y un momento para robar y tu instinto te "
      "dice que este no es el momento ni lugar adecuado.\n");
    return 1;
  }
  if ( hoo[0]->query_property("nosteal") )
  {
    tell_object(me, "Esta bastante alerta ahora mismo, intentalo "
      "despues.\n");
    return 1;
  }
  if( sizeof(me->query_attacker_list()) || 
      (member_array(me,hoo[0]->query_attacker_list()) != -1))
  {
    tell_object(me,"Imposible robarle a alguien mientras luchas.\n");
    return 1;
  }

  /* Checks on it */
  vat=find_match(what,hoo[0]);
  if (!sizeof(vat))
  {
    tell_object(me,"No puedes encontrar "+what+" en "+capitalize(who)+".\n");
    return 1;
  }
  if (vat[0]->query_in_use())
  {
    tell_object(me,"No puedes robar equipo que se este usando.\n");
    return 1;
  }
  vic_lev=(int)hoo[0]->query_level();
  thief_lev = me->query_level() + me->query_dex();
  diff=vic_lev-thief_lev;
  if (diff<1) diff=2;
  cost = ((STEAL_COST * diff)/10)+3;
  if ((int)me->query_gp() < cost)
  {
    tell_object(me,"No tienes ganas de robar ahora.\n");
    return 1;
  }

  // Stealing Objects, risk /XP based on weight
  if ((string)vat[0]->query_name() != "monedas")
  {
    if( !(xp = steal_succeed(me,hoo[0],vat[0])))
    {
      fail(me,hoo[0],cost);
      return 1;
    }
    if ( vat[0]->move(me) )
    {
      tell_object(me, "Hmm, no puedes robar eso por alguna razon.\n");
      return 1;
    }
    tell_object(me,"Robas "+vat[0]->short()+" a "
      +hoo[0]->query_cap_name()+".\n");
    vat[0]->add_property(STOLEN,1);
    me->adjust_xp(xp);
    me->adjust_gp(-cost);
    return 1;
  }

  // Stealing coins
  if ( !(hoo[0]->query_property("steal at will")) )
  {
    if(random((int)me->query_level()+(int)me->query_dex())  <
       random((int)hoo[0]->query_level() + diff) )
    {
        fail(me,hoo[0], cost);
        return 1;
    }
  }

  /* Here is the code for stealing money, not easy to implement a good
   * method for this. But the one here now doesen't work.. trying to fix it.
   * Baldrick oct '94.
   * Taniwha 1995, they can steal their level in coins 
   */
  thwap = (mixed)hoo[0]->query_money_array();

  diff = random(thief_lev)+2;
  if(me->query_guild_name() != "Ladron") 
    diff /= 2;
  if(!sizeof(thwap))
  {
    tell_object(me,"Hmm esta en banca rota, nada mas que teleranyas, bien, "
      "vive y aprende.\n");
    me->adjust_gp(-cost);
    return 1;
  }
  tell_object(me,"Robas ");
  for(i = sizeof(thwap) -1;diff > 0 && i > 0; i -= 2)
  {
    v = random(diff);
    if( v > thwap[i] ) 
      v = thwap[i];
    if(v)
    {
      me->adjust_money(v,thwap[i-1]);
      tell_object(me,sprintf("%i %s, ",v,thwap[i-1]));
      hoo[0]->adjust_money(-v,thwap[i-1]);
      diff -= v;
    }
  }
  tell_object(me,"monedas.\n");
  me->adjust_gp(-cost);
  return 1;
}

void fail(object me,object who, int cost)
{
  string bing, sme;
  int ldiff;
  bing=(string)who->query_cap_name();
  sme=(string)me->query_cap_name();

  tell_object(me,"Oh Dios , "+bing+
    " parece que se ha dado cuenta de tus actividades.\n");
  tell_object(who,"De repente notas a "+sme+
    " hurgar en tu equipo.\n");
  tell_room(environment(me),sme+" tiene un momento embarazoso "
    "al ser pillado. "+bing+" no parece muy contento.\n",
    ({who,me}));

  who->add_timed_property("nosteal",1,100);
  if( !me->query_creator() ) // Taniwha, so I don't waste time testing this
  {
    ldiff = (int)who->query_level() - (int)me->query_level();
    if (!interactive(who))
      who->attack_by(me);  /*  mean and nasty :) */
    else  /* since players won't auto-attack */
    {
      if(ldiff > 0) 
        me->add_timed_property(CAUGHT,1,ldiff * CAUGHT_LOCK);
      else if(ldiff < 0) 
        me->add_timed_property(CAUGHT,2, -(ldiff * CAUGHT_LOCK));
    }
  }
  me->adjust_gp(- ((cost/3)+1));
}

string help()
{
  return 
    "\n\nSintaxis: robar <objeto> a <objeto>\n"
    "Coste en PG: variable, dependiendo del nivel de la victima y el"
    "ladron.\n"
    "Descripcion:\n"
    "     Este comando te permite robar un objeto a un player o npc "
    ". Estar escondido ayuda, que funcione, depende de tu nivel, "
    "y el de la victima, y tambien del peso del objeto que este intetando "
    "robar.  En los objetos mas preciosos ganaras PE (no incluye monedas)\n";
}
