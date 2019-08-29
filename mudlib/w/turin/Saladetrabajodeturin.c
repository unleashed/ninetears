
   inherit "/std/room.c";   void setup () {   set_short ("%^YELLOW%^ Sala de trabajo de %^BLUE%^%^BOLD%^ Turin Turambar %^RESET%^.
");   set_long (query_short()+"
     Esta es la sala desde donde el inmortal %^BLUE%^%^BOLD%^ Turin Turambar %^RESET%^ trabaja por el bienestar de los mortales. Ves una mesa de nogal preciosa, con 5 sillas increiblemente comodas. Una lampara de aranya de velas alumbra la habitacion. Tambien ves un monton de muebles y estanterias llenas de libros y documentos sobre los mortales y todo lo relacionado con ellos. El suelo es de madera y las paredes de marmol blanco. Desde luego querrias vivir aqui.
");   add_item ("mesa","Es una mesa hecha de nogal, al mas puro estilo lujoso de los grandes reyes. Los adornos recorren toda la mesa excepto en la superficie donde es totalmente plana para la perfecta escritura en ella. Sobre ella hay varios libros abiertos, deben de ser la lectura del duenyo.
");   add_item ("sillas","Las sillas estan fabricadas en roble. Son altas y robustas. El cojin que tienen hacen parecerlas muy comodas. Los reposabrazos terminan con un remache de oro que las convierten en mas preciosas aun si cabe.
");   add_item ("lampara","Una preciosa lampara en forma de aranya de 9 brazos. Esta fabricada totalmente en oro blanco, y al mirarla fijamente casi te deslumbra. Puedes apreciar que las velas no parecen consumirse nunca.
");   add_item ("estanterias","Unas gigantescas estanterias llenas de libros y papeles perfectamente ordenados. El duenyo parece ser muy ordenado.
");   add_item ("libros","En la mesa ves unos libros con pastas de ebano con remaches de plata. Ves que estan todos escritos en un idioma o idiomas para ti desconocidos.
");   add_feel ("mesa","Al tocarla sientes la suavidad de la madera bien trabajada.
");   add_feel ("sillas","Al tocarlas notas que ningun tipo de rugosidades ni imperfecciones recorren las sillas.
");   add_feel ("lampara","La lampara esta demasiado alta como para alcanzarla.
");   add_feel ("estanterias","Notas que estan fabricadas con mucha habilidad, sin duda alguna un gran artesano.
");   add_feel ("libros","Al tocarlos sientes un incontrolable deseo de leerlos, pero al intentarlo solo ves signos indescriptibles.
");   add_exit ("comun","/w/common","door");   add_exit ("arriba","/w/turin/Elrellanodeturin.c","door");
}
