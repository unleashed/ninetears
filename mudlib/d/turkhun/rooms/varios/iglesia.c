//Lummen Oct'98

inherit "/std/room";
#define HAND "/d/oficios/clerigos/gestur/rooms/iglesia/hand_boda.c"
#include "/d/abarrach/path.h";


object placa;
void setup()
{
   set_short("%^BOLD%^Iglesia:%^MAGENTA%^ Bodas%^RESET%^");
   set_long("Te encuentras en la iglesia donde se celebran las bodas en "
   "Reinos de Leyenda. Aqui los clerigos se encargan de unir en matrimonio "
   "aquellos que deciden juntar sus vidas para siempre, o hasta que la muerte "
   "los separa como se suele decir. Puedes ver un altar al fondo adornado con "
   "flores y multitud de detalles. A los lados hay banquitos donde los asistentes "
   "pueden ver la boda. El pasillo que te lleba al altar esta adornado con una "
   "preciosa alfombra color rojo. Un clerigo espera cerca del altar.\n");
   set_light(60);
   add_exit("este", CIUDAD+"cruce1619.c", "door");
   add_clone(NPCGE+"cura_boda.c", 1);
   placa=clone_object("std/object");
   placa->set_name("placa");
   placa->set_short("placa");
   placa->set_long("Es una placa de un desconocido metal.\n");
   placa->set_read_mess("\nSi deseas casarte con alguien solo debes de "
   "tener 300 monedas de platino para pagar los anillos de boda y "
   "escribir el comando: %^BOLD%^casarse con <persona>%^RESET%^.\n\nPara "
   "mirar el registro de las bodas celebradas hasta el momento debes poner "
   "el comando: %^BOLD%^registro%^RESET%^.\n");
   placa->move(this_object());
   placa->reset_get();
}

void init()
{
  add_action("lista", "registro");
  ::init();
}

void lista()
{
   int i;
   mapping quienes = HAND->query_casarse();
   
   if(!m_sizeof(quienes))
   {
     notify_fail("Nadie se ha casado todavia.\n");
     return 0;
   }
   write("\nEl Registro de las bodas celebradas es:\n\n");
   for(i=0;i<sizeof(quienes);i++)
   {
      write("\t- "+capitalize(keys(quienes)[i])+" casado con "+
            capitalize(values(quienes)[i])+".\n"); 
   }
   write("\n\n");
   return 1;  
}

