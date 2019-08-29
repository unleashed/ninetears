/* Raskolnikov Nov 96 */

string *block_list = ({
  "/global/lord",
  "/global/lord.c",
  "/global/god",
  "/global/god.c",
});

object *children(string name) {
    int i;
    object *obs; 

    obs = efun::children(name);
    if(this_player() && this_player()->query_lord())
	return obs;
    for(i=0;i<sizeof(obs);i++)
	if(member_array(obs[i], block_list))
	    if(obs[i]->query_invis() == 2)
		obs -= ({ obs[i] });
    return obs;
}

