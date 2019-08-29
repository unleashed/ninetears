/*
**************************	**************************  
*        almenas.c       *      *        avenida.c       *  
**************************      **************************  
guardia		ciudadano       guardia		noble       
ciudadana	patrullero      sirvientes	perro       
                                gato                        

**************************	 **************************             
*        grieta.c        *       *        guardia.c       *             
**************************       **************************             
guardia		turista          capitan	patrullero      
halcon		conejo         
perro		gato


**************************	**************************
*        isla.c          *      *        lago.c          *
**************************      **************************
conejo		pajaro          pira�a		cangrejo  
planta                          calamar		pezdecolor


**************************	**************************
*        mercado.c       *	*        monumento.c     *
**************************	**************************
borracho	ciudadana       ciudadana	perro
ciudadano	noble           patrullero	fantasma
tendero		mercader        noble		ciudadano
guardian	perro           gato
gato            patrullero                        

**************************	**************************
*        muralla.c       *      *        parque.c        *
**************************      **************************
guardian	borracho        pajaro		raton     
nomada		soldado         halcon		ardilla   
gato		perro           conejo		perro     
mercader                        gato            

**************************	**************************
*        puerta.c        *      *        residencias.c   *
**************************      **************************
guardia_puerta	patrullero      noble		ciudadano 
                                ciudadana	sirvientes
*/

#include "/d/anduar/path.h"

object hija;
int i;
void crear_criaturas(string tipo,object donde)
{
	int i;
	if(!donde)
		write_file(LOGS+"handler_criaturas.log","Tipo: "+tipo+". Funcion llamada desde lugar desconocido. "+ctime(time())+"\n");
	else switch(tipo)
	{
		case "muralla_anduar":
			if(!random(4))	
                 		donde->add_clone(NPCS+"guardian", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"borracho", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"nomada", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"soldado", 1);
                 	else if(!random(4))
                 		donde->add_clone(NPCS+"gato", 1);
                 	else if(!random(4))
                 		donde->add_clone(NPCS+"perro", 1);
                 	else if(!random(2))
                 		donde->add_clone(NPCS+"mercader", 1);
                 break;
		case "mercado_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"borracho", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"ciudadana", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"ciudadano", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"noble", 1);
                 	else if(!random(4))
                 		donde->add_clone(NPCS+"tendero", 1);
                 	else if(!random(4))
      	           		donde->add_clone(NPCS+"mercader", 1);
                 	else if(!random(2))
                 		donde->add_clone(NPCS+"guardian", 1);
                 }
                 break;

		case "almenas_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"guardian", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"ciudadana", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"ciudadano", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"patrullero", 1);
                 }
                 break;

		case "avenida_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"guardian", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"noble", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"perro", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"gato", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"sirvientes", 1);
                 }
                 break;

		case "grieta_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"guardian", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"turista", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"halcon", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"conejo", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"perro", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"gato", 1);

                 }
                 break;

		case "guardia_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"guardian", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"patrullero", 1);
                 }
                 break;
                 
		case "isla_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"conejo", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"pajaro", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"planta", 1);
                 }
                 break;
                 
		case "lago_anduar":
		for (i = 0; i < 5; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"piranya", 1);
                 	else if(!random(2))
                 		donde->add_clone(NPCS+"cangrejo", 1);
                 	else if(!random(2))
                 		donde->add_clone(NPCS+"calamar", 1);
                 	else if(!random(3))
                 		donde->add_clone(NPCS+"pezdecolor", 1);
                 }
                 break;                 

		case "monumento_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"ciudadana", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"perro", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"patrullero", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"fantasma", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"noble", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"ciudadano", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"gato", 1);
                 }
                 break;                 

		case "parque_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"pajaro", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"raton", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"halcon", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"ardilla", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"conejo", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"perro", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"gato", 1);
                 }
                 break;                 

		case "residencias_anduar":
		for (i = 0; i < 2; i++) 
		{
      			if(!random(4))	
                 		donde->add_clone(NPCS+"noble", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"ciudadano", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"ciudadana", 1);
                 	else if(!random(5))
                 		donde->add_clone(NPCS+"sirvientes", 1);
                 }
                 break;                 
		default:
			if(!random(4))
				donde->add_clone(NPCS+"guardian",1);
			write_file(LOGS+"handler_criaturas.log","No se encontro del tipo de criatura "+tipo+" en "+file_name(donde)+".\n");
	}
}