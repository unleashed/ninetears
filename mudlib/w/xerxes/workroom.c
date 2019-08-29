#define CREATOR "xerxes"

inherit "/std/suboscuridad.c";

void setup()
{
  set_short("%^BLACK%^BOLD%^Algun lugar en el Plano del Abismo%^RESET%^");
  set_long("%^BLACK%^BOLD%^Algun lugar en el Plano del Abismo%^RESET%^\n\n"
  "     En algun lugar del plano abismal te encuentras, mas no es "
  "un lugar comun. Se trata del espacio vital de Xerxes, el lugar "
  "donde su alma encuentra descanso mientras crea una telaranya "
  "de terror y destruccion en el plano material de existencia. "
  "Si tus ojos pudieran ver la realidad de este plano, seguramente "
  "moririas del miedo, pero... no eres mas que un ser insignificante "
  "en un lugar en el que Xerxes es la Unica Entidad.\n\n");
  add_property("luz_real",50);
  set_exit_color("red");
  add_exit("comun","/w/common","door");
  add_exit("entrada","/room/entryroom.c","door");
  add_exit("urghak","/d/urghak/common.c","door");
  add_exit("penumbra","/d/ciudades/control/penumbra.c","door");
  "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");

}
