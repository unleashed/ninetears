//.oO JaDe Oo.  Agosto'02
inherit "obj/monster";
object myp;

void init()
{
 ::init();
 
 add_attack_command(40, "drenar", "/d/gremios/comandos/drain", "drenar" ,3);
 add_attack_command(70, "cargar", "/d/gremios/comandos/carga", "carga" ,3);

}
void setup()
{
  set_name("deckard");
  set_short("Deckard");
  set_long("Deckard, El Protector.\n"
           "Escogido por Vingardtur como su principal protector y comandante, Deckard es "
  	   "un imponente caballero de oscuros ojos y serio semblante. Sus recias manos y " 
  	   "las m�ltiples cicatrices repartidas por su cuerpo, te indican que ha sido curtido " 
  	   "en innumerables batallas y afrentas. Su tarea ahora es la de vigilar el gremio as� " 
  	   "como la de proteger al maestro y a los miembros del mismo.\n");
  	   
  set_race("human");
  set_race_ob("/std/races/human");
  set_guild("guerreros/caballerojade");
  set_guild_ob("/d/gremios/guerreros/caballerojade");
  add_property("NO_BUDGE", 1); 
  set_level(50);
  set_gender(1);
  set_str(40);
  set_int(20);
  set_cha(30);
  set_wis(20);
  set_dex(30);
  set_con(20);
  set_max_hp(1800);
  set_hp(1800);
  set_max_gp(600);
  set_gp(600);
  set_align(2000);
  set_aggressive(0);
  set_join_fight_mess("Deckard exclama: "+
        "Pagar�s con tu sangre semejante traici�n!\n");
  add_property("magical",75);
  load_chat(10,
  ({
     1, ":dice solemnemente: Proteger� con mi vida al Gran Maestro.",
     1, ":te mira desconfiadamente.",
     1, ":muestra orgulloso su insignia.",
     1, ":exclama: A luchar y a vencer!",
     1, ":dice seriamente: Nunca abandones la senda del Honor, pues pagar�s caras las consecuencias.",
     1, ":abrillanta su escudo.",
     1, ":dice: Es nuestro deber convertir a los infieles.",

  }));
  
  add_clone("/d/asgard/shield/portador.c",1);
  add_clone("/d/asgard/armour/ira.c",1);
  add_clone("/d/asgard/weapon/corruptora.c",1);
  add_clone("/baseobs/armours/amulet",1);
  add_clone("/baseobs/armours/bracers",1);
  add_clone("/baseobs/armours/ring",1);
  add_clone("/baseobs/armours/helmet",1);
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


//void event_enter(object ob, string mess, object from)
// {
//if (ob->query_cap_name()=="Jade") return ;
   
//     TO->attack_ob(ob);
//     ::event_enter(ob,mess,from);
// }
