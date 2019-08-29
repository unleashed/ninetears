inherit "/std/outside.c";

void habitacion(int i)
{
  switch (i)
  {
  	
  case 0:
  set_short("%^ORANGE%^Valle Sombrio: Alrededores del templo%^RESET%^.\n");
  
  set_long(query_short()+"\n\n Llegamos a los alrededores del templo, "
           "vemos que est� todo desertico y desolado, anta�o este lugar "
		   "estaba lleno de vida y vegetaci�n pero con la llegada de "
		   "Jade a Asgard quedo desolado y muerto, este lugar es peligroso, "
		   "aqui habitan criaturas malvadas.\n\n");
  set_night_long(query_short()+"\n\n Estamos en los alrededores del templo, "
                 "es de noche y esta todo muy oscuro, no podemos ver mucho "
				 "m�s lejos que un par de metros, de todas formas conseguimos "
				 "distinguir el camino y que no hay nada m�s. Oyes un ruido "
				 "extra�o.\n\n");
  
  set_zone("alrededores_del_templo");
  "/d/asgard/handlers/handler_bichos.c"->crear_criaturas("alrededores_del_templo",TO);
  set_exit_color("amarillo_c");
  break;
  case 1: 
  set_short("%^ORANGE%^Valle Sombrio: %^BOLD%^MAGENTA%^Ruinas del templo%^RESET%^.\n");

  set_long(query_short()+"\n\n Entramos en las ruinas del templo, esta todo " 
           "caido y derrumbado, hace mucho tiempo que nadie pasa por aqu�, "
		   "vemos algunos grabados en lo que queda de pared, logramos discernir " 
		   "que este templo era de culto a un dios de la luz.\n\n");
  set_night_long(query_short()+"\n\n Estamos en las ruinas del templo, esta "
                 "todo muy oscuro y en silencio, es de noche y la luz de la Luna "
				 "consigue reflejar poco de lo poco que queda en las ruinas, es "
				 "un lugar tranquilo, aunque se nota que el paso de los a�os ha "
				 "echo mella en el.\n\n");
  
  set_zone("ruinas_del_templo");
  "/d/asgard/handlers/handler_bichos.c"->crear_criaturas("ruinas_del_templo",TO);
  set_exit_color("rojo_c");
  break;
  case 2:
  set_short("%^ORANGE%^Valle Sombrio: %^MAGENTA%^Templo Abandonado%^RESET%^.\n");

  set_long(query_short()+"\n\n Llegamos al templo abandonado, esta parte del "
           "templo no esta derruida por suerte, esta todo deteriorado y viejo, "
		   "pero es normal aqui no ha venido nadie en siglos, salvo algun "
		   "animal, se pueden observar los mismos grabados en las paredes que "
		   "vimos en las ruinas.\n\n");
  
  set_zone("templo_abandonado");
  "/d/asgard/handlers/handler_bichos.c"->crear_criaturas("templo_abandonado",TO);
  set_exit_color("rojo_o");
  break;
  case 3:
  set_short("%^ORANGE%^Valle Sombrio: %^CYAN%^Zona Basta%^RESET%^.\n");

  set_long(query_short()+"\n\n DESC k no se me ocurre na");
  set_night_long(query_short()+"\n\n DESC Lo mismo pero de noche");

  set_zone("zona_basta");
  "/d/asgard/handlers/handler_bichos.c"->crear_criaturas("zona_basta",TO);
  set_exit_color("verde_o");
  break;
  case 4:
  set_short("%^ORANGE%^Valle Sombrio: %^BOLD%^GREEN%^Zona clara%^RESET%^.\n");
  set_long(query_short()+"\n\n DESC Mas de lo mismo");
  set_night_long(query_short()+"\n\n DESC Igual pero de noche");

  set_zone("zona_clara");
  "/d/asgard/handlers/handler_bichos.c"->crear_criaturas("zona_clara",TO);
  set_exit_color("verde_o");
  break;
  case 5:
  set_short("%^ORANGE%^Valle Sombrio: %^GREEN%^Zona Densa%^RESET%^.\n");
  set_long(query_short()+"\n\n DEESCCC \n\n");
  set_night_long(query_short()+"\n\n DESCCC NIGT.\n\n");

  set_zone("zona_densa");
  "/d/asgard/handlers/handler_bichos.c"->crear_criaturas("zona_densa",TO);
  set_exit_color("verde_c");
  break;
  case 6:
  set_short("%^ORANGE%^Valle Sombrio: %^BOLD%^BLACK%^Zona oscura%^RESET%^.\n");
  set_long(query_short()+"\n\n DEESCCC \n\n");
  set_night_long(query_short()+"\n\n DESCCC NIGT.\n\n");

  set_zone("zona_oscura");
  "/d/asgard/handlers/handler_bichos.c"->crear_criaturas("zona_oscura",TO);
  set_exit_color("verde_o");
  break;

}
   
  set_light(50);
  set_dark_long("Esta muy oscuro.\n");
}