#define CREATOR "enialish"
#include "../path.h"
inherit "/std/outside.c";
void prepara_room() {
set_short("%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Muralla Exterior Sudeste%^RESET%^");
set_long("\n%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Muralla Exterior Sudeste%^RESET%^\n\n"
"Ante ti se levanta la muralla de Elhadrien, la mas impresionante "
"estructura defensiva que jamas han contemplado tus ojos. La base "
"de la muralla es de granito gris pero a un par de metros de altura "
"deja paso a un extranyo tipo de piedra blanca muy resplandeciente, "
"es por lo que se conoce a Elhadrien como la Ciudad de la Luz. Sus "
"almenas y torres se elevan orgullosas sobre la altisima muralla, "
"fruto sin duda de los mas habiles arquitectos de la ciudad. Aunque "
"su belleza la hace parecer fragil miles de orcos y goblins muertos "
"podrian decir lo contrario.\n\n");
set_light(60);
}
