/*
 *  STANDARD HEADER FILE
 */

#ifndef __STD_HEADER__
#define __STD_HEADER__

#define MUDLIB_VERSION   "FRlib IIIR4"

#define TP           this_player()
#define NAME         (string)TP->query_name()
#define CNAME        (string)TP->query_cap_name()  /* this checks invis */
#define CAP_NAME     CNAME
#define LEVEL        (int)TP->query_level()
#define HE           (string)TP->query_pronoun()
#define HIM          (string)TP->query_objective()
#define HIS          (string)TP->query_possessive()
#define GENDER       (string)TP->query_gender()
#define TO           this_object()
#define ENV(XXX)     environment(XXX)
#define LC(XXX)      lower_case(XXX)
#define CAP(XXX)     capitalize(XXX)
#define DEAD         query_dead()
#define ETO        environment(this_object())

#define SETEUID seteuid((string)"/secure/master"->creator_file(file_name(TO)))
#define STDOB void create() { SETEUID; } void dest_me() { destruct(TO); }

// #pragma save_binary
#endif
