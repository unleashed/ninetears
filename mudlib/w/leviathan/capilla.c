inherit "/std/noncombat.c";
void setup() { 
set_short("%^BOLD%^WHITE%^Capilla de %^BOLD%^RED%^"+TP->query_cap_name()+"%^RESET%^.");
  set_long("%^BOLD%^WHITE%^Capilla de %^BOLD%^RED%^"+TP->query_cap_name()+"%^RESET%^.\n"
	" Aqui es donde se realizan los mas crueles ritos satanicos, bajo la "
	"estricta supervision de Leviathan. Aquel que realiza mal los ritos "
	"es utilizado por otro aprendiz en el siguiente rito, la vida es dura "
	"y los debiles no sobreviven....\n\n"
	"Quedate aqui, y las almas de los muertos te protegeran de todo mal.\n");

   set_light(30);
   add_exit("fuera","/w/leviathan/workroom.c","door");
return(0);
}

void init()
{
  ::init();
  add_action("trampa",({"salir","exit","quit","retire"}));
}

int event_enter()
{
	write("Una sensacion de paz recorre tu cuerpo al entrar en la capilla, sabes"
	" que estas en un sitio seguro en el que podras meditar sin miedo a que te"
	" ataque alguien... \n\n");
return 0;
}

int trampa()
{
 write("\nAbandonar aqui significaria la muerte en el siguiente rito.. vete rapido!!!.\n\n");
 return 1;
}
