   inherit "/std/room.c";   void setup () { 	   set_short ("%^YELLOW%^ El desvan de %^BLUE%^%^BOLD%^ Turin Turambar %^RESET%^.
");   set_long (query_short()+"
     Al entrar en la sala una sensacion de sabiduria y cultura te invade. Ves que en la sala hay un escritorio con pergaminos en blanco. Esta es la sala donde Turin Turambar escribe sus ideas y las guarda. Una lampara de aceite alumbra la sala. No hagas demasiado ruido no vaya a ser que molestes al duenyo.
");   add_item ("escritorio","Un viejo escritorio de nogal. Sus cajones estan llenos de pergaminos que no entiendes.
");   add_item ("lampara","Una sencilla lampara de aceite normal y corriente. Esta encendida.
");
   add_feel ("escritorio","AL tocarlo ves que, aunque viejo, el escritorio sigue teniendo una gran calidad, ademas de estar en perfecto estado.
");   add_exit ("este","/w/turin/Elrellanodeturin.c","door");
 }
