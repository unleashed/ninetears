//.oO JaDe Oo.  Mayo'02
inherit "obj/monster";
object myp;

void init()
{
 ::init();
 add_attack_spell(20,"charge", ({"/std/commands/charge","charge",1}));
 add_attack_spell(35,"proy_magico_menor", ({"/std/spells/escuelas/invocacion/","proy_magico_menor",1}));
}

void setup()
{
  set_name("vingardtur");
  set_short("Vingardtur");
  set_long("Al notar la presencia del Maesto de los Lords de JaDe tu alma se sobrecoge "
  	   "como si un millar de gelidos alfileres se clavaran en tu piel, y a pesar de " 
  	   "tus esfuerzos en un primer instante solo consigues distinguir una figura sombria " 
  	   "y dos ojos de un verde tan profundo que parecen estar leyendo tus mas intimos " 
  	   "pensamientos, sintiendo la necesidad de bajar la mirada. Su oscura y lisa cabellera "
  	   "apenas sobresale bajo su yelmo y a pesar de estar sentado en su trono sabes con "
  	   "certeza que su altura roza los dos metros.\n"  
	   "Una permanente aura ancestral de maldad y fiel devocion a su Diosa le rodea.\n"
	   "Es el elegido de JaDe.\n");
  set_race("human");
  set_race_ob("/std/races/human");
  set_guild("antipaladin");
  set_guild_ob("/std/guilds/warriors/antipaladin.c");
  set_level(80);
  set_gender(1);
  set_str(60);
  set_int(30);
  set_cha(40);
  set_wis(35);
  set_dex(50);
  set_con(30);
  set_max_hp(10000);
  set_hp(10000);
  set_max_gp(10000);
  set_gp(10000);
  set_align(2000);
  set_aggressive(1);
  set_join_fight_mess("Vingardtur exclama: "+
        "Tu alma pasara a pertenecerme!\n");
  add_property("magical",75);
  load_a_chat(10,
  ({
     1, "'Pagaras con tu sangre semejante traicion!",
     1, "'Otra alma para La Dama Oscura!",
    
  }));
  load_chat(10,
  ({
     1, "'Extendere mi ejercito de muerte por todo el reino, es la voluntad de JaDe y asi se hara.",
     1, ":te mira friamente, clavando sus verdes ojos en ti.",
     1, ":acaricia el filo de su espada y en su rostro se dibuja una tetrica sonrisa.",
     1, "'Es nuestro deber obedecer a La Dama Oscura, jamas oses desacatar una orden.",
     1, "'Si provocas mi ira o la de mi Senyora no viviras para contarlo.",
     1, "'No oses traicionar a La Dama Oscura.",

  }));
  
  add_clone("/baseobs/armours/platemail.c",1);
  add_clone("/baseobs/armours/great_helm.c",1);
  add_clone("/w/jade/weapon/corruptora.c",1);
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
if (ob->query_cap_name()=="Jade") return ;
   
     TO->attack_ob(ob);
     ::event_enter(ob,mess,from);
 }
