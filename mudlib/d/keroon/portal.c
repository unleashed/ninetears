//Valar in The Middle :P 2003
inherit "/std/suboscuridad.c";
// #include "path.h";
void setup ()
  {
set_short ("%^WHITE%^Portal hacia Keroon%^RESET%^");
set_long ("%^WHITE%^Portal hacia Keroon%^RESET%^\n\n"
	  " Te encuentras en algun lugar a mitad del camino entre Keroon y la Sala de "
          "los portales. Desde aqui podras acceder a las distintas zonas del Reino de "
          "Keroon. Deberas elegir la salida por ti mismo.\n");

	add_exit("volver","/room/sala_portales","corridor");
   add_exit("ciu_keroon","/d/keroon/keroon/keroon_pobre/taberna_pollo_cojo.c","corridor");
	add_exit("minas","/d/keroon/minas/minas_119","corridor");
        add_exit("entrada_reino","d/keroon/entrada/entrada","corridor");
	add_exit("cementerio","/d/keroon/cementerio/cemen_84","corridor");

}
