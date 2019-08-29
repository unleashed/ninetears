inherit "/std/outside.c";

void habitacion(int i)
{
  switch (i)
  {
  	
  case 0:
	  set_short("%^ORANGE%^Playas de Faeleen: %^BOLD%^Zona arenosa%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("playa_faeleen");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("playa_faeleen",TO);
	  set_exit_color("verde_c");
  break;
  case 1:
	  set_short("%^ORANGE%^Playas de Faeleen: %^BOLD%^Orilla%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");

	  set_zone("orilla_playa");
	  "/d/faeleen/handlers/handler_bichos_bb.c"->crear_criaturas("orilla_playa",TO);
	  set_exit_color("azul_c");
  break;
  case 2:
	  set_short("%^ORANGE%^Playas de Faeleen: %^BOLD%^BLACK%^Rocas%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("zona_rocosa");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("zona_rocosa",TO);
	  set_exit_color("white");
  break;
  case 3:
	  set_short("%^ORANGE%^Playas de Faeleen: Grutas%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("grutas_playa");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("grutas_playa",TO);
	  set_exit_color("rojo_c");
  break;
  case 4:
	  set_short("%^ORANGE%^Playas de Faeleen: %^RESET%^GREEN%^Espigones%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("espigones_playa");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("espigones_playa",TO);
	  set_exit_color("gris");
  break;
  case 5:
	  set_short("%^ORANGE%^Playas de Faeleen: %^BOLD%^WHITE%^Faro%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("faro_playa");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("faro_playa",TO);
	  set_exit_color("rojo_c");
  break;
  case 6:
	  set_short("%^ORANGE%^Playas de Faeleen: %^CYAN%^Acantilados%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("acantilados_playa");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("acantilados_playa",TO);
	  set_exit_color("azul_c");
  break;
  case 7:
	  set_short("%^ORANGE%^Playas de Faeleen: %^BOLD%^CYAN%^Mirador%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("mirador_playa");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("mirador_playa",TO);
	  set_exit_color("magenta_c");
  break;
  case 8:
	  set_short("%^ORANGE%^Playas de Faeleen: %^BOLD%^RED%^Barco Abandonado%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("barco_abandonado");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("barco_abandonado");
	  set_exit_color("rojo_o");
  break;
  case 9:
	  set_short("%^ORANGE%^Playas de Faeleen: %^RED%^Entrada al barco%^RESET%^");
      set_long(query_short()+"\n\n DESC .\n\n");
	  set_night_long(query_short()+"\n\n DESC NIGT .\n\n");
	  set_zone("entrada_barco");
	  "/d/faeleen/handlers/handler_bichos_pf.c"->crear_criaturas("entrada_barco");
	  set_exit_color("rojo_c");

  }
   
  set_light(50);
}