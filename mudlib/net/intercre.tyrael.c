//Basado en la idea del remote_cre de Hamblet FR Julio '96
/*Rutseg 3-XI-2002 Reinos de Leyenda (Los Anyos Oscuros)
 *
 *v2.0
 *  Implementada peticion 'quien' para recibir el comando quien del MUD
 *  Implementada peticion 'escuchando' para saber quien escucha el canal
 *v2.1
 *  Implementada accion 'reboot' para hacer un shut de emergencia desde otro
mud si intercre.c responde
 *v3.0
 *  Anyadido password entre las transmisiones de los MUDs
 *v3.1
 *  Anyadido soporte para varios MUDs simultaneos
*/

#include <socket_errors.h>
#include <network.h>

#define IP 0
#define PUERTO 1
#define PASS 2

//Logeamos los replys, Rutseg
#define REPLY_LOG "reply_intercre"
#define LOG "INTERCRE"
#define SERVICIOS ({"peticion","respuesta","accion"});

#define ESTE_MUD "9T"
#define PUERTO_INTERCRE 3011

int cs,rs;
/*MUDs que tienen acceso
         "NOMBRE":({"ip",puerto_remoto,"password"})*/
mapping muds_intercre= ([
        "RL":({"147.156.10.98",3011,"u<Is+{aO3?$az"}),
	"ILU":({"147.156.10.98",3010,"6i/aj.-?A#oAb3"}),
        ]);

void crear_socket();
void crear_socket_remoto();
void enviar_respuesta(string usuario,string servicio,string msj);
int transmitir(string mud,string servicio,mixed usuario,string canal,string msj);

nomask protected void create() {
        //string *muds= keys(muds_intercre);
        log_file(LOG,"--- *** ---"+"Iniciando sesion Intercre en "+ctime(time())+"");
        crear_socket();
        crear_socket_remoto();
        //for(int i=sizeof(muds);i--;)
        //crear_socket_remoto(muds_intercre[muds][PUERTO]);
	}
nomask protected void crear_socket() {
        int error;
        cs= socket_create(DATAGRAM,"procesar_transmision");
        if(cs<0) {
                log_file(LOG,"**socket_create: "+socket_error(cs)+"");
                return;
	        }
        log_file(LOG,"Socket creado "+cs+"");
        if(EESUCCESS!=error= socket_bind(cs,PUERTO_INTERCRE)) {
                event(users(),"inform","Error ("+error+") creando socket al puerto intercre","intercre");
                log_file(LOG,"**socket_bind: "+socket_error(error)+"");
                socket_close(cs);
                return;
        	}
        event(users(),"inform","Socket para intercre creado con exito","intercre");
	}
nomask protected void crear_socket_remoto() {
        int error;
        rs= socket_create(DATAGRAM,"procesar_transmision");
        if(rs<0) {
                log_file(LOG,"**socket_create: "+socket_error(rs)+"");
                return;
        	}
        log_file(LOG,"Socket creado "+rs+"");
        if(EESUCCESS!=error= socket_bind(rs,0)) {
                log_file(LOG,"**socket_bind: "+socket_error(error)+"");
                socket_close(rs);
                return;
        	}
	}

/*Formato para los datos: delimitacion por espacios.
        <nombre_mud> <usuario> <canal> <mensaje ... >
        <nombre_mud> peticion <servicio_pedido> <datos adicionales...>
        <nombre_mud> accion <tipo_accion>
*/

nomask void interwho(string cre, string mud)
{
	transmitir(mud, "peticion", cre, "quien", "x"); 
}


nomask void procesar_transmision(int fd,string data) {
        string nombre_mud,password,servicio,usuario,canal,msj,*tmp,respuesta;

tell_object(find_living("vilat"),fd+":"+data+"");
tell_object(find_living("tyrael"),fd+":"+data+"");
        
	//Transmision incompleta
        if(sizeof(tmp= explode(data," "))<6) {
                log_file(LOG,"**procesar_transmision (paquete incompleto): No se muestra el paquete por seguridad.");
                return;
        	}
        nombre_mud= tmp[0];
        password= tmp[1];
        servicio= tmp[2];
        usuario= tmp[3];
        canal= tmp[4];
        msj= implode(tmp[5..]," ");
        if(!muds_intercre[nombre_mud]) {
                log_file(LOG,"VIOLACION DE SEGURIDAD: el mud \""+nombre_mud+"\" intento establecer comunicacion.");
                return;
        	}
        if(password!=muds_intercre[nombre_mud][PASS]) {
                log_file(LOG,"VIOLACION DE SEGURIDAD: el mud \""+nombre_mud+"\" fallo el password durante la comunicacion.");
                socket_close(rs);
                crear_socket_remoto();
                return;
        	}
switch(servicio) {
                //Servicios actuales:
                case "peticion"://Comprobamos si nos pide una respuesta
	        switch(canal) {
                        case "quien":
                        respuesta="/cmds/player/who.c"->who_string(79,1,0);
                        transmitir(nombre_mud,"respuesta",usuario,"quien",respuesta);
                        break;
                        case "escuchando":
                        //respuesta=msj+"<$"+implode(CHANNEL_HAND->get_chan_users()," ");
                        respuesta= "Todavia sin implementar.";
			transmitir(nombre_mud,"respuesta",usuario,"escuchando",respuesta);                                        break;
                        }
                break;
                case "respuesta"://Tenemos respuesta por parte del otro MUD
                enviar_respuesta(usuario,canal,msj);
                break;
                case "accion"://Quieren producir una accion sobre el MUD (no seguro)
                /*Esto de momento es demasiado burro
                if(canal=="reboot") {
   	        if(sizeof(users())) break;
                      	log_file(REPLY_LOG,"Shutdown llamado por "+capitalize(usuario)+" en "+ctime(time())+"");
                        //Shutdown de emergencia, Rutseg
                      	shutdown(0);
                        //Esto no llegara a salir
                        transmitir("respuesta","reboot",msj+"<$Reboot iniciado con exito");
                      	}*/
                break;
                default:
                switch(canal) {
                        case "chat":
                        "/global/do_chat.c"->do_channel("chat",msj,usuario,nombre_mud);
                        break;
                        default:
                        "/global/do_chat.c"->do_channel("intercre",msj,usuario,nombre_mud);
                        break;
                      	}
        	}
	}

nomask int transmitir(string mud,string servicio,mixed usuario,string canal,string msj) {
        int error;
        string to_transmit;

        to_transmit= ESTE_MUD+" "+muds_intercre[mud][PASS]+" "+servicio+" ";
        if(objectp(usuario)) to_transmit+= capitalize(usuario->query_name());
        else to_transmit+= usuario;
        to_transmit+= " "+canal+" "+msj;
	//error= socket_write(rs,to_transmit,"127.0.0.1 "+puerto_remoto);
	//tell_object(find_living("tyrael"),"transmitiendo: "+to_transmit);
        error= socket_write(rs,to_transmit,muds_intercre[mud][IP]+" "+muds_intercre[mud][PUERTO]);
        if(error==EEBADF) {
                socket_close(rs);
                crear_socket_remoto();
        	}
        if(error<0) {
                log_file(LOG,"**socket_write: "+socket_error(error)+"");
                return 0;
        	}
        return 1;
	}

nomask void transmitir_mensaje(object usuario,string canal,string msj) {
        string *muds;
        if(file_name(previous_object())!="/global/do_chat") return;
        for(int i= sizeof(muds= keys(muds_intercre));i--;) transmitir(muds[i],"canal",usuario,canal,msj);
	}

nomask protected void enviar_respuesta(string usuario,string servicio, string msj) {
        //Hagamos un debug con un log que nos permita ver resultados de las
        if(servicio=="quien" || servicio=="reboot") {
                log_file(REPLY_LOG,"Reply de la accion "+servicio+" en "+ctime(time())+" por "+capitalize(usuario)+"");
                if(msj) tell_object(find_player(usuario),msj+"");
        	}
	}

