#include "point.h"
#include<iostream>

using namespace std;

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point operator-(const Point &p){
    Point temp(0, 0);
    temp.x = - p.x;
    temp.y = - p.y;
    return temp;
}

bool operator==(const Point &p1, const Point &p2){
    if (p1.x == p2.x && p1.y == p2.y)
        return true;
    else
        return false;
}

void Point::show(){
    cout << "(" << x << ", " << y << ")" << endl;
}
