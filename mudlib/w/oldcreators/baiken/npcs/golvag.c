// . Guild Master de los Barbaros
// Gurthang'00

int combo(object* chu);
inherit "/obj/monster";
int puerta;

void setup()
{
   set_name("golvag");
   set_short("Golvag el Destructor");
   set_main_plural("hermanos de Golvag");
   
   add_plural("guerreros");
   add_plural("orcos");
   add_plural("hermanos");
   
   set_guild_ob("/std/guilds/warriors/barbarian");
   set_gender(1);

   set_str(30);
   set_cha(20);
   set_con(18);
   set_dex(17);
   set_int(10);
   set_wis(9);
   
   
   set_long("El sobrenombre de Glonurg es el Salvaje, en cambio, Golvag es conocido "
	"como El Destructor, su ansia de sangre supera a la de la temible Lloth. Elfos, "
	"humanos, halfling, y sobre todo enanos han muerto en manos de este ser, mas "
	"parecido a un demonio que a un humanoide. Las leyendas dicen que mide mas de "
	"dos metros, que es capaz de arrancar un arbol con sus manos y que su piel es "
	"mas dura que las armaduras de los Senyores del Bien. Ahora si quieres puedes "
	"comprobarlas.\n");
            
   add_clone("/baseobs/weapons/scimitar.c",1);
   add_clone("/d/oficios/guerreros/barbaros/items/destripadora",1);
   add_clone("/d/oficios/guerreros/barbaros/items/piel",1);
   add_clone("/d/oficios/guerreros/barbaros/items/taparrabos",1);

   this_object()->init_equip();
   set_level(89);
   set_max_hp(1500);
   set_max_gp(300+random(200));
   set_gp(300);
   set_align(2000);
   adjust_tmp_damage_bon(7);
   
   add_property("magical",100);
   add_property("air",70);
   add_property("fire",70);
   add_property("acid",70);
   add_property("cold",70);
   add_property("electrical",70);
   do_command("guild on");
   load_chat(10,({
        1,"'Nunca me ha gustado hablar mucho. Prefiero matar, matar y matar!!!",
        1,"'Los que no tengan derecho a estar aqui, no les dejare pasar.",
        1,":coge algun resto humanoide del suelo y se entretiene con el",
   }));
    puerta = 0;
}

void init()
{
   set_heart_beat(1);
   ::init();
}

void heart_beat()
{
  if(sizeof(TO->query_attacker_list()))
  {
   combo(TO->query_attacker_list());
  }
::heart_beat();
}
int combo(object* lala)
{
 object chu = lala[random(sizeof(lala))];
 if(!random(3))
 "/std/commands/strike"->do_command(chu,TO);
 if(!random(6))
 "/std/commands/go_berserk"->go_berserk(chu,TO);
 if(!random(4))
 "/std/commands/desarmar"->disarm(chu,TO);
 if(!random(8))
  {
   tell_room(ENV(TO),"Golvag finta tus ataques esquivando tus defensas.\n");
   if(ENV(TO)!=ENV(chu))
    {
    tell_room(ENV(TO),"Golvag intenta golpear a "+chu->query_cap_name()+" pero "
    	"este ya no se encuentra aqui.\n");
    return 1;
    }
    else {
    tell_room(ENV(TO),"Golvag jugando sucio le pega una patada "
	"a "+chu->query_cap_name()+" dejandolo en el suelo sin poder respirar "
	"durante unos segundos.\n",chu);
    tell_object(chu,"Golvag, jugando sucio, te pega una patada en el pecho dejandote sin respiracion durante "
	"unos segundos.\n");
    chu->add_timed_property("passed out",1,2);
    return 1;
    }
  } 
 return 1;
}
void attack_by(object mec)
{
  if(puerta == 0 && !random(5))
   {
    tell_room(ENV(TO),"Golvag se mueve hacia una pared y con un rapido movimiento "
	"apreta un boton.\n");
    do_command("'ahora sera un combate mas entretenido.");
    "/d/oficios/guerreros/barbaros/rooms/esca"->remove_exit("oeste");
    "/d/oficios/guerreros/barbaros/rooms/esca"->renew_exits();
    puerta = 1;
   }
  if(!random(6))
   do_command("guild @[%^RED%^BOLD%^El Destructor%^RESET%^]: "+mec->query_cap_name()+" esta intentando entrar "
	"en la sala de la destruccion!");
  ::attack_by(mec);
}
void event_enter(object ob)
{
    if(interactive(ob))
        if(ob->query_guild_name() !="Barbaro")
        {
            attack_ob(ob);
            TO->do_command("'Que haces tu aqui! Ahora moriras!!");
         }
}
         

int query_res() { return 55; }
int query_total_ac() { return -180; }
