/* The FR basic workroom.
 * time to phase out the DW one, a lot of new roomcode is added since then.
 * It is not perfectly described, hey it's made by Baldrick..:=)
 */
#define CREATOR "barthleby"
inherit "/std/room";

object button;

void setup() 
  {
/* the short description is what you get in a room in brief mode.
 */
  set_short("Despacho de "+CREATOR+".");
/* you set this so you can see in the room.
 * for a description of light levels and what they mean type
 * help light
 */
  set_light(55);
/* the long description is the description you get when you type look
 * and when you work into a room in verbose mode.
 */
  set_long("El despacho de "+CREATOR+". Es una peque�a y sucia habitaci�n de 2X3 metros cuadrados "+
          "con unos muebles no exactamente brillantes. Tiene el mobiliario habitual de "+
          "un despacho; El escritorio es grande y no hay nada salvo polvo sobre el mismo, " +
          "tiene una fea silla tras �l y una l�mpara cuelga del techo. "+
          "Definitivamente necesita una limpieza.\n");

  /* If we inherited /std/outside, we would be able to use this one.
  set_dark_long(" The workroom of " + CREATOR + ". You can barely see some "+
          "furnitures  and a lamp in the dark.\n");
   */

/* Right this is the Senses code as coded and described by me - Sojan */
  add_smell("despacho", "Huele a viejo.");
  add_feel(({"silla", "sill�n",}), "Se siente mullido pero ahora tienes los dedos cuviertos de polvo.");
  add_taste("aire", "El aire sabe a mustio y viejo.");
  add_sound("campanas", "Puedes oir unas tintilantes campanas.");
/*  Explanation of above.
    When you use add_item to add items that players can look at you
    can also use a similar syntax as described above to add extra
    senses to the objects to add greater dimension to the rooms
    you create.  The syntax follows the same general pattern
    as add_item but has less options.
    Try to add sensible extra senses, in other words someone tasting
    a chair is dodgy but feeling or smelling it isn't so bad ..
    obviously sound is the most restricted ..
    the senses are interacted with via smell <object> taste <object>
    feel <object> and listen <sound> - touch <object> is also defined ...
    you cannot currently add_senses to objects - only in rooms can you do it ..
    Sojan - 9/12/1994
*/

/* the items are the things in the room that you can look at. */
/* try and put lots of these in the rooms you make, it makes them much
 * more interesting.
 */
  add_item("silla", "La silla est� hecha de oscura madera, no puedes averiguar de "+
                    "que tipo de madera se trata por culpa del polvo. "+
                    "Es fea pero parece verdaderamente c�moda.\n");
  add_item("escritorio", "El escritorio est� hecho de la misma oscura madera que la silla y "+
                   "tambi�n parece c�modo. Es grande y tiene el tama�o ideal "+
                   "para ti.\n");
  add_item("l�mpara", "La l�mpara brilla bastante, pero una limpieza har�a que la l�mpara "+
                    "cumpliese mejor su cometido.\n");

/* adds all the exits to the room.
 * the first paramater is the verb used to get through the exit.
 * the second is where to go once that exit is opened.
 * and the third is the type of the exit.  For a better desription of
 * this read the docs on rooms.
 */
  add_exit("common", "/w/common", "door");
  add_exit("tavern", "/d/ss/daggerford/ladyluck", "door");
  add_exit("noella", "/w/barthleby/entrada_provisional_a_noella", "door");
  add_exit("vestuario", "/w/barthleby/vestuario","corridor");
/* these two add_alias alias the exits.  Now when you type north (or n)
 * you will go to the mended drum and south to the common room
 */
  add_alias("north", "tavern");
  add_alias("south", "common");

/* this adds and exit back to your workroom into the common room
 */
  "/w/common"->add_exit(CREATOR, "/w/barthleby/workroom", "door");
  "/w/barthleby/entrada_provisional_a_noella"->add_exit(CREATOR, "/w/barthleby/workroom", "door");
} /* setup */

void init()
  {
  /* this gives you the possibility to add special actions to the object.
   * very useful.
   */
  add_action("do_clean", "limpiar");
  ::init();
} /* init() */

void reset()
  {
/* if the button does not exist (it has been dested or it hasnt been
 * created yet the varible is set to 0)  This makes sure you dont get
 * more than one button in your room.
 */
  if (!button) {
    button = clone_object("/obj/misc/button");
    button->move(this_object());
  }
} /* reset */

void dest_me()
  {
/* the dest_me function is called when an object is destructed.  We trap
 * this so that when the room is updated you dont end up with lots of
 * buttons, which does look pretty silly.
 */
  if (button)
    button->dest_me();
/* for a description of what the :: does go and shoot someone.
 * I dont think I can explain it in less than ten pages, and you would
 * not understand it anyway.
 */
  ::dest_me();
} /* dest_me */

/* The cleaning the add_action added */

int do_clean()
  {
  write("Comienzas a limpiar el escritorio y encuentras un trozo de papel bajo el "+
        "polvo.\n");
  new("/obj/misc/newcreator_paper")->move(this_player());
  return 1;
} /* do clean */

void event_enter(object guest, string mess, object from)
  {
  tell_room(this_object(), guest->query_cap_name() +
        " entra en el despacho de " + CREATOR + " .\n", guest);
  tell_object(guest, "Entras en el despacho de " + CREATOR + ".\n");
  return;
} /* event_enter */


