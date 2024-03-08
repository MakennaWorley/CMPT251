/*
 * heartbleed.c
 *
 * A demonstration of how the Heartbleed bug in SSL can
 * be exploited to leak secret information.
 *
 * https://en.wikipedia.org/wiki/Heartbleed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secret();

int main()
{
    // Call secret() to simulate there being some history of
    // secret information in memory
    secret();

    int length;
    printf("How long is your name? ");
    scanf("%d", &length);

    // calloc(n, s) allocates enough memory to hold n chunks
    // of size s (e.g. an array of n elements where each
    // element has size s).
    // It also zeros out the memory allocated!
    
    char *name = (char *)malloc(length + 1);
    //char *name = (char *)calloc(length + 1, sizeof(char));
    
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Your name is ");
    // Print out exactly length characters, regardless of
    // how long the name actually was
    for (int i = 0; i < length; ++i)
        printf("%c", name[i]);
        
    printf("\n\n");

    return 0;
}

void secret()
{
    // Allocate some memory to hold secret information
    char *credentials = (char *)malloc(100);
    // Copy secret data into the memory
    strcpy(credentials, "Username: Administrator\nPassword: SeCrEt PaSsWoRd!1!1\n");

    // In a real program we would do something with the
    // secret information at this point...

    // All done with the secrets!
    free(credentials);
}
