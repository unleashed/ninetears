    /* Vilat 01.09.2002 - Migrando al castellano */
    // Las antiguas denominaciones se mantendran validas hasta el 1 de Octubre, asi que hay un mes para migrar.
    // Despues hasta el 1 de Enero de 2003 seguiran como comentario por si algo fallase o alguien no hubiese actualizado sus objetos.
    // El 1 de Enero se eliminaran por completo las antiguas denominaciones

// Remodelado by Tyrael - May '02
// Extraido el max numero de obs de cada tipo wearables a la vez
// y redefinidos de nuevo los tipos (y anyadidos mas) para el
// sistema de localizacion de equipo. NO SE USAN ESCUDOS EN ESTA TABLA.


int max_type_wearing(int x) {
	// Orejas, Dedos y Amuletos/Collares pueden llevar multiples obs
	switch (x) {
		case 5: 
		return 2;
		
		case 8:
		case 15:
		return 4;
		
		default:
		return 1;
		}
	}

string query_type_name(int x) {
	switch (x) {
		case 1: return "Cuerpo";
		case 2: return "Cabeza";
		case 3: return "Frente";
		case 4: return "Ojos";
		case 5: return "Orejas";
		case 6: return "Nariz";
		case 7: return "Labios";
		case 8: return "Cuello";
		case 9: return "Hombros";
		case 10: return "Pecho";
		case 11: return "Vientre";
		case 12: return "Brazos";
		case 13: return "Munyeca";
		case 14: return "Manos";
		case 15: return "Dedos";
		case 16: return "Cintura";
		case 17: return "Pelvis";
		case 18: return "Piernas";
		case 19: return "Tobillo";
		case 20: return "Pies";
		case 21: return "Torso";
		case 22: return "Espalda";
		case 23: return "Culo";
		default: return "Por ahi";
		}
	return "Por ahi";
	}

int query_num_types() {	return 23; }

int query_armour_type_name(string name) {
	switch(CAP(name)) {
		case "Cuerpo": return 1;
		case "Cabeza": return 2;
		case "Frente": return 3;
		case "Ojos":case "Ojo": return 4;
		case "Orejas":case "Oreja": return 5;
		case "Nariz":case "Narices": return 6;
		case "Labios":case "Labio": return 7;
		case "Cuello": return 8;
		case "Hombros":case "Hombro": return 9;
		case "Pecho":case "Pechos": return 10;
		case "Vientre": return 11;
		case "Brazos":case "Brazo": return 12;
		case "Munyeca":case "Munyecas": return 13;
		case "Manos":case "Mano": return 14;
		case "Dedos":case "Dedo": return 15;
		case "Cintura": return 16;
		case "Pelvis": return 17;
		case "Piernas":case "Pierna": return 18;
		case "Tobillo":case "Tobillos": return 19;
		case "Pies":case "Pie": return 20;
		case "Torso": return 21;
		case "Espalda": return 22;
		case "Culo":case "Gluteos": return 23;
		}
	}

int *lookup_armour_data(string name) {
  	int *armour_data;

/* Elementos de armour_data:
 *  0: Coste en monedas de oro. Los valores negativos indican monedas de plata.
 *  1: Coste en monedas de oro de un arma encantada (+1), un arma (+2) multiplicaria este
     	valor por 2, mientras que un arma (+3) lo haria por 4, un arma (+3), por 8 y
     	asi sucesivamente (crece de forma exponencial).
 *  2: Peso.
 *  3: Tamanyo (De 1 [anillos] a 20 [armadura completa]).
 *  4: AC.
 *  5: Lugar donde se lleva (mirar query_type_name() mas arriba).
 *  6: Material:
      	1.- Madera (supongo que esto esta obsoleto y es de la epoca de los escudos) <-Pos no, vease splint mail
     	2.- Metal
     	3.- Cuero
     	4.- Ropa
 *  7: Empunyable (1) o vestible (0). Lo de empunyable tambien esta obsoleto, usar siempre 0.
 *  8: Indica si la armadura quita agilidad. 0 significa que no es asi, mientras que 1 si quita agilidad.
 */


  	switch(name) {
		// Metalicas y otras que afectan a conjuros
		case "ring mail":
		case "anillas":
		case "cota_de_anillas":
                armour_data=({  80,  4000, 300, 17, 30, 1, 2, 0, 0 }); break;

                case "studded leather":
		case "cuero_tachonado":
                armour_data=({  30,  4000, 250, 15, 30, 1, 2, 0, 0 }); break;

                case "scale mail":
		case "escamas":
		case "cota_de_escamas":
                armour_data=({ 100,  4000, 400, 17, 40, 1, 2, 0, 0 }); break;

                case "brigandine":
		case "brigantina":
                armour_data=({ 120,  4000, 350, 17, 40, 1, 2, 0, 0 }); break;

    		case "chain mail":
    		case "chain":
    		case "chainmail":
    		case "cota":
    		case "malla":
		case "cota_de_mallas":
      		armour_data=({  75,  3500, 400, 17, 50, 1, 2, 0, 0 }); break;

    		case "elfin chain":
    		case "cota_elfica":
      		armour_data=({5000, 20000, 150, 17, 50, 1, 2, 0, 0 }); break;

                case "drow chain":
		case "armadura_drow":
                armour_data=({5000,  7000, 150, 17, 50, 1, 2, 0, 0 }); break;

    		case "banded mail":
    		case "banded":
		case "bandas":
    		case "cota_de_bandas":
      		armour_data=({ 200,  4000, 350, 18, 60, 1, 2, 0, 0 }); break;

    		case "bronze plate":
    		case "coraza":
    		case "placas_bronce":
		case "placas_de_bronce":
      		armour_data=({ 400, 10000, 450, 20, 60, 1, 2, 0, 1 }); break;

    		case "plate mail":
    		case "plate":
    		case "placas":
      		armour_data=({ 600,  5000, 500, 20, 70, 1, 2, 0, 1 }); break;

    		case "field plate":
    		case "campanya":
		case "campa�a":
      		armour_data=({2000, 15000, 600, 20, 80, 1, 2, 0, 1 }); break;

		case "dwarf plate":
		case "armadura_enano":
		case "placas_enano":
		armour_data=({2000,  9000, 900, 20, 80, 1, 2, 0, 1 }); break;

    		case "full plate":
    		case "completa":
      		armour_data=({8000, 30000, 400, 20, 90, 1, 2, 0, 1 }); break;

		// Cuero y otras que no deber�an afectar a conjuros
    		case "shirt":
    		case "camiseta":
      		armour_data=({  -5,   500,  10,  6,  0, 1, 4, 0, 0 }); break;

                case "tunica":
		case "t�nica":
                armour_data=({   3,  3000,  50, 20,  0, 1, 4, 0, 0 }); break;

		case "leather":
    		case "cuero":
      		armour_data=({   5,  2000, 150, 15, 20, 1, 3, 0, 0 }); break;

    		case "padded leather":
    		case "padded":
    		case "cuero_acolchado":
      		armour_data=({  10,  3000, 100, 15, 20, 1, 3, 0, 0 }); break;

                case "gnome leather":
		case "cuero_gn�mico":
		case "gn�mica":
                armour_data=({  50,  4000, 150, 15, 30, 1, 3, 0, 0 }); break;

    		case "hide":
    		case "piel":
      		armour_data=({  80,  4000, 300, 17, 40, 1, 3, 0, 0 }); break;

    		case "splint mail":
    		case "splint":
    		case "armadura_de_tablillas":
		case "tablillas":
      		armour_data=({ 200,  6000, 400, 17, 60, 1, 1, 0, 0 }); break;

    		case "heavy hide":
    		case "piel_pesada":
      		armour_data=({1000,  4000, 600, 20, 60, 1, 3, 0, 1 }); break;

    /* Shields: - YA NO HAY SHIELDS AKI, MIRA shield_table.c
     Desaparecidos sus ultimos restos de aki por culpa de Vilat (01.09.2002)
     De aqui en adelante, el equipo vestible que no es una armadura en si: */

		// Cabeza
    		case "capucha":
     		armour_data=({   4,  1500,  10,  2,  0, 2, 4, 0, 0 }); break;

    		case "cowl":
    		case "casco":
     		armour_data=({   6,  1500,  10,  4, 10, 2, 2, 0, 0 }); break;

    		case "helm":
    		case "helmet":
    		case "basinet":
		case "bacinete":
    		case "yelmo":
      		armour_data=({   8,  1500,  50,  5, 15, 2, 2, 0, 0 }); break;

    		case "great helm":
    		case "full helm":
    		case "visored helm":
    		case "yelmo_grande":
      		armour_data=({  30,  2500, 100,  6, 20, 2, 2, 0, 0 }); break;
      
      		// Frente
    		case "cinta": /* Nuevo */
      		armour_data=({   1,  1500,   5,  1,  0, 3, 4, 0, 0 }); break;
      
      		// Ojos
    		case "gafas": /* Nuevo */
		case "parche":
      		armour_data=({   10, 1500,   8,  1,  0, 4, 2, 0, 0 }); break;
      
		// Orejas
    		case "pendant":
    		case "pendiente":
      		armour_data=({   10, 4000,   2,  1,  0, 5, 2, 0, 0 }); break;
      
      		// Nariz
    		case "nariz": /* Nuevo */
		case "anillo_nariz":
		case "pendiente_nariz":
      		armour_data=({    1,  1500,  5,  1,  0, 6, 2, 0, 0 }); break; /* Es algo metalico, que conste */

      		// Labio
    		case "labio": /* Nuevo, lo mismo, algo metalico q no se pa q puede valer (un piercing?) */
      		armour_data=({    1,  1500,  5,  1,  0, 7, 2, 0, 0 }); break;

      		// Cuello
    		case "amulet":
    		case "necklace":
    		case "amuleto":
    		case "collar":
      		armour_data=({   10,  4000,  2,  1,  0, 8, 2, 0, 0 }); break;

      		// Hombros
    		case "hombreras": /* Nuevo de cuero */
      		armour_data=({   20,  1500, 10,  6,  0, 9, 3, 0, 0 }); break;

      		// Pecho
    		case "pechera": /* Nuevo tb de cuero */
      		armour_data=({   20,  1500, 15, 15,  0,10, 3, 0, 0 }); break;

      		// Vientre
    		case "vientre": /* Nuevo y no se pa que puede valer, pero lo pongo como cuero */
      		armour_data=({   25,  1500, 20,  6,  0,11, 3, 0, 0 }); break;

      		// Brazos
    		case "brazal_cuero": /* Nuevo, lo antiguo eran munyequeras y ahora van alli */
      		armour_data=({   20,  2000, 15,  6,  0,12, 3, 0, 0 }); break;

      		case "brazal_metal": /* Nuevo tb */
      		armour_data=({   25,  2500, 20,  6,  0,12, 2, 0, 0 }); break;

		// Munyecas
    		case "bracers":
    		case "pulsera":
		case "mu�equeras":
      		armour_data=({    7,  2000,  5,  2,  0,13, 2, 0, 0 }); break;

       		// Manos
    		case "guantes":
    		case "gloves":
      		armour_data=({    3,  2000,  3,  2,  0,14, 3, 0, 0 }); break;

    		case "gauntlets":
    		case "guantelete":
      		armour_data=({    3,  2000,  5,  3,  0,14, 2, 0, 0 }); break;

      		// Dedos
    		case "ring":
    		case "anillo":
      		armour_data=({    1,  4000,  1,  1,  0,15, 2, 0, 0 }); break;

		// Cintura
    		case "belt":
    		case "cinturon":
      		armour_data=({    7,  2000,  5,  2,  0,16, 3, 0, 0 }); break;

        	// Pelvis
    		case "pelvis": /* Nuevo, otra cosa que no se para que puede valer pero weno, lo pongo en cuero */
      		armour_data=({   25,  1500, 20,  5,  0,17, 3, 0, 0 }); break;

        	// Piernas
    		case "trousers":
    		case "pantalon":
                armour_data=({    5,   500,  2,  6,  0,18, 4, 0, 0 }); break;

    		case "greba_metal": /* Nuevo */
      		armour_data=({   30,  2500, 20,  6,  0,18, 2, 0, 0 }); break;

    		case "greba_cuero": /* Nuevo */
      		armour_data=({   25,  2000, 15,  6,  0,18, 3, 0, 0 }); break;

      		// Tobillos
    		case "tobilleras": /* Nuevo aunq no es algo muy... lo pongo en tipo ropa */
      		armour_data=({   -2,   500,  1,  4,  0,19, 4, 0, 0 }); break;

		// Pies
    		case "shoes":
		case "zapatos":
    		case "boots":
    		case "botas":
      		armour_data=({    2,  1500, 15,  3,  0,20, 3, 0, 0 }); break;

    		case "slippers":
    		case "zapatillas":
      		armour_data=({    1,  1500, 10,  2,  0,20, 4, 0, 0 }); break;

    		case "botas_metal": /* Nuevo */
      		armour_data=({    3,  1500, 20,  4,  5,20, 2, 0, 1 }); break;

		// Torso
    		case "cape":
    		case "cloak":
    		case "capa":
    		case "manto":
      		armour_data=({    1,  1500, 10, 10,  0,21, 4, 0, 0 }); break;

    		case "piel": /* Vilat 24.08.2002 (piel base del despellejar) */
      		armour_data=({    1,  1500, 10, 10,  2,21, 3, 0, 0 }); break;

      		// Espalda
    		case "espalda": /* Otra cosa de esas nuevas q no se pa q pueden valer... quizas de rinyonera? Lo pongo en cuero */
      		armour_data=({    1,  1500,  8,  8,  0,22, 3, 0, 0 }); break;

		case "bagpack": /* Quizas para esto? XDDDDD  yo creo que si */
		case "mochila":
                armour_data=({    1,  1000,  10, 6,  0,12, 4, 0, 0 }); break;

        	// Culo
    		case "culo": /* Lo ultimo nuevo y tp le veo utilidad.. Pa unos calzones? lo pongo en tipo ropa */
      		armour_data=({   -5,   500,  1,  4,  0,23, 4, 0, 0 }); break;

    		default:
                armour_data=({    1,     1,  1,  1,  1, 1, 1, 1, 1 }); break;
    		break;
  		}
  	return armour_data;
	}
