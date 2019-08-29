#define YO "drakzten"

inherit "/std/room.c";

void setup () {

set_short("Entrada a la casa de "+capitalize(YO));

set_long(query_short()+"\n  Esta es la entrada de la casa del gran "+capitalize(YO)+" es muy bonita y humilde, puedes ver que es muy amplia y bien decorada, puedes ver en la puertas dos guardianes vigilando.\n\n");

add_item("puerta","Es una resistente y bonita puerta de madera.\n");

add_feel("puerta","Tocas la puerta.... un guardian te mira raro...\n");

add_exit("comun","/w/common","door");

add_exit("dentro","/w/drakzten/cocina","door");

add_exit("tralak","/w/drakzten/bosque/room/entrada_bosque","door");

add_exit("urghak","/d/urghak/common","door");

add_clone("/w/drakzten/guardian_drakzten.c",2);

}