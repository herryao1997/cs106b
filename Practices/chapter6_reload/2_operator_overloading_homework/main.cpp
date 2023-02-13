/**
 * - requirement of the practice:
 * 1. define a class of point to describe the concept of the point with properties of
 *  (x, y) representing the coordinates and overload the - and == operator to achieve
 *  reverse the coordinate and the judgement of equality of two points
 *  ---------------------------------------------------------------------------------
 *  using the method of member function >> >> only with one parameter need to define
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "point.h"

using namespace std;

int main() {
    Point p1(1, 2);
    Point *pp;
    pp = &p1;
    pp->show();
    cout << (*pp == p1) << endl;
    Point p2 = -p1;
    p2.show();

    return 0;
}
