#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("Escalera.");
  
  set_long("Estas en una escalera angosta y oscura, los pasamanos estan llenos de polvo, parece que hace mucho que nadie pasa por aqui.\n\n"); 

  set_light(40);
  add_exit("dentro","/w/duriel/casa/recibidor.c");
  
  add_exit("abajo","/w/duriel/casa/escalera2.c");
  

  
	    
  
}

