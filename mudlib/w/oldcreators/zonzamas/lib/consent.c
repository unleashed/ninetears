/* consent.c
 *
 * This mess by Wonderflug, til I convince someone to let
 * me put in a real consent system.
 * Basically properties the player can set himself.
 * Only ones that matters right now are resurrect, determines
 * whether the player wants to be resurrected or not,
 * and drinks, lets another player buy you a drink.
 */

mapping consents;
static mixed valid_consents;

string help()
{
  return "Uso: consentir <tipo> <on/off>\n\n"
    "Solo son validos los siguientes tipos: \n"
    "resurreccion:  Mantenlo a off para que nadie intente resucitarte sin tu consentimiento \n"
    "seguir: De los mas importantes, asegurate de tenerlo a off para que nadie te siga sin tu consentimiento\n"
    "reincarnation: Igual que resurreccion pero para el hechizo 'reincarnate'.\n"
    "autogolpear : (Nombre provicional) Cuando eres atacado para responder automaticamente, si no no empezaras peleas hasta hacer un matar <bicho> \n"
    "tag:Para jugar a juegos estupidos e inofensivos :D\n" 
    "beber:  Permite que otros jugadores te inviten a beber. (No conviene andar borracho)\n "  ;

}  

void create()
{
  consents = ([ ]);
  valid_consents = ({ "resurreccion","autogolpear", "seguir", "beber","tag",
                      "reincarnation"});
}

void consent_commands()
{
  add_action("change_consent", "consentir");
}

mixed query_consent(string which)
{
  return consents[which];
}

mapping query_consents()
{
  return consents;
}


int change_consent(string str)
{
  string which;
  int value;

  if ( str && sscanf(str, "%s on", which) == 1 )
    value = 1;
  else if ( str && sscanf(str, "%s off", which) == 1 )
    value = 0;
  else
  {
    write("Estado de tus consentir:\n");
    for (int i=0; i<sizeof(valid_consents); i++)
      write("Consentir para "+valid_consents[i]+" esta a "+
        (consents[valid_consents[i]]?"on":"off")+".\n");
    write("\nPara mas informacion 'help consent'.\n");
    return 1;
  }

  if ( member_array( which, valid_consents ) == -1 )
  {
    notify_fail("Tipo de consentir no valido.  Prueba con: "+
      implode(valid_consents, ", ")+".\nMira 'help consent' para obtener "
      "mas informacion.\n");
    return 0;
  }

  if ( !consents )
    consents = ([ which : value ]);
  else
    consents += ([ which : value ]); 

  // This looks nasty but just converts 1/0 back to on/off
  tell_object(this_object(), "Ok. Consentimiento para "+which+" cambiado a "+
    ((value==1)?"on":((value==0)?"off":(sprintf("%d",value))))+".\n");

  return 1;
}
