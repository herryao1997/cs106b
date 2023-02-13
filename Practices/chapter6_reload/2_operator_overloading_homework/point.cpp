#include "point.h"
#include<iostream>

using namespace std;

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point Point::operator-(){
    Point temp(0, 0);
    temp.x = - this->x;
    temp.y = - this->y;
    return temp;
}

bool Point::operator==(const Point &p){
    if (p.x == this->x && p.y == this->y)
        return true;
    else
        return false;
}

void Point::show(){
    cout << "(" << x << ", " << y << ")" << endl;
}
