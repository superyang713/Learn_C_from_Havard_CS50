#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


struct point_tag
{
    double x;
    double y;
};
typedef struct point_tag point_t;


point_t rotate(point_t p, double angle)
{
    // rotation around origin, is done by
    // matrix multiplication:
    // [x] = [cos angle, -sin angle] * [x]
    // [y]   [sin angle,  cos angle]   [y]
    p.x = p.x * cos(angle) - p.y * sin(angle);
    p.y = p.x * sin(angle) + p.y * cos(angle);
    return p;
}

double deg2rad(double degrees)
{
    return degrees * M_PI / 180;
}

void testRotate(double orig_x, double orig_y, double degrees, double exp_x,
                double exp_y)
{
    printf("Rotating (%f, %f) by %f degrees: \n", orig_x, orig_y, degrees);
    point_t p;
    p.x = orig_x;
    p.y = orig_y;
    point_t ans = rotate(p, deg2rad(degrees));
    assert(fabs(ans.x - exp_x) < 0.000001);
    assert(fabs(ans.y - exp_y) < 0.000001);
    printf("     Got(%f, %f)\n", ans.x, ans.y);
}


int main(void)
{
    testRotate(1, 0, 90, 0, 1);
    testRotate(0, 1, 90, -1, 0);
    testRotate(0, 0, 45, 0, 0);
    testRotate(3, 3, 90, -3, 3);
    testRotate(4, 2, -90, 2, -4);
    testRotate(3, 7, 180, -3, -7);
    testRotate(6, 8, 360, 6, 8);
    testRotate(-2, 4, 0, -2, 4);
    testRotate(20, 0, 30, 10*sqrt(3), 10);
    testRotate(20, 0, 60, 10, 10*sqrt(3));
    return EXIT_SUCCESS;
}

