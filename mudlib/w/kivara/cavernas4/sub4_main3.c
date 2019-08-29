/*
Suboscuridad 4 by Kivara
*/

inherit "/std/suboscuridad.c";

     string long = "%^BLACK%^%^BOLD%^Cuevas de la %^RED%^suboscuridad%^RESET%^\n\n"
      "Te encuentras medio perdido en la parte mas profunda y peligrosa de las cuevas. "
      "Los trolls sanguinareos se sienten entre estas paredes de roca "
      "como si estuvieran en casa y conocen cada pasadizo palmo a palmo. Pocos son los "
      "aventureros que han conseguido adentrarse en estas cavernas y muchos menos los "
      "que han conseguido salir para contarlo. Se dice que estos pasadizos llevan a una "
      "antigua ciudad troll, aunque es practicamente imposible llegar a verla a "
      "no ser que se haya nacido troll. \n\n ";
	
     string short = "%^BLACK%^%^BOLD%^Cuevas de la %^RED%^Suboscuridad%^RESET%^\n\n";

void do_desc(int do_short, int do_long)
{
    if (do_long)
	set_long(long);
    if (do_short)
        set_short(short);
    add_item(({"cueva","pared","techo"}),"Las negras paredes de la cueva te rodean "
    	"y te hacen sentir incomodo, aunque por su firmeza no parece que se vayan"
    	" a derribar\n");
    //set_light(80);
  
    set_zone("cuevas_suboscuridad_4");
} /* do_desc */