/*
 * ptrs.c
 *
 * Experimentation with pointers and dereferencing.
 */

#include <stdio.h>

void f(long *lp, double *dp);

int main()
{
    int i = 42;
    int *p = &i;
    long *lp = 0;
    double *dp = 0;

    printf("The value of i: %d\n", i);
    printf("The value of *p: %d\n", *p);
    printf("The address of i: %p\n", &i);
    printf("The address of *p: %p\n", &*p);

    *p = 54;
    printf("The value of i: %d\n", i);
    printf("The value of *p: %d\n", *p);
    printf("The address of i: %p\n", &i);
    printf("The address of *p: %p\n", &*p);

    printf("The value of *lp: %ld\n", *lp);
    printf("The value of dp: %lf\n", *dp);
    f(lp, dp);
    printf("The value of *lp: %ld\n", *lp);
    printf("The value of dp: %lf\n", *dp);
    return 0;
}

void f(long *lp, double *dp)
{
    *lp = 1034;
    *dp = 2.718;
}
