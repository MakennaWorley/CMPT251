#include <stdio.h>
#include "circle.h"
#include "cylinder.h"

//double circle_radius_to_area(double r);

int main()
{

    double r = 0;
    double h = 0;

    printf("Please enter the radius of a circle: ");
    scanf("%lf", &r);

    printf("Please enter the height of a cylinder: ");
    scanf("%lf", &h);

    //printf("The number entered is: %lf\n", r);

    double a = circle_radius_to_area(r);
    printf("The area is %lf\n", a);

    double c = circle_radius_to_circumference(r);
    printf("The circumference is %lf\n", c);

    double a1 = cylinder_radius_to_area(r, h);
    printf("The volume of a cylinder is %lf\n", a1);

    double sa = cylinder_radius_to_surface_area(r, h);
    printf("The surface area of a cylinder is %lf\n", sa);

    return 0;
}
