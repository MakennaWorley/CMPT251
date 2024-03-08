#include <math.h>
#include "circle.h"

double cylinder_radius_to_area(double r, double h)
{
    double a = circle_radius_to_area(r);
    double a1 = a*h;
    return a1;
}

double cylinder_radius_to_surface_area(double r, double h)
{
    double p = circle_radius_to_circumference(r);
    double sa = p*h;
    return sa;
}
