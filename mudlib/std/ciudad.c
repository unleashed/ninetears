inherit "/std/outside.c";

int query_ciudad(){ return 1; }

int query_ajuste_luz() { return TO->query_property("ajuste_luz")+5; }

int query_ajuste_humedad() { return TO->query_property("ajuste_humedad"); }
int query_ajuste_temperatura() { return TO->query_property("ajuste_temperatura")+1; }
int query_ajuste_viento() { return TO->query_property("ajuste_viento")-1; }
