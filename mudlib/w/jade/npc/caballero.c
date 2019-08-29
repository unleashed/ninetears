//.oO JaDe Oo.  Junio'01
inherit "obj/monster";
object myp;

void init()
{
 ::init();
 add_attack_spell(20,"charge", ({"/d/gremios/comandos/charge","charge",1}));
 add_attack_spell(35,"proy_magico_menor", ({"/d/gremios/hechizos/escuelas/invocacion/","proy_magico_menor",1}));
}

void setup()
{
  set_name("caballero");
  set_short("Caballero de la Muerte");
  set_main_plural("Caballeros de la Muerte");
  add_plural("caballeros");
  set_long("Esta criatura es la horrible corrupcion de un paladin, maldecido por los "
           "dioses y condenado a presentar esta forma terrible como castigo por haber "
           "vulnerado el codigo de honor que contemplo en vida. Su rostro es un craneo "                    "ennegrecido, cubierto de fragmentos de carne reseca y podrida. En lugar de "
           "ojos, dos destellos anaranjados titilan en el fondo de las cuencas. El porte "
           "de un Caballero de la Muerte es tan terrorifico que hasta los mas valientes "
           "se asustan ante su presencia.\n");
  set_race("human");
  set_race_ob("/std/races/human");
  set_guild("antipaladin");
  set_guild_ob("/d/gremios/guerreros/antipaladin.c");
  set_level(50);
  set_gender(1);
  set_random_stats(17, 18);
  set_str(28);
  set_cha(18+random(2));
  set_align(2000);
  set_aggressive(2);
  set_join_fight_mess("Caballero de la Muerte grita: "+
        "Pagaras tu osadia bastardo!\n");
  add_property("magical",75);
  load_a_chat(10,
  ({
     1, "'Muere escoria!",
     1, "'Soy la muerte que viene a por vos!",
     1, "'Pagaras tu osadia bastardo!",
  }));
  load_chat(10,
  ({
     1, ":sonrie diabolicamente.",
     1, ":te mira friamente.",
     1, ":entona un oscuro cantico.",
     1, "'Solo obedezco a mi Senyora.",
     1, "'Soy la muerte que viene a por vos!",
     1, "'No oses atacar a mi Senyora.",

  }));
  
  add_clone("/baseobs/armours/platemail.c",1);
  add_clone("/baseobs/armours/great_helm.c",1);
  add_clone("/d/driade/weapons/espada_hielo.c",1);
     if(!random(40))
 {
      add_clone("/w/jade/weapon/lanza.c",1);
 }
  this_object()->init_equip();
  add_property("nodisarm",1);
}

void event_person_say(object ob, string start, string mess, string lang, int speaker)
{
   if (TP != myp)
     return 0;
   if (lang != "drow")
     return 0;
   switch (mess)
   {
   case("protegeme"):
            do_command("protect " + myp->query_name());
            break;
   case("sigueme"): 
            do_command("follow " + myp->query_name()); 
            break;
   case("sigueme y protegeme"):
            do_command("protect " + myp->query_name());            
            do_command("follow " + myp->query_name());
            break;
   default:return 0;
   }
}


void event_enter(object ob, string mess, object from)
 {
if (ob->query_cap_name()=="Jade" || ob->query_cap_name()=="Tyrael" ||  ob->query_cap_name()=="Caballero" || ob->query_cap_name()=="Avatar") return ;
   
     TO->attack_ob(ob);
     ::event_enter(ob,mess,from);
 }
