// Radiks '99

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

int ex_spool(string yn,string file,int linum);
varargs void wiz_present(string str,object ob,int internal);

void setup() {
        position = 1;
}

int got_fname;
int show_lines,show_enum,show_colors,show_pause;

string uso = "Uso: mmore [-n][-c][-p] <ficheros>\n"
             "   -n: No mostrar numeros de linea\n"
             "   -c: Mostrar colores\n"
             "   -p: No esperar paginas (mostrar todo seguido)\n";

int cmd(string s, object me) 
{
   object *things;
   string *filenames;
   string *st;
   string str;
   int egg;
   string spam;
   int a;
   
   
   if(s == 0 || s == "") {
        notify_fail(uso);
        return 0;       
   }
   
   got_fname = 0;
   
   st=explode(s," ");
   
   str="";

        show_lines = show_enum = show_pause = 1;
        show_colors = 0;
   
   for (a=0;a<sizeof(st);a++) {
        if (st[a][0]=='-' && st[a][1]!=0) {
                switch(st[a][1]) {
                        case 'n':
                                show_lines = 0;
                                break;
                        case 'c':
                                show_colors = 1;
                                break;
                        case 'p':
                                show_pause = 0;
                                break;
                        case 'z':
                                show_enum = 0;
                                break;
                        default:
                                notify_fail(uso);
                                return 0;
                }
        } else {
                if(st[a][0]=='-'||got_fname) {
                                notify_fail(uso);
                                return 0;
                } else {
                        got_fname=1;
                        str=st[a];
                }
        }
   }
  
        if (!got_fname) {
           notify_fail(uso);
           return 0;
        }

   if (sizeof(things =  me->wiz_present(str, me))) {
     spam = file_name(things[0]);
     sscanf(spam, "%s#%d", spam, egg);
     if(file_size(spam) < 0)
       filenames = ({ spam+".c" });
     else
       filenames = ({ spam });
   } else filenames = me->get_files(str);
   if (!sizeof(filenames)) { 
       str = me->get_path(str);
   } else {
       if (sizeof(filenames) > 0) {
         str = filenames[0];
         if(sizeof(filenames) > 1) {
           int loop;
 
           loop = 0;
           while(loop < sizeof(filenames) && file_size(filenames[loop]) < 0)
             loop++;
           if(loop >= sizeof(filenames)) {
              notify_fail("No existe el fichero.\n");
              return 0;
           } else {
              str = filenames[loop];
           } 
           write("Nombre ambiguo, usando: " + str + "\n");
         }
      }
  }
  if (file_size(str) == -2) {
     notify_fail("Es un directorio\n");
     return 0;
  }
  ex_spool("y",str,1);
  return 1;
}

int ex_spool(string yn,string fil,int linum) {
   string s1;
   int i;
   mixed tnum;
   
   if(sscanf(yn,"%d",tnum) == 1) {
      linum = (int)tnum;
      if(linum<1) linum = 1;
   }
   if((yn == "Q")||(yn == "q")) return 1;
   for(i=0;i<20;linum++) {
        if(show_pause)
                i++;    
   
      s1 = read_file(fil,linum,1);
      if(s1) {
        s1=replace_string(s1,"\n","");
        if(!s1||s1=="") s1=" ";
        if (show_lines) {
                if(show_colors) {
                        printf("%4d:",linum);
                        write(s1+"\n");
                } else {
                        printf("%4d: %s\n",linum,s1);
                }
        } else {
                if(show_colors) {
                        write(s1+"\n");
                      } else {
                        printf("%s\n",s1);
                      }
        }
                } else {
         return 1;
      }
   }
   printf("[Fichero %s - Q para salir]",fil);
   input_to("ex_spool",0,fil,linum);
   return 1;
}
