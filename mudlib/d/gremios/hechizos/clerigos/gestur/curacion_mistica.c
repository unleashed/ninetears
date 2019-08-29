/*** Mystical Heal Spell by Shauri ***/ 
/*** -> base spell by Wonderflug   ***/ 
 
#define MYSTIC_HEAL_SHADOW "/w/shauri/code/ducky/spells/mystic_heal_shadow.c" 
inherit "/d/gremios/hechizos/base.c"; 
 
#define	NOMBRE	"Curacion Mistica"
#define	NIVEL	6
#define	ESFERA	({"curadora"})
#define	ESCUELA	({"yvendur"})
#define	CANCION	"'Mistical Drainz'"
#define	TIPO	""

void setup() 
{ 
   set_spell_name(NOMBRE); 
   set_sphere(ESFERA);
   set_school(ESCUELA); 
   set_spell_level(NIVEL); 
 
   set_target_type("one"); 
   set_range(0); 
   set_line_of_sight_needed(0); 
 
   set_help_desc("Este hechizo envuelve al objetivo en un aura mistica de curacion, sanando " 
     "sus heridas muy deprisa. Sus efectos no son permanentes. El Clerigo ruega a su Dios "
     "Yvendur que le de fuerzas para hacer el Bien y este es compensado con algo de fuerza de su Dios.\n"); 
 
   set_gp_cost(NIVEL); 
   set_casting_time(1); 
   set_rounds( ({ "round1" }) ); 
} 
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet) 
{ 
   object ob; 
   int level=0; 
 
   if(wrong_alignment(caster)) { 
      punish_align(caster); 
      return 0; 
   } 
 
   if(!target) { 
      tell_object(caster, 
         "Tu hechizo falla ... no hay nadie aqui con ese nombre.\n"); 
      return -1; 
   } 
  
   if(target->query_mystic_heal_spell()) { 
      tell_object(caster, 
         "Tu objetivo ya esta curado por este hechizo.\n"); 
      return -1; 
   } 
 
   if(!quiet) { 
      tell_room(ETO,(string)caster->query_cap_name()+ 
         " canta, "+CANCION+".\n", ({target,caster})); 
      tell_object(target, "Tu cantas, "+CANCION+".\n"); 
   } 
 
   if(target == caster) { 
      tell_object(caster, "Formulas "+NOMBRE+" sobre ti mismo.\n"); 
      tell_room(environment(caster),(string)caster->query_cap_name()+ 
         " formula un hechizo sobre si mismo.\n",caster); 
   } else { 
      tell_object(target, (string)caster->query_cap_name()+ 
         " alarga un brazo apoyandolo sobre tu hombre y te sana " 
         "usando su poder mistico.\n"); 
    
      tell_object(caster, "Alargas un brazo tocando el hombro de "+ 
         (string)target->query_cap_name()+" y sanando sus heridas con tu poder mistico.\n"); 
             
      tell_room(ETO,(string)caster->query_cap_name()+ 
         " alarga un brazo tocando a "+target->query_cap_name()+", sanandole sus heridas.\n", 
         ({target,caster}) ); 
   } 
   level=(int)caster->query_level(); 
   ob=clone_object(MYSTIC_HEAL_SHADOW); 
   ob->setup_shadow(target); 
   target->add_extra_look(ob); 
   target->add_timed_property("mystic_heal_on",1,level); 
 
   return 0; 
} 
 
