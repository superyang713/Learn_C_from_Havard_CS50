#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct point_tag{
    int x;
    int y;
};
typedef struct point_tag point;

double computeDist(point a, point b)
{
    double distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return distance;
}

point * closestPoint(point * s, int n, point p)
{
    if (n == 0) { return NULL; }
    double bestDistance = computeDist(s[0], p);
    point * bestChoice = &s[0];
    for (int i = 1; i < n; i++)
    {
        double currentDist = computeDist(s[i], p);
        if (currentDist < bestDistance)
        {
            bestChoice = &s[i];
            bestDistance = currentDist;
        }
    }
    return bestChoice;
}

int main(void)
{
    point p;
    point p1;
    point p2;
    point p3;
    point p4;

    p.x = 1;
    p.y = -1;
    p1.x = 2;
    p1.y = 7;
    p2.x = 8;
    p2.y = -2;
    p3.x = 7;
    p3.y = -6;
    p4.x = -3;
    p4.y = -5;

    point pointSeries[4] = {p1, p2, p3, p4};
    point * bestChoice = closestPoint(pointSeries, 4, p);
    printf("The closest point is (%d, %d)\n", (*bestChoice).x, (*bestChoice).y);
    return EXIT_SUCCESS;
}
