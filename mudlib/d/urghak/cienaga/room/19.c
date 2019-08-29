inherit "std/outside.c";

void setup () {

  set_short ("%^ORANGE%^Cienagas de Urghak%^RESET%^");
  set_long (query_short()+"
     A medida que avanzas por las cienagas el olor nauseabundo se acrecenta. Empiezan a recorrer todo tu cuerpo sensaciones muy desagradables debido al continuo olor. Empiezas a darte cuenta de que quizas deberias de salir de aqui pronto si no quieres tener una muerte por intoxicamiento. El unico camino visible son los huecos entre charca cienagosa y charca cienagosa. El unico camino posible viene del oeste y puede continuar hacie el sur o hacia el este
");
  add_smell ("aire","Al oler el aire haces grandes esfuerzos para contener los irrefrenables deseos de vomitar. Realmente no oliste nada semejante en tu vida.
");
  add_exit ("oeste","/d/urghak/cienaga/room/13.c","door");
  add_exit ("este","/d/urghak/cienaga/room/24.c","door");
  add_exit ("sur","/d/urghak/cienaga/room/20.c","door");
  
}
