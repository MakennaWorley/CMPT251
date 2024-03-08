#include <stdio.h>

int main()
{

    char *names[] = {
        "Drake", "Prash", "Makenna", "Jesse", "Nic", "Arogya", "Kathy"
    };

    //sizeof(name) would be 56, each pointer is 8 bytes and there are 7 pointers here
    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", names[i]);
    }

    //char *name0 = "Drake";
    //char *name1 = "Prash";
    //char *name2 = "Makenna";
    //char *name3 = "Jesse";
    //char *name4 = "Nic";
    //char *name5 = "Arogya";
    //char *name6 = "Kathy";

    //printf"%s\n", name0); //printing out the names one by one
}
