inherit "/std/room.c";
#include "../../path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Caminos de Ormerod%^RESET%^.");
	set_long("%^BOLD%^YELLOW%^Caminos de Ormerod%^RESET%^.\n\n Es un camino sin, "
	"calzar, de arena y grava,tiene la anchura de dos carros, unos diez metros, "
	"en los bordes vemos piedras, redondas y de tamanyo medio, estan a lo largo de"
	" todo el camino.Despues de las piedras hay una cuneta de un metro mas o "
	"menos, es la separacion que tiene un camino con unos pastos que lo rodean.El "
	"camino esta muy marcado, con lo que apreciamos que esta en continuo uso.\n";
	set_light(50);
	set_zone("camino_ormerod");
	set_exit(