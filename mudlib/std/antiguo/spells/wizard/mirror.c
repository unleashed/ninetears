/*** MIRROR IMAGE ***/
/*** NPC friendly, coded by Wonderflug ***/

#include "tweaks.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Mirror Image");
  set_spell_level(2);
  set_school("conjuration");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell creates several mirror images of the target that "
    "surround them.  These images are indistinguishable from the "
    "target, and often attackers will be confused as to which one the "
    "real target is.  When a clone is hit, it is destroyed.  The number "
    "of clones created is dependent on the caster's level.  Smart "
    "and experienced attackers may see through the images straight to "
    "target, however.");

  set_gp_cost(MIRROR_GP);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shadow;
  int num_images;

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( target->query_mirror_spell() )
  {
    if ( target == caster )
      tell_object(caster, "You already have mirror images.\n");
    else
      tell_object(caster, "Your target already has mirror images.\n");
    return -1;
  }

  num_images = (int)caster->query_level() / MIRROR_IMAGES_PER_LEVEL;
  num_images += random(5) - 4;  /* fiddle it a bit */
  num_images = num_images>12 ? 12 : ( num_images<=0 ? 1 : num_images );

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'sancti numbro duplis'.\n", 
      caster);
    tell_object(caster, "You chant, 'sancti numbro duplis'.\n");
  }

  if ( target != caster )
    tell_object(caster, "You make "+num_images+" clones of "+
      target->query_cap_name()+" appear.\n");

  tell_object(target, "Suddenly "+num_images+" mirror images of you "
    "appear and array themselves around you.\n");
  tell_room(environment(caster), num_images+" duplicates of "+
    target->query_cap_name()+" suddenly appear.\n",
    ({ target, caster }) ); 

  shadow = clone_object(MIRROR_SHADOW);
  shadow->setup_shadow(target,num_images); 
  target->add_extra_look(shadow);

  return 0;
}
