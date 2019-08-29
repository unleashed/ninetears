inherit "/obj/weapon";

void setup()
{
  set_base_weapon("twohanded sword");
  set_name("%^BOLD%^%^RED%^espada sangrienta%^RESET%^");
  set_short("%^BOLD%^%^RED%^espada sangrienta%^RESET%^");
  add_alias("espada");
  add_alias("sagrada");
  set_long("    Es una enorme espada con un mango grisaceo y una hoja "
     "larga y mellada con varios simbolos sagrados grabados en ella. Esta es "
     "la espada mas grande y hermosa que has visto en tu vida. Su hoja es "
     "como un hombre y supones el gran poder destructivo que posee.\n");
  set_main_plural("%^BOLD%^%^RED%^espadas sangrientas%^RESET%^");
  add_alias("espada");
  add_plural("espadas");
//  set_genero(1);
  set_twohanded(0);
}

void init()
{
 ::init();
 add_action("no_slice","slice");
}


int no_slice(string str) /* menudo bug, hay q comprobar q te puesta */
{ /* waaakaaaa, aunke este en el suelo xD se pilla esto */
write("Este arma no esta disenyada para hacer un slice.\n");
return 1;
}
