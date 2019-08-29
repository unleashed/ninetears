// Thalos

inherit "/obj/monster";
#include "../../../path.h"

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("duergar");
  switch(random(10))
  {
  case 0:
      set_name("ninyo");
      set_short("ninyo");
      set_long("Es un pequenyo ninyo, que disfruta jugando alegremente con sus companeyeros bajo la atenta mirada de sus padres.\n");
      add_alias("ninyo");
      set_main_plural("ninyos");
      add_plural("ninyos");
      set_gender(1);
      ataque1="patea la espinilla";
      ataque2="muerde en un brazo";
      ataque3="sacude una patada";
      set_level(10+random(5));
      add_clone(ITEMSJARDINES+"zapatos.c",1);
      add_clone(ITEMSJARDINES+"jubon.c",1);
      ::init_equip();
      break;
  case 1:
      set_name("ninya");
      set_short("ninya");
      set_long("Es una pequenya ninya, que disfruta jugando alegremente con sus companyeros, mientrasd su ninyera no le saca un ojo de encima.\n");
      add_alias("ninya");
      set_main_plural("ninyos");
      add_plural("ninyos");
      set_gender(2);
      ataque1="patea la espinilla";
      ataque2="muerde en un brazo";
      ataque3="sacude una patada";
      set_level(10+random(5));
      add_clone(ITEMSJARDINES+"zapatos.c",1);
      add_clone(ITEMSJARDINES+"vestido.c",1);
      ::init_equip();
      break;
  case 2:
      set_name("jovencita");
      set_short("jovencita duergar");
      set_long("Es una encantadora jovencita duergar, que le gusta pasear por los jardines a la espera de que algun encantador muchacho de su edad se le acerque y le conceda poder acompanyarla durante su paseo..\n");
      add_alias("jovencita""jovencitas");
      set_main_plural("jovencitas");
      add_plural("jovencitas");
      set_gender(2);
      set_level(15+random(5));
      add_clone(ITEMSJARDINES+"zapatos.c",1);
      add_clone(ITEMSJARDINES+"falda.c",1);
      add_clone(ITEMSJARDINES+"corpinyo.c",1);
      ::init_equip();
      set_max_hp(query_level() * 8);
      break;
  case 3:
      set_name("anciano");
      set_short("anciano");
      set_long("Es un anciano duergar, disfrutando de un tranquilo paseo por los jardines y esperando a su grupo de amigos para discutir con ellos la situacion politica de la ciudad.\n");
      add_alias("anciano");
      set_main_plural("ancianos");
      add_plural("ancianos");
      set_gender(1);
      set_level(15+random(5));
      set_max_hp(query_level() * 8);
      add_clone(ITEMSJARDINES+"botas.c",1);
      add_clone(ITEMSJARDINES+"jubon.c",1);
      add_clone(ITEMSJARDINES+"mallas.c",1);
      add_clone(ITEMSJARDINES+"capa_arminyo.c",1);
      add_clone(ITEMSJARDINES+"cinturon.c",1);
      ::init_equip();
      break;
  case 4:
      set_name("anciana");
      set_short("anciana");
      set_long("Es un anciana duergar, disfrutando de un tranquilo paseo por los jardines, mientras vigila a sus nietecitos y se fija en el atuendo de las otras damas para poder criticarlas luego en privado con sus amigas.\n");
      add_alias("anciana");
      set_main_plural("ancianos");
      add_plural("ancianos");
      set_gender(2);
      set_level(15+random(5));
      set_max_hp(query_level() * 8);
      add_clone(ITEMSJARDINES+"zapatos.c",1);
      add_clone(ITEMSJARDINES+"falda.c",1);
      add_clone(ITEMSJARDINES+"corpinyo.c",1);
      ::init_equip();
      break;
  case 5:
      set_name("jovencito");
      set_short("jovencito duergar");
      set_long("Es un jopven duergar, que aprovecha sus paseos por el jardin para tratar de ligar con cualquier jovencita duergar de su edad que vea en sus cercanias.\n");
      add_alias("jovencito""jovencitos");
      set_main_plural("jovencitos");
      add_plural("jovencitos");
      set_gender(1);
      set_level(15+random(5));
      set_max_hp(query_level() * 8);
      add_clone(ITEMSJARDINES+"botas.c",1);
      add_clone(ITEMSJARDINES+"jubon.c",1);
      add_clone(ITEMSJARDINES+"cinturon.c",1);
      add_clone(ITEMSJARDINES+"mallas.c",1);
      ::init_equip();
      break;
  
  case 6:
      set_name("ninyera");
      set_short("ninyera");
      set_long("Es una ninyera, encargada de velar por la seguridad de los hijos de sus amos, aunque eso no le impide tener tiempo para coquetear de vez en cuando con algun joven soldado.\n");
      add_alias("ninyera""niyeras");
      set_main_plural("ninyeras");
      add_plural("ninyeras");
      set_gender(2);
      set_level(15+random(5));
      set_max_hp(query_level() * 8);
      add_clone(ITEMSJARDINES+"falda.c",1);
      add_clone(ITEMSJARDINES+"zapatos.c",1);
      add_clone(ITEMSJARDINES+"corpinyo.c",1);
      ::init_equip();
      
      break;
  
   case 7:
      set_name("potentado");
      set_short("potentado duergar");
      set_long("Es uno de los potentados duergars, que aprovecha los ratos de ocio que tiene para venir a pasear por los jardines y asi encontrarse con sus amistades y cerrar algun que otro suculento negocio.\n");
      add_alias("potentado""potentados");
      set_main_plural("potentados duergars");
      add_plural("potentados");
      set_gender(1);
      set_level(20+random(5));
      set_max_hp(query_level() * 8);
      add_clone(ITEMSJARDINES+"botas.c",1);
      add_clone(ITEMSJARDINES+"jubon.c",1);
      add_clone(ITEMSJARDINES+"cinturon.c",1);
      add_clone(ITEMSJARDINES+"mallas.c",1);
      add_clone(ITEMSJARDINES+"anillo_rubi.c",1);
      add_clone(ITEMSJARDINES+"guantes.c",1);
      add_clone(ITEMSJARDINES+"daga_enjoyada.c",1);
      ::init_equip();
      
      break;
    
     case 8:
      set_name("dama");
      set_short("dama");
      set_long("Es un dama de la alta sociedad, que se viene a lucir el ultimo vestido o peinado, y de paso observar como van de arragladas el resto de las damas, para poder criticarlas luego.\n");
      add_alias("dama""damas");
      set_main_plural("damas");
      add_plural("damas");
      set_gender(1);
      set_level(20+random(5));
      set_max_hp(query_level() * 8);
      add_clone(ITEMSJARDINES+"gargantilla.c",1);
      add_clone(ITEMSJARDINES+"zapatos_tacon.c",1);
      add_clone(ITEMSJARDINES+"corpinyo.c",1);
      add_clone(ITEMSJARDINES+"falda.c",1);
      ::init_equip();
  
      break;
   
   case 9:
      set_name("noble");
      set_short("noble duergar");
      set_long("Es uno de los nobles duergars, que aprovecha los ratos de ocio que tiene para venir a pasear por los jardines y asi encontrarse con los otros nobles con los que comentar la situacion politica de la ciudad.\n");
      add_alias(({"noble" "nobles"}));
      set_main_plural("nobles duergars");
      add_plural("nobles");
      set_gender(1);
      set_level(20+random(5));
      set_max_hp(query_level() * 8);
      add_clone(ITEMSJARDINES+"capa_arminyo.c",1);
      add_clone(ITEMSJARDINES+"botas.c",1);
      add_clone(ITEMSJARDINES+"jubon.c",1);
      add_clone(ITEMSJARDINES+"cinturon.c",1);
      add_clone(ITEMSJARDINES+"mallas.c",1);
      add_clone(ITEMSJARDINES+"anillo_rubi.c",1);
      add_clone(ITEMSJARDINES+"guantes.c",1);
      add_clone(ITEMSJARDINES+"daga_enjoyada.c",1);
      ::init_equip();
      break;
    
    }
  add_move_zone("jardines");
  set_move_after(20+random(10), 20+random(10));
  set_random_stats(8,19); 
  set_al(0);
  set_wimpy(90);
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


mixed valiad_attack()
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
