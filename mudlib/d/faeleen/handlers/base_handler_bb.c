inherit "/std/outside.c";

void habitacion(int i)
{
  switch (i)
  {
  	
  case 0:
	  set_short("%^GREEN%^Bosque de %^ORANGE%^Bandidos%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("bosque_bandidos");
	  "/d/faeleen/handlers/handler_bichos_bb.c"->crear_criaturas("bosque_bandidos",TO);
	  set_exit_color("azul_c");
  break;
  case 1:
	  set_short("%^BOLD%^RED%^Camino entre el %^RESET%^GREEN%^Bosque%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("camino_bosque_bandidos");
	  "/d/faeleen/handlers/handler_bichos_bb.c"->crear_criaturas("camino_bosque_bandidos",TO);
	  set_exit_color("amarillo_c");
  break;

  }
   
  set_light(50);
  set_dark_long("Esta muy oscuro.\n");
}