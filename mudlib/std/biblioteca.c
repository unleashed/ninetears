// Vilat 26.09.2002
#include <money.h>
inherit "/std/room";
mixed lista_libros=({});
nosave object bibliotecario;
object add_bibliotecario(string bfile);

void create() {
 ::create();
 restore_object(file_name(TO));
 if (!bibliotecario) add_bibliotecario("/baseobs/npcs/bibliotecario");
 }

void init() {
 ::init();
 add_action("solicitar","solicitar");
 add_action("listado","listar");
 add_action("add_libro","catalogar");
 add_action("remove_libro","descatalogar");
 }

object add_bibliotecario( string bfile ) {
 if (!bibliotecario=clone_object(bfile)) {
  log_file("runtime_debug.log","Error al clonar bibliotecario\nNo se pudo llevar a cabo la funcion clone_object(\""+bfile+"\") en "+file_name(TO)+"->add_bibliotecario(string bfile)\n");
  return 0;
  }
 bibliotecario->move(TO,bibliotecario->query_short()+" deja sus lecturas para atenderte.\n");
 return bibliotecario;
 }
int listado(string str) {
 int a;
 string listado="\n%^BOLD%^Titulo%^RESET%^\n";
if (!sizeof(lista_libros)) return notify_fail("El catalogo esta vacio.\n");
 for(a=0;a<sizeof(lista_libros)/2;a++) listado+=lista_libros[a*2]+"\n";
 tell_object(TP,listado+"\n");
 return 1;
 }
int add_libro(string str) {
 if(!TP->query_creator()) return 0;
 if(!str) return notify_fail("Sintaxis:  catalogar <titulo>\n");
 if(member_array(str,lista_libros)!=-1) return notify_fail("Ya hay un libro con ese titulo.\n");
 tell_object(TP,"Por favor introduce el nombre del archivo de texto asociado:\n");
 lista_libros+=({str});
 input_to("add_libro2");
return 1;
 }

int add_libro2(string str) {
 lista_libros+=({str});
 tell_object(TP,"Ok.\n");
 return 1;
 }
int remove_libro(string str) {
 int i;
 if(!TP->query_creator()) return 0;
 if (!str) return notify_fail("Sintaxis:  descatalogar <titulo>\n");
 if(i=member_array(str,lista_libros)==-1) return notify_fail("Titulo inexistente.\n");
 lista_libros=delete(lista_libros,i,2);
 tell_object(TP,"Ok.\n");
 return 1;
 }

int solicitar(string str) {
 object libro;
 if(!str) return notify_fail("Sintaxis:  solicitar <titulo>\n");
 if (member_array(str,lista_libros)==-1) return notify_fail("Lo siento, el titulo solicitado no existe.\n");
if (!bibliotecario) return notify_fail("El bibliotecario no esta para atenderte en estos momentos.\n");
if (bibliotecario->query_fighting()) return notify_fail("El bibliotecario esta ocupado luchando por su vida!!!\n");
 libro=new("/w/vilat/libro.c");
 libro->add_property("texto",lista_libros[member_array(str,lista_libros)+1]);
 libro->set_long("Un libro titulado: "+str+".\n");
 libro->move(TP);
 tell_object(TP,"Recibes el libro que has pedido.\n");
 tell_room(environment(TP),TP->query_cap_name()+" compra un libro.\n",TP);
 return 1;
 }

void dest_me() {
 save_object(file_name(TO));
 ::dest_me();
 }

varargs void add_letrero(string nombre) {
 if(!nombre) nombre="letrero";
 add_sign("Un "+nombre+" con algo escrito.\n",TO->query_short()+"\nLos comandos utiles de las bibliotecas son:\n\n<%^GREEN%^listar%^RESET%^> para ver los libros disponibles.\n<%^GREEN%^solicitar%^RESET%^> para pedir un titulo.\n",nombre,nombre);
 }
