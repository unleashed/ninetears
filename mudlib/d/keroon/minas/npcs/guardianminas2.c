// Modificate by Valar

inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
      set_race("monster");
      set_name("guardian de la mina");
      set_short("guardian de la mina");
      set_long("Un guardia de la mina de mas alto rango. Su objetivo es vigilar que los mineros "
      "y exclavos cumplan su trabajo, si es necesario utilizara su fuerza bruta para ello.\n");
      add_alias("guardian");
      set_main_plural("guardianes de las minas");
      add_plural("guardianes");
      adjust_money(1+random(5), "gold");
      ataque1="golpea en la mandibula";
      ataque2="pega un puntapie";
      ataque3="muerde en un brazo";
      set_level(20+random(10));
      set_gender(1);
      add_clone("/d/keroon/minas/minas2/items2/latigo",1);
      add_clone("/d/keroon/minas/minas2/items2/hacha_guardia",1);
      add_clone("/d/keroon/minas/minas2/items2/cota_guardia",1);
      ::init_equip();
    
}
