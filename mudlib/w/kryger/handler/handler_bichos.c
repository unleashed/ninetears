#define LOGS "/w/kryger/handler/"
void crear_criaturas(string tipo,object donde)
{
   if(!donde)
           write_file(LOGS+"handler_criaturas.log","Tipo: "+tipo+". Funcion llamada desde lugar desconocido."+ctime(time())+"\n");
   else switch(tipo)
   {
		case "zona_neutral":
		   if(!random(2))
		   	donde->add_clone("/w/leviathan/dummy.c",1);
		break;
   }// del switch
}// de crear_criaturas
