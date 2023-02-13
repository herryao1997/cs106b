#ifndef POINT_H
#define POINT_H
#include<iostream>

using namespace std;

class Point
{
private:
    double x, y;
public:
    Point(double x, double y);
    void show();
    Point operator-();
    bool operator==(const Point &p);
    friend ostream &operator << (ostream &my_out, const Point &p);
    friend istream &operator >> (istream &my_in, Point &p);
};

#endif // POINT_H
