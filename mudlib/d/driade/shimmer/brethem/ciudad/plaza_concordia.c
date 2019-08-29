/* By Shimmer */

#define CREATOR "shimmer";

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   add_item("jardines" "jardin", "Son pequenyos jardincillos que adornan la plaza con bonitas flores.\n");   
   add_smell("jardin","Un olor fresco y humedo de flores te imprenga cuando te paras a respirar profundamente.\n");
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Plaza de la Concordia%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Plaza de la Concordia%^RESET%^\n\n"
       "La Calle del Mar se anchea en esta zona formando una pequenya plaza, hay varios bancos y jardincillos "
       "bien ciudados, con flores de todo tipo. Una fuente en el medio de la plaza sirve de bebedero para todas "
       "los habitantes que se acercan a echar un trago, el agua esta tan fresca que algunos perros, gatos y pajaros "
       "se revuelcan el los charcos que se forman en el suelo. Desde aqui puedes oir como el mar choca contra las "
       "rocas que forman el rompeolas que protege la zona de la bravura de las olas.\n\n");

   add_item("fuente" , "Una pequenya fuente de piedra de la cual brota un agua clara y transparente, te dan ganas "
            "de echar un trago y apaciguar tu sed.\n");

   add_clone(BRETHEM+"npcs/gato",random(2));
   add_clone(BRETHEM+"npcs/pajaro",random(0));
   add_clone(BRETHEM+"npcs/guardia",random(3));

add_exit("oeste",    BRETHEM + "mar7.c","standard");
add_exit("sudeste",  BRETHEM + "mar6.c","standard");
add_exit("norte",    BRETHEM + "parque3.c","standard");

}
