#include "drinks.h"
/* ok handles hps, Spell/Power points and drinking/eating things...
 * Hmmmm, considering we dont want to have drinks/food I will not
 * put that in at the moment.
 */
/* Logging Taniwha 1995 */
#define XP_LIMIT 15000
#define LOGFILE "BUSTED"
int hp=1;
int max_hp=1;
int gp=1;
int max_gp=1;
int ep=1;
int max_ep=1;
int xp, total_xp, wimpy, fp;
int rp=50;

private int *drink_info;
nosave mapping damage_done;

void create() {
    damage_done = ([ ]);
} /* create() */

int query_hp() { return hp; }
int query_max_hp() { return max_hp; }
int query_gp() { return gp; }
int query_max_gp() { return max_gp; }
int query_xp() { return xp; }
int query_total_xp() { return total_xp; }
mapping query_damage_done() { return damage_done; }

int set_wimpy(int i) 
{
    int j;
    j = this_object()->query_property("fear");
    if(i < j) i = j;
    if (i <0 || i > 100)
	return -1;
    return (wimpy = i);
} /* set_wimpy() */

int query_wimpy() { return wimpy; }

int set_max_hp(int i) {
    if (max_hp)
	hp = hp*i/max_hp;
    else
	hp = max_hp;
    max_hp = i;
    if (max_hp==1)
	max_hp = 2;
    if (hp>max_hp)
	hp = max_hp;
    return max_hp;
}  /* set_max_hp() */

// Made varargs : Radix - March 3, 1997
varargs int set_hp(int i, object hp_remover)
{
    if (i>max_hp)
	i = max_hp;
    hp = i;
    if (hp<0)
	call_out("do_death", 0,  hp_remover);
    return hp;
} /* set_hp() */

// int is_spell_damage a 1 indica que se produjo como consecuencia
// de un hechizo -> solo importante para shadows como piel piedra
// se llama desde global/spell.c con 1 en is_spell_damage.
int adjust_hp(int i, object hp_remover, int is_spell_damage)
{
    int bah = 1;    // for color on hp monitor - Radix
	/*if (is_spell_damage) {
		tell_object(TO, "Danyo por spell:" + i);
	}*/
    hp += i;
    if(hp_remover && !(int)hp_remover->query_dead() )
	damage_done[hp_remover] += i;
    if ( hp>max_hp )
	hp = max_hp;

    if ( hp<0 ) /* eeek we died! */
    {
	if(i > 0 && hp_remover == this_object() ) call_out("do_death",0,0); /* NOT this object, use attacker list */
	else if (i <= 0 && hp_remover == TO) // new by Tyrael - Evita ver que te propinas.
	{
		tell_object(TO, "Acabas con tu triste existencia.\n");
		tell_room(ETO, TO->QCN + " termina con su triste existencia.\n", TO);
		call_out("do_death",0,0);
	}
	else
	    call_out("do_death", 0, hp_remover);
    }
    // Radix Jan 1996
    if (hp < max_hp/5)
	bah = 0;
    if(interactive(this_object()))
    {
	remove_call_out("display_monitor");
	call_out("display_monitor",0,bah);
    }
    return hp;
} /* adjust_hp() */


// ahora pierdes piel de piedra si la llevas
int really_adjust_hp(int i, object hp_remover) // se pasa por el forro shadows
{
	// EL is_spell_damage NO INDICA NECESARIAMENTE Q SEA DANYO POR HECHIZO
	// PUEDE USARSE PARA QUE ESTA FN SI HAGA DANYO INCLUSO CON PIEL PETREA
	// POR EJEMPLO SI UNA CLERA METE LEPRA AL TIO SIN PIELES Y LUEGO
	// SE LAS TIRA, LA LEPRA SEGUIRA DANYANDOLE SIN QUITAR PIELES.
	//
	// AUN NO RULA
	//
	// Tyrael - Ene'02
    int bah = 1;    // for color on hp monitor - Radix
/*	if (query_stoneskin_spell()) {
		if (!is_spell_damage)
			return adjust_hp(i, hp_remover);
	}*/
    hp += i;
    if(hp_remover && !(int)hp_remover->query_dead() )
	damage_done[hp_remover] += i;
    if ( hp>max_hp )
	hp = max_hp;

    if ( hp<0 ) /* eeek we died! */
    {
	if(i > 0 && hp_remover == this_object() ) call_out("do_death",0,0); /* NOT this object, use attacker list */
	else
	    call_out("do_death", 0, hp_remover);
    }
    // Radix Jan 1996
    if (hp < max_hp/5)
	bah = 0;
    if(interactive(this_object()))
    {
	remove_call_out("display_monitor");
	call_out("display_monitor",0,bah);
    }
    return hp;
} /* really_adjust_hp() */

int set_max_gp(int i) 
{
    if (max_gp)
	gp = gp*i/max_gp;
    else
	gp = max_gp;
    max_gp = i;
    if (gp>max_gp)
	gp = max_gp;
    return max_gp;
} /* set_max_gp() */

int set_gp(int i) {
    gp = i;
    if (gp > max_gp)
	gp = max_gp;
    return gp;
} /* set_gp() */

int adjust_gp(int i) {
    if(gp + i < 0)
	return -1;
    gp += i;
    if (gp>max_gp)
	gp = max_gp;
    return gp;
} /* adjust_gp() */
void logit(string what,int amount)
{
    if(interactive(this_object()))
    {
	log_file(LOGFILE,(string)this_object()->query_cap_name()+" awarded "+amount+" "+what+
	  " by "+previous_object()->query_name()+" file "+file_name(previous_object())+
	  "\n");
    }
}

int adjust_xp(int i) 
{
    // Radix : Aug 1997
    master()->valid_adjust_xp(previous_object(), this_object(), i);
    if(i > XP_LIMIT) logit("XP",i);
    if (i>0) {
	i = (100-wimpy)*i/100;
	total_xp += i;
    }
    xp += i;
    return xp;
} /* adjust_xp() */

int set_xp(int i) {
    // Radix : Aug 1997
    master()->valid_adjust_xp(previous_object(), this_object(), i);
    if( (i-xp) > XP_LIMIT) logit("XP",(i-xp));
    if ( (xp-i) > XP_LIMIT) logit("XP", -(xp-i));
    if(i == -1 || !i) logit("XP", i);
    xp = i;
}

/* int set_xp(int i) { xp = i; return xp; } */

int adjust_volume(int type, int amt) {
    if (!pointerp(drink_info))
	drink_info = allocate(D_SIZEOF);
    if (type >= D_SIZEOF)
	return 0;
    return drink_info[type] += amt;
} /* adjust_volume() */

int query_volume(int type) {
    if (!pointerp(drink_info))
	drink_info = allocate(D_SIZEOF);
    if (type >= D_SIZEOF)
	return 0;
    return drink_info[type];
} /* query_volume() */

void update_volumes() {
    int i;

    if (!drink_info)
	return ;
    for (i=0;i<sizeof(drink_info);i++)
	if (drink_info[i] > 0)
	    drink_info[i]--;
	else
	    drink_info[i] = 0;
} /* update_volumes() */

string health_string() {
	if (hp < max_hp/25)
		return "esta al borde de la muerte";
	if (hp < max_hp/20)
		return "esta en estado critico";
    if (hp < max_hp/10)
	return "esta en muy mal estado";
    if (hp < max_hp/5)
	return "esta en mal estado";
    if (hp < max_hp/2)
	return "no esta en muy buen estado";
    if (hp < max_hp - 200)
	return "esta algo herido";
	if (hp < max_hp)
    return "esta en buen estado";
	if (hp == max_hp)
    return "esta en perfecto estado";
} /* health_string() */

string volume_string() {
    	int i = 0;
	if(drink_info[i]<= 0) return "sobrio";
    	if(drink_info[i] <= 50) return "algo contentillo";
    	if(drink_info[i] <= 100) return "borracho";
    	if(drink_info[i] <= 500) return "ciego de bebida";
    	if(drink_info[i] <= 2000) return "vomitando por el alcohol";
    	if(drink_info[i] <= 6000) return "al borde del coma etilico";
    	return "en coma etilico";
	}

// Puntos de Energia (Vilat 04.09.2002)

int set_max_ep(int i) {
    	if (max_ep) ep = ep*i/max_ep;
    	else ep = max_ep;
    	max_ep = i;
    	if (ep>max_ep) ep = max_ep;
    	return max_ep;
	} /* set_max_ep() */

int set_ep(int i) {
    	ep = i;
    	if (ep > max_ep) ep = max_ep;
    	return ep;
	} /* set_ep() */

int adjust_ep(int i) {
    	if(ep + i < 0) return -1;
    	ep += i;
    	if (ep>max_ep) ep = max_ep;
    	return ep;
	} /* adjust_ep() */

int query_ep() { return ep; }
int query_max_ep() { return max_ep; }

int query_fp() { return fp; }

int query_rp() { return rp; }

int set_fp(int i) {
 if (!i||i<0||i>100) return fp;
 fp=i;
 return fp;
 }

int set_rp(int i) {
 if (!i||i>100||i<0) return rp;
 rp=i;
 return rp;
 }

int adjust_fp(int i) {
 if(!i||fp+i<0||fp+i>100) return fp;
 fp+=i;
 return fp;
 }

int adjust_rp(int i) {
 if(!i||rp+i>100||rp+i<0) return rp;
 rp+=i;
 return rp;
 }

string query_fp_name() {
 switch(fp) {
  case 0..10:return "Newbie";
  case 11..20:return "Aprendiz";
  case 21..30:return "Iniciado";
  case 31..50:return "Maestro";
  case 51..70:return "Profesional";
  case 71..100:return "Viciado";
  default:return "Bug";
  }
 }

string query_rp_name() {
 switch(rp) {
  case 0..9:return "Despreciado";
  case 10..24:return "Odiado";
  case 25..44:return "Traicionero";
  case 45..55:return "Normal";
  case 56..75:return "Honesto";
  case 76..90:return "Admirado";
  case 91..100:return "Santo";
  default:return "Bug";
  }
 }
