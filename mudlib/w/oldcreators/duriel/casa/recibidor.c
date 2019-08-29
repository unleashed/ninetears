#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^Recibidor de %^CYAN%^Hielo%^RESET%^.");
  
  set_long(" Te encuentras en el recibidor de la casa de Duriel."
	   "Puedes ver como una alfombra de terciopelo que tapa el suelo de Hielo ."
	   "Esta evita que los invitados resbalen al no estar acostumbrados a andar sobre hielo.\n"); 

  set_light(80);
  add_exit("fuera","/w/duriel/casa/escalera1.c");
  
  add_exit("norte","/w/duriel/casa/sala_estar.c");
  

  add_item(({"alfombra"}),
            "Una bonita alfombra de terciopelo.\n"
            "Esta decorada con un mosaico con la cara de Duriel.\n");
  
  add_item(({"suelo"}),
            "Un suelo resbaladizo de %^BOLD%^CYAN%^Hielo%^RESET%^.\n"
            "Mas te valdria haber venido con un buen abrigo de wargo si no quieres pasarlo francamente mal.\n");
	    
  
}

