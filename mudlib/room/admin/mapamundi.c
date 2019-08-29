//Vilat 18.10.2002
inherit "/std/room";

object board;

void setup() {
	string *doms=get_dir("/d/");
	string com;
	int i;

	set_short("Sala del %^GREEN%^BOLD%^Ma%^YELLOW%^pa%^BLUE%^mun%^RESET%^ORANGE%^di%^RESET%^");
	set_long(query_short()+"\nSe trata de una sala fascinante. En el suelo hay una maqueta en relieve que representa Driade muy detalladamente, mientras que en las paredes estan pintados los astros con tal maestria que parecen reales... Incluso un globo de luz levita en mitad de la estancia cambiando su luminosidad segun avanza el dia en el plano material. Ademas si te situas sobre un dominio y asi lo deseas te transportaras a el... Sin duda esta sala es una maravilla de la tecnica.\n");

	add_exit("arriba","/w/common","stair");
	for(i=0;i<sizeof(doms);i++) {
		com="/d/"+doms[i]+"/common.c";
		if (file_size(com)<1) continue;
		add_exit(doms[i],com,"plain");
		}

	}

void reset()
	{if(!board) {
		board=clone_object("/obj/misc/board_tale");
       		board->set_teller_name("cuentacuentos");
       		board->move(this_object());
       		board->set_datafile("quests");
      		}
   	}

void dest_me() {
	if(board) board->dest_me();
	::dest_me();
	}
