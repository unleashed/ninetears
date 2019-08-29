/*
Suboscuridad 4 by Kivara
*/

inherit "/std/suboscuridad.c";

     string long = "%^BLACK%^%^BOLD%^Cuevas de la %^RED%^suboscuridad%^RESET%^\n\n"
      "La oscuridad que te rodea no te permite ver mucho mas alla, pero te parece "
      "que estas cuevas no tienen final. Una ligera corriente de aire proveniente del "
      "interior de las cavernas te trae extra�os ruidos y grunyidos. Tales sonidos "
      "te hacen pensar que no ha sido una gran idea aventurarse hasta estas profundidades.\n\n ";
	
     string short = "%^BLACK%^%^BOLD%^Cuevas de la %^RED%^Suboscuridad%^RESET%^\n\n";

void do_desc(int do_short, int do_long)
{
    if (do_long)
	set_long(long);
    if (do_short)
        set_short(short);
    add_item(({"cueva","pared","techo"}),"Las negras paredes de la cueva te rodean "
    	"y te hacen sentir incomodo, aunque por su firmeza no parece que se vayan "
    	"a derribar\n");
    //set_light(80);
  
    set_zone("cuevas_suboscuridad_4");
} /* do_desc */