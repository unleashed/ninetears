inherit "/std/room.c";
void setup()
{
	set_light(80);
	set_short("%^BOLD%^BLACK%^Celda%^RESET%^.");
	set_long("%^BOLD%^BLACK%^Celda%^RESET%^.\n\n"
	"Esta celda tiene un aspecto viejo,aparte de tener mucha humedad."
	"Las paredes estan decoradas por los escritos que los anteriores presos"
	"pintraron por su desesperacion.\n\n");
	add_exit("este","/w/kryger/prision/corredor2.c","door");
}
	