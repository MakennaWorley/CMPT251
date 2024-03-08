
/*
 * types.c
 * A demonstration of some of C's basic data types
 */
#include <math.h>
#include <stdio.h>

int main()
{
    // Variables of some basic types
    int i =         3272616;
    float f =       0.25;
    double d =      3.1415926535;
    short s =       20000;              // "short" is short for "short int"
    long l =        28671800000000;     // "long" is short for "long int"
    long long ll =  l;                  // "long long" is short for "long long int"
    // Sorry, no "long long long" in C! =(
    char c =        'W';

    // Believe it or not, C does not have a string type. The closest thing it has
    // is "char *" (pointer-to-char). We will talk much more about pointers later on!
    char *str =     "CMPT 251";

    printf("The population of Utah is about %d.\n", i);
    printf("A quarter is worth $%f.\n", f);
    printf("The ratio of a circle's circumference to its diameter is approximately %lf.\n", d);
    printf("Jules Verne wrote a book called %d Leagues Under the Seas.\n", s);
    printf("The current national debt of the USA is currently about $%ld.\n", l);
    printf("Again, the current national debt of the USA is about $%lld.\n", ll);
    printf("You are a student at %cestminster College.\n", c);
    printf("You are taking %s.\n", str);

    printf("On this system, an int is %d bytes.\n", sizeof(int));
    printf("On this system, a float is %d bytes.\n", sizeof(float));
    printf("On this system, a double is %d bytes.\n", sizeof(double));
    printf("On this system, a short is %d bytes.\n", sizeof(short));
    printf("On this system, a long is %d bytes.\n", sizeof(long));

    int a;
    printf("\nPlease give me a number without a decimal! This will be a. ");
    scanf("%d", &a);
    float b;
    printf("\nPlease give me a number! This will be b. ");
    scanf("%f", &b);
    double cc;
    printf("\nPlease give me a number! This will be c. ");
    scanf("%lf", &cc);

//This was taken from programiz.com/c-programming/examples/quadratic-roots for the code below
    double dis, root1, root2, real, imag;

    dis = b * b - 4 * a * cc;

    if (dis > 0)
    {
        root1 = (-b + sqrt(dis)) / (2 * a);
        root2 = (-b - sqrt(dis)) / (2 * a);
        printf("\nroot1 = %.2lf and root2 = %.2lf\n", root1, root2);
    }

    else if (dis == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("\nroot1 = root2 = %.lf\n", root1);
    }

    else
    {
        real = -b / (2 * a);
        imag = sqrt(-dis) / (2 * a);
        printf("\nroot1 = %.2lf+%.2lf and root2 = %.2f-%.2fi\n", real, imag, real, imag);
    }

    printf("Isn't that so cool! See code for where I found the quadratic roots code\n");
    
    return 0;
}
