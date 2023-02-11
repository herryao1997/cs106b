#ifndef POINT_H
#define POINT_H


class Point
{
private:
    int x, y;
public:
    Point(int a, int b);
    ~Point();
    int X () const;
    int Y () const;
    friend double Distance(Point &p1, Point &p2);
};

double Distance2(const Point &p1, const Point &p2);
#endif // POINT_H
