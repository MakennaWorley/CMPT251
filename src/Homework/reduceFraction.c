#include <stdio.h>

void reduceFraction(int *p, int *q);
int gcd(int m, int n);

int main()
{
    int top, bottom;
    printf("Enter a fraction: ");
    scanf("%d/%d", &top, &bottom);

    if (top == 0 || bottom == 0)
        printf("There is a 0 in this fraction\n");
    else
    {
        int* p = &top;
        int* q = &bottom;

        reduceFraction(p, q);

        printf("In lowest terms, that fraction is %d/%d\n", *p, *q);
    }

    return 0;
}

void reduceFraction(int *p, int *q)
{
    int top = *p;
    int bottom = *q;

    int divisor = gcd(top, bottom);
    //printf("divisor is: %d\n", divisor);
    *q = bottom/divisor;
    *p = top/divisor;

}

//provided function
int gcd(int m, int n)
{
    if (m < 0)
        return gcd(-m, n);
    else if (n < 0)
        return gcd(m, -n);
    else if (m < n)
        return gcd(n, m);
    else if (m % n != 0)
        return gcd(n, m%n);
    else
        return n;
}
