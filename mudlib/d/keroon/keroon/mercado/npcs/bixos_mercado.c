// Thalos
// NPCS del mercado
#include "../../../path.h"
inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  switch(random(3))
  {
  case 0:
      set_race("duergar");
      set_name("cliente");
      set_short("cliente");
      set_long("Es uno de los muchos clientes que se a acercado al mercado para realizar sus compras cotidianas.\n");
      add_alias("cliente");
      set_main_plural("clientes");
      add_plural("cliente");
      set_gender(1);
      adjust_money(10+random(5), "plata");
      load_chat(50, ({ 1, "'Esta seguro de que es de buena calidad.", 
                       1, "'No tratara de enganyarme vendiendome algo defectuoso.",
                       1, "'Ese precio es un escandolo 3 puestos mas abajo es la mitad de precio.",
                       1, ":mira la mercancia sin decidirse por nada en especial.",
                       1, "'Si te compro 3 me haces descuento?."
                       }));
      
      
      add_clone(ITEMSMERCADO+"pantalones.c",1);
      add_clone(ITEMSMERCADO+"botas.c",1);
      add_clone(ITEMSMERCADO+"camisa.c",1);
      add_clone(ITEMSMERCADO+"daga.c",1);
      ::init_equip();
      set_level(10+random(5));
        
      break;
  case 1:
      set_race("duergar");
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
      
      add_clone(ITEMSMERCADO+"botas.c",1);
      add_clone(ITEMSMERCADO+"cinturon_cuerda.c",1);
      add_clone(ITEMSMERCADO+"tunica.c",1);
      add_clone(ITEMSMERCADO+"daga.c",1);
      adjust_money(15+random(5), "oro");
      ::init_equip();
      set_level(15+random(5));
      
      break;
  case 2:
      set_name("esclavo");
      set_short("esclavo");
      switch(random(7)){
     case 0:      
      set_race_ob("/std/races/human");      
      set_race("humano");
      //set_al(-500);
     break;
     case 1:      
      set_race_ob("/std/races/dwarf");      
      set_race("enano");
      //set_al(-500);
     break;
     case 2:      
      set_race_ob("/std/races/elf");      
      set_race("elfo");
      //set_al(-500);
     break;
     case 3:      
      set_race_ob("/std/races/lizard-man");      
      set_race("hombre-lagarto");
      //set_al(0);
     break;
     case 4:      
      set_race_ob("/std/races/halfling");      
      set_race("halfling");
      //set_al(-500);
     break;
     case 5:      
      set_race_ob("/std/races/orc");      
      set_race("orco");
      //set_al(500);
     break;
     case 6:      
      set_race_ob("/std/races/goblin");      
      set_race("goblin");
      //set_al(500);
     break;}
     set_long("Es un esclavo"+this_object()->query_race()+", mandado sin duda por sus amos para realizar las compras necesarias, algunos aprovechan esta oportunidad para escapar y se les ve vagabundeando por la ciudad.\n");
      add_alias("esclavo");
      set_main_plural("esclavos");
      add_plural("esclavos");
      set_gender(1);
      set_level(5+random(5));
      set_max_hp(query_level() * 8);
      adjust_money(10+random(5), "plata");
      load_chat(80, ({ 1, ":Mira de puesto en puesto buscando lo que su amo le ha ordenado."}));
      add_clone(ITEMSMERCADO+"cadena.c",1);
      //add_clone(ITEMSMERCADO+"harapos.c",1);
      ::init_equip();
      
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


mixed valid_attack()
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
