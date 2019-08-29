#define CREATOR "enialish"
inherit "/baseobs/weapons/bastard_sword.c";
void setup() {
set_base_weapon("bastard sword");
set_name("Espada de Elhadrien");
set_short("%^BOLD%^Espada%^RESET%^ de %^BOLD%^CYAN%^Elhadrien%^RESET%^");
set_long("Esta espada es una obra maestra de la artesania belica de los elfos "
"y solo esta raza posee la destreza necesaria para emplearla. Su larga hoja "
"esta ligeramente curvada y tiene unos dibujos tallados a lo largo y la "
"empunyadura esta decorada con una esmeralda en el centro para darle un toque "
"de elegancia.\n");
set_main_plural("%^BOLD%^Espadas%^RESET%^ de %^BOLD%^CYAN%^Elhadrien%^RESET%^");
add_alias("espada");
add_alias("elhadrien");
add_plural("elhadriens");
add_plural("espadas");
set_enchant(1);
add_property("race",({"Elfo"}));
add_timed_property("evil",10,999999);
add_timed_property("messon","Sientes el poder de la magia en tus manos y la "
"necesidad de batalla en tu alma.\n",9393939);
add_timed_property("messoff","Bajas tu arma y la necesidad de combate cesa "
"por el momento.\n",9393939);
}
