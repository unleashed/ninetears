// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/w/kryger/handler/base_zona.c";

void setup()
{
   // Disponible para usar con sar
   habitacion(0);
   //Espacio para un sar
   add_exit("norte"   ,"/w/kryger/handler/a0717.c","road");
   add_exit("sudeste" ,"/w/kryger/handler/a0717.c","road");
}
