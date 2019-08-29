/*** temp shadow for Spirit Armour spell ***/
/* extra look wasnt being removed after it expired, i think i fixed it =)
				Shaper, 14/IX/96   */

#include "tweaks.h"

int check_off=0;
object my_player;

void setshadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
}

void destruct_spirit_armour_shadow()
{
  destruct(this_object());
}

int check_duration()
{
  if ( my_player->query_property(SPIRIT_ARMOUR_PROPERTY) )
    return 0;

  if(!check_off)
  {
    if ( (string)my_player->query_guild_name() != "necromancer" )
    {
      my_player->adjust_hp(-random(4)-random(4)-2,my_player);
      tell_object(my_player, "%^RED%^You are wracked with pain as your "
        "spirit armour burns away.%^RESET%^\n");
      tell_room(environment(my_player), my_player->query_cap_name()+
        " is wracked with pain as the surrounding mist disappears.\n", 
        my_player);
    }
    tell_object(my_player, "Your spirit armour fades away.\n");
    my_player->remove_extra_look(load_object("/d/gremios/hechizos/wizard/sp_armour"));
    check_off=1;
  }
  return 1;
}

varargs mixed move_player(string dir, string dest, mixed message,
                  object followee, mixed enter )
{
  if ( check_duration() )
	call_out("destruct_spirit_armour_shadow",0,0);
  return my_player->move_player(dir,dest,message,followee,enter);
}

status wear_ob(object ob)
{
  tell_object(my_player,
    "You have no need of material protection with your spirit "
    "to protect you.\n");
  if (check_duration()) 
    destruct_spirit_armour_shadow();
}
 
int do_wear(string str)
{
  tell_object(my_player,
    "You have no need of material protections with your spirit "
    "to protect you.\n");
  if (check_duration()) 
    destruct_spirit_armour_shadow();
  return 1;
}

int query_total_ac()
{
  int i;

  if ( !check_duration() )
    {
      i = ( (int)my_player->query_total_ac() - (SPIRIT_ARMOUR_BASE
        +( (5+(int)my_player->query_level())*SPIRIT_ARMOUR_LEVEL_MOD)) );
      if(i < -100) i = -100;
      return i;
    }
  else 
  {
    call_out("destruct_spirit_armour_shadow",0,0);
    return (my_player->query_total_ac());
  }
}

int query_spirit_armour_spell() { return 1; }

