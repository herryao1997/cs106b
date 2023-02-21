#include <iostream>
#include <string>
#include <cmath>
#include "console.h"

using namespace std;
/* - this is the homework for practicing class
 * - definition for the homework are as followed:
 * - design a class for circle, there should be properties radius and member functions for
 * radius setting and the area calcs;
 * - the aim is to practice the class definition method, instantiation; pointer; reference
 */

const int PI = acos(-1);

class Shape{
 public:
    Shape(){
        cout << "at 0" << endl;
    }

};

class Composition{
public:
    Composition(){
        cout << "at 3" << endl;
    }
};

class Circle:public Shape{
private:
    int radius;
    Composition com;
public:
    void setRadius();
    void getPerimeter();
    void getArea();
    Circle(){
        cout << "at 1" << endl;
    }
};

int main() {
    Circle c;

    return 0;
}

int getSum (int a, int b){
    return a + b;
}

inline void Circle::setRadius(){
    cout << "Please enter the radius for the circle: " << endl;
    cin >> radius;
}

inline void Circle::getArea(){
    cout << "the area of given circle is: " << PI * radius * radius << endl;
}

inline void Circle::getPerimeter(){
    cout << "the perimeter of given circle is: " << PI * 2 * radius << endl;
}
