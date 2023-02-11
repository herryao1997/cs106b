/**
 *  - case: define the class of point with properties of x and y coordinates
 *   and define the function of the distance between two point
 *  - distance is a function defined in stl library cannot be reused
 *  - when the reference parameter is set as the constant to access the function
 *   in the class, the type of the returned value in the class should also be the
 *   constant the basic format should be :
 * ==================================================================
 * class Point{

private:
    int x, y;

public:
    Point(int a, int b){
        cout << "The constructor with two parameters is being called now." << endl;
        x = a;
        y = b;
    }

    ~Point(){
        cout << "The destructor is being called now." << endl;
    }

    int X() const{
        return x;
    }

    int Y() const{
        return y;
    }
};

double Distance2(const Point &p1, const Point &p2){
    double d;
    d = sqrt((p1.X() - p2.X()) * (p1.X() - p2.X()) + (p1.Y() - p2.Y()) * (p1.Y() - p2.Y()));
    return d;
}
 * ==================================================================
 * - the aim of usage of friend function is to improve the efficiency of the program
 * - be careful when using the friend function, since it result in the outside accessing to the private
 *  or protected members, which destruct the confidential properties of the information stored
 *
 * - the friend in class includes:
 * 1. friend functions
 * 2. friend members
 * 3. friend classes
 *
 *  - friend member:
 *  - one member of a class can be a friend function for another class
 *  - the member of class can not only access all the members in the current class,
 *  but also access the class with declaration of friend
 *  - in this way the interaction between different two classes can be achieved to
 *   complete one task cooperatively
 * ==================================================================
 *
 * - friend class:
 * - one class can be a friend for another class
 * - when one class declared as a friend of another class, all the members in the
 *  class with declaration are available to this friend class
 * - the basic declaration method of the friend class should be as follow:
 * friend class_name;
 * - the declaration can be placed at public/protected/private
 * ==================================================================
 * - to be noticed:
 * 1.friend ship among classes is one-way without exchangeability, B is declared as friend
 *  in A but without declaration in B, then B can access A, while A cannot access B.
 * 2. only while both classes declared each other as friend class the inter-action can be truely achieved
 * 3. the friend ship is not transferable, A is friend of B, B is friend of C, which means:
 *          A can access all the members in B
 *          B can access all the members in C
 *          while A cannot access the private members in C
 * ------------------------------------------------------------------
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "point.h"
#include "couple.h"

using namespace std;

//class Point{
//private:
//    int x, y;

//public:
//    Point(int a = 0, int b = 0){
//        x = a;
//        y = b;
//    }

//    void show(){
//        cout << "(" << x << "," << y << ")" << endl;
//    }

//    int X() const
//    {
//        return x;
//    }

//    int Y() const
//    {
//        return y;
//    }

//    friend double Distance(Point &p1, Point &p2);

//};


//double Distance(Point &p1, Point &p2){
//    double d;
//    d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
//    return d;
//}


//double Distance2(const Point &p1, const Point &p2){
//    double d;
//    d = sqrt((p1.X() - p2.X()) * (p1.X() - p2.X()) + (p1.Y() - p2.Y()) * (p1.Y() - p2.Y()));
//    return d;
//}

int main() {
    Point p1(0, 0), p2(1, 1);
    double distance = Distance2(p1, p2);
    //double distance = Distance(p1, p2);
    cout << "The distance between two point is " << distance << endl;

    cout << "---------------------------------" << endl;
    cout << "---------------------------------" << endl;
    cout << "---------------------------------" << endl;
    cout << "---------------------------------" << endl;

    Boys he("Edward");
    Girls she("Rose");

    he.IntroduceOneself();
    he.IntroduceFriend(she);
    she.IntroduceOneself();
    return 0;
}




