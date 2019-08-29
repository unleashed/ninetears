#define CREATOR "baiken"

inherit "/std/room.c";

void setup()
{
  set_short("Aposentos Secretos de %^BOLD%^%^MAGENTA%^B%^BLACK%^aiken%^RESET%^.");
  
  set_long("Acabas de acceder a los aposentos secretos de Baiken, El Guardia del Tiempo"
	   ", �ltimo descendiente de una antigua dinast�a olvidada con el "
	   "paso de los siglos. Al mirar a tu alrededor te sientes sobrecogido "
	   "por la amplitud de la habitaci�n, esta es de forma ovalada y no "
	   "parece tener ninguna esquina. Al fondo puedes ver una enorme mesa "
  	   "de obsidiana y un trono que se alza detras de la mesa, resaltando "
	   "de forma especial gracias al gran ventanal de forma circular que se "
           "encuentra justo detr�s. A la derecha puedes ver una gran estanteria "
           "repleta de libros, y a la izquierda un estante con una gran variedad "
           "de armas colgando de la pared justo encima de un amplio sill�n. "
           "Al mirar a tus pies te das cuenta de que est�s sobre una alfombra y "
	   "cuando diriges tu mirada al techo, este te llama especialmente la "
   	   "atenci�n.\n\n");
  
    set_light(80);
   
    add_item("habitacion"," La habitacion desprende una sensacion de frio y soledad "
	   "que te inquieta. Te sientes intranquilo aqui dentro, como si algo o "
           "alguien te estuviese observando en todo momento. Te das cuenta de que "
           "la mayor parte de la ilunminacion de la habitacion proviene de la pared "
           "y el techo.\n");
  
    add_item("pared"," A lo largo de la larga pared puedes distinguir que toda ella "
           "esta cubierta de runas en las partes visibles, un ligero "
	   "resplandor azulado surge de ellas...\n");

    add_item("techo"," Puedes observar como la pared segun va pasando a ser techo "
           "sigue estando repleta de distintas runas que no consigues descifrar, "
           "pero en lo que podria considerarse el centro de la cupula distingues "
           "una mas grande que el resto.\n");

    add_item("runa"," Al mirar detenidamente esa runa ves que se trata de varias que "              	  	    "circunferencias concentricas y signos presumiblemente esot�ricos que "
	    "se intoducen en las circunferencias creando un extra�o dibujo que crees "
 	    "haber visto antes, aunque no recuerdas exactamente donde, esta brilla "
            "mas que el resto de runas con un fulgor %^BOLD%^%^CYAN%^azulado%^RESET%^ " 	    "iluminando la habitacion.\n");

    add_item("trono"," Detr�s de la enorme mesa de obsidiana puedes ver un gran trono "
	    "que parece estar echo de restos de cadaveres, te resulta de lo mas "
	    "desagradable que hayas visto jamas, distingues que los apoyabrazos "
	    "acaban ambos en dos calaveras con largos colmillos.\n");
  
    add_item(({"calavera","calaveras"})," No consigues reconocer a que animal "
	   "o extra�o ser debieron pertenecer, pero por alguna razon cuanto "
           "mas las miras, mas incomodo te sientes.\n");
    
    add_item("mesa"," Tienes ante ti una gran mesa de obsidiana pulida de un negro "
           "tan profundo ke al mirarla fijamente empiezas a tener la sensacion de "
 	   "que la mirada se te pierde dentro de ella, como si de un abismo se "
	   "tratatase.\n");

    add_item("estanteria"," Ves una estanter�a de roble tallada con raros s�mbolos "
	   "que vagamente te recuerdan a constelaciones. A lo largo de la estanter�a "
           "ves libros y mas libros de diferentes tama�os y colores, aqui debe estar "
           "acumulada una gran sabiduria. Entre todos los libros, un gran libro de "
           "lomo %^BOLD%^%^BLACK%^negro%^RESET%^ y rebordes plateados te llama "
	   "especialmente la atencion en el centro de la estanteria.\n");

    add_item("libro"," Solo consigues ver el lomo negro y los rebordes plateados del "
	   "libro.\n");

    add_item("sillon"," Es un gran sillon de apariencia muy comoda, parece ser que "
	   "esta ahi para que las visitas puedan descansar a gusto, aunque no crees "
	   "que haya muchas visitas por aqui...\n");

    add_item("estante"," Por encima del sill�n ves un estante bastante grande repleto "
	   "de armas, en especial armas de filo. No puedes distinguir mucho mas ya que "
	   "lo que parece ser una barrera magica te obliga a retirar la mirada.\n");

    add_item("ventanal"," Detr�s del imponente trono ves un gran ventanal de forma "
	   "circular con un diametro de m�s de 3 metros. Al asomarte puedes ver "
	   "perfectamente los reinos de Driade, dandote la sensacion de que estas en "
	   "un refugio en el cielo. Desde aqui puedes ver absolutamente todo y hay "
	   "una gran vista del universo junto con regiones del mundo que ni "
	   "siquiera han sido descubiertas por los mortales.\n");

    add_item("alfombra"," Al mirar a tus pies ves que te encuentras sobre una alfombra "
	   "rectangular de gran tama�o que  ocupa la mayor parte del suelo delante de "
	   "la mesa. La alfombra es de color morado con distintas inscripciones y dibujos "
	   "en dorado, en cada esquina ves una especie de peque�o mechon de pelo tambi�n "
	   "de color dorado. AL andar sobre ella notas una ligera vibraci�n en tus pies..\n");

   
    add_smell(({"habitacion","aire"}),"Puedes oler la pintura recien "
	    "usada en las pareces.\n");
  
    add_feel("mesa","Sientes el frio de la oscura obsidiana con la que "
	    "han hecho la mesa.\n");
  
    add_sound("habitacion","Lo �nico que escuchas aparte de los comentarios del "
	    "guardi�n, es el latir de tu coraz�n. Por lo dem�s la habitaci�n est� "
	    "en completo silencio.\n");
  
     
    add_clone("/w/baiken/npcs/lebeau.c",1);
  
  
    add_exit("comun","/w/common","door");
  
  "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
  "/w/common.c"->renew_exits();
}


void init()
{
  
  ::init();
  add_action("tocar_mesa","tocar");
  add_action("coger_libro","coger");
}

int tocar_mesa(string str)
{
  if(str=="mesa")
   {
   tell_object(this_player(),"Tocas la mesa y una sensaci�n de frio te llega "
                            "hasta los huesos.\n");
   tell_room(this_object(),this_player()->query_cap_name()+" toca la mesa "
		  "y tiembla.\n",this_player());
   }
   return(1);
}

int coger_libro(string str)
{
  if(str=="libro")
  {
   tell_object(this_player(),"Al intentar coger el libro una descarga de energia magica "
                            "sale de este hacia tu mano dejandote el brazo entumecido.\n");
   tell_room(this_object(),this_player()->query_cap_name()+" intenta coger el libro de  "
		  "la estanteria y un peque�o rayo surge desde el libro hasta su mano.\n",this_player());
   }
   return(1);
}