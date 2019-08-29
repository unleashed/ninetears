inherit "std/outside.c";

void setup () {

  set_short ("%^ORANGE%^Cienagas de Urghak%^RESET%^");
  set_long (query_short()+"
     A medida que avanzas por las cienagas el olor nauseabundo se acrecenta. Empiezan a recorrer todo tu cuerpo sensaciones muy desagradables debido al continuo olor. Empiezas a darte cuenta de que quizas deberias de salir de aqui pronto si no quieres tener una muerte por intoxicamiento. El unico camino visible son los huecos entre charca cienagosa y charca cienagosa. El unico camino posible viene del sudeste y continua hacia el noroeste.
");
  add_smell ("aire","Al oler el aire haces grandes esfuerzos para contener los irrefrenables deseos de vomitar. Realmente no oliste nada semejante en tu vida.
");
  add_exit ("noroeste","/d/urghak/cienaga/room/14.c","door");
  add_exit ("sudeste","/d/urghak/cienaga/room/27.c","door");
  
}
