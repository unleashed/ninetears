inherit "std/outside.c";

void setup () {

  set_short ("%^ORANGE%^Cienagas de Urghak%^RESET%^");
  set_long (query_short()+"
     Te encuentras en la entrada de las famosas y pestilentes%^ORANGE%^Cienagas de Urghak %^RESET%^, un terreno gigantesco que en tiempos pasados fue un bosque muy conocido. Al conquistar los goblins la zona vecina talaron el bosque para evitar la proliferacion de elfos en las cercanias de sus territorios, y para asegurarse de su exito vertieron los mas terribles residuos y los shamanes invocaron grandes desgracias sobre la tierra. El resultado esta ante ti, y a medida que avanzas por ellas tu angustia y asco se acrecentan a cada paso. Tus pies se hunden en el terreno dejandotelos llenos de porquerias y una sensacion harto desagradable. El aire cargado de inmundicias y  el olor nauseabundo te marea y no consigues ver mas adelante el fin de tan desagradable extension. El camino viene del noroeste y avanza hacia el este.
");
  add_smell ("aire","Al oler el aire haces grandes esfuerzos para contener los irrefrenables deseos de vomitar. Realmente no oliste nada semejante en tu vida.
");
  add_exit ("noroeste","/d/urghak/cienaga/room/01.c","door");
  add_exit ("este","/d/urghak/cienaga/room/03.c","door");

}
