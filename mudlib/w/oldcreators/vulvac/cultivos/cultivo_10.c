// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^GREEN%^Cultivos subterraneos%^RESET%^");

set_long("\n%^GREEN%^Cultivos subterraneos%^RESET%^.\n\nVes como te vas adentrando cada vez mas en los cultivos. No sabes por que pero la gente del lugar trabaja con mucho esmero y rapidez, parece como si este lugar les otorgara vitalidad. Los cultivos siguen siendo de liquenes, hongos, setas y demas.\n\n");
add_item("hongos","Ves hongos de todo tipo. A simple vista no te parecen algo muy apetitoso pero a las gente de keroon les resulta un manjar.\n");
add_item("setas","Son un tipo de seta muy raro que nunca has visto, tienen la base grande y el extremo de la seta pequenyo. Es de color marron. A simple vista no parece muy buena.\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("sudoeste" ,CULTIVOS+"cultivo_9.c","standard");
add_exit("norte" ,CULTIVOS+"caseta_1.c","standard");
add_exit("sudeste" ,CULTIVOS+"cultivo_11.c","standard");

}