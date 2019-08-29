#define CREATOR "jade"

inherit "/std/room.c";

void setup()
{
  set_short("%^BOLD%^%^BLACK%^Escondite de %^GREEN%^JaDe%^RESET%^");
  
  set_long("Esta es la sala donde JaDe pasa la mayor parte de su tiempo. "
	   "Aqui se aisla de todo y de todos para urdir sus mas sangrientos "
	   "planes, para crear sus diab�licas huestes y forjar sus artefactos "
           "malditos. Esta habitaci�n tambi�n es su lugar de descanso y meditaci�n. "
	   "Una c�moda y amplia cama y una peque�a mesa cubierta de pergaminos y "
           "libros viejos son la �nica decoraci�n de la sala.\n\n");
  
  
  add_item(({"pared","paredes"}),"Son de piedra y completamente negras. Nunca antes viste una "              "piedra as�.\n");

  add_smell(({"habitacion","aire"}),"Huele a flores... no no, huele a... no sabes a que huele " "con exactitud, pero sea lo que sea es un aroma muuuy dulce.\n");
  
  add_sound("habitacion","Escuchas un suave y adormecedor siseo... Una palabra "
                "se forma en tu mente... %^BOLD%%^GREEN%^JaDe%^RESET%^.\n");
  
  add_clone("/w/jade/items/inki.c",1);
 
  add_exit("cripta","/w/jade/workroom.c","door");
 
}


