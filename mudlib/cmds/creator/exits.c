#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

#define TE environment(TP)
#define R   "%^BOLD%^RED%^"
#define RE  "%^RESET%^"
#define C   "%^BOLD%^CYAN%^"
#define G   "%^BOLD%^GREEN%^"
int cmd(string str, object me) 
{
	mixed *dirs,dirs2;
	string aqui;
	int a;
	int error;
  	mapping contrarios = 
             (["norte":"sur","sur":"norte","oeste":"este",
		       "este":"oeste","noroeste":"sudeste",
		       "sudeste":"noroeste","noreste":"sudoeste",
		       "sudoeste":"noreste","arriba":"abajo","abajo":"arriba",
		       "dentro":"fuera","fuera":"dentro"]);

			   
  	if(!TE) {
    	write("No estas en ninguna parte!.\n");
    	return 1;
  	}
	aqui=file_name(TE);
//	write("--------------------------------------------------------------------------\n");
	write("\n");
	write("--%^BOLD%^%^RED%^[%^RESET%^ %^GREEN%^The%^BOLD%^Light%^YELLOW%^Zoners%^RESET%^ Debugger %^BOLD%^%^RED%^]%^RESET%^---------------------------------------------\n");
	write(" Nombre:  "+aqui+"\n");
	write(" Tamanyo: "+file_size(aqui+".c")+" bytes\n");
	write("--%^BOLD%^%^RED%^[%^RESET%^ Salidas En la habitacion %^BOLD%^%^RED%^]%^RESET%^--------------------------------------------\n");
	dirs = TE->query_dest_dir();
  	if(!sizeof(dirs)) {
    	write("No hay salidas en esta habitacion.\n");
  	} else {
		for(a=0;a<sizeof(dirs);a+=2) {
		    printf("%-10s -> ",dirs[a][0..8]);
		    sscanf(dirs[a+1],"%s.c",dirs[a+1]);
//		    dirs[a+1] = dirs[a+1]+".c";
			write(dirs[a+1]+"\n");
		}
		write("--%^BOLD%^%^RED%^[%^RESET%^ Status de Salidas %^BOLD%^%^RED%^]%^RESET%^---------------------------------------------------\n");
		for(a=0;a<sizeof(dirs);a+=2) {
		    string ppp,match;
			int j;
		
		    printf("%-10s: ",dirs[a][0..8]);
    		if(file_size(dirs[a+1]+".c") == -1) {
				write(dirs[a+1]+G+" no existe."+RE+"\n");
			} else {
		      	if(ppp=catch(dirs2 = dirs[a+1]->query_dest_dir())) {
        			write(dirs[a+1]+G+" no carga."+RE+"\n");
					//write(ppp);
				} else {
			        match = 0;
			        if(sizeof(dirs2))
			        for(j=0;j<sizeof(dirs2);j=j+2) {
						sscanf(dirs2[j+1],"%s.c",dirs2[j+1]); 
				  		if(file_name(TE)==dirs2[j+1])
			    		match = dirs2[j];
			        }
			        if(!match)
			  	  		write(dirs[a+1]+ R+" no tiene salida aqui"+RE+".\n");
			        else {
				  		if(contrarios[dirs[a]] == match)
			    			write("Ok.\n");
			         	else
				    		write(dirs[a+1]+ " -> "+C+match[0..8]+"."+RE+"\n");
        			}
				}
			}
		}
	}
	write("--------------------------------------------------------------------------\n");
	write("(c) Radiks, %^GREEN%^The%^BOLD%^Light%^YELLOW%^Zoner%^RESET%^ 1999\n");
	write("--------------------------------------------------------------------------\n\n");
    return 1;
}
