/*  The feeling I've tried to picture is a combination of good (light, warmth
    peace, joy, contentment, happiness etc) with the chaotic nature of the
    sounds, birds, flowers, colors, etc.  I see Chaotic Good as random acts
    of kindness.  Striving for good but ... at random.
 
    Guilo Forgebane             [The Bearded One]
*/
 
//object shadow, special;
inherit "/std/sacroom";
 
void setup()  {
 
  set_light(80);
  add_property("no_clean_up",1);
 
  set_short("Catedral del Bien: Templo de Barthleby");
 
  set_long("\nCatedral del Bien:  Templo de la Bondad.\n\n"
           "   Luz y color junto con el sonido de los pajaros piando "
           "te dan la bienvenida al entrar en esta zona sagrada. "
           "Retratos de las mas heroicas batallas de las fuerzas del Bien, "
	   "y de los mas honorables Paladines decoran las paredes de "
           "marmol y granito de este templo. Sientes tu alma en completa "
	   "armonia y la paz te invade. Tus pensamientos forman escenas "
	   "de amor, paz y justicia.  En el centro del templo un Altar "
	   "bajo una enorme cupula te llama la atencion.\n"
           "\n");
 
  add_smell(({"flowers","wildflowers"}),
            "   The purfume of a thousand varieties of flowers greet your "
            "senses with a confusing blend of sweetness and strength.  Your "
            "head begins to swim in its overpowering fragrance.\n"
            "\n");
 
  add_feel(({"light","warmth"}),
           "   The light is bright but not painfully so.  It is warm, "
           "comforting and uplifting.  You feel at peace with the world "
           "even though the myriad of sounds and lights adds some confusion "
           "to the world.\n"
           "\n");
 
  add_sound(({"chirping","bird","birds"}),
            "   The birds let out a joyous song of peace.  There are "
            "thousands of different sounds filling the air and lending a "
            "kind of chaotic, confusing feeling to the shrine.\n"
            "\n");
 
  add_sound(({"animals","animal","scurrying"}),
            "   Forest animals of all shapes and sizes scurry and run "
            "through the trees and across the paths of this joyous place.\n"
            "\n");
 
  add_item(({"light"}),
           "   The sunlight streaming through the leaves of the trees is "
           "bright and warm, filling you with peace and contentment.  You "
           "wish you could stay here forever.\n"
           "\n");
 
  add_item(({"bird","birds"}),
           "   The thousands of different types of birds flit among the "
           "trees in a playful game of tag.  Their colors clash and blend "
           "with the surrounding leaves in a confusing array of light and "
           "sound.\n"
           "\n");
 
  add_item(({"animal","animals"}),
           "   These are common woodland animals but you notice both "
           "predator and prey playing together among the trees and paths.  "
           "It seems only peace and joy rule here.\n"
           "\n");
 
  add_item(({"flower","flowers","wildflower","wildflowers"}),
           "   The flowers provide a thick carpet of colors and hues.  They "
           "blend and contrast with the surrounding forest in random "
           "splashes of color.\n"
           "\n");
 
  add_item(({"trees"}),
           "   This area is not heavily wooded but the trees are many and "
           "large.  They provide grateful shade to the animals and people "
           "who come here to worship Hokemj.\n"
           "\n");
 
  add_item(({"water","stream","streams","pool","pools"}),
           "   Water flows freely among the trees and paths of the area.  "
           "It splashes and flows playfully over the sand and rocks.  You "
           "bend down to try some and find it cool and refreshing.\n"
           "\n");
 
  add_exit("abajo","/room/templo_bien","door");
  set_god_here("barthleby");

// Back in play - Elladan, June 1996
  //add_clone("/d/bf/banefall/mobs/helf.c",1);
}  /* setup */

/*
void event_enter(object ob)
{
  if(ob->query_name()=="opus" || ob->query_name()=="hokemj")
  {
   shadow=clone_object("/w/hokemj/sac_shadow.c");
   shadow->setup_shadow(ob);
   special=ob;
  }
}

void event_exit(object ob)
{
  if(ob->query_name()=="opus" || ob->query_name()=="hokemj")
  {
   ob->dest_sac_shadow();
  }
}
*/
