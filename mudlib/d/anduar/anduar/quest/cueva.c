//Paris & Manu(Bevilac en el Spisa)

inherit "/std/room.c";

void setup()
{
   set_short("\n%^BOLD%^BLACK%^Cueva Oculta%^RESET%^.\n\n");

   set_long("   Es una cueva en la cual hay pieles de bufalo y de buey"
      " colgadas de las paredes, y un arco con flechas hecho a mano"
      " junto a la entrada. Hay un pequenyo fuego que ilumina la"
      " habitacion ligeramente.\n\n");

   set_light(20);
  
   add_smell(({"aire","habitacion"}),"Un olor acido envuelve toda la"
   " habitacion, debe ser por que esta constantemente cerrada.\n");
   add_item(({"piel","pieles"})," Tan solo son unas pieles colgadas"
   " y secas.\n");
   add_item("fuego"," Un pequenyo fuego que sirve para iluminar "
   "muy ligeramente la cueva, si no seria imposible ver.\n");

  add_exit("fuera","/d/anduar/camino_real2/real_b_1","path");
  add_clone("/d/anduar/anduar/quest/indio",1);
}
