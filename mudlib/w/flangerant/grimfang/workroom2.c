
#define CREATOR "grimfang"

inherit "/std/room.c";

void setup()
 {
  set_short("%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: Dormitorio%^RESET%^");
  set_long("\n%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: Dormitorio%^RESET%^\n\n"
           "El dormitorio de Grimfang, pese a la violenta naturaleza de su amo, es un remanso"
           " de paz y tranquilidad, una sala relajante y llena de todo tipo de entretenimientos."
           " Al fondo de la estancia puedes ver una comoda 'cama' de un disenyo esplendido. Clavada"
           " a la pared hay una 'diana' un tanto peculiar, dispuesta para jugar. Tambien hay un "
           "munyeco de 'Sparring' plegable tirado en una esquina, crees que podrias desplegarlo "
           "sin problemas. Por ultimo una gran 'cadena' estereo reposa en un mueble apoyado en la pared,"
           " se trata sin duda de un regalo de Flangerant, traido de sus viajes a tiempos futuros.\n\n");
  add_exit("mando","/w/grimfang/workroom.c","door");
  add_exit("haren","/w/grimfang/rooms/home/haren.c","door");
  add_exit("balcon","/w/grimfang/rooms/home/balcon.c","door");
  add_property("no_undead",1);
  set_light(30);
  add_item("diana","Se trada de una diana un tanto peculiar. Esta compuesta por una plancha "
                   "de madera redonda, que tiene la cara de un tio muy feo y vizco con gafas "
                   "grapada a su superficie. Tres dardos de aspecto mortifero estan clavados con "
                   "fuerza en la diana. Para jugar deberas escribir <usar diana>.");
  add_item("cama","Una enorme cama con motivos goticos reposa al fondo de la sala. Esta limpia "
                  "y recien hecha, lista para hecharse a dormir o tumbarse a descansar."
  add_item("cadena","Una maravilla tecnologica de la era moderna. Con miles de botoncitos que no"
                    " sirven para absolutamente nada pero que quedan tan monos. Miles de "
                    "altavoces se distribuyen por toda la estancia. Entre tanto boton inutil "
                    "consigues encontrar el PLAY. Puedes encender la cadana escribiendo "
                    "<encender cadena>.");
  add_item("sparring","Aunque esta plegado y tirado en el suelo puedes apreciar que se trata "
                      "de un inconfundible Aokorki2002, todo un clasico de los dummies que se "
                      "adapta a los nuevos tiempos con innumerables ventajas, tales como voz y "
                      "sonidos, un aspecto totalmente renovado y exento de esos tan molestos "
                      "pixeles y, por supuesto, con 5 anyos de garantia, como todos los dummies "
                      "de Aokorki's, una autentica maravilla de dummy. Para desplegarlo escribe "
                      "<desplegar dummy>.");
                                                  
  return(0);
 
 }
void init()
 {
  ::init();
  add_action("usar_diana","usar");
  add_action("desplegar_dummy","desplegar");
  add_action("encender_cadena","encender");
  add_action("usar_cama","usar");
 }
    
int usar_diana(string str)
 {
  if (str=="diana")
   {
    write("\nCoges un dardo de la diana y apuntas con gran precision a el ojo sano de Aokromes, "
          "obteniendo un certero tiro que trepana su globo ocular\n\n");
    say(this_player()->query_cap_name()+" arranca un dardo de la diana y lo lanza con estilo, "
                                        "parece divertirse bastante, porque no pruebas tu?.\n\n");
   return(1);                                        
   }
   notify_fail("Para jugar a los dardos pon <usar_diana>.\n");
   return(0);
   }  
      
int desplegar_dummy(string str)
 {
  if (str=="dummy")
   {
    write("\nCoges el Aokorki2002 de la esquina y lo despliegas con un par de habiles maniobras. "
          "Te aseguras de que los repulsores gravitatorios funcionan correctamente y te dispones "
          "a pasar un buen rato con tu Aokorki.\n\n")
    say(this_player()->query_cap_name()+" coge el Aokorki2002 y lo despliega rapidamente. Una "
                                        "sonrisa de satisfaccion recorre su rostro mientras se "
                                        "asegura de que el dummy se mantiene erguido.\n\n")
    clone_object("w/grimfang/npc/aokorki.c")->move(this_object());
   return(1);
   }
   notify_fail("No seria mejor que escribieras <desplegar dummy>?\n");
   return(0);
   }  
   
int encender_cadena(string str)
 {
  if (str=="cadena")
   {
    write("\nRELAX! Dont do it\n\nWhen you want to go to it\n\nRELAX! Dont do it\n\nWhen you want "
          "to come\n\n");
    say(this_player()->query_cap_name()+" enciende la cadena y empiezas a oir una extranya melodia."
          "\nRELAX! Dont do it\n\nWhen you want to go to it\n\nRELAX! Dont do it\n\nWhen you want "
          "to come\n\n");
   return(1);
   }
   notify_fail("Has probado <encender cadena>?\n");
   return(0);
   }
     
int usar_cama(string str)
 {
  if (str=="cama")
   {  
    write("\nTe sientes cansado y decides reposar un rato mientras esperas a Grimfang. A los pocos "
           "minutos de reposar en la mullida cama empiezas a sonyar con los angelitos.\n\n");
    TP->adjust_hp(500);
    say(this_player()->query_cap_name()+" deshace la cama de Grimfang y se acuesta a echar la "
                                         "siesta, durmiendose a los pocos minutos.\n\n");
   return(1);
   }
   notify_fail("Porque no <usar_cama>?\n");
   return(0);
   }
  }
   
