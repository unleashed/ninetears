inherit "/std/race_group.c";

setup()
{
   set_name("d'lakten house");

   set_short("D'lakten House");

   set_long("So, you want to join House D'lakten?  Do you know what "
            "it means to be a member of the most chaotic house in "
            "Banefall?  I will tell you what it means.  When you join "
            "this house you must be willing to give your mortal soul "
            "to Cyrcia the spider queen.  The order of loyalties is "
            "simple...First you give loyalty to Cyrcia above all else, "
            "second you give loyalty to your house and all the "
            "members of this house, and last you give loyalty to "
            "yourself so that you can achieve the proper level to "
            "destroy all surface scum that you encounter.  The "
            "glory of Cyrcia and of House D'lakten is entrusted "
            "to you my young Drow...Long Live D'lakten!\n\n");
            
}

int query_channel() { return(1); }

int query_drow_house() { return 1; }
