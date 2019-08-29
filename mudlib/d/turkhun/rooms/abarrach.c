#include "/d/abarrach/rooms/special.c"
#include "../../path.h"
inherit "/std/outside.c";

void habitacion(int i)
{
int j;
  switch (i){
  	
  case 0:
  
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Ciudad de los Desterrados%^RESET%^");
  
  set_long("Tras cruzar las puertas, y el hechizo de ilusion externo de la ciudad"
           " has llegado a Abarrach, la ciudad de los desterrados, el lugar a donde"
           " la peor calanya de todos sitios viene a parar para refugiarse de las"
           " leyes y las sociedades que les persiguen. Si no eres uno de ellos y"
           " entras en la ciudad, salir vivo de ella sera una ardua tarea. Las"
           " leyes de la ciudad, son respetadas por todos, el robo y el asesinato"
           " no esta permitido, lo cual es cumplido por todos por un bien comun,"
           " aunque nunca esta de mas tener los sentido alerta para ver lo que se"
           " esconde detras de cada esquina.\n");
  
  set_zone("zonaneutral");
  
  case 1: 
  
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Interior de la Muralla%^RESET%^.");
  
  set_long("Caminas por el interior de la muralla de Abarrach. El color marfil del exterior se"
           " torna rojo fuego, y la sensacion de magia, se convierte en una sensacion de inseguridad"
           " que te persigue por toda la ciudad. En lo alto de la muralla puedes ver apostados guardias"
           " con arcos y maquinas de guerra para proteger a la ciudad y su contenido de intrusos, curiosos"
           " y cazarrecompensas de otras ciudades.\n");
  
   set_zone("zonaneutral");
  break;
  
  case 2:
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Calle Central %^RESET%^.");
  
  
  set_long("Caminas por una calle que corta Abarrach de norte a sur pasando por la plaza de la Luna Nueva."
           " La calle esta repleta de guardias armados por si acaso algun fisgon non grato logra colarse dentro"
           " de la ciudad. Esta calle divide los diferentes barrios en los que esta divida la ciudad, barrios"
           " ocupados por los diferentes gremios de proscritos, ladrones y asesinos, entre los cuales se ha"
           " establecido un consejo, el cual gobirna la ciudad.\n");

  set_zone("zonaneutral");

  break;
  
  case 3:
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Calle Central %^RESET%^.");
  
  
  set_long("Caminas por una calle que corta Abarrach de este a oeste pasando por la plaza de la Luna Nueva."
           " La calle esta repleta de guardias armados por si acaso algun fisgon non grato logra colarse dentro"
           " de la ciudad. Esta calle divide los diferentes barrios en los que esta divida la ciudad, barrios"
           " ocupados por los diferentes gremios de proscritos, ladrones y asesinos, entre los cuales se ha"
           " establecido un consejo, el cual gobirna la ciudad.\n");

  set_zone("zonaneutral"); 
  
  break; 
  
  case 4:
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Zona de los Ladrones%^RESET%^.");
  
  
  set_long("Estas en el barrio controlado por la cofradia del Baja Helrek y sus seguidores, el gremio de ladrones."
           " Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, se ha decidido que"
           " cada gremio reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas bajas, es el hogar de los ladrones y los suyos. Si no eres de la ciudad evita esta zona ya que"
           " tu espalda acabara siendo un colador. Si eres ladron, bienvenido, Helrek te hara un hueco en su cofradia,"
           " si eres proscrito simplemente disfruta, pero respeta a los alli presentes.\n");

  set_zone("zonaladrones");
  
  break;
  
  case 5:
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Zona de los Luchadores%^RESET%^.");
  
  
  set_long("Estas en el barrio controlado por la comunidad de proscritos luchadores y sus seguidores."
           " Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, se ha decidido que"
           " cada gremio reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas pocos cuidadas, y arenas de lucha, es el hogar de los luchadores y los suyos. Si no eres de la ciudad evita esta zona"
           " ya que encontrar pelea es muy sencillo. Si eres luchador, bienvenido, aqui podras encontrar todos los estilos de lucha en las"
           " diferentes arenas, si eres proscrito simplemente disfruta, pero respeta a los alli presentes o cobraras de lo lindo.\n");

  set_zone("zonaluchadores");
   
  break;
    
  case 6:
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Zona de los Asesinos%^RESET%^.");
  
  
  set_long("Estas en el barrio controlado por la cofradia del Baja Armadin y sus seguidores, el gremio de asesinos."
           " Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, se ha decidido que"
           " cada gremio reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas bajas y callejones oscuros, es el hogar de los asesinos. Si no eres de la ciudad evita esta zona ya que"
           " tu garganta acabara rajada antes de que sepas quien ha puesto su cuchillo en tu cuello."
           " Si eres asesino, bienvenido, Armadin estara encantado de ensenyarte sus tecnicas de emboscada y subterfugio,"
           " si eres un proscrito, eres bienvenido, pero cuidate ya que jugar con los asesinos puede ser tarea peligrosa.\n");

  set_zone("zonaasesinos");
  
  break;
  
  case 7:
  
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^Zona de los Bardos%^RESET%^.");
  
  
  set_long("Estas en el barrio controlado por Gabriel y sus seguidores, el gremio de Bardos."
           " Aunque todo el mundo tiene acceso a toda la ciudad, para afianzar las relaciones, se ha decidido que"
           " cada gremio reuna a los suyos y sus familias en una parte de la ciudad. Esta zona oscura con multitud"
           " de casas bajas, tabernas y prostibulos es el hogar de los bardos y los suyos. Si no eres de la ciudad evita esta zona ya"
           " que acabaras embriagado y hechizado. Si eres bardo, bienvenido, gabriel te ensenyara el arte del timo,"
           " si eres proscrito simplemente disfruta, pero cuidado no bebas mas de la cuenta.\n");

  set_zone("zonabardos");  
  
  
    
 
  


}

  
   
  set_light(50);
  set_dark_long("Esta muy oscuro.\n");
  exit_color="%^BOLD%^YELLOW%^";
}

