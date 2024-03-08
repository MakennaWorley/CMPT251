#include <stdio.h>

char NAME_LETTERS[4] = { 'A', 'B', 'C', '\0' };

void f();
void g();

int main()
{
    /*
    char *name = &NAME_LETTERS;
    printf("%p\n", name);
    printf("%s\n", &name);

    int x = 0x434241;
    printf("%d\n", x);  // x in decimal (base 10)
    printf("%x\n", x);  // x in hexadecimal (base 16)

    printf("%c\n", *name);
    int *p = &x;
    printf("p = %lx\n", p);     // value of p (address of x)
    printf("*p = %x\n", *p);    // dereference p (value of x)

    *p = 5; // changes the value of x (because that's what p points to)
    //int *p = 5; // declares a variable p, an int pointer, with value (mem addr) 5

    printf("x = %d\n", x);
    //printf("*x = %d\n", *x);

    /*
    String[] cheeses = { "Münster", "Cheddar", "Mozzarella" };
    cheeses = ... // change cheeses (it will be a different array of Strings)
    cheese[0] = ... // change value of first element of cheeses
    */

/*
    long l = 4613302810693613912;
    double d = *(double *) &l;
    printf("d = %lf\n", d);
    */

    printf("Hello, world!\n");
    int x;
    printf("What is your favorite number? ");
    scanf("%d", &x);
    g();
    f();


    int y = 99;
    int *p = &y;
    int **pp = &p;

    printf("y = %d\n", y);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);
    
    return 0;
}

void f()
{
    double *dp; // don't leave pointers uninitialized!!!
    dp = NULL; // C's version of Java's null
    printf("dp = %lx\n", dp);
    printf("*dp = %lf\n", *dp);
    
}

void g()
{
    long rutabaga = 34873487347835;
    printf("rutabaga = %ld\n", rutabaga);
}
