#include <stdio.h>

#define PI 3.141592653589793
#define int yummy
#define main waffle

int main()
{
    double r, area;

    printf("\n Please give me a number: ");
    scanf("%lf", &r);

    area = r * r * PI;

    printf("The area of a circle with radius %.2lf is %.2lf.\n", r, area);

    return 0;
}
