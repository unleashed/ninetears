 // Valar 28-10-02
 
    // Las nuevas tiendas heredan /std/tienda.c
    inherit "/std/tienda";
    
    void setup() {
     
      set_short("Tienda de Valar");
      set_long(query_short()+"\nEsta es la tienda de uso EXCLUSIVO para inmortales en donde sirven los mejores equipos.\n");
     
     set_dependiente("/w/valar/pruebas/sirvienta.c");
     
     set_tipo("standard"); // Si hacemos una tienda estandar no es necesario q pongamos esto, pq es el tipo por defecto. Lo he puesto para que veais como se hace
     
     add_suministro("/room/camino_avalon/objs/brazalete_ogro.c ",random(10)); 
     add_suministro("/room/camino_avalon/objs/cinturon_prisma.c",random(10)); 
     add_suministro("/w/aprendizaje/bastonrunico.c",random(10)); 
     add_suministro("/w/asleigh/shai.c",random(10)); 
     add_suministro("/w/enialish/items/e_elfica.c",random(10)); 
     add_suministro("/w/gareth/mandoble_flamigero.c",random(10)); 
     add_suministro("/w/oldcreators/blastaar/objetos/anillonib.c",random(10)); ;
     add_suministro("/w/oldcreators/blastaar/objetos/bra_str.c",random(10)); 
          
     
     // Ahora pondremos ajustes a los precios. Los ajustes pueden basarse en raza, clase, gremio, ciudadania o alineamiento. Un ajuste no puede ser mejor del 50% ni peor del 500%
     
     
     
     // Por ultimo esta funcion mete en la tienda un cartel con los comandos disponibles. Si le ponemos argumento ese sera el nombre del cartel, y si no por defecto sera una "placa"
     add_cartel("");
     }
   
  
