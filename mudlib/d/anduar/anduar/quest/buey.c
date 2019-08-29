#include "standard.h";
inherit "/obj/monster";

void setup()
{
   set_name("buey");
   set_short("Buey");
   add_alias("buey");
   set_gender (2);
   set_str(20);
   set_cha(15);
   set_dex(17);
   set_level(15+random(2));
   set_max_hp(150);
   set_hp(150);
   set_weight(100);
   set_long (" Ves un gran buey, con unos grandes cuernos, que pasta en el"
            "prado.\n");
   set_wimpy (20);
   set_main_plural("Bueyes");
   add_plural("bueyes");
   load_chat (10,
      ({
       5, ":pasta de la hierba.",
      }));
   load_a_chat (100,
      ({
       80, "' muuuuuuuuuuuuuuuuuuu"
      }));
   set_move_after (1,5);
}
 
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack () {

  int auan,apeix,agromenauer,joronya;
  auan=random(2);
  apeix=random(3);
  agromenauer=random(4);
  joronya=random(5);

  return ([
    "punch"   :({ AN+" "+({"muerde","golpea","roza",})[agromenauer]+
                " a "+DN+" en "+({"la mano","el pie","la pierna","el cuello","la ingle",})[joronya]+
                ".\n",
                 "Pegas a "+DN+".\n",
                  AN+" te "+({"muerde","golpea","roza",})[agromenauer]+
                  " en "+({"el brazo","la pierna","el cuello","la ingle","el pie",})[joronya]+
                  ".\n"}),
    "kick"    :({ AN+" "+({"muerde","golpea","roza",})[agromenauer]+
                " a "+DN+" en "+({"la mano","el pie","la pierna","el cuello","la ingle",})[joronya]+
                ".\n",
                 "Pegas a "+DN+".\n",
                  AN+" te "+({"muerde","golpea","roza",})[agromenauer]+
                  " en "+({"el brazo","la pierna","el cuello","la ingle","el pie",})[joronya]+
                  ".\n"}),
    "knee"    :({ AN+" "+({"muerde","golpea","roza",})[agromenauer]+
                " a "+DN+" en "+({"la mano","el pie","la pierna","el cuello","la ingle",})[joronya]+
                ".\n",
                 "Pegas a "+DN+".\n",
                  AN+" te "+({"muerde","golpea","roza",})[agromenauer]+
                  " en "+({"el brazo","la pierna","el cuello","la ingle","el pie",})[joronya]+
                  ".\n"}),
    "headbutt":({ AN+" "+({"muerde","golpea","roza",})[agromenauer]+
                " a "+DN+" en "+({"la mano","el pie","la pierna","el cuello","la ingle",})[joronya]+
                ".\n",
                 "Pegas a "+DN+".\n",
                  AN+" te "+({"muerde","golpea","roza",})[agromenauer]+
                  " en "+({"el brazo","la pierna","el cuello","la ingle","el pie",})[joronya]+
                  ".\n"})
  ]);}

int do_death(object ob)
{
   object carne;
   
   write("De una gran estocada terminas con la vida de el Buey. \n");
   say(TP->query_cap_name()+" propina el golpe mortal a Buey. \n");
   write("Al matar al animal, recoges un pedazo de carne de su cuerpo.\n");
   carne = clone_object ("/d/anduar/anduar/quest/carne.c");
   carne -> move (ob);
   return ::do_death(ob);
}
