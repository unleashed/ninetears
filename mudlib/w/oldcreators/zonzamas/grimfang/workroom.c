 #define CREATOR "grimfang"
 inherit "/std/room.c";
 void setup()
 {
   set_short("%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: "
      "Sala de %^RED%^Mando%^RESET%^");
   set_long("\n%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: "
      "Sala de %^RED%^Mando%^RESET%^\n\n"
      "Te encuentras en los dominios de Grimfang, el Dios "
      "de la Guerra. Aqui es donde toma sus decisiones y toman forma "
      "todos sus designios. En el centro de la sala se halla una gran "
      "mesa redonda de madera pulimentada. Reposando sobre esta puedes "
      "ver una enorme 'maqueta', recorrida por motitas de polvo que se "
      "mueven de un lado a otro. Al fondo de la sala se encuentra el "
      "'trono' del Dios de la Guerra, que en estos momentos se halla "
      "desocupado afortunadamente para ti. Mientras empiezas a pensar "
      "que haria Grimfang contigo si te encontrara en sus oscuros dominios "
      "posas tu mirada en una estanteria con multiples repisas, repletas "
      "todas ellas con los restos momificados de craneos de todas las razas, "
      "los 'trofeos' del Dios de la Guerra. Buscas el craneo correspondiente a "
      "tu raza desesperadamente, no vaya a ser que no se encuentre entre la "
      "coleccion de Grimfang y este decida solucionarlo... contigo. Oyes "
      "pasos que se acercan, lentos pero firmes. El suelo empieza a temblar. "
      "Un fuego abrasador empieza a recorrer toda la sala, no parece quemar "
      "nada excepto a ti. Crees que va siendo hora de abandonar esta sala.\n\n");
   add_exit("comun", "/w/common","door");
   add_exit("entrada","/room/entryroom.c","door");
   add_exit("dormitorio","/w/grimfang/workroom2.c","door");
   add_exit("ab","/w/grimfang/rooms/home/forja.c","door");
   add_property("no_undead",1);
   set_light(40);
   add_item("maqueta","Ante ti se muestra una especie de maqueta "
                      "que se asemeja a muchos de los mapas de Driade que has observado "
                      "a lo largo de toda tu vida. Sin embargo, esta maqueta esta "
                      "realizada con gran precision y detalle. Al acercar mas la vista "
                      "puedes observar como esas motitas de polvo son, en realidad, los "
                      "moradores de Driade, que corren de aqui para alla, ajetreados, "
                      "ocupados en sus asuntos, carentes de interes para ti. Piensas que "
                      "seria divertido dejar caer esa roca sobre la cabeza de aquel granjero, "
                      "pero no crees que a Grimfang le gustara que traqueteases con sus "
                      "juguetes.");
   add_item("trono","Observas el regio trono que se encuentra ubicado al "
                    "fondo de la sala. Te quedas embelesado observando su belleza. Adornado "
                    "con gemas de una talla exquisita, el trono esta hecho en su totalidad con "
                    "Galvorn, un metal tan duro como el acero de los Enanos, pero tan maleable "
                    "que resulta flexible, lo que le da una gran comodidad y resistencia.");
   add_item("trofeos","Sientes una leve sensacion de nausea al observar los "
                      "restos de seres vivos que constituyen los trofeos del Dios de la Guerra. "
                      "Entre ellos destaca una gran cabeza de Minotauro, con unos cuernos "
                      "descomunales y las cuencas oculares un tanto deformadas. Esta marcada "
                      "con una etiqueta en runas orcas, que dice: Aokromes el Vizco Cabron.");
 }





