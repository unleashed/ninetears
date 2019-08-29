inherit "/std/outside.c";

void setup()

{
    set_short("%^BOLD%^Entrada a la zona de %^GREEN%^PRUEBAS%^RESET%^");
     set_long("Te encuentras ante el limite de la zona de OMIQs donde "+
      "los mortales aprenden a dominar las tecnicas de la masacre, con "+
      "la zona de pruebas, donde los mortales pueden probar parte "+
      "de aquellas cosas que no funcionan del todo bien, que necesitan "+
      "revision, o que se ponen ahi precisamente para que alguien como "+
      "tu informe de posibles bugs.\n\n");

    set_light(70);

add_exit("norte","/room/camino_avalon/camino12","road");
add_exit("dentro","/room/test_area/r01","door");
}
