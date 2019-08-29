#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Forrest Path");

    set_long("Forrest Path.\n\n"
        "       Walking through the meadow the spirit of nature "
	"really reveals itself.  Everywhere life explodes in the "
	"most extraordinary ways and colours. In the middle of "
	"the wide meadow stands a great oak. Its size resembles "
	"nothing you ever have seen. Steadly it overlooks the open "
	"heart of life in this area.\n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The trees are of mixed "
	"type. Here and there stand an oak, making it all seem "
	"majestetic.\n");   
	 
	add_item("oak","     When looking at it, you think you "
	"remember that your parents once told you of such fantastic "
	"oak. It was called Ygnarion, and held something called "
	"speaker of souls. The speaker, which is a carved wooden "
	"nut, was made and carried by the druid Ashandrillam. When "
	"he returned to his birthplace, after over 100 years of "
	"wandering, he placed the speaker in a great oak. No one "
	"ever found it and Ashandrillam disappeared right after he'd "
	"hidden then nut. Rumours say that the nut carried the gathered "
	"souls of animals and plants, which he saved from various "
	"horrible deaths. And that the carrier would be gifted the "
	"powers of all these.\n");   

	add_exit("north",ROOMS+"y23.c","path");
	add_exit("southeast",ROOMS+"A25.c","path");
	//mayhapp a climb tree with a nut somewhere ;)	
   }