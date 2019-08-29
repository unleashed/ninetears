inherit "/std/outside.c";
#include "/d/turkhun/path.h"

void habitacion(int i)
{
  switch (i)
  {
  	
  case 0:
  
  
  
  
  set_short("%^BOLD%^GREEN%^Bosque de %^BLACK%^Turkhun%^RESET%^");
  
  set_long(TO->query_short()+"\n\n"+"Tras cruzar las puertas, y el hechizo de ilusion externo de la ciudad"
           " has llegado a Turkhun, la ciudad de los desterrados, el lugar a donde"
           " la peor calanya de todos sitios viene a parar para refugiarse de las"
           " leyes y las sociedades que les persiguen. Si no eres uno de ellos y"
           " entras en la ciudad, salir vivo de ella sera una ardua tarea. Las"
           " leyes de la ciudad, son respetadas por todos, el robo y el asesinato"
           " no esta permitido, lo cual es cumplido por todos por un bien comun,"
           " aunque nunca esta de mas tener los sentido alerta para ver lo que se"
           " esconde detras de cada esquina.\n");
  
  set_zone("bosque");
    "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("bosque",TO);
  break;
  case 1: 
  
  set_short("%^BOLD%^WHITE%^Cementerio de %^BLACK%^Turkhun%^RESET%^: Entrada");
  
  set_long(TO->query_short()+"\n\n"+"Caminas por el interior de la muralla de Turkhun. El color marfil del exterior se"
           " torna rojo fuego, y la sensacion de magia, se convierte en una sensacion de inseguridad"
           " que te persigue por toda la ciudad. En lo alto de la muralla puedes ver apostados guardias"
           " con arcos y maquinas de guerra para proteger a la ciudad y su contenido de intrusos, curiosos"
           " y cazarrecompensas de otras ciudades.\n");
  
   set_zone("cementerio");
   "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("cementerio",TO);
  break;
  
  case 2:
  set_short("%^BOLD%^WHITE%^Cementerio de %^BLACK%^Turkhun%^RESET%^: Muralla");
  
  
  set_long(TO->query_short()+"\n\n"+"Caminas por una calle que corta Turkhun de norte a sur pasando por la plaza de la Luna Nueva."
           " La calle esta repleta de guardias armados por si acaso algun fisgon non grato logra colarse dentro"
           " de la ciudad. Esta calle divide los diferentes barrios en los que esta divida la ciudad, barrios"
           " ocupados por los diferentes gremios de proscritos, ladrones y asesinos, entre los cuales se ha"
           " establecido un consejo, el cual gobirna la ciudad.\n");

  set_zone("muralla");
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("muralla",TO);
  break;
  
  case 3:
  set_short("%^BOLD%^WHITE%^Cementerio de %^BLACK%^Turkhun%^RESET%^: Pasillo");
  
  
  set_long(TO->query_short()+"\n\n"+"Te encuentras en el mercado de Turkhun, lugar por excelencia para la compra de "
  	   "objetos procedentes de robos, atracos, asesinatos y profanaciones. Toda la zona esta "
  	   "llena de gente de todo tipo, asesinos, carteristas, altos cargos de algunas ciudades "
  	   "de los reinos etc.. gente despiadada que no dudara en matar por unas monedas, o por el "
  	   "simple placer de ver correr tu sangre.\n");

  set_zone("pasillo"); 
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("pasillo",TO);  
  break; 
  
  case 4:
  set_short("%^BOLD%^BLACK%^Torre del exilio: %^RESET%^Primer nivel.");
  
  
  set_long(TO->query_short()+"\n\n"+"Estas en el barrio controlado por la cofradia del Baja Helrek y sus seguidores."
           " Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, se ha decidido que"
           " cada grupo reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas bajas, es el hogar de los ladrones y los suyos. Si no eres de la ciudad evita esta zona ya que"
           " tu espalda acabara siendo un colador. Si eres ladron, bardo o asesino, bienvenido, tendras tu hueco en la cofradia,"
           " si eres proscrito, simplemente disfruta, pero respeta a los alli presentes.\n");

  set_zone("niveluno");
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("niveluno",TO);  
  break;
  
  case 5:
  set_short("%^BOLD%^BLACK%^Torre del exilio: %^RESET%^Segundo nivel.");
  
  
  set_long(TO->query_short()+"\n\n"+"Estas en el barrio controlado por la comunidad de proscritos luchadores y sus seguidores."
           " Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, se ha decidido que"
           " cada grupo reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas pocos cuidadas, y arenas de lucha, es el hogar de los luchadores y los suyos. Si no eres de la ciudad evita esta zona"
           " ya que encontrar pelea es muy sencillo. Si eres luchador, bienvenido, aqui podras encontrar todos los estilos de lucha en las"
           " diferentes arenas, si eres proscrito simplemente disfruta, pero respeta a los alli presentes o cobraras de lo lindo.\n");

  set_zone("niveldos");
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("niveldos",TO);   
  break;
    
  case 6:
  set_short("%^BOLD%^BLACK%^Torre del exilio: %^RESET%^Tercer nivel.");
  
  
  set_long(TO->query_short()+"\n\n"+"Estas en el barrio de la Magia,  Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, "
  	   "se ha decidido que cada grupo reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas bajas y callejones oscuros, es el hogar de los asesinos. Si no eres de la ciudad evita esta zona ya que"
           " tu garganta acabara rajada antes de que sepas quien ha puesto su cuchillo en tu cuello."
           " Si eres asesino, bienvenido, Armadin estara encantado de ensenyarte sus tecnicas de emboscada y subterfugio,"
           " si eres un proscrito, eres bienvenido, pero cuidate ya que jugar con los asesinos puede ser tarea peligrosa.\n");

  set_zone("niveltres");
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("niveltres",TO);  
  break;
  
  case 7:
  
  set_short("%^BOLD%^BLACK%^Torre del exilio: %^RESET%^Cuarto nivel.");
  
  
  set_long(TO->query_short()+"\n\n"+"Estas en el barrio controlado por los Bardos."
           " Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, se ha decidido que"
           " cada grupo reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas bajas, tabernas y prostibulos es el hogar de los bardos y los suyos. Si no eres de la ciudad evita esta zona ya"
           " que acabaras embriagado y hechizado. Si eres bardo, bienvenido, gabriel te ensenyara el arte del timo,"
           " si eres proscrito simplemente disfruta, pero cuidado no bebas mas de la cuenta.\n");

  set_zone("nivelcuatro");  
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("nivelcuatro",TO);  
  break;

  case 8:
  set_short("%^BOLD%^BLACK%^Torre del exilio: %^RESET%^Quinto nivel.");
  set_long(TO->query_short()+"\n\n"+"Te encuentras en una caverna natural, formada tras miles y miles de anyos de aguas "
  	   "filtrandose y disolviendo la roca, estalactitas y estalagmitas se pueden encontrar por "
  	   "todas partes, un pequenyo arroyo discurre por el fondo de la misma, y una ligera corriente "
  	   "de aire da un toque de frescor al silencioso ambiente del interior.\n");

  set_zone("nivelcinco");
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("nivelcinco",TO);  
  break;

  case 9:
  set_short("%^BOLD%^BLACK%^Torre del exilio: %^RESET%^Sexto nivel.");
  set_long(TO->query_short()+"\n\n"+"Frente a ti se abre en todo su explendor un gran valle, circundado por altas montanyas "
  	   "nevadas y suaves pendientes arboladas hasta el valle, donde las manadas de caballos "
  	   "blancos pastan pacificamente, y sus crias juguetean entre las altas hierbas. Entre la "
  	   "arboleda se abre un camino de tierra posiblemente creado por el paso de los animales, "
  	   "que serpentea entre los pastos en un armonioso juego de luces y sombras. "
  	   "Al final del valle se puede observar una alta muralla de color marfil, parece ser una "
  	   "ciudad oculta en el valle, aunque nunca oiste a nadie hablar de algo similar.\n");

  set_zone("nivelseis");
  "/d/turkhun/handler/handler_criaturas.c"->crear_criaturas("nivelseis",TO);  
  break;

}
   
  set_light(50);
  set_dark_long("Esta muy oscuro.\n");
  exit_color="%^BOLD%^YELLOW%^";
}

