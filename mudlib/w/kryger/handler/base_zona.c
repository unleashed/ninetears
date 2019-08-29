inherit "/std/outside.c";

void habitacion(int i)
{
  switch (i)
  {
  	
  case 0:
  set_short("%^BOLD%^BLACK%^Abarrach: %^RED%^La Ciudad Maldita%^RESET%^");
  
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
  "/w/kryger/handler/handler_bichos.c"->crear_criaturas("zona_neutral",TO);
  break;

}
   
  set_light(50);
  set_dark_long("Esta muy oscuro.\n");
  exit_color="%^BOLD%^YELLOW%^";
}

