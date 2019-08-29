
/*** Stone shadow ***/
/*** By Taniwha ***/
#include "tweaks.h"

object my_player;
void dispell_me();
void attack_ob(object ob)
{
}
void add_protector(object ob)
{
}
void add_protecting(object ob)
{
}
void do_protect(string str)
{
notify_fail("You can't protect anyone while stoned!\n");
return 0;
}
void destruct_stone_shadow()
{
  destruct(this_object());
}
void setup_shadow(object ob) 
{
  if(!ob->query_stone_spell())
  {
    shadow(ob,1);
    my_player = ob;
      my_player->add_static_property("pacify_on",1);
      my_player->add_static_property("nocast",1);
      my_player->add_static_property("noguild",1);
  }
  else destruct_stone_shadow();
}

varargs mixed move_player(string dir, string dest, mixed message, object
				followee, mixed enter)
{
   if(!my_player->query_property("stoned")) dispell_me();
    if(!random(20))
    {
        tell_object(my_player,"You struggle and manage to move.\n");
        return my_player->move_player(dir, dest, message, followee, enter);
    }
   tell_object(my_player,"You set your will against the stone and a l m o s t move, maybe with a bit more effort.....\n");
    return 1;
}
string query_short()
{
    return "A statue of "+my_player->query_short();
}

int query_stone_spell() { return 1; }
int unarmed_attack(object him,object me)
{
    return 0;
}
int weapon_attack(object him, object me)
{
   return 0;
}
int query_gender() { return 0; }

string long(int dark)
{
    return "This seems to be a lifelike statue of "+ my_player->long(dark);
}
int adjust_hp(int hp, object doer)
{
     if(hp < 0) return my_player->adjust_hp(hp/20,doer);
     else return my_player->adjust_hp(hp/5,doer);
}
void attack_by(object ob)
{
   if(ob)
   {
      ob->stop_fight(this_object());
      ob->stop_fight(my_player);
      my_player->stop_fight(ob);
   }
}

/* for an eventual dispel magic spell */
void dispell_me()
{
  int i;
  object *olist;
   if(my_player)
   {
      my_player->remove_static_property("pacify_on");
      my_player->remove_static_property("noguild");
      my_player->remove_static_property("nocast");
  olist=all_inventory(my_player);
  for(i = 0; i < sizeof(olist);i++)
  {
    if(olist[i] && olist[i]->query_name() == "stoned")
    {
        olist[i]->dest_me();
    }
  }
  tell_object(my_player,
    "Flakes of stone fall from you as your flesh softens once again.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
    " slowly softens and turns back into flesh.\n",
    my_player);
   }

  destruct(this_object());
}



