/*
 * addrs.c
 *
 * Demonstration of the & operator and areas of memory
 */

#include <stdio.h>

// These are global variables: they can be accessed from anywhere in the program.
int gi = 1000;
double gd;
char *gs = "Global string";

void f(int pi, char pc, char *ps);

int main()
{
    // These are local variables
    int i;
    long l;
    char *s = "Local string";

    // Print the address of variable i
    //printf("Address of i: %ld\n", &i);
    // Print the address of variable i as a pointer (in hexadecimal)
    //printf("Address of i as a pointer: %p\n", &i);

    f(i, 'X', s);
    
    //printf("Address of gi: %p\n", &gi);
    //printf("Address of gd: %p\n", &gd);
    printf("Address of gs: %p\n", gs);
    //printf("Address of i: %p\n", &i);
    //printf("Address of l: %p\n", &l);
    printf("Address of s: %p\n", s);

    return 0;
}

void f(int pi, char pc, char *ps)
{
    // pi, pc, and ps are parameters
        //printf("Address of pi: %p\n", &pi);
        //printf("Address of pc: %p\n", &pc);
        printf("Address of ps: %p\n", ps);
}
