   inherit "/std/room.c";   void setup () {   set_short ("%^YELLOW%^ El rellano de %^BLUE%^%^BOLD%^ Turin Turambar %^RESET%^.
");   set_long (query_short()+"
     Estas en el segundo piso de la torre de Turin Turambar. Este lugar de la torre esta iluminado con una antorcha que proporciona la luz suficiente para ver. Cada paso que das resuena en todos los rincones de la torre y producen un eco que se repite muchas veces. Aqui es imposible pasar desapercibido.
");
   add_item ("antorcha","Una antorcha de un tamanyo mas grande de lo normal. Ilumina bastante mas de lo normal pero aun asi deja la habitacion con algunas penumbras.
");   add_feel ("antorcha","Al tocarla observas que no es ningun tipo de antorcha normal. Su material parece ser madera, sin embargo esta no se consume con el paso del tiempo.
");   add_exit ("este","/w/turin/workroom.c","door");   add_exit ("oeste","/w/turin/Eldesvandeturin.c","door");   add_exit ("abajo","/w/turin/Saladetrabajodeturin.c","door");  }
