inherit "/baseobs/weapons/hand_axe.c";

void setup()
{
    ::setup();
    set_enchant(1); // maybe remove this if it's TOO good
    set_short("Splitting axe");
    set_long("This axe seems to have been specially designed for splitting logs. "
    "It has a long narrow head and which is counter-weighted with a hammer shaped "
    "chunk of steel at the back. The section of handle just above the blade "
    "is padded with some sort of tough fabric. It looks as if it'd do a fine job "
    "on a wood pile, and maybe on a skull or two as well.\n"
    "There are marks stamped into the head which you can't read, but from all "
    "you've heard you guess that it was made by dwarves.\n");
}

