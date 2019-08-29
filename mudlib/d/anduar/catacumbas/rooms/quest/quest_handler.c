#include "path.h"

int abierta;
string habitacion_tumba;
mixed lista_habitaciones;

mixed crear_lista_habitaciones();
void escribir_archivo_ecos();

void create()
{
   abierta=0;
   habitacion_tumba=0;
   lista_habitaciones=crear_lista_habitaciones();
   escribir_archivo_ecos();
   seteuid("Root");
}

int puerta_abierta() { return abierta; }

mixed crear_lista_habitaciones()
{
   mixed aux, lista;
   int i;
   
   lista=({ });
   
   aux=get_dir(CATACUMBAS+"*.c");
   
   for (i=0; i<sizeof(aux); i++)
      if (sizeof(aux[i])<6)
         lista+=({ aux[i] });

   return lista;   
}

void escribir_archivo_ecos()
{
   int i;
   
   write_file(CATAECOS,
   "// Archivo que produce un eco en todas las habitaciones de las\n"
   "// catacumbas. Generado automaticamente por \"quest_handler.c\" asi\n"
   "// que no editarlo porque sera machacado cuando se recargue el handler\n"
   "\n", 1);

   write_file(CATAECOS, "#include \"path.h\"\n\nvoid create()\n{\n"
   "   seteuid(\"Root\");\n}\n\nvoid raweco(string str)\n{\n", 0); 
   for (i=0; i<sizeof(lista_habitaciones); i++)
      write_file(CATAECOS, "   CATACUMBAS\""+lista_habitaciones[i]+
      "\"->raweco(str);\n", 0);
   write_file(CATAECOS, "}\n\nvoid eco(string str)\n{\n", 0);

   for (i=0; i<sizeof(lista_habitaciones); i++)
      write_file(CATAECOS, "   CATACUMBAS\""+lista_habitaciones[i]+
      "\"->eco(str);\n", 0);
   write_file(CATAECOS, "}\n", 0);
}

void raweco(string str)
{
   CATAECOS->raweco(str);
}

void eco(string str)
{
   CATAECOS->eco(str);
}

void abrir_puerta()
{
   raweco("Rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr.\n");
   call_out("abrir_puerta_2", 8);
}
      
void abrir_puerta_2()
{
   raweco("Clonk!!!!!!!!!!!.\n");
   abierta=1;
   CATACUMBAS"l3"->add_exit("norte", CATACUMBAS+"p7", "gate");
   CATACUMBAS"p7"->add_exit("sur", CATACUMBAS+"l3", "gate");
   CATACUMBAS"l3"->renew_exits();
   CATACUMBAS"p7"->renew_exits();
   call_out("cerrar_puerta", 10);
}

void cerrar_puerta()
{
   raweco("Rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr.\n");
   call_out("cerrar_puerta_2", 8);
}

void cerrar_puerta_2()
{
   raweco("Brooom!!!!!!!!!!.\n");
   abierta=0;
   CATACUMBAS"l3"->remove_exit("norte");
   CATACUMBAS"p7"->remove_exit("sur");
   CATACUMBAS"l3"->renew_exits();
   CATACUMBAS"p7"->renew_exits();
}
