inherit "/std/bosque.c";



void setup()
{
   set_short("%^BOLD%^%^GREEN%^Jardin%^RESET%^ de %^BOLD%^%^BLACK%^Karn-Daragh%^RESET%^");

   set_long("%^BOLD%^%^GREEN%^Jardin%^RESET%^ de %^BOLD%^%^BLACK%^Karn-Daragh%^RESET%^\n\n"
      "   Una basta extensi�n verde en la que se alza enmedio un gran castillo de piedra. "
      "Rodeado por una verja de metal, como �nicas salidas estan la misma entrada de la verja, "
      "que lleva a la sala com�n en el cielo, y la puerta de la fortaleza, propiedad de Karn-Daragh. "
      "El jardin en si mas bien parece un bosque, lleno de arboles y plantas que solo dejan un peque�o"
      " sendero el cual lleva directamente de la entrada de la fortaleza. Durante el dia, la espesura "
      "parece tranquila y inofensiva, y transitar el sendero no te parece que vaya a resultar especialmente"
      " peligroso o dificultoso.\n\n");
   set_night_long("%^BOLD%^%^GREEN%^Jardin%^RESET%^ de %^BOLD%^%^BLACK%^Karn-Daragh%^RESET%^\n\n"
      "   Una basta extensi�n verde en la que se alza enmedio un gran castillo de piedra. "
      "Rodeado por una verja de metal, como �nicas salidas estan la misma entrada de la verja, "
      "que lleva a la sala com�n en el cielo, y la puerta de la fortaleza, propiedad de Karn-Daragh. "
      "El jardin en si mas bien parece un bosque, lleno de arboles y plantas que solo dejan un peque�o"
      " sendero el cual lleva directamente de la entrada de la fortaleza. Durante la noche, la espesura "
      "del jardin te da la impresi�n que te estubiera observando, y un sentimiento de inquietud recorre"
      " tu cuerpo al intentar cruzar el sendero.\n\n");

   add_item("sendero","Un sendero de tierra que lleva desde la entrada del jardin hasta la entrada de la fortaleza.\n");
   add_item(({"fortaleza","castillo"}),"Un enorme castillo de piedra se alza alrededor de la maleza. \n");
   add_item("verja","Una verja de metal limita el terreno, est� bastante elaborada y parece antigua.\n");
   add_item(({"planta","plantas","arbol","arboles"}),"Una extens�sima variedad de plantas y arboles, mayormente"
            " zarzales y plantas no muy agradables a la vista y al tacto. Los arboles por su parte son oscuros "
            "y parece como si la sombra de la muerte planeara sobre ellos.\n");
  
   add_exit("fuera","/w/common","door");
   add_exit("dentro","/w/karndaragh/entrada.c","door");
   "/w/common.c"->add_exit("Karn-Daragh","/w/jardin.c","door");
   
 
}