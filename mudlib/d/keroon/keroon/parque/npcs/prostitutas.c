// Made by Thalos 

#include "../../../path.h"
inherit "/obj/monster";
int haciendo_objeto = 0;

void setup()
 {
      object objeto;
      set_name("prostituta");
      set_short("prostituta");
      set_gender(2);
      set_main_plural("prostitutas");
      add_alias("prostituta" "barragana" "meretriz");
      add_plural("prostitutas" "barraganas" "meretrices");
      
     switch(random(8)){
     case 0:      
      set_race_ob("/std/races/human");      
      set_race("humano");
      //set_al(-500);
     break;
     case 1:      
      set_race_ob("/std/races/dwarf");      
      set_race("enano");
      //set_al(-500);
     break;
     case 2:      
      set_race_ob("/std/races/elf");      
      set_race("elfo");
      //set_al(-500);
     break;
     case 3:      
      set_race_ob("/std/races/lizard-man");      
      set_race("hombre-lagarto");
      //set_al(0);
     break;
     case 4:      
      set_race_ob("/std/races/halfling");      
      set_race("halfling");
      //set_al(-500);
     break;
     case 5:      
      set_race_ob("/std/races/orc");      
      set_race("orco");
      //set_al(500);
     break;
     case 6:      
      set_race_ob("/std/races/goblin");      
      set_race("goblin");
      //set_al(500);
     break;
     case 7:      
      set_race_ob("/std/races/duergar");      
      set_race("duergar");
      //set_al(500);
     break;}
      

     set_long("Ves a una prostituta de raza "+this_object()->query_race()+" .Algunas son esclavas obligadas a protituirse por sus amos, otras estan aqui por circustancias de la vida.Lleva una falda muy corta verde, y un top de cuero, tres tallas mas pequenyo de lo que deberia ser, al darse cuenta de tu presencia se mueve provocativamente, a medida que se te acerca a ti. Su chulo no debe andar lejos.Si pagas una modica cantidad tal vez puedas acceder a sus servicios.\n");
     
      set_wimpy(35);
      set_random_stats(12, 18);
      set_level(6+random(8));
      adjust_money(random(15), "plata");
      add_move_zone("parque");
      set_move_after(8,10);
      add_clone(ITEMSPARQUE+"bolso.c",1);
      add_clone(ITEMSPARQUE+"falda.c",1);
      add_clone(ITEMSPARQUE+"top.c",1);
      add_clone(ITEMSPARQUE+"zapatos.c",1);
      add_clone(ITEMSPARQUE+"cinturon.c",1);
      ::init_equip();
      set_aggressive(0);
      
load_chat(30,
         ({
               1, "'Carinyo quieres pasar un buen rato?.",
               1, "'Guapeton acercate y veras lo que es bueno.",
               1, ":empieza a frotarse sus senos por encima de la ropa.",
               1, "Carinyo, te hago un completo?.",
               1, "Animate, no es caro y te aseguro que merece la pena el precio.",
               1, "Ensenyame el pajarito nene.",
               1, "Si vienes con un amigo te hago descuento.",
               1, ":empieza hacer gesto como si realizara una felacion.",
               1, "Nene te hago lo que quieras, frances, griego, cubana...."
          }));
          do_command("hablar common");
}
void attack_by(object atacante)
{
   atacante->add_timed_property("chulo", 1, 600);
   ::attack_by(atacante);
}


/*

void init()
{
	::init();
	add_action("pagar", "pagar");
	haciendo_objeto = 0;
}

void empezar_show(object myp)
{
	do_command("decir Piel de Ogro! Por todos los dioses!");
	call_out("show0", 2, myp);
}

void show0(object myp)
{
	do_command("decir Esto sera perfecto para mi experimento.");
	call_out("show1", 3, myp);
}

void show1(object myp)
{
	tell_room(ENV(TO), QCN + " comienza a formular un hechizo.\n");
	call_out("show2", 4, myp);
}

void show2(object myp)
{
	tell_room(ENV(TO), QCN + " pronuncia el cantico 'natura fuere impregnus'.\nYebarcles termina de formular un hechizo sobre un objeto.\n");
	call_out("show3", 3, myp);
}

void show3(object myp)
{
	do_command("decir Eureka!\n");
	call_out("show4", 6, myp);
}

void show4(object myp)
{
	do_command("decir Ah! Ya casi me olvidaba, aqui tienes tu recompensa!");
	call_out("show5", 2, myp);
}

void show5(object myp)
{

	
	haciendo_objeto = 0;
}

int pagar(string str)
{
	int i;
	object myp = TP;
	object *obs;

	if (haciendo_objeto) {
		do_command("say Un momento, por favor.");
		notify_fail("");
		return 0;
	}

	if (str != "monedas") {
		do_command("decir No te preocupes nene que kedaras satisfecho");

		empezar_show(myp);
		return 1;
	}

	do_command("decir No te acuerdas de la cantidad son 10 platinos");
	notify_fail("");
	return 0;
}*/