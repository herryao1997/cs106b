#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;


Point::Point(int a, int b){
    cout << "The constructor with two parameters is being called now." << endl;
    x = a;
    y = b;
}

Point::~Point(){
    cout << "The destructor is being called now." << endl;
}

int Point::X () const{
    return x;
}

int Point::Y () const{
    return y;
}

double Distance(Point &p1, Point &p2){
    double d;
    d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return d;
}

double Distance2(const Point &p1, const Point &p2){
    double d;
    d = sqrt((p1.X() - p2.X()) * (p1.X() - p2.X()) + (p1.Y() - p2.Y()) * (p1.Y() - p2.Y()));
    return d;
}
