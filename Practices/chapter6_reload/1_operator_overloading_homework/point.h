#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double x, y;
public:
    Point(double x, double y);
    void show();
    friend Point operator-(const Point &p);
    friend bool operator==(const Point &p1, const Point &p2);
};

#endif // POINT_H
