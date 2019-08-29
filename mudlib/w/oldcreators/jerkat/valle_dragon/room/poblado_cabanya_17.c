inherit "/std/room";

void setup() 
{
   set_exit_color("CYAN");
   set_light(80);
   set_short("%^BLUE%^Cabanya de la Familia Llui%^RESET%^");
   set_long("%^BLUE%^Cabanya de la Familia Llui%^RESET%^.\n\n"
   "Has entrada a la cabanya de la Familia Llui. "
   "Es la tipica casa de arbol del poblado. Es muy senzilla,"
   "tiene todo lo que una familia de 3 sujetos puede necesita.\n"
   "Te llama la atencion una cama a la que le falta la pata la cual"
   " esta hechada en el suelo y un viejo cuadro de toda la familia"
   " junta.\n\n.");
   add_exit("abajo","w/jerkat/valle_dragon/room/poblado_valle_17","door");
   add_item("pata","Es una pata de madera desgastada.\n Parace estar hechada "
      "en el suelo expresamente ya que no parece estar rota.\nEsto te da a pensar.");		
   add_item("cama","La cama es la del padre de familia. "
      "Observas que le falta una pata, pero que no esta rota,"
      " sino que ha estado quitada dejando un hueco.");	   
}      
void init()
{
::init();
  add_action("accion_pata",({"poner","colocar"}));
}    
     
int accion_pata(string str)
  {
    if ((str=="pata en hueco") || (str=="pata en el hueco"))
	{
	write("Colocas la pata encajando perfectamente en el hueco.\n");	
	write("De repente la cama se empieza a mover, y aparece un tunel.\n"
		"Te quedas mirado atonito el tunel que acaba de aprecer\n"
		"Cuando de repente.... \n\n");
	TP->adjust_hp(-(2+random(3)));
	TP->move("w/jerkat/valle_dragon/room/guarida_familia.c");
	return(1);
	}
  }	