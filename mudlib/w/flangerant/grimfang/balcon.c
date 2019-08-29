
#define CREATOR "grimfang"
  
inherit "/std/outside.c";
  
void setup()
 {
  set_short("%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: Balcon%^RESET%^");
  set_long("\n%^BOLD%^Aposentos de %^GREEN%^Grimfang%^WHITE%^: Balcon%^RESET%^\n\n"
           "Mas que un balcon el lugar donde te encuentras podria calificarse de anfiteatro, pues "
           "sus dimensiones son gigantescas. Fabricado con un exquisito marmol de un blanco "
           "inmaculado, este balcon ofrece una de las vistas mas espectaculares de Driade, el "
           "Desierto de Margkhor. Su extension supera tu campo de vision, lo que te hace pensar que "
           "estas mirando hacia el norte de la Fortaleza de Margkhor, ubicada al sur del 'desierto'. "
           "Grandes dunas de arena avanzan impasibles conforme discurre el tiempo. El monotono "
           "paisaje te provoca una dulce sensacion de relajacion y, cansado, buscas una 'silla' "
           "y te sientas en una "
           "comoda mecedora de madera de roble junto a una gran 'mesa' circular del mismo material que "
           "el balcon. La mesa esta repleta de suculentos 'manjares' y deliciosos 'elixires', asi que "
           "supones que hace las veces de comedor para Grimfang. Come y bebe, y deshazte del cansancio"
           " del fatigoso viaje que has realizado. No creo que a Grimfang le importe que su invitado "
           "se relaje mientras lo espera, porque eres su invitado verdad?\n\n");
  add_exit("dormitorio","/w/grimfang/workroom2.c","door");
  add_property("no_undead",1);
  set_light(50);
  add_item("desierto","Un vasto desierto se extiende ante tus ojos. El desierto ejerce un efecto "
                      "hipnotizador sobre ti que te hace desear bajar ahora mismo y empezar "
                      "a deambular sobre las grandes dunas de dorada arena, pero tu sentido comun"
                      " se sobrepone y rechazas la idea de ponerte a caminar por el desierto, "
                      "pues sabes que no durarias mas de dos horas hay fuera. Se rumorea que el"
                      " desierto esta habitado por tribus de nomadas barbaros, que viajan de "
                      "oasis en oasis, pero solo son eso, rumores. Los unicos visos de "
                      "civilizacion que se han hallado en los desiertos de Margkhor han sido "
                      "los restos de la Fortaleza conquistada por los orcos, en otros tiempos "
                      "prospera y llena de vida, pero que ahora ha perdido todo su antiguo "
                      "esplendor.");
  add_item("barandilla","Una resistente barandilla de marmol blanco. Su tacto es frio y refresca "
                        "la piel de tus manos, aliviandote un poco del sofocante calor de este "
                        "clima desertico.");
  add_item("silla","Estas sentado en una comoda mecedora de madera de roble. Intentas recordar "
                   "si en el desierto crecen los robles pero el vivaz balanceo de la mecedora "
                   "te borra el pensamiento de la cabeza. Estas en tu hora de relajamiento, pasa"
                   " un rato calido y feliiiiiz, feliiiiiiiiz, feliiiiiiiiiiiiz, ahahhahhahha.");
  add_item("mesa","Una robusta mesa circular fabricada en marmol blanco, suave y frio al tacto."
                  " Su superficie se halla repleta de toda clase de manjares y elixires. Al "
                  "observar detenidamente la mesa te das cuenta de que no tiene patas. En efecto,"
                  " esta flotando magicamente a la altura de tus codos. Oyes una estupda voz en"
                  " tu cabeza que dice algo sobre orcos, magia y katapum, pero no le haces caso."
                  " De acuerdo, la mesa esta flotando en el aire... y a quien le importa?");
  add_item("manjares","Una multitud de suculentos platos dispuestos ordenadamente sobre la mesa"
                      " que emanan un delicioso y aromatizante olor despiertan tu apetito. Al "
                      "instante un par de cubiertos y un gran plato se materializan ante ti. "
                      "Vamos sirvete, estas en tu casa. Bueno era un decir, por supuesto no estas"
                      " en tu casa, pero ya que estas aqui disfruta de una deliciosa comida antes"
                      " de que Grimfang te mat... te reciba. Si quieres disfrutar solo tienes que"
                      " <comer manjares>.");
  add_item("elixires","Vinos, cervezas de todos los colores, refrescos gaseosos, hidromiel, y "
                      "muchas mas bebidas exoticas de las que pudieras imaginar se muestran a tu"
                      " alcance. Y lo mas importante, estan bien fresquitas. La sequedad de tu "
                      "dolorida gargante te recuerda que mas del 70% de tu cuerpo es liquido, o "
                      "era el 80%? Mmmm no me digas que eres de letras y no lo sabes. No te "
                      "preocupes, no importa, preparate a anyadirle un buen porcentaje de liquido"
                      "a tu cuerpo. Estas listo para <beber elixires>?");
                         
  return(0);  
 }
void init()
 {
  ::init();
  add_action("comer_manjares","comer")
  add_action("beber_elixires","beber")
 }
    
int comer_manjares(string str)
 {
  if (str=="manjares")
   {
    write("\nDegustas los suculentos manjares, picando de todo un poco hasta que ya no puedes mas "
          "y estas a punto de reventar.\n\n");
    TP->adjust_hp(100);
    say(this_player()->query_cap_name()+" se come casi toda la comida de Grimfang, devorandola como"
                                        " un autentico cerdo.");
   }
   notify_fail("Solo hay 'manjares' para comer.\n");                                                                               
 }
