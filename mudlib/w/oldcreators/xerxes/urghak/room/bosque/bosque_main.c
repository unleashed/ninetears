/* 
   Bosque de Urghak (sin ranitas)
   ------------------------------
   Xerxes, 2002
*/

inherit "/std/outside.c";

     string long = "%^BLACK%^BOLD%^Bosque de %^RESET%^GREEN%^Urghak%^RESET%^\n\n"
      "Este bosque es de los mas antiguos segun los olvidados documentos "
	"de los historiadores humanos. Se cuenta que fue levantado por "
	"el mismisimo shaman J'Zhadra, como manera de proteccion contra los "
	"incesantes ataques enemigos: es por ello que las hojas secas que "
	"pisas y los viejos troncos sobre los que te apoyas son producto "
	"de todo el odio y de toda la malevolencia que un shaman puede "
	"llegar a depositar en ellos. Los arboles, altos y esbeltos, "
	"apenas te dejan ver el cielo, que supones grisaceo y nublado. "
	"Bajando la vista de nuevo al suelo, compruebas que esta inundado "
	"de hojas muertas y humus, cuya monotonia es rota por cadaveres "
	"descompuestos de seres del bosque que no podrias catalogar en "
	"ninguna raza conocida, y cuya carne seca es picoteada por algun "
	"que otro cuervo que planea entre los arboles.\n\n";
	
     string short = "%^BLACK%^BOLD%^Bosque de %^RESET%^GREEN%^Urghak%^RESET%^";

void do_desc(int do_short, int do_long)
{
    set_dark_long("%^BLACK%^BOLD%^Bosque de %^RESET%^GREEN%^Urghak%^RESET%^\n\n"
		"%^BLACK%^BOLD%^Absolutamente nada. Eso es lo que ves ahora mismo. "
		"temerosamente tanteas con tus manos el inmenso vacio del bosque, "
		"algo totalmente diferente a la espesura y la densidad vegetal que "
		"habia de dia. Te preguntas si los arboles juegan contigo, puesto que "
		"ademas de apartarse de tu vago camino, te parece oir sus malevolas risas. "
		"Quien sabe que es lo que traman.%^RESET%^\n");
    if (do_long)
	set_long(long);
    if (do_short)
        set_short(short);
    set_light(80);

    add_item(({"suelo", "hojas", "hoja"}),"Las hojas, muertas, yacen en el suelo, completamente "
	"inertes: estaticas por la falta de viento que las meza.\n");

    add_item(({"arbol", "arboles"}), "Los arboles, que parecen esperar "
	"el momento mas oportuno para dar cuenta de la poca vida que poseen, "
	"estiran sus ramas hacia el cielo. Seguramente les gusta estar aqui "
	"tan poco como a ti.\n");

    add_item(({"cielo", "nubes", "sol"}), "Como suponias, el poco cielo que ves "
        "esta cubierto por un denso manto de nubes grises.\n");
    
    set_zone("bosque_urghak");
} /* do_dest */