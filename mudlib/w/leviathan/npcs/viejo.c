inherit "/obj/monster";
 

void setup()
{
set_name("soldado");
add_alias("viejo");
set_short("Viejo soldado");
add_plural("Soldados Viejos");
set_long("Es un viejo guardian de la mina que trabajaba en esta zona hasta que fue "
         "cerrada. Tras enloquecer decidio quedarse en estas tinieblas a esperar "
         "la llegada de su muerte. En su demencia no para de hablar de cosas extranyas, "
         "muchas de las cuales no tienen que ver con la realidad, aunque otras, "
         "las que menos son vivencias del pobre loco.\n");
set_race("dwarf");
set_guild("khazad dhum uzbad");
set_random_stats(12,15);
set_level(90);
set_gender(1);
set_al(-100);
set_aggressive(0);
set_wimpy(0);
set_max_hp(2000);
set_hp(2000);
adjust_money(2+random(1),"gold");
add_clone("/baseobs/weapons/twohandedsword.c",1);
add_clone("/baseobs/armours/fullplate.c",1);
add_clone("/baseobs/armours/gauntlets.c",1);
add_clone("/d/dendara/rooms/mina_secreta/items/yelmo_mithril.c",1);
add_clone("/baseobs/armours/botas.c",1);
   ::init_equip();
load_chat (20,
  ({
  1,"' La bestia morira el dia que poderosos guerreros y hombres santos lo decidan.\n",
  1,"' Estan atacando Kheleb-Dum.\n",
  1,"' En los almacenes escondi la desintegradora de gnomos.\n",
  1,"' Como anyoro a mi amada Chuchi.\n",
  1,"' La gran bestia solo podia ser invocada en salas capaces de albergarla.\n",
  1,"' Aun le debo pagar el yelmo al armero.\n",
  1,"' Del suelo salieron garras que le arrancaron las piernas, no debio invocarlo.\n",
  1,"' La vida es una tombola tom tom tombola, de luz y de coloooooorrrrrr.\n",
  1,"' Tras una roca encontre un camino hacia una aldea de seres pequenyitos.\n",
  1,"' Laoielisha ollelinleslloea lealileesha.\n",
  1,"' Dile a Durin que Temoden sigue vivo y te reconpensara.\n",
  1,"' Ojala Temoden siga curando a todos los que se lo solicitan.\n",
  1,"' Nadie me creyo cuando encontre un arbol que daba melones de oro.\n",
  1,"' Si comes muchas manzanas tendras estrenyimiento.\n",
  1,"' En un lugar de Kattak de cuyo nombre no quiero acordarme.....\n",
  1,"' Llamadme Ismael.\n",
  1,"' Soy un pollo gigante cocoricoooooooo.\n",
  1,"' En la lejana casa de un halfling habia una puerta secreta a un mundo desconocido.\n",
  1,"' Asoma la patita por debajo de la puerta.\n",
  1,"' Marchese senyor aventurero, marchese.\n",
  1,"' Cuando digo esta ciudad no digo esta ciudad, digo  KHELEB-DUM.\n",
  1,"' Las pocimas de la bruja te daban mas fuerza de momento pero a la larga te debilitaban.\n",
  1,"' Si abres los tres sellos el espiritu del bien inmovilizara a la bestia marina.\n",
  1,"' Uno de los barriles de aguardiente contiene una pocima de poder.\n", 
  1,"' La armadura de aquel monstruo era casi inutil si no se transformaba.\n",
  1,"' Si invocas a los caballeros de la bondad te protegeran largo tiempo.\n",
  1,"' Un ladron aprendio artes secretas en una prestigiosa academia.\n",
  1,"' Con la piel de un monstruo polar se hizo un abrigo estupendo.\n",
  1,"' Una mala hembra me contagio con unos bichitos muy molestos, pero menuda noche me hizo pasar.\n",
  1,"' Mama, soy un ninyo bueno y me lo he comido todo.\n",
  1,"' Hace anyos que perdi mis dientes, y mi prostata me esta matando. No tendreis alguna medicina?.\n",
  1,"' Los contrabandistas de mithril tienen poderosas armas escondidas en un sitio insospechado.\n",
  1,"' Cuenta la leyenda que un monstruo de mares lejanos tenia un poderoso arma pero era muy fragil.\n",
  1,"' El banquero pertenece a la mafia, si le das la contrasenya haras negocios con el.\n",
  1,"' Un de los minero es un poderoso guerrero.\n",
  1,"' Una vez alguien fumo junto a los barriles de aguardiente y todo volo por los aires.\n",
  1,"' Tengo diarrea, no tendreis unas hojas para limpiarme?.\n",
  1,"' No puedo, no puedo......\n",
  1,"' Veo dolor, mucho dolor.....\n",
  1,"' Me rio yo de los orcos.\n",
  1,"' Todos los duergars son tontos.\n",
  1,"' Apestas mas que un goblin.\n",
  1,"' Camarero, traigame un caldo de pollo.\n",
  1,"' Alejaos con vida mientras podais.\n",
  1,"' En realidad soy un viejo noble de Kheleb.\n",
}));
}
