
#define CREATOR "grimfang"

inherit "/std/room.c";
    
void setup()
 {
  set_short("%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: Haren%^RESET%^");
  set_long("\n%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: Haren%^RESET%^\n\n"
           "Bienvenido a el haren de Grimfang. El perfume de las 'mujeres' te envuelve nada mas "
           "entrar en la habitacion. Mientras tratas de recordar cuando has muerto y ascendido a "
           "los cielos te deleitas contemplando a lindas jovencitas de todos los tamanyos, colores,"
           " y ... sabores! Muchachitas rubias de ojos azules y blanca piel, mulatitas de pelo negro "
           "rizado y ojos morenos, y todas estan dispuestas a satisfacer tus deseos. Una gran 'cama' "
           "en forma de corazoncito descansa en el centro de la habitacion, lista para ser usada. "
           "Que aproveche!\n\n");
  add_exit("dormitorio","/w/grimfang/workroom2.c","door");
  add_property("no_undead",1);
  set_light(40);
  add_item("mujeres","Muaahhahwahwahhahahwahhhahahhahahahhahahahhahaa, auuuuuuuuuuuuuuuuuuuuuu"
                     "uuuuuuuuu, arf arf arf arf arf arf, Te dije que me volvia locaaaaaaaa.");
  add_item("cama","Es una cama en forma de corazon, con el suficiente tamanyo para contener a "
                  "Grimfang y a varias de sus mujercitas. Las sabanas estan hechas de seda y son "
                  "de color fucsia, al tumbarte sobre ella compruebas que los muelles son muy "
                  "resistentes y que podrian aguantar a cien caballos galopando sobre ellos.");
     
 }
