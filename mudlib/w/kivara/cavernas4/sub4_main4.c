/*
Suboscuridad 4 by Kivara
*/

inherit "/std/underground.c";

     string long = "%^BLACK%^%^BOLD%^Cuevas de la %^RED%^suboscuridad%^RESET%^\n\n"
      "Debido a la profundidad a la que te encuentras, sientes una gran sensacion de "
      "calor y el aire viciado que respiras te produce una gran sensacion de ahogo. El silencio "
      "que te rodea te permite escuchar claramente el acelerado ritmo de tu corazon. En "
      "todo momento te sientes vigilado y de vez en cuando distingues inquieto, un ligero "
      "destello rojo en la oscuridad.\n\n ";
	
     string short = "%^BLACK%^%^BOLD%^Cuevas de la %^RED%^Suboscuridad%^RESET%^\n\n";

void do_desc(int do_short, int do_long)
{
    if (do_long)
	set_long(long);
    if (do_short)
        set_short(short);
    //set_light(80);
        set_short(short);
 		add_item(({"cueva","pared","techo"}),"Las negras paredes de la cueva te rodean "
    	"y te hacen sentir incomodo, aunque por su firmeza no parece que se vayan"
    	" a derribar\n");
    add_item(({"destello","ojos"}),"Tus temores se acrecentan cuando te das cuenta de que"
    	"estas siendo vigilado por inquietantes ojos rojos, que te estudian desde la profundidad\n");
    set_zone("cuevas_suboscuridad_4");
} /* do_desc */