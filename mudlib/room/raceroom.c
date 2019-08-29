inherit "std/room";
#define AYUDA_RAZAS "/rol/razas/ayuda/"
#define RAZAS "/rol/razas/"
#define RAZARR ({"drow","duergar","goblin","orco","humano","enano","elfo","halfling","hombre-lagarto","gnomo","semielfo","shade"})
#define PUNTOS 85
#define CARACTERISTICAS ({"fue","des","con","int","sab","car"})

void abortar(object me);
void nacimiento5(string str);

void setup() {
   	add_property("no_undead",1);
	set_short("%^BOLD%^Plano Inmaterial%^RESET%^");
  	set_long(query_short()+"\n"
		"Tu alma se encuentra flotando en la inmensa oscuridad del Plano Material. "
		"Poco a poco parece como si el espacio se combase y te sientes caer durante "
		"un instante que se hace eterno... hasta chocar con la oscuridad. De repente "
		"se enciende una potente luz blanca, y otra y otra hasta dejarte deslumbrado "
		"por completo. No eres capaz de ver nada, pero una palabra resuena en tu "
		"conciencia: '%^YELLOW%^nacer%^RESET%^'.\n");
	}

int no_kill(string str) { return 1; }

void init() {
  	::init();
  	add_action("nacimiento", "nacer");
   	add_property("nocast",1);
   	add_property("noguild",1);
   	add_action("no_kill","matar");
   	add_action("no_kill","kill");
	}

int nacimiento() {
 	object me=TP;
	string ret="";
	if(TP->query_property("nato")) return notify_fail("Solo se puede nacer una vez en la vida.\n");
	tell_object(me,"Una forma humanoide aparece ante ti y te dice sonriendo: Asi que deseas ser mortal, eh?\n");
	tell_object(me,"La forma te dice: Esta bien, esta bien. Sigue mis instrucciones y te concedere un cuerpo.\n");
	tell_object(me,"La forma te dice: Primero has de elegir tu raza de entre las siguientes:\n");
	for (int i=1;i<sizeof(RAZARR)+1;i++) ret += "%^BOLD%^"+(string)i+"%^RESET%^\t"+CAP((RAZAS+RAZARR[i-1])->query_name())+"\n";
	ret = sprintf("%-#*s\n", me->query_cols(), ret);
	me->do_efun_write(ret);
	tell_object(me,"%^BOLD%^Escribe %^YELLOW%^ayuda <numero>%^WHITE%^ para mas informacion sobre una raza.\n");
	tell_object(me,"La forma te pregunta: Y bien, que eliges?\n");
	input_to("nacimiento2",2);
	return 1;
	}

int nacimiento2(string str) {
	int trace,ayuda;
	string ret="";
	string *clases;
	if(!str) return tell_object(TP,"Decides no nacer.\n");
	if(str[0..4]=="ayuda") {
	    ayuda=1;
	    str=str[5..];
	    }
	sscanf(str, "%d", trace);
	if(!trace||trace<1||trace>sizeof(RAZARR)) {
		tell_object(TP,"La forma te dice: Me alegro de que decidas no nacer. La verdad es que no te veia capaz de sobrevivir en el plano mortal.\n");
		abortar(TP);
		return 0;
		}
	if(ayuda) {
	    str=read_file(AYUDA_RAZAS+RAZARR[trace-1]);
	    tell_object(TP,str+"\n\n�Qu� eliges?");
	    input_to("nacimiento2",2);
	    return 1;
	    }
	TP->add_property("nraza",RAZARR[trace-1]);
	tell_object(TP,"La forma empieza a parecerse a un "+CAP((RAZAS+RAZARR[trace-1])->query_name())+".\n");
	tell_object(TP,CAP((RAZAS+RAZARR[trace-1])->query_name())+" te dice: Ahora elegiras clase.\n");
	clases=(RAZAS+RAZARR[trace-1])->query_clases();
	for (int i=1;i<sizeof(clases)+1;i++) ret += "%^BOLD%^"+(string)i+"%^RESET%^ "+clases[i-1]+"\n";
	ret = sprintf("%-#*s\n", TP->query_cols(), ret);
	TP->do_efun_write(ret);
	tell_object(TP,CAP((RAZAS+RAZARR[trace-1])->query_name())+" te pregunta: Cual es tu eleccion?\n");
	input_to("nacimiento3",2);
	}

int nacimiento3(string str) {
	int trace;
	string ret="";
	mixed alins=({});
	object tmp;
	if(!str) return tell_object(TP,"Decides no nacer.\n");
	sscanf(str, "%d", trace);
	if(!trace||trace<1||trace>sizeof((RAZAS+TP->query_property("nraza"))->query_clases())) {
		tell_object(TP,"El "+CAP((RAZAS+TP->query_property("nraza"))->query_name())+" te dice: Me alegro de que decidas no nacer. La verdad es que no te veia capaz de sobrevivir en el plano mortal.\n");
		abortar(TP);
		return 0;
		}
	TP->add_property("nclase",((RAZAS+TP->query_property("nraza"))->query_clases())[trace-1]);
	tell_object(TP,"El "+CAP((RAZAS+TP->query_property("nraza"))->query_name())+" se pone los atuendos de un "+TP->query_property("nclase")+".\n");
	tell_object(TP,CAP((RAZAS+TP->query_property("nraza"))->query_name())+" "+TP->query_property("nclase")+" te dice: El siguiente paso es que elijas alineamiento.\n");

	alins=(RAZAS+TP->query_property("nraza"))->query_alineamientos();
	for (int i=1;i<sizeof(alins)+1;i++) {
		ret += "%^BOLD%^"+(string)i+"%^RESET%^\t";
		tmp=clone_object("/global/player");
		tmp->set_alineamiento(alins[i-1][0],alins[i-1][1]);
		ret+=tmp->query_alineamiento_name()+"\n";
		}
	ret = sprintf("%-#*s\n", TP->query_cols(), ret);
	TP->do_efun_write(ret);
	tell_object(TP,CAP((RAZAS+TP->query_property("nraza"))->query_name())+" "+TP->query_property("nclase")+" te pregunta: Que alineamiento prefieres?\n");
	input_to("nacimiento4",2);
	}

int nacimiento4(string str) {
	int trace;
	if(!str) return tell_object(TP,"Decides no nacer.\n");
	sscanf(str, "%d", trace);
	if(!trace||trace<1||trace>sizeof((RAZAS+TP->query_property("nraza"))->query_alineamientos())) {
		tell_object(TP,"El "+CAP((RAZAS+TP->query_property("nraza"))->query_name())+" te dice: Me alegro de que decidas no nacer. La verdad es que no te veia capaz de sobrevivir en el plano mortal.\n");
		abortar(TP);
		return 0;
		}
	TP->add_property("nalin",((RAZAS+TP->query_property("nraza"))->query_alineamientos())[trace-1]);
	tell_object(TP,CAP((RAZAS+TP->query_property("nraza"))->query_name())+" "+TP->query_property("nclase")+" te dice: Muy bien, ahora tendras que elegir tus caracteristicas.\n");
	nacimiento5("reiniciar");
	}

void abortar(object me) {
	me->remove_property("nraza");
	me->remove_property("nclase");
	me->remove_property("nalin");
	me->remove_property("nfue");
	me->remove_property("ndes");
	me->remove_property("ncon");
	me->remove_property("nint");
	me->remove_property("nsab");
	me->remove_property("ncar");
	return;
	}

int nacimiento6(string str) {
	int repajust;
	if (str=="s") {
		tell_object(TP,CAP((RAZAS+TP->query_property("nraza"))->query_name())+" "+TP->query_property("nclase")+" te dice exclamando: De acuerdo. Has nacido. Buena suerte!\n");
		TP->set_race(TP->query_property("nraza"));
		TP->fijar_clase(lower_case(TP->query_property("nclase")));
		TP->set_alineamiento(TP->query_property("nalin")[0],TP->query_property("nalin")[1]);
		TP->set_str(TP->query_property("nfue"));
		TP->set_dex(TP->query_property("ndes"));
		TP->set_con(TP->query_property("ncon"));
		TP->set_int(TP->query_property("nint"));
		TP->set_wis(TP->query_property("nsab"));
		TP->set_cha(TP->query_property("ncar"));
		repajust=TP->query_property("nalin")[1];
		if (repajust>0 && TP->query_property("nalin")[0] == 1) repajust++;
		if (repajust<0 && TP->query_property("nalin")[0] == -1) repajust--;
		repajust+=(RAZAS+TP->query_property("nraza"))->ajustar_reputacion();
		repajust*=5;
//		repajust+=TP->query_property("ncar"); // Sumamos la carisma a la reputacion inicial
		abortar(TP);
		TP->set_rp(50+repajust);
		TP->adjust_level(15); // Hack temporal
		(TP->query_clase_ob())->equipame(TP);
		write_file("/log/nacidos",TP->query_cap_name()+" nacio el "+ctime(time())+".\nSus tiradas fueron: FUE: "+TP->query_str()+"   CON: "+TP->query_con()+"   DES: "+TP->query_dex()+"   CAR: "+TP->query_cha()+"   SAB: "+TP->query_wis()+"   INT: "+TP->query_int()+"\n");
		TP->move("/room/entryroom");
		TP->add_property("nato",1);
		return 1;
		}
	if (str=="n") {
		nacimiento5("XXX");
		return 0;
		}
	tell_object(TP,"El "+CAP((RAZAS+TP->query_property("nraza"))->query_name())+" te dice: Me alegro de que decidas no nacer. La verdad es que no te veia capaz de sobrevivir en el plano mortal.\n");
	abortar(TP);
	return 0;
	}

void nacimiento5(string str) {
	int Fue,Des,Con,Car,Int,Sab;
	int fuemin=8,desmin=8,conmin=8,carmin=8,intmin=8,sabmin=8;
	int fuemax,desmax,conmax,carmax,intmax,sabmax;
	int puntosr;
	int valor;
	string raza=(RAZAS+TP->query_property("nraza"));
	string clase=TP->query_property("nclase");
	string *buf;
	switch (clase) {
		case "Guerrero":
		fuemin=16;
		desmin=14;
		conmin=15;
		break;
		case "Hechicero":
		desmin=15;
		intmin=16;
		break;
		case "Sacerdote":
		fuemin=14;
		conmin=14;
		carmin=10;
		sabmin=16;
		break;
		case "Bribon":
		fuemin=10;
		desmin=10;
		carmin=10;
		break;
		default:
		break;
		}
	fuemax=raza->limitar_fue();
	desmax=raza->limitar_des();
	conmax=raza->limitar_con();
	intmax=raza->limitar_int();
	sabmax=raza->limitar_sab();
	carmax=raza->limitar_car();

	if(lower_case(str)=="reiniciar") {
		Fue=fuemin;
		Des=desmin;
		Con=conmin;
		Int=intmin;
		Sab=sabmin;
		Car=carmin;
		}
	else {
		Fue=TP->query_property("nfue");
		Des=TP->query_property("ndes");
		Con=TP->query_property("ncon");
		Int=TP->query_property("nint");
		Sab=TP->query_property("nsab");
		Car=TP->query_property("ncar");
		}

	if(str=="") return;
	if(str=="aceptar") {
		if(PUNTOS-Fue-Des-Con-Car-Int-Sab) {
			tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice exclamando: Aun tienes puntos por repartir!\n");
			input_to("nacimiento5",2);
			return 0;
			}
		tell_object(TP,CAP(raza->query_name())+" "+clase+" te pregunta: Estas seguro (s/n)?\n");
		input_to("nacimiento6",2);
		return;
		}

	buf=explode(str," ");
	if (sizeof(buf)==3) {
		sscanf(buf[2], "%d", valor);
		if(valor&&valor>0) {
			if(lower_case(buf[0])=="sumar") {
				if(member_array(lower_case(buf[1]),CARACTERISTICAS)==-1) {
					tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: Las caracteristicas validas son Fue, Des, Con, Int, Sab y Car.\n");
					input_to("nacimiento5",2);
					return;
					}
				if(valor>PUNTOS-Fue-Des-Con-Car-Int-Sab) {
					tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No tienes tantos puntos disponibles.\n");
					input_to("nacimiento5",2);
					return;
					}
				switch(lower_case(buf[1])) {
					case "fue":
					if(Fue+valor>fuemax) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes superar el maximo.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Fue+=valor;
					break;
					case "des":
					if(Des+valor>desmax) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes superar el maximo.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Des+=valor;
					break;
					case "con":
					if(Con+valor>conmax) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes superar el maximo.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Con+=valor;
					break;
					case "int":
					if(Int+valor>intmax) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes superar el maximo.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Int+=valor;
					break;
					case "sab":
					if(Sab+valor>sabmax) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes superar el maximo.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Sab+=valor;
					break;
					case "car":
					if(Car+valor>carmax) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes superar el maximo.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Car+=valor;
					break;
					default:break;
					}
				}
			else if(lower_case(buf[0])=="restar") {
				if(member_array(lower_case(buf[1]),CARACTERISTICAS)==-1) {
					tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: Las caracteristicas validas son Fue, Des, Con, Int, Sab y Car.\n");
					input_to("nacimiento5",2);
					return;
					}
				switch(lower_case(buf[1])) {
					case "fue":
					if(Fue-valor<fuemin) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes bajar tanto la caracteristica.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Fue-=valor;
					break;
					case "des":
					if(Des-valor<desmin) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes bajar tanto la caracteristica.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Des-=valor;
					break;
					case "con":
					if(Con-valor<conmin) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes bajar tanto la caracteristica.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Con-=valor;
					break;
					case "int":
					if(Int-valor<intmin) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes bajar tanto la caracteristica.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Int-=valor;
					break;
					case "sab":
					if(Sab-valor<sabmin) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes bajar tanto la caracteristica.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Sab-=valor;
					break;
					case "car":
					if(Car-valor<carmin) {
						tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: No puedes bajar tanto la caracteristica.\n");
						input_to("nacimiento5",2);
						return;
						}
					else Car-=valor;
					break;
					default:break;
					}
				}
			}
		}

	puntosr=PUNTOS-Fue-Des-Con-Car-Int-Sab;

	tell_object(TP,CAP(raza->query_name())+" "+clase+" te dice: Ahora mismo estas son tus caracteristicas:\n");
	tell_object(TP,"%^BOLD%^Caracteristica         Minimo\tMaximo\t\tActual%^RESET%^\n\n");
	tell_object(TP,"%^BOLD%^FUE%^RESET%^rza                 %^RED%^BOLD%^"+(string)fuemin+"\t%^GREEN%^"+(string)fuemax+"\t\t%^YELLOW%^"+(string)Fue+"%^RESET%^\n");
	tell_object(TP,"%^BOLD%^DES%^RESET%^treza               %^RED%^BOLD%^"+(string)desmin+"\t%^GREEN%^"+(string)desmax+"\t\t%^YELLOW%^"+(string)Des+"%^RESET%^\n");
	tell_object(TP,"%^BOLD%^CON%^RESET%^stitucion           %^RED%^BOLD%^"+(string)conmin+"\t%^GREEN%^"+(string)conmax+"\t\t%^YELLOW%^"+(string)Con+"%^RESET%^\n");
	tell_object(TP,"%^BOLD%^INT%^RESET%^eligencia           %^RED%^BOLD%^"+(string)intmin+"\t%^GREEN%^"+(string)intmax+"\t\t%^YELLOW%^"+(string)Int+"%^RESET%^\n");
	tell_object(TP,"%^BOLD%^SAB%^RESET%^iduria              %^RED%^BOLD%^"+(string)sabmin+"\t%^GREEN%^"+(string)sabmax+"\t\t%^YELLOW%^"+(string)Sab+"%^RESET%^\n");
	tell_object(TP,"%^BOLD%^CAR%^RESET%^isma                %^RED%^BOLD%^"+(string)carmin+"\t%^GREEN%^"+(string)carmax+"\t\t%^YELLOW%^"+(string)Car+"%^RESET%^\n\n");
	tell_object(TP,"Ahora mismo tienes %^BOLD%^"+(string)puntosr+"%^RESET%^ puntos para repartir.\n");
	tell_object(TP,"Pulsa INTRO para abortar, o utiliza uno de estos comandos:\n");
	tell_object(TP,"<%^ORANGE%^reiniciar%^RESET%^> para volver al estado inicial de tus caracteristicas.\n");
	tell_object(TP,"<%^ORANGE%^aceptar%^RESET%^> para quedarte con estas tiradas.\n");
	tell_object(TP,"<%^ORANGE%^sumar  'caracteristica' 'numero'%^RESET%^> para ajustar una caracteristica.\n");
	tell_object(TP,"<%^ORANGE%^restar 'caracteristica' 'numero'%^RESET%^> para ajustar una caracteristica.\n");

	TP->add_property("nfue",Fue);
	TP->add_property("ndes",Des);
	TP->add_property("ncon",Con);
	TP->add_property("nint",Int);
	TP->add_property("nsab",Sab);
	TP->add_property("ncar",Car);

	input_to("nacimiento5",2);
	}
