#include "/d/asgard/room/valle_sombrio/path.h"
#include "/d/asgard/room/valle_sombrio/path2.h"
inherit "/std/outside.c";

void habitacion(int i)
{
int j;
  switch (i)
  {
  	
  case 0:
	  set_short("%^ORANGE%^Valle Sombrio: %^CYAN%^Zona Basta%^RESET%^.\n");
      set_long(query_short()+"\n"+VSOMZB".\n\n");
	  set_night_long(query_short()+"\n"+VSOMZBN".\n\n");
	  set_zone("zona_basta");
	  "/d/asgard/habdlers/handler_criaturas.c"->crear_criaturas("zona_basta",TO);
  break;
  case 1:
    set_short("%^ORANGE%^Valle Sombrio: %^BOLD%^GREEN%^Zona clara%^RESET%^.\n");
	set_long(query_short()+"\n"+VSOMZC".\n\n");
	set_night_long(query_short()+"\n"+VSOMZCN".\n\n");
	set_zone("zona_clara");
	"/d/asgard/habdlers/handler_criaturas.c"->crear_criaturas("zona_clara",TO);
  break;
  case 2:
	set_short("%^ORANGE%^Valle Sombrio: %^GREEN%^Zona Densa%^RESET%^.\n");
	set_long(query_short()+"\n"+VSOMZD".\n\n");
	set_night_long(query_short()+"\n"+VSOMZDN".\n\n");
	set_zone("zona_densa");
    "/d/asgard/habdlers/handler_criaturas.c"->crear_criaturas("zona_densa",TO);
  break;
  case 3:
	set_short("%^ORANGE%^Valle Sombrio: %^BOLD%^BLACK%^Zona oscura%^RESET%^.\n");
	set_long(query_short()+"\n"+VSOMZO".\n\n");
	set_night_long(query_short()+"\n"+VSOMZON".\n\n");
	set_zone("zona_oscura");
	"/d/asgard/habdlers/handler_criaturas.c"->crear_criaturas("zona_oscura",TO);
  break;
  case 4:
    set_short("%^ORANGE%^Valle Sombrio: Alrededores del templo%^RESET%^.\n");
	set_long(query_short()+"\n"+VSOMADT".\n\n");
	set_night_long(query_short()+"\n"+VSOMADTN".\n\n");
	set_zone("alrededores_del_templo");
	"/d/asgard/habdlers/handler_criaturas.c"->crear_criaturas("alrededores_del_templo",TO);
  break;
  case 5:
    set_short("%^ORANGE%^Valle Sombrio: %^BOLD%^MAGENTA%^Ruinas del templo%^RESET%^.\n");
	set_long(query_short()+"\n"+VSOMRDT".\n\n");
	set_night_long(query_short()+"\n"+VSOMRDTN".\n\n");
	set_zone("ruinas_del_templo");
	"/d/asgard/habdlers/handler_criaturas.c"->crear_criaturas("ruinas_del_templo",TO);
  break;
  case 6:
    set_short("%^ORANGE%^Valle Sombrio: %^MAGENTA%^Templo Abandonado%^RESET%^.\n");
	set_long(query_short()+"\n"+VSOMTA".\n\n");
	set_zone("templo_abandonado");
    "/d/asgard/habdlers/handler_criaturas.c"->crear_criaturas("templo_abandonado",TO);
  break;
  }
  set_light(50);
}