#define GOLPEAR   "/d/gremios/comandos/golpear.c"
#define MURO "/d/gremios/hechizos/mg/muro_ilusorio"

inherit "/obj/monster";
/*
void init()
{
 ::init();
add_attack_command(15,"furia",  "/d/gremios/comandos/furia",    "furia",0);
add_attack_command(16,"carga",  "/d/gremios/comandos/carga.c",  "carga",3);
add_attack_command(17,"drain",  "/d/gremios/comandos/drain.c",  "drain",3);
add_attack_command(18,"berserk","/d/gremios/comandos/berserk.c","berserk",3);

}
*/

void setup() {
set_name("Vigilante del Guild");
set_short("vigilante");
add_alias("vigilante");
set_race("human");
add_plural("vigilantes");
set_guild_ob("/d/gremios/misc/wizwar");
set_gender(1);
set_main_plural("vigilantes");
set_str(50);
set_con(40);
set_dex(25);
set_int(18);
set_wis(18);
set_cha(28);
set_long("Es un guerrero de los primeros tiempos, un autentico heroe mundialmente conocido, se ha ofrecido voluntariamente a defender el guild debido a los continuos ataques y saqueos que este sufre ultimamente. \n");
add_clone("/d/driade/prueba/obj/ammuleto_atlante",1);
add_clone("/d/driade/prueba/obj/anillo_atlante",1);
add_clone("/d/driade/prueba/obj/armadura_atlante",1);
add_clone("/d/driade/prueba/obj/botas_atlante",1);
add_clone("/d/driade/prueba/obj/capa_atlante",1);
add_clone("/d/driade/prueba/obj/maza_atlante",2);
add_clone("/d/driade/prueba/obj/brazalete_atlante",1);
add_clone("/d/driade/prueba/obj/guante_atlante",1);
add_clone("/d/driade/prueba/obj/pantalon_atlante",1);
add_clone("/d/driade/prueba/obj/yelmo_atlante",1);
init_equip();
set_max_hp(2500);
set_hp(2500);
set_max_gp(5000);
set_level(51);
set_heart_beat(2);
set_thac0(-115);
set_aggressive(0);
set_heart_beat(1);
}


int already_attacking(object me,object victim);





void event_enter(object enterer, string message)
{
       /* BUG, HAY Q LLAMAR A ::event_enter al finalizar cada return */
       string msg;
       int lvl, luchando = 0;
       if (!enterer) // la documentacion dice q hay q mirar esto
	       return;
       if (enterer->query_dead())
	       return;
       if (enterer->query_guild_name() == "caballero de jade") 
       {
           call_out("murito", 0, 1);
       }
}


void murito()
{
                if (TO->query_property("murito_hecho"))
                        return;
                MURO->cast_spell("sudeste", TO, 0);
                TO->ATP("murito_hecho", 1, 100);
}


int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
         return 1;
   if(member_array(me,victim->query_call_outed()) != -1)
         return 1;
return 0;
}

