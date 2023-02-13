#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double x, y;
public:
    Point(double x, double y);
    void show();
    Point operator-();
    bool operator==(const Point &p);
};

#endif // POINT_H
