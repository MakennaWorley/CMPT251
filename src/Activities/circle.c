#include <math.h>

const double PI = 4 * atan(1);

double circle_radius_to_area(double r)
{
    double area = PI*r*r;
    return area;
}

double circle_radius_to_circumference(double r)
{
    double c = 2*PI*r;
    return c;
}
