inherit "/room/camino_avalon/camino_avalon.c";

void setup()
{
	do_desc(1);
add_exit("noreste","/room/entryroom","door");
add_exit("sudoeste","/room/camino_avalon/camino01","road");
add_exit("testarea","/room/zonas/main.c","door");
modify_exit("testarea", ({"function", "go_abajo",
"message", "@$N %^BLUE%^se va hacia la zona de testeo de areas... algo en tu interior te anima a seguir su ejemplo y buscar unos bugs para notificar...\n%^RESET%^"}));

return(0);
}

int go_abajo(string str, object ob, string special_mess)
{
        tell_object(ob, " \n\n%^BOLD%^YELLOW%^Estas en la room de testeo de areas, gracias por venir aqui, leete la \n"+
			"descripcion de la room, y suerte en la caza de bugs! \n"+
			"Tienes a tu disposicion el comando 'resucitar' y el comando 'plaza',\n"+
			"el primero es obvio lo que hace, y el segundo te permitira salir de una\n"+
			"zona en la que las salidas fallen, en ese caso, notifica desde esa misma \n"+
			"room el fallo, y utiliza el comando para poder salir del lio.%^RESET%^\n\n");
        return 1;
}


