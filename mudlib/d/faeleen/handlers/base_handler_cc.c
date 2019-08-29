inherit "/std/outside.c";

void habitacion(int i)
{
  switch (i)
  {
  	
  case 0:
	  set_short("%^YELLOW%^Camino a la Playa%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("camino_playa");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("camino_playa",TO);
	  set_exit_color("verde_c");
  break;
  case 1:
	  set_short("%^BOLD%^RED%^Camino a Rongrond%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("camino_rongrond");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("camino_rongrond",TO);
	  set_exit_color("negro_c");
  break;
  case 2:
	  set_short("%^ORANGE%^Camino secundario%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGTH .\n\n");
	  set_zone("camino_secundario");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("camino_secundario",TO);
	  set_exit_color("amarillo_c");
  break;
  case 3:
	  set_short("%^ORANGE%^Camino de tierra%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("camino_tierra");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("camino_tierra",TO);
	  set_exit_color("amarillo_c");
  break;
  case 4:
	  set_short("%^ORANGE%^Desvio a Ormerod%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("desvio_ormerod");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("desvio_ormerod",TO);
	  set_exit_color("amarillo_c");
  break;
  case 5:
	  set_short("%^BOLD%^RED%^Calzada a Faeleen%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("calzada_faeleen");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("calzada_faeleen",TO);
	  set_exit_color("rojo_o");
  break;
  case 6:
	  set_short("%^BOLD%^Via ancha%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("via_ancha");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("via_ancha",TO);
	  set_exit_color("gris");
  break;
  case 7:
	  set_short("%^RED%^Cruce de caminos%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("cruce_caminos");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("cruce_caminos",TO);
	  set_exit_color("green_c");
  break;
  case 8:
	  set_short("%^BOLD%^Via %^BLUE%^larga%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("via_larga");
	  "/d/faeleen/handlers/handler_bichos_cc.c"->crear_criaturas("via_larga",TO);
	  set_exit_color("blanco");
  break;

  }
   
  set_light(50);
  set_dark_long("Esta muy oscuro.\n");
}