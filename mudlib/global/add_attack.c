// parece q este add_attack no es para armas sino para monstruos.

// Vilat - Vale, supongamos ke es de monstruos... ningun npc lo carga :S

#include "weapon.h"

mixed attack_name,
      attack_data;
nosave string skill;

void create() 
{
  attack_name = ({ });
  attack_data = ({ });
}

int add_attack(string name, mixed flag, int chance, mixed base,
               mixed hit, mixed dam, string type)
{
/* Checks whether an attack with that name already exists */
  if (member_array(name, attack_name) != -1)
    return 0;
  attack_name += ({ name });
  attack_data += ({ flag, chance, base, hit, dam, type });
}

mixed query_attack_name() { return attack_name; }
mixed query_attack_data() { return attack_data; }

void set_weap_skill(string str) { skill = str; }
string query_weap_skill() { return skill; }

int add_arr_attack(string name, mixed *arr) {
  int i;
  if (!pointerp(arr) || sizeof(arr) != W_ARRAY_SIZE)
    return 0;
  if ((i=member_array(name, attack_name)) != -1) {
    attack_data = attack_data[0..i*W_ARRAY_SIZE-1] +
                  arr+attack_data[(i+1)*W_ARRAY_SIZE+1..sizeof(attack_data)];
    return 1;
  }
  attack_name += ({ name });
  attack_data += arr;
  return 1;
}

void remove_attack(string name) {
  int i;

  if ((i=member_array(name, attack_name)) == -1)
    return ;

  attack_name = delete(attack_name, i, 1);
  attack_data = delete(attack_data, i*W_ARRAY_SIZE, W_ARRAY_SIZE);
}

int calc_value(mixed arg, int skill, string name) {
  int i, amt;

  if (intp(arg))
    return (int)this_object()->modify_damage((random(arg)*(100+skill))/300,
                                                 name);
  if (!pointerp(arg))
    return 0;
  switch (sizeof(arg)) {
    case 1:
      return (int)this_object()->modify_damage(arg[F_FIXED], name);
    case 2:
      return (int)this_object()->modify_damage(arg[F_FIXED]+
                            ((random(arg[F_RAND])*(100+skill))/300), name);
    case 3:
      for (i=0;i<arg[F_NUM];i++)
        amt += random(arg[F_DIE]);
      return (int)this_object()->modify_damage(arg[F_FIXED]+((amt*
                                 (100+skill))/300),
                                                      name);
    default :
      return 0;
  }
}

static object target, me;

void do_attack(int name) {
  int i, off, hit, base, ac, skill_val;
  string our_name;

  our_name = attack_name[name];
  off = name*W_ARRAY_SIZE;
  if (skill)
    skill_val = (int)me->query_skill_bonus(skill);
  else
    skill_val = 50;
  base = calc_value(attack_data[off+W_BASE], skill_val, our_name);
  hit = calc_value(attack_data[off+W_HIT], skill_val, our_name);
  ac = (int)target->query_ac(attack_data[off+W_TYPE]);
  hit += base - ac;
  if (hit < 0) {
    this_object()->write_message(0, target, me, attack_data[off+W_TYPE],our_name);
    this_object()->hit_weapon(ac, name);
    return ;
  }
  base -= ac;
  if (base < 0)
    base = 0;
  base += calc_value(attack_data[off+W_DAM], skill_val, our_name);
  this_object()->write_message(base, target, me, attack_data[off+W_TYPE], our_name);
  this_object()->hit_weapon(ac, name);
  if (base > target->query_hp())
    base = target->query_hp()+1;
  target->adjust_hp(-base);
  me->adjust_xp(base/10);
  if (!target)
    return ;
  for (i=0;i<sizeof(attack_data);i+=W_ARRAY_SIZE)
    if (attack_data[i+W_FLAG] == our_name)
      if (random(100) < attack_data[i+W_CHANCE])
        if (attack_data[i+W_CHANCE]>200) {
          if (hit > attack_data[i+W_CHANCE]-200)
            do_attack(i/W_ARRAY_SIZE);
        } else
          do_attack(i/W_ARRAY_SIZE);
}

int weapon_attack(object targ, object ob) {
  int i, off;

  target = targ;
  me = ob;
  for (i=0;i<sizeof(attack_name);i++) {
    off = i*W_ARRAY_SIZE;
    if (!target)
      continue;
    if (!attack_data[off+W_FLAG])
      if (random(100)<attack_data[off+W_CHANCE])
        do_attack(i);
  }
}

// este write_message nunca lo he visto en el juego.
void write_message(int dam, object attack_ob, object attack_by, string type,
                   string name) {
  string *message;

  message = (string *)"/std/weapon.mess"->query_message(dam ,type,
                                                    attack_ob, attack_by, name);
  if (message && sizeof(message) >= 3) {
    tell_object(attack_by, message[0]);
    tell_object(attack_ob, message[1]);
    tell_room(environment(attack_ob), message[2], ({ attack_ob, attack_by }) );
    return ;
  }
  if (dam<30) {
    tell_object(attack_by, "# "+attack_ob->short()+" esquiva habilmente tu ataque.\n");
    tell_object(attack_ob, "* Esquivas habilmente el ataque de"+
	capitalize((string)attack_by->short()) +".\n");
    tell_room(environment(attack_ob), capitalize((string)attack_ob->short()) +
     " esquiva habilmente el ataque de " + attack_by->short() +".\n", ({ attack_ob, attack_by}));
  } else {
    tell_object(attack_by, "# Alcanzas a " + attack_ob->short() + " con tu golpe.\n");
    tell_object(attack_ob, "* * "+capitalize((string)attack_by->short()) +
      " te golpea.\n");
    tell_room(environment(attack_ob), capitalize((string)attack_by->short()) +
      " golpea a " + attack_ob->short() + ".\n", ({ attack_ob, attack_by }));
  }
}

string calc_string(mixed b) {
  if (intp(b))
    return "rand("+b+")";
  if (!pointerp(b))
    return "Dead";
  switch (sizeof(b)) {
    case 1 :
      return ""+b[0];
    case 2 :
      return ""+b[0]+"+rand("+b[1]+")";
    case 3 :
      return ""+b[0]+"+"+b[1]+"d"+b[2];
    default :
      return "Oh hell";
  }
}

mixed weapon_stats() {
  int i, j;
  mixed *ret;

  ret = ({ });
  for (i=0;i<sizeof(attack_data);i+=W_ARRAY_SIZE,j++)
    ret += ({ ({ "ATT"+j+" name", attack_name[i/W_ARRAY_SIZE], }),
              ({ "     flag", attack_data[i+W_FLAG], }),
              ({ "   chance", attack_data[i+W_CHANCE], }),
              ({ "     base", calc_string(attack_data[i+W_BASE]), }),
              ({ "      hit",  calc_string(attack_data[i+W_HIT]), }),
              ({ "      dam", calc_string(attack_data[i+W_DAM]), }),
              ({ "     type", attack_data[i+W_TYPE], }),
          });
  return ret;
}

void set_attack_name(mixed *bing) { attack_name = bing; }
void set_attack_data(mixed *bing) { attack_data = bing; }

mixed stats() {
  return weapon_stats();
} /* stats() */

mixed *query_init_data() {
  return ({ "attack name", attack_name, "set_attack_name/p",
            "attack data", attack_data, "set_attack_data/p",
            "attack skill", skill, "set_weap_skill/p" });
} /* query_init_data() */
