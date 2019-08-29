inherit "/std/room";
#include "../path.h"

void setup()
{
  add_property("luz_real",50);
  set_exit_color("red");
  set_short("Altar Abandonado: Bajo la Arcada del Tanar'ri");  
  set_long("Altar Abandonado: Bajo la Arcada del Tanar'ri\n\n"
  "     En medio del olvido de la inexistencia se encuentra este "
  "altar, a simple vista abandonado. Cubierto de sangre se encuentra, "
  "con multiples inscripciones que se extienden no solo por el altar, "
  "sino por todo el suelo. Restos de organos humanoides y otros "
  "productos de la casquer�a se encuentran desperdigados armoniosamente "
  "por el altar. Y tras el altar, la gran Arcada del Tanar'ri. Una "
  "majestuosa puerta al m�s all�, donde los que buscan la comuni�n con "
  "el caos y el horror del Plano Abismal encontrar�n la respuesta a "
  "sus preguntas.\n\n");
  
  add_item("arcada","La arcada est� compuesta por dos semicirculos "
  "que se cortan en el extremo superior, dando lugar a una serie de "
  "afilados pinchos de granito, donde, casualmente, siempre hay sitio "
  "para alg�n que otro cuerpo empalado de alguna criatura del bien. "
  "Bajo la arcada est� la respuesta a los que buscan la comuni�n "
  "con el plano abismal. Y, como todo, para encontrarla, hay que "
  "sucumbir el poder del plano abismal.\n");
  
  set_zone("guild_shamanes");
}

void init()
{
  ::init();
  add_action("do_sucumbir","sucumbir");
}

int do_sucumbir(string str)
{
  if (str == "el poder del plano abismal")
  {
    tell_object(this_player(), "Con la maligna bendici�n del "
    "Caos y del Horror, sucumbes ante el Imp�o poder el Plano Abismal, "
    "y �ste te responde con el silencio que se ve roto por "
    "los gritos de los fustigados y los torturados, que deshollan "
    "tu mente hasta la extenuaci�n, y cuando quieres volver a "
    "abrir los ojos, cuando quieres recuperar el control de tu "
    "cordura, apareces en el lugar que estabas buscando. Bienvenido "
    "al Circulum Vitiosus, el hogar de los Shamanes, los hijos del "
    "Plano Abismal.\n");
    this_player()->move(ROOM+"entrada1.c");
    return 1;
  } else {
    notify_fail("Ante el que deseas sucumbir?\n");
    return 0;
  } 
}
