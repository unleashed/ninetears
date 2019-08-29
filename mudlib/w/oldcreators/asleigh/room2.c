inherit"/std/room.c";
void setup()
{
set_short("%^BOLD%^YELLOW%^Dormitorio de %^BOLD%^WHITE%^Asleigh");
set_long("Al entrar ves una preciosa  y amplia habitaci�n "
	"adornada con buen gusto por su due�a,los techos "
	"son altos aunque no parec�a una habitaci�n de "
	"estas dimensiones cuando entraste en ella por una "
	"verja. Las paredes est�n pintadas de un amarillo "
	"claro, da una sensaci�n de paz en el ambiente. En "
	"el centro puedes observar una gran cama,con s�banas "
	"de seda roja,en ella hay un collar con rubies "
	"engarzados,te llama mucho la atenci�n.Al fondo hay "
	"un peque�o escritorio de madera, uno de los cajones "
	"est� medianamente abierto. En el escritorio se encuentra "
	 "una peque�a lampara que alumbra la habitaci�n,pero no "
	 "demasiado.\n\n");
	
set_light(4);
add_item("Lampara","Observas una peque�a lampara antigua"
	 "de aceite,su luz alumbra una pequenya parte de"
	 "la habitacion.\n");
add_item("Cama","Es una gran cama de roble,el color es exactamente "
	"igual al de la mesa de trabajo.Parece bastante c�moda,se "
	"debe descansar bien entre esas s�banas.\n");
add_item("paredes","Las paredes est�n pintadas de un amarillo claro "
	" que da una sensaci�n de tranquilidad al ambiente.\n");
add_item("collar","Ves un largo collar de oro con rubies engarzados "
	"tirado en la cama.\n");
add_item("espejo","Ves un extra�o espejo con un aura muy raro,te "
	"que habr� dentro....\n");
add_item("escritorio","Ves un antiguo escritorio de madera, tiene un "
	"color parecido a la madera de la cama, ves un caj�n medio abierto.\n");
add_item("caj�n","Ves uno de los cajones del escritorio abierto,a lo "
	"mejor hay algo dentro...\n");	
 
add_exit("verja", "/w/asleigh/workroom.c","door");

}

 void init() 
   {
     ::init();
     add_action("entrar_espejo","entrar");
     add_action("abrir_caj�n","abrir");
     add_action("leer_carta","leer");
   }
      
 int entrar_espejo (string str)
 {
   if(str=="espejo")
     {
       tell_object(this_player(),"Comienzas a introducirte en el espejo y sientes "
		"una sensaci�n extra�a, un universo desconocido se abre ante ti.\n");
       tell_room(this_object(),this_player()->query_cap_name()+" Comienza a introducirse en el espejo.\n",
           this_player());
       add_exit("limbo","/w/danae/limbo/lm0103.c","door");
       renew_exits();
       modify_exit("limbo",({"function","permiso"}));
       return(1);
     }
   notify_fail("Nombrar que?.\n");
   return(0);
 }
 
 int permiso()
 {
   if(this_player()->query_creator())
   {
      tell_object(this_player(),"Pasa, Oh inmortal, y alcanza el destino que has deseado!\n");
      return(1);
    }
    notify_fail("Un mortal no deberia pisar siquiera estos aposentosi!!!!\n");
    return(0);

 }
   int abrir_cajon(string str)
   {
 	if(str=="cajon")
   {
   	tell_object(this_player(), "Te acercas y abres el caj�n para ver que "
   		"hay dentro y descubres un papel escrito.\n");
   	tell_room(this_object(),this_player()->query_cap_name()+" Comienza a abrir el caj�n "
   		"y encuentra una carta .\n",
           this_player());
         return(1);
        }
        notify_fail("abrir que?.\n");
        return(0);  	
  }
  	int leer_carta(string str)
  	{
  		if(str=="carta")  
  	{
  	tell_object(this_player(),"comienzas a leer la carta y te quedas inmovilizado "
  		"cuando te das cuenta que lo �nico que pone en la carta es: %^BOLD%^RED%^ ERES "
  		"UN COTILLO %^RESET%^. Pero si te interesa ver algo interesante entra en el espejo.\n");
  	tell_room(this_object(),this_player()->query_cap_name()+"Comienza a leer la carta y se queda "
  		"inmovilizado por unos instantes.\n", this_player());
  	return(1);
}
	notify_fail("leer que?.\n");
	return(0);
}
	