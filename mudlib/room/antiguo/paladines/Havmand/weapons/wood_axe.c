inherit "/baseobs/weapons/hand_axe.c";

void setup()
{
    ::setup();
    set_enchant(1); // maybe remove this if it's TOO good
    set_name("hacha maderera");
    set_short("Hacha maderera");
    add_alias("hacha");
    add_alias("maderera");
    set_long("Este hacha parece estar disenyada para cortar maderas, troncos, lenyos... "
    "Tiene una ancha hoja contrapesada con un mazacote de metal en forma de martillo "
    "en el reverso. El mango esta recubierto de algun tipo de tela dura que ayuda "
    "a sujertarla con firmeza. Parece capaz de cortar cualquier cosa.\n "
    "Tiene unas marcas estampadas que no eres capaz de leer, pero por tus "
    "conocimientos, aunque aun son pocos, dirias que esta hecha por enanos.\n");
}

