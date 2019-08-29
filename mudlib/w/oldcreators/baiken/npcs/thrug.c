// Gurthang '00
inherit "/obj/monster";

int combo(object* chu);
int entrenador;
void setup()
{
   
  set_name("thrug");
  set_short("Thrug, el espiritu asesino");
  set_gender(1);
  set_main_plural("Espiritus parecidos a Thrug");
  set_race("orc");
  set_guild("Shaman");
  set_guild_ob("/std/guilds/priests/shaman");
  set_str(18);
  set_con(4);
  set_dex(25);
  set_int(20);
  set_wis(23);
  set_cha(21);
  set_long("Thrug fue en vida uno de los orcos mas sangrientos que existio "
        "en todos los Reinos de Leyenda. Cuando murio, los shamanes "
        "lamentaron su perdida y enseguida convocaron a su espiritu. Cuando "
        "estuvo presente dividieron su espiritu en infinitas partes y cada "
        "una fue atada a un anillo. Estos son conocidos como los NazgThrug.\n");
  add_property("nodisarm",1);
  init_equip();
  TO->do_command("guild on");
  set_level(69);
  set_max_hp(500);
  set_max_gp(600);
}
int query_res() {return 40;}
int query_total_ac() {return -80;}
/*
void init()
{
  set_heart_beat(1);
  ::init(); 
}
void heart_beat()
{
   if(TO->query_attacker_list())
   {
      combo(TO->query_attacker_list());
   }
   ::heart_beat(); //MUY importante
   
}
int combo(object* lala)
{
   object chu = lala[random(sizeof(lala))];
   DESGARRAR->do_command(chu,this_object());
        if(!random(3))
           MORDISCO->do_command(chu,this_object());
        if(!random(4))	   
   	   "/std/commands/desarmar.c"->disarm(chu->query_name()); 
	if(!random(3))   
	   COLETAZO->hacer_strike(this_object(),chu);
	return 1;
}
*/
int unarmed_attack(object target,object me)
{
      object *att;
      att=(object *)me->query_attacker_list();
      monster::unarmed_attack(att[random(sizeof(att))],me);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      monster::unarmed_attack(att[random(sizeof(att))],me);
}
void heart_beat()
{
if(!present(ENV(TO),entrenador))
  {
  TO->move(ENV(entrenador));
  tell_room(ENV(TO),TO->query_cap_name()+" llega de algun lado.\n");
  TO->do_command("seguir "+entrenador);
  TO->do_command("protect "+entrenador);

  if(TO->query_attacker_list())
   {
      combo(TO->query_attacker_list());
   }
   ::heart_beat(); //MUY importante

  }
}
