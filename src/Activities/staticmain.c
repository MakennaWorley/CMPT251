#include <stdio.h>
#include <segment.h>

int main()
{
    double x = 0;
    double y = 0;

    double *xm = &x;
    double *ym = &y;

    segment_midpoint(0, 0, 2, 2, xm, ym);

    printf("The midpoint of (0.00, 0.00) and (2.00, 2.00) is (%.2lf, %.2lf)\n", *xm, *ym);

    return 0;
}