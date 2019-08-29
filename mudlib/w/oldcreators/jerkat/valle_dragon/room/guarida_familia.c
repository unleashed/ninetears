inherit "/std/room";

void setup() 
{
   set_exit_color("CYAN");
   set_light(30);
   set_short("Habitacion Secetra");
   set_long("Habitacion Secetra%^RESET%^.\n\n"
   "Esta es una habitacion secreta que has encontrado por sorpresa tuya.\n"
   "Parece ser un pequenyo refugio en caso de emergencia que tiene preparada"
   "esta familia. Dispone de alimentos para una semana aproximadamente\n"
   "Sera mejor que no tokes nada. si cogieras algo podrian darse cuenta...\n"
   "Cuando entraste te diste un buen colpe y no recuerdas por donde"
   " entraste. Sera mejor que empiezas a buscar\n\n");
   add_exit("fuera","w/jerkat/valle_dragon/room/poblado_cabanya_17","hidden");
  }      
void init()
{
::init();
  add_action("buscar_pan","buscar");
  add_action("luz_on","encender");
  add_action("luz_off","apagar");
}    

int buscar_pan(string str)
  {
    if (str=="pan")
	{
	write("Has encontrado un trozo de pan envasado en la"
		" estanteria de arriba del todo. \n\n");
	add_clone("/w/jerkat/valle_dragon/item/pan_envasado",1);
	renew_exits();
	return(1);
	}
  }
  
int luz_on(string str)
  {
  	if (str=="la luz")
  		{
  			write("Enciendes la luz. \n\n");
  			set_light(80);
  			return 1;
  		}
  	else
  		{
  			write("�Encender el que ? Un piti ?");
  			return 0;
  		}
  }
int luz_off(string str)
  {
  	if (str=="la luz")
  		{
  			write("Apagas la luz. \n\n");
  			set_light(30);
  			return 1;
  		}
  	else
  		{
  			write("�Apagar el que ? Un piti ?\n");
  			return 0;
  		}
  }