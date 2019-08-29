inherit "/std/room.c";
void setup()
{
set_light(80);
set_short("%^BOLD%^MAGENTA%^Habitacion%^RESET%^ %^BOLD%^CYAN%^de trabajo%^RESET%^ de %^BOLD%^WHITE%^Asleigh%^RESET%^");
set_long(" Te encuentras en la habitaci�n de trabajo de Asleigh, "
	"es una habitaci�n tranquila y amplia, las paredes "
	"est�n pintadas de un color amarillento que da alegr�a "
	"al cuarto para contrastar con el color de las paredes "
	"ves colgadas unas cortinas de un azul claro que no dejan "
	"ver lo que sucede en el exterior. En el centro ves colocada "
	"una mesa de roble,parece bastante antigua,pero de muy buena "
	"calidad, realmente llama bastante la atenci�n. De pronto te "
	"fascina un cuadro que hay colgado en la pared,la mujer del "
	"retrato es muy bella de rasgos suaves y con una mirada serena, "
	"que te hace sentir bien, el pelo largo negro contrasta con la "
	"palidez de su cara, estas seguro de que nunca has visto nada "
	"igual. En un peque�o rincon de la habitaci�n hay colocado un "
	"peque�o divan tapizado con seda roja,parece ser bastante c�modo, "
	"seguramente le resulte muy c�modo a Danae cuando est� muy cansada "
	"de realizar todo el trabajo diario. Danae no parece ser muy "
	"cuidadosa, en el suelo ves una serie de libros antiguos apilados "
	"en peque�as monta�as, junto con papeles repartidos por varios "
	"puntos de la habitaci�n.\n\n");
	
add_item("libros","Son antiguos libros de magica,apilados en el suelo "
	 "parece que los han utilizado hace poco tiempo.\n");
add_item("papeles","Al igual que los libros,estos papeles parecen contener "
	 "informaci�n sobre poderosos hechizos antiguos.\n");
add_item("mesa","Ves una gran mesa de roble,parece que podr�a soportar bastante "
	 "peso,debe ser muy util para el trabajo que realiza Danae.\n");
add_item("cuadro","Al fijarte en el cuadro puedes observar el retrato de una "
	 "de las mujeres m�s atractivas que jam�s has visto, su mirada te reconforta"
	 "y te inspira serenidad.\n");
add_item("divan","Ves una especie de sof� de seda roja,parece c�modo.\n");
add_feel("aire","Sientes una vaga sensaci�n de seguridad estando en esta"
	 "habitaci�n.\n");
	 
add_exit("comun","/w/common","door");
  "/w/common.c"->add_exit("danae","/w/danae/workroom","door");
  "/w/common.c"->renew_exits();
 
}
 
 void init()
 {
 	add_action("mover_mesa","mover");
 	::init();
}
	int mover_mesa(string str)
{
	if (str=="mesa")
	 {
	tell_object(TP,"Mueve la mesa descubriendo una peque�a verja escondia en el suelo.\n");
	tell_room(this_object(),this_player()->query_cap_name()+" mueve la mesa.\n",this_player());
	add_exit("verja","/room/void.c","door");
	renew_exits();
	return 1;
	 }

	tell_object(TP,"No puedes mover "+str+"\n");
	return 0;
 }

	

