#define HEAVEN "/d/heaven/"
inherit "std/room";

object board;

int i,n;
int x;
void reset() {
	object *all;
	if(!board) {
		board=clone_object("obj/misc/board");
		board->set_datafile("ambientacion");
		board->move(TO);
   		}
   	n = reclaim_objects();
   	for(i = 0; i < sizeof(all=children("/global/lord.c")); i++) if(all[i]) tell_object(all[i],"[Objects reclaimed: "+ n +" ]\n");
   	}

void setup() {
	set_short("Hall del %^GREEN%^BOLD%^Paraiso%^RESET%^");
  	set_long(query_short()+"\nEsta es sin lugar a dudas la sala mas concurrida del paraiso. Es una habitacion inmensa, con un gigantesco tablon en una de sus paredes, donde los Inmortales dejan sus notas y opiniones sobre la ambientacion de Driade para que los demas sepan lo que piensan, y asi entre todos construir un Mud mejor. Al norte se encuentra la Sala de Asambleas del Paraiso. Al sur se extiende un pasillo hacia otras dependencias administrativas, mientras que unas escaleras descienden hacia el mundo de los mortales. Las demas paredes estan repletas de puertas que conducen a las dependencias personales de cada Inmortal. Semioculta entre ellas esta la puerta del trastero, donde se guardan las cosas antiguas del Paraiso.\n");
  	add_exit("sur",HEAVEN+"admin2","corridor");
	add_exit("norte",HEAVEN+"asamblea","corridor");
	add_exit("trastero",HEAVEN+"oldcommon","door");
	add_exit("abajo","/room/admin/mapamundi","stairs");
	}

void dest_me() {
	if (board) board->dest_me();
	::dest_me();
	}
