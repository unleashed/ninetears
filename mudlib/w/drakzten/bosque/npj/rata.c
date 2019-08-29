inherit "/obj/monster";

void setup(){
set_name("rata");
set_short("Rata");
set_long(query_short()+"\nUna peque�a, mugrienta y asquerosa rata que ronda buscando migas de pan o restos de comidas.\n\n");
set_main_plural("Ratas");
add_alias("rata");
add_plural("ratas");
set_gender(3);
set_level(3+random(5));
set_random_stats(8, 10);
set_int(5);
set_wimpy(1);
load_chat(50,({
1, ":corretea por todos lados.",
2, "'Cick! Cick!."}));
load_a_chat(100,({
3, ":chilla desagradablemente.",}));
}