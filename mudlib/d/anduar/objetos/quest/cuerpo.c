// By Sinister Mayo 00

inherit "/obj/corpse";

void setup()

{

        set_short("Cuerpo de Ezebhra");
        set_name("Cuerpo de Ezebhra");
        set_main_plural("Varios cuerpos de Ezebhra");
        add_alias("cuerpo");
        set_weight(5000);
        set_value(0);
        
        set_long("Ante ti el cuerpo destrozado de lo que fuera "
        "Ezebhra, La nigromante.\n");

}

void init()
{
        ::init();
        add_action("rajar_cuerpo","rajar");
}

int rajar_cuerpo(string str)
{
object cuerpo;
        if(str=="cuerpo")
        {
        write("Rajas el cuerpo de Ezebhra y dentro de el encuentras "
        "lo que parece ser un miembro de cuerpo ensangrentado.\n"
	"Al instante ves como el cuerpo desaparece sin dejar ningun "
	"rastro.\n");
cuerpo = clone_object("/d/anduar/objetos/quest/corazon.c");
 cuerpo->move(TP);
   destruct(TO);
}
  return 1;
}
