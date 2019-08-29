// Vilat 20.09.2002
#define SFILE "/w/vilat/magallanes"
inherit "/std/object";
int index=2;
mixed datos=({1,"/room/entryroom","",({}),1});
void magallanes();
void actualizar(string loc);
void reservar(int id,string loc);
void update_info(string loc,string tipo,string *ady_loc);

void setup() {
 set_name("magallanes");
 set_short("Magallanes Project");
 set_long("Controlador del Proyecto Magallanes.\n");
 restore_object(SFILE);
 call_out("magallanes",0);
 }

void magallanes() {
 int a;
 int rexp=sizeof(datos)/5;
 for (a=0;a<rexp;a++) {
  datos[a*5+4]--;
  if (datos[a*5+4]<=0) actualizar(datos[a*5+1]);
  }
 save_object(SFILE);
 call_out("magallanes",5);
 }

void reservar(int id,string loc) {
 if (!id) {
  id=index;
  index++;
  }
 datos+=({id,loc,"",({}),1});
 }

void actualizar(string loc) {
 int i;
 string tipo;
 string *ady_loc=({});
 if (!loc->query_outside()) tipo="interior";
 else tipo="exterior";
 for (i=0;i<sizeof(loc->query_dest_dir())/2;i++) {
  string aloc=loc->query_dest_dir()[i*2+1];
  if (aloc[strlen(aloc)-2..strlen(aloc)-1]==".c") aloc=aloc[0..strlen(aloc)-3];
  ady_loc+=({aloc});
  }
 update_info(loc,tipo,ady_loc);
 }

void update_info(string loc,string tipo,string *ady_loc) {
 int a,i;
 int *ady=({});
 for (a=0;a<sizeof(ady_loc);a++) {
  if(i=member_array(ady_loc[a],datos)!=-1) { for (i=0;i<sizeof(datos);i++) if (datos[i]==ady_loc[a]) ady+=({datos[i-1]}); }
  else {
   reservar(index,ady_loc[a]);
   ady+=({index});
   index++;
   }
  }
 for (i=0;i<sizeof(datos);i++) if (datos[i]==loc) break;
// i=member_array(loc,datos);
 datos[i+1]=tipo;
 datos[i+2]=ady;
 datos[i+3]=100;
 }

void dest_me() {
 save_object(SFILE);
 ::dest_me();
 }
