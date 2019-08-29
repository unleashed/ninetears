// Flangerant, copiado de Thalos solo pa testear si rula...

inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("duergar");
  switch(random(9))
  {
  case 0:
      set_name("cliente");
      set_short("cliente");
      set_long("Es uno de los muchos clientes que se a acercado al mercado para realizar sus compras cotidianas.\n");
      add_alias("cliente");
      set_main_plural("clientes");
      add_plural("cliente");
      set_gender(1);
      add_clone("/baseobs/weapons/knife.c",1);
      adjust_money(10+random(5), "plata");
      ::init_equip();
      set_level(10+random(5));
        
      break;
  case 1:
      set_name("mercader");
      set_short("mercader");
      set_long("Es un mercader, seguramente venido de muy lejos para vender sus mercancias aqui.\n");
      add_alias("mercader");
      set_main_plural("mercaderes");
      add_plural("mercaderes");
      set_gender(2);
      load_chat(50, ({ 1, "'Lo mio es mas barato.", 
                       1, "'Compre ahora y no se arrepentira.",
                       1, "'Ahora 3 por el precio de 2.",
                       1, "'Venga que se me acaban las existencias, esto es lo unico que me queda.",
                       1, "'Ha visto alguna vez algo de mayor calidad?.",
                       1, "'Si lo encuentra mas barato y mejor le devuelvo el dinero."}));
      
      add_clone("/baseobs/armours/leather.c",1);
      add_clone("/baseobs/weapons/knife.c",1);
      adjust_money(15+random(5), "oro");
      ::init_equip();
      set_level(15+random(5));
      
      break;
  case 2:
      set_name("esclavo");
      set_short("esclavo");
      set_long("Es un esclavo, mandado sin duda por sus amos para realizar las compras necesarias, algunos aprovechan esta oportunidad para escapar y se les ve vagabundeando por la ciudad.\n");
      add_alias("esclavo");
      set_main_plural("esclavos");
      add_plural("esclavos");
      set_gender(1);
      set_level(5+random(5));
      set_max_hp(query_level() * 8);
      adjust_money(10+random(5), "plata");
      break;
    }
  add_move_zone("mercado");
  set_move_after(20+random(10), 20+random(10));
  set_al(-500);
  set_random_stats(8,19); 
  set_wimpy(20);
  set_xp(100);
}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keroon", 1, 600);
   ::attack_by(atacante);
}


#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
} 


valid_attack() 
{
   return([
      "kick"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "knee"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "punch"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"})]);


}
