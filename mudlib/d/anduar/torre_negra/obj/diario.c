inherit "/std/item.c";

void setup()
{
   set_short("Diario");
   add_alias("diario");
   set_long("Es un diario, con las puntas de cobre, y la tapa de cuero.\n\n");
}

void init()
{
   ::init();
   add_action("leer_diario","leer");
}

int leer_diario(string str)
{
   if(!str || str != "diario")
   {
      notify_fail("Leer que?");
      return 0;
   }
   tell_object(TP,"Martes, 4 de Marzo del anyo 29\n"
	" Oh dios mio, estoy tan emocionado, queria aventuras y las voy a "
	"tener, he salido de mi hogar en cuanto a salido el sol, en busca "
	"de esa maldita Torre Negra, la cual me cuentan mis padres que "
	"esconde el secreto mas bien guardado del mundo. Estoy seguro que "
	"despues de esto podre entrar al fin en la tan temida orden de los "
	"Antipaladines de Oskuro.\n\n"
	" Sabado, 19 de Agosto del anyo 29\n"
	" Siiiii!, la he encontrado, ahora solo falta encontrar eso, el "
	"problema es que nadie, nunca, lo encontro, espero tener suerte.\n\n"
	" Domingo, 20 de Agosto del anyo 29\n"
	" Esto es la peor pesadilla que jamas he tenido, hay zombies por "
	"todas partes, reclamando mi sangre caliente, y no, no se si podre "
	"seguir, mis heridas me debilitan mas cada dia, no lo se...\n\n"
	" Martes, 22 de Agosto del anyo 30\n"
	" No puedo soportarlo mas, ese monstruo se ha comido mi pierna derecha "
	"despues de arrancarmela, y no se, ni si podre salir de este maldito "
	"camino, estoy notando algo caliente encima de mi abdomen, creo que "
	"son mis intestinos, no lo se,. em mepiza afa llar lha vista, parde...\n\n");
	return 1;
}
