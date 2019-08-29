// Mago al servicio de los guardias

// Kaska, se niega a ser clonado

inherit "/obj/monster";

int contador = 0, retried = 0;

#define ESPEJISMO "/d/gremios/hechizos/mago/espejismo.c"

void setup() {
      set_name("Mago de la Orden del Cono Azul");
      set_short("Mago de la Orden");
      set_al(60);
      set_main_plural("Magos de la Orden del Cono Azul");
	add_plural("magos");
	add_plural("azules");
	add_plural("ordenados");
      add_alias("mago");
	add_alias("azul");
	add_alias("ordenado");
      set_race("human");
	set_gender(1);
      set_level(51+random(10));
	set_thac0(0);
	set_ac(-100);
      set_wimpy(0);
	set_max_hp(query_level() * 10);
	set_hp(query_max_hp());
	set_max_gp(query_level() * 15);
	set_gp(query_max_gp());
      set_random_stats(20, 22);
      set_long("Mago de la Orden del Cono Azul.\n\n"
		"Es un crack, yo de ti no me meteria con el.\n\n");
      adjust_money(random(8), "platino");
//      set_aggressive(0);
	new("/baseobs/weapons/dagger")->move(this_object());
	new("/baseobs/weapons/dagger")->move(this_object());
	new("/baseobs/armours/fullplate")->move(this_object());
	this_object()->init_equip();
      load_chat(20,
         ({
               1, "'Nuestra Orden venera los hechizos de frio.",
               1, ":observa horrorizado el castillo.",
//               1, "@grin evilly $lname$",
               1, ":parece entretenido probando un hechizo de frio.",
               1, "'He visto horrores jamas imaginados en este castillo.",
               1, "'El Bien prevalecera.",
          }));
      load_a_chat(30,
         ({
               1, ":te mira con los ojos inyectados en sangre.",
               1, "'Nadie osa perturbar la paz de los servidores del Bien!",
//               1, "@grin evilly $lname$",
               1, "'Tu afrenta sera recordada por la Orden!",
          }));
	//set_guild("mago");	// no tiene efecto sin set_guild_ob()...
	set_guild_ob("/d/gremios/magos/magobueno");
	add_attack_spell(20, "toque vampirico",
	({"/d/gremios/hechizos/mago/toque_vampirico", "cast_spell",1,0}));
	add_attack_spell(15, "toque helado",
	({"/d/gremios/hechizos/mago/toque_helado", "cast_spell",1,0}));
	add_attack_spell(60, "cono de frio",
	({"/d/gremios/hechizos/mago/cono_frio", "cast_spell",1,0}));
	add_attack_spell(40, "tormenta acida",
	({"/d/gremios/hechizos/mago/tormenta_acida", "cast_spell",1,0}));
	add_attack_spell(10, "tormenta de hielo",
	({"/d/gremios/hechizos/mago/tormenta_hielo", "cast_spell",1,0}));
	add_attack_spell(15, "flecha de hielo",
	({"/d/gremios/hechizos/mago/flecha_hielo", "cast_spell",1,0}));
//	set_heart_beat(1);
}
/*
void heart_beat()
{
	if (sizeof(query_attacker_list()))
	if (!(contador % 10) || (query_hp() < (query_max_hp()/10))) {
//		if (!query_mirror_spell()) {
			if (!retried) {
				retried=8;
				if (!random(2))
				ESPEJISMO->cast_spell(query_short(), this_object(), 0);
			}
			else
				retried--;
//		}
	}
	::heart_beat();
}
*/
