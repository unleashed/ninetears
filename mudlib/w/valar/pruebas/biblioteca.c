// Valar 27-09-02 ---> Biblioteca

inherit "/std/biblioteca.c";



void setup()
{
   
   add_letrero("cartel");
   set_short("%^B_BLUE%^Biblioteca de los Dioses%^RESET%^");

   set_long("\n%^B_BLUE%^Biblioteca de los Dioses%^RESET%^.\n\n"
      "   Te encuentras en la zona mas recondita del paraiso celestial de los dioses. "
      "En esta biblioteca se encuentran los libros mas antiguos y preciados de toda la "
      "historia de los dioses. En ellos esta recogida todas su sabiduria y sus "
      "conocimientos. La sala esta algo abandonada desde su construccion quien sabe ya "
      "cuando.""\n\n");

   add_item(({"libreria","estanteria"}),"Contienen los miles y miles de libros con las "
   "historias, relatos e informacion sobre Ninetears.\n");
   

   add_item(({"paredes","techo","suelo"}),"Las paredes y techo se mantienen firmes aun, "
   "pero el suelo esta bastante estropeado con grietas y losas rotas.\n");

   add_smell(({"sala","biblioteca","aire"}),"El aire es puro y fresco y una suave brisa "
   "sopla por toda la sala.\n");
    
   add_bibliotecario("/w/valar/pruebas/mini-levi"); 
   
   //salidas
   add_exit("fuera","/w/common","door"); 
  

    

}