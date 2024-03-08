#include <stdio.h>
#include <math.h> // for math functions like sqrt()

struct point
{
    double x;
    double y;
};

void printPoint(struct point p);
struct point inputPoint(const char *prompt);
double distanceFromOrigin(struct point p);

int main()
{
    struct point p;

    p.x = 1.8;
    p.y = -4.7;

    // Delete the comment below to do #4
    p = inputPoint("Type in a point in the form (x, y): ");

    printf("The point is ");
    printPoint(p);
    printf("\n");

    printf("The distance from the origin is %lf\n", distanceFromOrigin(p));

    return 0;
}

void printPoint(struct point p)
{
    // Add code here (print the point in the form "(x, y)")
    printf("at (%lf,%lf)", p.x, p.y);
}

struct point inputPoint(const char *prompt)
{
    struct point p;

    // Add code here (print the prompt, then have the user
    // have the user write a point in the form "(x, y)")
    printf("%s", prompt);
    scanf("(%lf, %lf)", &p.x, &p.y);

    return p;
}

double distanceFromOrigin(struct point p)
{
    struct point o;
    o.x = 0.0;
    o.y = 0.0;

    double sq = pow(p.x-o.x, 2) + pow(p.y-o.y, 2);
    //printf("under square root is %lf", sq);
    return sqrt(sq);
}
