inherit "std/outside.c";

void setup () {

  set_short ("%^ORANGE%^Cienagas de Urghak%^RESET%^");
  set_long (query_short()+"
     Empiezas a llegar a la parte central de las cienagas, o por lo menos eso piensas debido al ahora mas que nunca toxico olor que hay en la zona. Ya no alcanzas a ver tus pies hundidos en las charcas pestilentes. De vez en cuando escuchas una especie de chapoteo en alguna de las charcas que te rodean, pero te parece imposible de que haya alguna criatura capaz de sobrevivir al desagradable olor y a tanta inmundicia. Empieza a agobiarte mucho este lugar y te sientes enfermar e incluso a perder la capacidad de pensar con claridad  a cada paso que das. La unica ruta que puedes seguir son algunas zonas de las charcas menos profundas en las que mas o menos puedes andar o al menos intentarlo. El unico camino posible viene del sur y continua hacia el este.
");
  add_smell ("aire","Al oler el aire haces grandes esfuerzos para contener los irrefrenables deseos de vomitar. Realmente no oliste nada semejante en tu vida.
");
  add_exit ("este","/d/urghak/cienaga/room/28.c","door");
  add_exit ("sur","/d/urghak/cienaga/room/26.c","door");
  
}
