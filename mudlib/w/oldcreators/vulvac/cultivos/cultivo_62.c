// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^Centro de refugiados%^RESET%^");

set_long("\n%^BOLD%^Centro de refugiados%^RESET%^.\n\nEstas delante de lo que antiguamente era un centro para refugiados duergars. En estos momentos su estado es lamentable y la gente que lo habita no son ni mucho menos refugiados. Ves como en esta zona un bandido orco ha establecido a su cuadrilla para hacer fechorias por los cultivos.\n\n");

add_exit("sur" ,CULTIVOS+"cultivo_61.c","standard");
}