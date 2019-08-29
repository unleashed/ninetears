inherit "/std/spells/base";

void setup()
{
  set_spell_name("Palabra Sagrada");
  set_spell_level(18);
  set_sphere("protection");
  set_target_type("all");
  set_range(0);
  set_help_desc(
   "This spell channels part of the force of the caster's god through\n"
   "a mighty shout.  All those within range will be stunned and incapcitated\n"
   "for some time.\n");
  set_gp_cost(35);
  set_casting_time(1);
  set_rounds( ({"round1"}) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level, i;
  object shadow;

// ESTO ES UNA GUARRADA, PERO NECESARIO POR AHORA, A FALTA DE HACERLO BIEN
// PARA KE ESTE HECHIZO: 1) NO SALGA CASI SIEMPRE INSTANT, COMO AHORA,
// Y 2) SEA COMO LOS DE MAGO, NO SE PUEDA LANZAR CONTINUAMENTE.
	if (caster->QTP("noholy")) {
		tell_object(caster, "No te encuentras preparado para volver a canalizar todo ese poder sobre tu cuerpo.\n");
		tell_room(ENV(caster), caster->QCN + " intentaba acumular poder para formular un hechizo, pero no fue suficiente.\n");
		return -1;
	}
	caster->ATP("noholy",1,60);

  if(sizeof(target) < 2)
  {
	// esto podria ser bug pq formular palabra a alguien con npcs
	// no saldria (a menos q el hechizo este puesto como all).
	if (random(3)) { // si no, nos comemos nuestro holy
    tell_object(caster,
      "Te das cuenta justo antes de gritar la Palabra Sagrada de que " 
	"no hay nadie aqui que pueda ser afectado.\n");
    return -1;
	}
  }
  if(!quiet)
  {
    tell_object(caster,
      "Agarras tu simbolo sagrado y respiras profundamente.\n"
      "Sosteniendolo fuertemente, lo muestras a todos.  El nombre de\n"
      "tu dios resuena a lo largo y ancho de los reinos, golpeando a\n"
      "aquellos que se encuentran a tu alrededor.\n"
      "Estas aturdido y cansado, tras canalizar tanto poder a traves de tu cuerpo.\n");
    tell_room(environment(caster),
      caster->query_cap_name()+
      " agarra "+caster->query_possessive()+" simbolo sagrado, y lo muestra\n"
      "a todos con una amplia sonrisa. "+caster->query_pronoun()+" respira profundamente, \n"
      "y cierra "+caster->query_possessive()+" ojos. De repente, un berrido "
      "criminal tipico de un \n"+
      capitalize(caster->query_guild_name())+
      "! llena la zona. La fuerza de su palabra te golpea.\n"
      "Te recuperas lentamente, pero estas aturdido y confundido.\n", caster);
  }

  for(i=0;i<sizeof(target);i++)
  {
    level = (int)target[i]->query_level();
    target[i]->clear_attackers();
    if(!target[i]->query_creator())
    {
    shadow = clone_object("/std/spells/cleric/h_word_sh1.c");
    shadow->setshadow(target[i],caster);
	// target[i]->add_property("passed out", "flipiandin");
	// como hacer q un npc no rebane en holy?
    if(target[i] == caster)
      call_out("hw1_wear_off", 12, target[i]);
    else {
	int total = 20+random(4); // calculado, en 23 se come carga
	//tell_object(target[i], "Estas stuneado "+total+" hearts.\n");
      call_out("hw1_wear_off", total, target[i]);
	}
    }
  }
  return 0;
}

void hw1_wear_off(object target)
{
  if(target)
  {
    target->destruct_hw1_shadow();
  }
}
