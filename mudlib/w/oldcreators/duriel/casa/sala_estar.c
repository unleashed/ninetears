#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^sala de estar %^RESET%^.");
  
  set_long(" Te encuentras en una sala enorme, el vapor sale de tu boca al hablar y el sonido rebota por las paredes provocando un suave eco. Esto es la sala de estar, es aqui donde descansa en su tiempo libre despues de un duro dia de trabajo.\n\n"); 

  set_light(80);
  add_exit("sur","/w/duriel/casa/recibidor.c");
  
  add_exit("este","/w/duriel/casa/pasillo.c");
  

  add_item(({"sofa"}),
            "Un enorme sofa de piel de %^RED%^Wargo%^RESET%^.\n"
            "Ya se ve que es muy comfortable y caluroso.\n");
  
  add_item(({"television"}),
            "Un Magnifico Televisor con una pantalla panoramica y sonido Stereo.\n"
            "Parece que Duriel en su tiempo libre se lo pasa en grande.\n");


}







