#include "var.h"
inherit "/obj/monster";
inherit "/std/basic/respond_give.c";
#define SIMBOLO "/std/spells/items/simbolo_paladin"
#define NOMBRE "Patric"
#define DINERO 15
#include "sanarse.h"
object *array;
void setup()
{
  set_name("patric");
  set_short(NOMBRE);
  set_long("Este es "+NOMBRE+", legendario paladin del Dios de la mente."
      " Durante toda su vida ha luchado por la causa en el continente. "
      "Ahora es el Maestro y Patron de los Paladines ensenyando a los "
      "heroes a saber manejar la espada para cuando el se marche. Es alto "
      "y corpulento, protegido por una coraza dorada, y empunyando la "
      "espada legendaria Inspiracion\n");
  set_main_plural("paladines");
  add_alias("guerrero");
  add_alias("paladin");
  add_plural("guerreros");
  adjust_tmp_damage_bon(20);
  adjust_tmp_tohit_bon(20);
  set_gender(1);
  set_aggressive(0);
  set_race("humano");
  set_race_ob("/std/races/human");
  set_guild_ob("/std/guilds/warriors/paladin");
  set_str(28);
  set_dex(18);
  set_con(18);
  set_int(18);
  set_wis(18);
  set_cha(20);
  set_gender(1);
  set_aggressive(0);
  set_alignment(-1000);
  set_wimpy(0);
  set_level(60);
  set_max_hp(query_max_hp()+roll(query_con(),query_level()));
  set_max_gp(1000+query_max_gp()+roll(query_wis(),query_level()));
  adjust_money(1+random(query_level()),"platinum");
  add_property("nodisarm",1);
  add_clone("/baseobs/weapons/bastard_sword.c",1);
  add_clone("/baseobs/armours/fullplate.c",1);
  add_clone("/baseobs/armours/great_helm.c",1);
  add_clone("/baseobs/armours/large_shield.c",1);
  add_clone(P_ITEMS+"bondad",1);
  array = all_inventory(TO);
  respond_give("dar_equipo");
  init_equip();

}
void init()
{
// add_known_command("cargar");
   add_attack_spell(40+roll(2,10),"charge",({"/std/commands/charge","charge",1}));
   add_attack_spell(40+roll(2,10),"disarm",({"/std/commands/desarmar","disarm",1}));
// add_attack_spell(90,"plegaria",({"/std/commands/prayer","cast_spell",3}));
// add_attack_spell(90,"bendicion",({"/std/commands/bless","cast_spell",3}));
   add_action("do_bow", "bow");
   give_init();
   ::init();
   TO->change_consent("dar on");
}
int do_bow(string str)
{
  object simbolo;
  str = capitalize(lower_case(str));
  if(str!=NOMBRE)
  {
    notify_fail("Hacer una reverencia a quien?\n");
    return 0;
  }
  if(this_player()->query_guild_name()!= "paladin")
  {
    tell_object(this_player(),NOMBRE+" te ignora como el ser inferior "
                "que eres.\n");
    return (1);
  }
  if(this_player()->query_level()<20)
  {
    tell_object(this_player(),NOMBRE+" te saluda con la cabeza.\n");
    tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
    return(1);
  } 
  if(this_player()->query_timed_property("holy symbol"))
  {
    tell_object(TP,NOMBRE+" te dice: Tan pronto?\n");
    tell_object(TP,NOMBRE+" te dice: Los simbolos sagrados del bien "
                "no son para ser malgastados.\n");
    return(1);
  }
  tell_room(ETO,TP->query_cap_name()+" saluda a "+NOMBRE+".\n",TP);
  tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
  simbolo=clone_object(SIMBOLO);
  if (simbolo && !simbolo->move(this_player()))
  {
    tell_object(TP,NOMBRE+" se aproxima a ti y te da algo.\n");
    tell_room(ETO,NOMBRE+" se aproxima y da algo a "+TP->query_cap_name()
              +".\n",TP);
    this_player()->add_timed_property("holy symbol",1,1800);
  }
  return(1); 
}

void dar_equipo(object player)
{
  object Objeto, *items;
  string str = "";  
  int i;
  
  if (!player) return 0;
  items = all_inventory(TO) - array - ({ present("object") });
  if (!sizeof(items)) return 0;
  Objeto = items[0];
  if (sizeof(items)>1)
  {
    tell_object(player,NOMBRE+" te da varios de los objetos que le has dado.\n");
    for (i=1;i<sizeof(items);i++)
     items[i]->move(player);    
  }
  switch(capitalize(Objeto->query_short()))
  {
//    case("Maza Sagrada de Durin"):
    case("Delantal de Cocinero"): 
    case("%^BOLD%^Brazaletes del Heroe%^RESET%^"):
        str = "c_luz.c";       break;
    case("%^BOLD%^Coraza de plata%^RESET%^"):
    case("%^BOLD%^Brazaletes del %^RED%^Heroe Caido%^RESET%^"):
        str = "templanza.c";   break;
    case("Venganza"):
        str = "inspiracion.c"; break;
    case("Gran Hacha a Dos Manos"):
        str = "sagrada.c";     break;
    case("Baston de %^BLUE%^Aldrhon%^RESET%^"):
        str = "bondad.c"; break;
    default: str = ""; break;
  }
  do_command("bow "+player->query_name());
  if (str == "")
  {
    tell_object(player,NOMBRE+" no quiere el objeto que le has dado y te lo devuelve.\n");
    Objeto->move(player);
    return 1;
  }
  write_file("/d/oficios/paladines/rooms/paladines.txt",player->query_name()+".\n");
  write_file("/w/aokromes/paladines.txt",player->query_name()+" dio a Patric");
  Objeto->dest_me();
  Objeto = clone_object("/d/oficios/paladines/items/"+str);
  if (!Objeto) return 1;
  call_out("entrega",1,Objeto, player);
}

void entrega(object item, object ob)
{
  do_command("o");
  call_out("entrega2",1,item, ob);
}
void entrega2(object item, object ob)
{
  do_command("sacar "+DINERO+" monedas de platino");
  do_command("e");
  call_out("entrega3",1,item, ob);
}
void entrega3(object item, object ob)
{
  if (TO->query_value()<DINERO*500)
  {
    tell_object(ob,TO->query_short()+" te dice: No hay dinero suficiente en la tesoreria.\n");
    item->dest_me();
  }    
  else
  {
    TO->adjust_money(({ "platino", -DINERO }));
    if (environment(TO)!=environment(ob)) return 1;
    tell_object(ob,TO->query_short()+" te dice: Has demostrado una vez mas"+
          " ser valedor de este equipo.\n");
    tell_object(ob,TO->query_short()+" te deja algo en el suelo.\n");
    item->move(ENV(ob));
  }
}
void event_enter(object ob, string mensaje, object donde)
{
   if ( (ob->query_guild_name()!=query_guild_name()) && (ob->query_guild_ob()!=0)
       && (!ob->query_creator()))
      attack_ob(ob);
   ::event_enter(ob, mensaje, donde);
}
int query_bonus()
{
  return 3*TO->query_level();
}
