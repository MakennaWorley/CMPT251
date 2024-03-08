#include <stdio.h>
#include <myfunction.h>

int main()
{
    double in = 0;

    printf("Give me a number please: ");
    scanf("%lf", &in);

    double mm = length_inch_to_mm(in);
    double cm = length_mm_to_cm(mm);
    double m = length_cm_to_m(cm);

    printf("%.2lf inches is equal to %.2lf mm\n", in, mm);
    printf("%.2lf mm is equal to %.2lf cm\n", mm, cm);
    printf("%.2lf cm is equal to %.2lf m\n", cm, m);
}