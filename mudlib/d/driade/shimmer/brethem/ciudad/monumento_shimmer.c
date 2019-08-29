/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("white");
   set_short("%^BOLD%^%^WHITE%^Monumento a  %^BOLD%^BLUE%^S H %^RESET%^%^CYAN%^I M M %^BOLD%^%^BLUE%^E %^BLUE%^R%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Monumento a  %^BOLD%^BLUE%^S H %^RESET%^%^CYAN%^I M M %^BOLD%^%^BLUE%^E %^BLUE%^R%^RESET%^\n\n"
             "Ante ti, sobre un enorme pilar de un material oscuro y reluciente se alza imponente una "
             "gran estatua de un guerrero humano, cuando la miras un escalorio te recorre el cuerpo de "
             "arriba abajo, dejandote despues una sensacion de calma y tranquilidad que jamas habias tendo.\n\n");
             




   add_sound(({"silencio","aire","estatua","shimmer"}),
            "   No sabes por que pero un silencio absoluto rodea la zona. La gente se limita a contemplar la estatua "
            "maravillados con su belleza. No hay mas sonidos que los que tu cuerpo genera, si te concentras puedes oir el "
            "latir de tu propio corazon.\n");
 
   add_item(({"estatua","shimmer"}),
           "   Cuando elevas la mirada para centrarla en la estatua un leve brillo te ciega debilmente por unos "
           "segundos, entonces logras ver la figura de un humano joven, fuerte y robusto. Si te fijas en su cara, "
           "puedes ver una gran cicatriz, el pelo le cubre media cara pero puedes reconocer en ella un gesto de victoria "
           "y regocijo en. Su torso lo cubre una gran coraza y en su mano derecha, alta y firme elevandose hacia el "
           "cielo porta una gran espada, Veronika, que siempre le acompanyaba en sus aventuras. Cuando por fin "
           "alejas tu mirada de la estatua un escalorio te recorre el cuerpo de arriba abajo, dejandote despues una "
           "sensacion de calma y tranquilidad que jamas habias tendo.\n");
 

   add_item(({"base","pilar"}),
           "   Es un enorme pilar de alguna extranya roca negra y brillante. Colgando "
           "sobre el puedes ver un cartelito con algunas palabras. sobre el pilar descansa "
           "la gran estatua.  Cuando tocas la roca notas como una sensacion de calma te invade.\n");




 //  crea_npcs();





add_exit("norte",          BRETHEM + "monum14.c","standard");
add_exit("este",           BRETHEM + "monum13.c","standard");


}
