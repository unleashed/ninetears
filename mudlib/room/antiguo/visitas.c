inherit "std/room";

object board;

setup() 
{
  add_property("no_undead",1);
  set_light(60);
  set_short("%^BOLD%^%^CYAN%^VISITAS : Libro de Notas y Sugerencias%^RESET%^");
  set_long("%^BOLD%^%^CYAN%^VISITAS : %^GREEN%^Libro de Notas y Sugerencias%^RESET%^\n\n"
           "Un enorme tablon descansa sobre la pared norte de esta " +
           "estancia. En el, los visitantes de estos reinos dejan sus " +
           "notas, opiniones, sugerencias, bugs, agradecimientos (o no) " +
           "y demas basurilla.\n\n");
//   add_clone("/d/driade/npcs/dummy.c",1);
//   add_clone("/w/leviathan/demon.c",1);
   add_exit("abajo","/room/entryroom.c","door");
   add_exit("banco","/room/banco.c","door");
}

void reset() {
   if(!board) {
     board = clone_object("/obj/misc/board");
     board->set_datafile("librovisitas");
     board->move(this_object());
     }
   ::reset();
}
