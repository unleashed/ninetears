// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";
object ob;
void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Paris%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar a ambos lados de la "
   "calzada observas un grupo de casas echas de piedra en la parte delantera "
   "una higuera decora el jardin, en el cual un petirrojo esta posado en una "
   "rama mientras es observado por una mujer que pasea por el mismo entre "
   "petunias, a salvo gracias a una hilera de columnas que rodea la propiedad."
   "Observas un escaparete de una tienda que parece comprar y vender de todo "
   "lo habido y por haber");
   add_exit("norte"   ,ANDUAR"ao1507.c","road");
   add_exit("sur"     ,ANDUAR"cruce1707.c","road");
   add_exit("dentro"     ,ANDUAR"tienda","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}

void init()
{
ob=find_object("/d/anduar/npcs/rutic.c");
if(!ob)
{
	//tell_object(find_player("ather"),"NO ENV\n");}
	clone_object("/d/anduar/npcs/rutic.c")->move(TO);}             
  ::init();  
} 


