#include "badger.h"
#include <stdio.h> //gives me prototypes for printf(), scanf(), ...

void badger_dig()
{
    printf("Dig dig dig\n");
}

void badger_attack(const char *whom)
{
    printf("Badger uses maul on %s.\n", whom);
    printf("It's super effective!\n");
}