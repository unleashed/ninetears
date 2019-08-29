inherit "/obj/monster.c";

void setup()
{
    set_name("Sir Rodion");
    add_alias("rodion");
    add_alias("caballero");
    set_main_plural("caballeros");
    add_alias("Caballeros");
    set_short("Sir Rodion el caballero del Roto Navio");
    set_long("Ante ti tienes a uno de los mas bravos caballeros de "
      "todos los reinos, Sir Rodion.  Tiempo atras, durante una peligrosa "
      "mision, Rodion y su tripulacion atravesaron una terrible tormenta. "
      "Su nave se partio en dos a causa del oleaje y el bravo Rodion "
      "fue el unico superviviente.  El anhela ver su guild de los "
      "Paladines y a sus companyeros una vez mas, aunque mientras "
      "tanto , si se lo pides amablemente te contara una historia "
      "o dos.\n\n");
    set_heart_beat(1);
    set_guild_ob("/std/guilds/warriors/paladin.c");
    set_race("human");
    set_gender(1);
    set_al(-1000);
    set_max_gp(100);
    set_gp(100);
    set_max_hp(100);
    set_level(20);
    set_str(18);
    set_dex(18);
    set_con(18);
    set_wis(18);
    set_int(18);
    set_cha(18);
    set_kill_xp(800);
    load_chat(70, ({
	1, "' Como deseo ver a mis cofrades de nuevo.",
	1, "' Salve Virga y sus miticos Paladines!",
	1, ":mira largamente en la lejania sobre el Oceano.",
      }));
    load_a_chat(80, ({
	1, "' Miserable pagano!  Ahora debes perecer!",
	1, "' Estas realmente en el camino del mal?!",
	1, "' Eres afortunado, estos viejos huesos mios no son lo que fueron!",
	1, ":grita con un lenguaje malsonante insultando a tu familia.",
	1, ":Se acerca cargando contra ti!",
	1, ":deja caer su arma sobre tu craeno!",
      }));
    add_clone("/baseobs/weapons/broad_sword.c", 2);
    add_clone("/baseobs/armours/chainmail.c", 1);
    this_object()->init_equip();
}

void init()
{
    ::init();
    add_action("do_story", "contar");
}

int do_story(string str)
{
    if(str == "historia")
    {
	if(this_object()->query_property("storytelling") == 1)
	{
	    do_command("say Ya estoy contando una historia!");
	    return 1;
	}
	do_command("say Ahh asi que quieres oir una historia?  Dejame "
	  "contarte la historia del famoso Gremio de Paladines.");
	this_object()->add_property("storytelling", 1);
	call_out("part_one", 5);
	return 1;
    }
}

int part_one()
{
    do_command("say Tiempo atras la Mitica Diosa de la bondad y el amor, Virga, "
      "reunio a los mas bravos y fuertes de sus seguidores para formar un "
      "Grupo de Elite de Guerreros que la ayudaran a sembrar su benevolencia "
      "por todos los Reinos.");
    do_command("suspirar");
    call_out("part_two", 7);
    return 1;
}

int part_two()
{
    do_command("say A estos Guerreros de Elite se les dieron algunos "
      "poderes para ayudar a Virga en su cometido.  Fueron adiestrados "
      "a cargar en combate y se les doto con el poder de curar con sus "
      "propias manos las heridas, y los mas poderosos y avanzados tenian "
      "la habilidad de invocar a virga para que se les concediera "
      "un arma especial que les hacia aun mas temibles en la "
      "batalla.");
    do_command("beam");
    call_out("part_three", 10);
    return 1;
}

int part_three()
{
    do_command("say El camino del Paladin no es facil.  Uno debe "
      "ser honorable, legal y de buen corazon.  El caballero tiene que viajar "
      "en busca del sitio donde aprender formas de lucha, y el coste para avanzar "
      "no es poco. El caballero ha de ser muy fuerte y de considerable constitucion, "
      "ademas de ser rapido y de agiles reflejos. "
      "Un caballero siempre ha de estar en guardia contra las fuerzas del mal, "
      "y sobre todo atento a sus peores rivales, los Anti-Paladines, estos pueden ser "
      "tan poderosos como ellos. Pero siendo persistente un dia llegara a ser parte "
      "de uno de los mas poderosos Gremios de los Reinos, los Paladines!");
    do_command("sonreir");
    this_object()->remove_property("storytelling");
    return 1;
}
