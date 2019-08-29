  inherit "/std/room.c";  
  void setup () {   
  set_short ("%^YELLOW%^ Sala de Meditacion de %^BLUE%^%^BOLD%^ Turin Turambar %^RESET%^ .");  
  set_long (query_short()+"
     Entras en la habitacion y una sensacion de tranquilidad y desasosiego inundan tu alma y tu cuerpo. El suelo esta formado por un cesped mullido donde puedes tumbarte a descansar. Al fondo de la habitacion una fuente emite el claro, suave y relajante sonido del agua callendo despacio sobre las rocas. Hay muchas plantas de muchos tamanyos y colores que llenan la habitacion de colores armoniosos y vibrantes. El techo emite una luz que no consigues explicar de donde proviene.");  
  add_item ("cesped","Esta cuidado con mucha habilidad. Parece que esta recien cortado. Ves que brilla.");  add_item ("techo","Al mirarlo directamente te deslumbra. Te pones la mano frente a los ojos y ves que no tiene nada de especial salvo que emite un inexplicable brillo de luz muy intenso.");  
  add_item ("fuente","Al fondo de la habitacion ves una fuente que simula una cascada pequenya. El sonido del agua al caer sobre las rocas te relaja.");  
  add_item ("flores","No puedes reconocer ninguna de estas flores, pero sus aromas te resultan extranyamente familiares. Las hay de muchos tipos y colores.");  
  add_feel ("flores","Aunque son muy diferentes una de otras todas son suaves al tacto.");  
  add_feel ("fuente","La roca en la que esta fabricada esta pulida de manera que al tocarla no notas ninguna imperfeccion ni rugosidad.");  
  add_sound ("fuente","El suave sonido del agua al caer sobre la roca te aporta una sensacion de tranquilidad.");  
  
  add_exit ("oeste","/w/turin/Elrellanodeturin.c","door");  add_exit ("arriba","/w/turin/Saladecontemplacion.c","door");
-
  add_exit ("urghak","/d/urghak/common","door");

 }
