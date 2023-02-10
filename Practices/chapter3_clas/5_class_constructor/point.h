/**
 * - this is the interface of class, which is the .h file
 * - inside class interface there are class members, and member function declaration
 * - inside class interface there are also the constructor and destructor
 * - when the constructor is reloaded inside implementation, it should be also declared
 *  inside the class_interface
*/

#ifndef POINT_H
#define POINT_H

class Point{
private:
    int x, y;
public:
    void set();
    void show();

    Point();
    Point(int a, int b);
    virtual ~Point();
};

#endif // POINT_H
