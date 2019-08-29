// Demonio de Fuego, v:0.9  by Leviathan
// Anteriormente, Drakull by Tyrael
//
#define SLICE   "/d/gremios/comandos/slice.c"

inherit "/obj/monster";

object ob, sang1, sang2;



void event_enter(object ob, string mensaje, object donde)
{
if (!ob->query_hidden()) {
  this_object()->attack_ob(ob);
  if(ob->query_alive() && ob == this_player())
    {
          if (!query_property("discurso_soltado")) {
          add_timed_property("discurso_soltado", 1, 5);
          do_command("say Me llevare tu alma, ya que veo que tu no la usas demasiado !!!!\n");
	  do_command("seguir "+this_player()->query_cap_name());
    }
}
  ::event_enter(ob, mensaje, donde);
}
	if (ob->query_corpse()) call_out("coger1", 1);
         ::event_enter(ob, mensaje, donde);
}

void coger1()
{
    do_command("coger all de cuerpos");
    do_command("enterrar");
    call_out("coger2", 1);
}

void coger2()
{
    do_command("get all");
    call_out("run_away", 2);
    call_out("coger3", 4);
}
                                
void coger3()
{
    TO->init_equip();
}


void setup() {
  set_name("Demonio de Fuego");
  add_alias("demonio");
  set_al(10000);
  set_wimpy(100);
  set_short("Demonio de %^BOLD%^RED%^FUEGO%^RESET%^");
  set_race("human");
  set_language("common");

  // Nivel bajo, puesto que atacara a todo lo que se mueva
  set_level(31);
  set_max_hp(1500);
  set_max_gp(1500);
  set_hp(1500);
  set_gp(1500);
  set_random_stats(46, 48);
  set_ac(-400);
  set_thac0(-70);
  set_gender(1);
  set_long("Una forma humanoide, envuelta en llamas por todas partes, realmente es una criatura aterradora, llegada de lo mas profundo de los infiernos en busca de algun ser al que cazar para llevarse su alma y complacer a su senyor.\n");
  sang1 = clone_object("/room/castillo_drakull/armas/vampirica");
  sang2 = clone_object("/room/castillo_drakull/armas/vampirica");
  sang1->move(TO);
  sang2->move(TO);
  sang1->remove_property("no_slice");
  sang2->remove_property("no_slice");
  add_clone("/room/camino_avalon/objs/cinturon_prisma", 1);
  init_equip();
  set_join_fight_mess("El Demonio de Fuego aumenta su tamanyo al sentir la sangre cerca ! "
  "sus ojos se vuelven rojos y empiezan a escupir llamaradas de fuego.\n");
  set_aggressive(4);
} /* setup() */

void init()
{
  ::init();
//  add_attack_command(25, "furia", "/d/gremios/comandos/furia","furia",0);
}

void attack_by(object atacante)
{
   SLICE->slice(atacante->query_name(),TO);
::attack_by(atacante);
}
/*
void heart_beat()
{
	object *i;
	if (sizeof(i=query_attacker_list()))
	{
		SLICE->slice(i[random(sizeof(i))]->query_name(), TO);
	}
	::heart_beat();
}
*/
/*
void do_death(object ob)
{
  object *snarf; 
        int i; 
	int a; 
        snarf=query_attacker_list(); 
 
        for(i=0;i<sizeof(snarf);i++) 
        { 
          write_file("/w/leviathan/logs/demoniodefuego", snarf[i]->query_name()+ 
          " ha matado al demonio de Fuego: "+ctime(time())+".\n"); 
	    
	  
          if snarf[i]->query_property("matodemoniofuego")
	  {
	  	a=this_player()->query_property("matodemoniofuego");
	  	snarf[i]->add_property("matodemoniofuego",a++);
	  }
	  else
	  {
	  	snarf[i]->add_property("matodemoniofuego",1);
	  }
	} 
  ::do_death(ob);
}*/

void do_death(object ob)
{
	sang1->add_property("no_slice", 1);
	sang2->add_property("no_slice", 2);
	sang1->dest_me();
	sang2->dest_me();
	write ("\nTu enemigo se desvanece en una nube de %^BOLD%^WHITE%^humo%^RESET%^! \n\n");
	write("\nEl Demonio de %^BOLD%^RED%^FUEGO%^RESET%^ ha sido derrotado esta vez y vuelve cabizbajo a los infiernos... pero no tardara en volver a salir a por almas!!\n\n");
	dest_me();
	if (!ob) ob = this_player();
//no queremos mas problemas.. el demonio se vuelve al infierno y se acabo.. no se hable mas, no deja ni cuerpo ni equipo
//::do_death(ob);
}
