inherit "/d/gremios/hechizos/base";

void setup()
{
  set_spell_name("Holy Word");
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
  if(sizeof(target) < 2)
  {
    tell_object(caster,
      "There are no living beings here to be affected by Holy Word.\n");
    return -1;
  }
  if(!quiet)
  {
    tell_object(caster,
      "Agarras tu simbolo sagrado y respiras profundamente.\n"
      "Sosteniendolo fuertemente, lo muestras a todos.  El nombre de\n"
      "tu dios resuena a lo largo y ancho de los reinos, golpeando a\n"
      "aquellos que se encuentran a tu alrededor.\n"
      "Estas aturdido y cansado, tras canalizar tanto poder sobre ti.\n");
    tell_room(environment(caster),
      caster->query_cap_name()+
      " agarra "+caster->query_possessive()+" simbolo sagrado, y lo muestra\n"
      "a todos con una amplia sonrisa. "+caster->query_pronoun()+" respira profundamente, \n"
      "y cierra "+caster->query_possessive()+" ojos. De repente, un berrido "
      "criminal de \n"+
      capitalize(caster->query_guild_name())+
      "! llena la zona. La fuerza del sonido te golpea.\n"
      "Te recuperas lentamente, pero estas aturdido y confundido.\n", caster);
  }

  for(i=0;i<sizeof(target);i++)
  {
    level = (int)target[i]->query_level();
    target[i]->clear_attackers();
    if(!target[i]->query_creator())
    {
    shadow = clone_object("/d/gremios/hechizos/cleric/h_word_sh1.c");
    shadow->setshadow(target[i],caster);
    if(target[i] == caster)
      call_out("hw1_wear_off", 12, target[i]);
    else
      call_out("hw1_wear_off", 20, target[i]);
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
