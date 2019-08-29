inherit "/std/outside.c";

void habitacion(int i)
{
  switch (i)
  {
  	
  case 0:
	  set_short("%^GREEN%^Bosque de %^BOLD%^BLACK%^Lobos%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("bosque_lobos");
	  "/d/faeleen/handlers/handler_bichos_bl.c"->crear_criaturas("bosque_lobos",TO);
	  set_exit_color("orange");
  break;
  case 1:
	  set_short("%^BOLD%^GREEN%^Claro en el %^RESET%^GREEN%^Bosque%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("claro_bosque_lobos");
	  "/d/faeleen/handlers/handler_bichos_bl.c"->crear_criaturas("claro_bosque_lobos",TO);
	  set_exit_color("orange");
  break;

  }
   
  set_light(50);
  set_dark_long("Esta muy oscuro.\n");
}