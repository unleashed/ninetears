inherit "/obj/monster";

void setup(){
set_name("buho");
set_short("Buho");
set_long(query_short()+"\nUn peque�o buho con grandes unos grandes ojos y unas grandes alas.\n\n");
set_main_plural("Buhos");
add_alias("buho");
add_plural("buhos");
set_gender(2);
set_level(8+random(5));
set_random_stats(8, 12);
set_int(5);
set_wimpy(1);
load_chat(50,({
1, ":gira toda su cabeza.",}));
load_a_chat(100,({
3, ":trata de aranyarte con sus garras.",}));
}