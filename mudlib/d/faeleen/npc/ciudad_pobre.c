//Fichero de npcs de los barrios pobres de Faeleen

inherit "/obj/monster";

void setup()
  {
  add_move_zone("faeleen_pobre");
  set_move_after(20+random(10), 20+random(10));
  set_race("humano");
  switch(random(4))
  {
  case 0:
      set_name("obrero");
      set_short("Obrero");
      set_long("Obrero.\n\n"
               "    Es uno de los muchos obreros que se contrataron recientemente"
               " en Faeleen para construir las nuevas mansiones de la zona rica. Se"
               " trata de un hombre de mediana edad, bastante musculoso, y parece de"
               " bastante mal humor.\n\n");
      set_main_plural("Obreros");
      add_plural("obreros");
      set_gender(1);
      set_level(10+random(6));
      if(!random(40))
      {
      	add_clone("/baseobs/weapons/twohanded_mace.c",1);
      }

      ::init_equip();
      load_chat(20, ({ 1, "'Odio este maldito barrio.", 
                       1, "@escupe.",
                       1, "'Grrr."}));
        
      break;
  case 1:
      set_name("mujer pobre");
      set_short("Mujer pobre");
      set_long("Mujer pobre.\n\n"
               "    Una habitante de las zonas pobres de Faeleen. Dedica su vida "
               "mayormente a las tareas domesticas y a ir al mercado de la zona rica"
               " para abastecerse de comida y primeras materias.\n\n");
      add_alias("mujer");
      add_alias("pobre");
      set_main_plural("Mujeres pobres");
      add_plural("mujeres pobres");
      add_plural("mujeres");
      add_plural("pobres");
      set_gender(2);
      load_chat(20, ({ 1, "'Como me gustaria salir de este maldito barrio.", 
                       1, "'Maldita envidiosa, ya la pillare ya...",
                       1, "Ves como una mujer te mira con desconfianza."}));
      
      ::init_equip();
      set_level(7+random(5));
      
      break;
  case 2:
      set_name("granuja");
      set_short("granuja");
      set_long("Granuja.\n\n"
               "    Un granujilla que dedica su vida a holgazanear por la ciudad, "
               "buscando de donde puede obtener unos ingresos faciles. No parece muy"
               " agresivo pero tal vez sea peligroso.\n\n");
      set_main_plural("Granujas");
      add_plural("granujas");
      set_gender(1);
      set_level(18+random(7));
      adjust_money(0+random(5), "plata");
      add_clone("/baseobs/armours/leather.c",1);
      add_clone("/baseobs/weapons/daga.c",1);
      ::init_equip();
      break;
  case 3:
      set_name("hombre pobre");
      set_short("Hombre pobre");
      set_long("Hombre pobre.\n\n"
               "    Un habitante de las zonas pobres de Faeleen. Debido a lo escaso "
               "de sus ingresos no puede permitirse vivir en las zonas lujosas de la "
               "ciudad y vive resignado en las barriadas.\n\n");
      add_alias("hombre");
      add_alias("pobre");
      set_main_plural("Hombres pobres");
      add_plural("hombres pobres");
      add_plural("hombres");
      add_plural("pobres");
      set_gender(1);
      load_chat(20, ({ 1, "'algun dia podre pagar una casa en las zonas ricas.", 
                       1, "'creo que volvere un rato a la taberna",
                       1, "@se urga el bolsillo, pero no encuentra nada."}));
      
      ::init_equip();
      set_level(7+random(5));
      
      break;
    }
;

}



