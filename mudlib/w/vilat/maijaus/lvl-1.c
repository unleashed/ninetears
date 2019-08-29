//Vilat 20.07.2002
inherit "/std/room.c";

void setup() {
  set_short("%^CYAN%^%^BOLD%^Cueva bajo la Torre de Vilat%^RESET%^");
  set_long("Estas en una curiosa cueva de hielo bajo la Torre de Vilat. La sangre que mana del techo se vierte en unos recipientes y desde ellos se filtra a traves del hielo negro, por donde prosigue su recorrido. En el centro de la habitacion, sobre una columna de hielo, descansa un globo de cristal. Un mullido sofa te invita a tumbarte desde un rincon; en otro aprecias unos huecos en el hielo que deben ser estanterias, pues estan llenos de libros. Por el tercero cae la sangre, pero tras el repugnante chorro hay una escalera que regresa arriba. En el ultimo vertice, una mesa de hielo rodeada de sillas del mismo gelido material brilla con los reflejos de las antorchas.\n");
  set_light(60);

  add_item(({"pared","suelo","hielo"}),"La estancia esta construida en frio hielo negro, finamente labrado. Las antorchas de fuego azul le arrancan caprichosos destellos.");
  add_item(({"antorcha","antorchas"}),"Numerosas antorchas iluminan la estancia formando un estremecedor espectaculo. Curiosamente, el fuego es de un extranyo azul claro.");
  add_item("sangre","El precioso fluido vital chorrea desde el techo y se interna en el hielo.");
  add_sound("habitacion","Escuchas el salpicar de la sangre que cae desde el techo.");
  add_feel(({"antorcha","antorchas","fuego","llama","llamas"}),"El fuego azul de las antorchas no desprende calor alguno.");
  add_item("globo","Se trata de un modelo de globo de vision muy novedoso, que ofrece una nitida imagen y sonido envolvente de ultima generacion. Parece estar danyado.");
  add_item("sofa","Un comodo sofa de color verde botella, donde Vilat se tumba en sus ratos libres. Al observarlo detenidamente descubres un agujero.");
  add_item("agujero","Tras un minucioso examen al sofa, descubres un pequenyo agujero, sin duda producido por la ceniza de un cigarrillo. Recuerda contarselo a Vilat para que lo arregle, seguro que es capaz de ello.");
  add_item(({"huecos","estanterias","libros","hueco","estanteria","libro"}),"En las estanterias cortadas en el hielo encuentras diversos titulos famosos.");
  add_item(({"escalera","escaleras"}),"Regresan a la Torre de Vilat.");
  add_item(({"mesa","sillas","silla"}),"Fabricadas en hielo, la mesa y las sillas parecen estar dispuestas para reuniones y acontecimientos por el estilo.");
  
  
  add_exit("sur","/w/vilat/maijaus/cocina","door");
  add_exit("arriba","/w/vilat/maijaus/lvl0","stair");
}