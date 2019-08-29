/*** Raise Dead Spell ****/
/*** origional author unknown ***/
/*** modified for use on FR-MUD by Eerevann ***/
/* Adding some nastyness, this makes the spell a more unstable.
 * they may loose a statpoint when they get raised, maybe even a con..
 * lover con, giver bigger chance to loose a stat.
 * Baldrick, jan '95
 */ 
/*** -> base spell, Wonderflug ***/


inherit "/std/spells/base.c";
#define	NOMBRE	"Levantacion de Muertos"
#define	NIVEL	5
#define	ESFERA	({"alteracion"})
#define	ESCUELA	({})
#define	CANCION	"'Necros Resurrectis'"
#define	TIPO	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo resucita a un espiritu de la muerte.  Le "
    "quitara uno de los puntos de constitucion, si no es resucitado, y seguira "
    "siendo un espiritu. Si el espiritu no espera volver de la muerte "
    "el hechizo fallara.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !target )
  {
    tell_object(caster, "Tu hechizo falla .. No hay nadie con este nombre "
      "aqui.\n");
    return -1;
  } 
  if (!target->query_dead())
  {
    tell_object(caster, (string)target->query_cap_name() + 
      " no esta muerto todavia.\n");
    return -1;
  }
  if (target->query_property("noregen"))
  {
    tell_object(caster, "Sinister te dice: ESPERA UN MOMENTO "
      "AUN NO HE ACABADO CON EL.\n");
    return -1;
  }
  if ( !target->query_consent("resucitar") )
  {
    tell_object(caster,"El espiritu no espera volver a la "
      "vida todavia. (mira 'ayuda consentir')\n");
    return -1;
  }

  tell_object(caster,"Llamas a los Dioses para poder liberar a "+
    (string)target->query_cap_name()+" de su estado inmaterial, con un haz de luz que asciende hasta los cielos\n");
  tell_object(target, (string)caster->query_cap_name() +
    " ruega a los Dioses que le den energia suficiente para devolverte a la vida.\n"
    "Un haz de luz comienza a ascender hacia las alturas.\n");
  tell_room(environment(caster),(string)caster->query_cap_name() + 
    " levanta las manos al cielo implorando a los Dioses que le den "
    "el suficiente poder para liberar a "+target->query_cap_name()+" de su estado inmaterial.\n", ({ caster, target }) );

  target->remove_ghost();

  return 0;
}
