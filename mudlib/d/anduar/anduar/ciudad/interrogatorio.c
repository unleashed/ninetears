inherit "/std/room.c";

void setup ()
 {
     set_short("Sala de interrogatorios.\n");
     set_long("Si estas aqui es por que eres sospechoso de algo.\n");
     set_light(50);
 }    

void init()
 {
//   add_action ("finalizar",({"finalizar","do"}));
    add_action ("go",({"ir","goto","go","home","goback"}));
add_action("more",({"more","grep","cat","call","clone","exec","ed","dest","update"}));
   ::init();
 }
 
 int finalizar(string str)  
  {
   if (str=="interrogatorio")
     {
       write("el interrogatorio ha finalizado.\n");

this_player() -> move("/room/void");
                 return(1);
     }// del if        
    }// del procedimiento            
  
  int go(string str)
  {
     if(this_player()->query_name() != "aokromes") 
      { 
        write("No puedes hacer eso, tiene que concluir el interrogatorio.\n");

        return 1;
      } 
  }
   
  void  more()
  {
    if(this_player()->query_name() != "aokromes") 
      { 
        write("No puedes hacer eso, tiene que concluir el interrogatorio.\n");

        return 1;
      } 
  }
