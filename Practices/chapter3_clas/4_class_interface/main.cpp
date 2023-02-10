/**
 *  - object is the instance of the class, the basic definition for it should be format as follow:
 * class_name class_name_list;
 *
 * Point p1, p2; // create 2 objects of class Point
 * Point p[3];  // create a Point class type array with length==3
 * Point *p3;   // create a pointer of Point class type
 * Point &rp = p1;  // define a reference of Point type class toward p1(give p1 object a alias as rp)
 * ================================================================================
 * - there are two types pf access member methods in class objects:
 * 1. point_access_method eg:
 * Point p1;
 * p1.show();
 * 2. pointer_access_method eg:
 * Pointer *pt = &p1;
 * pt -> show();
 * ================================================================================
 * both methods are presented here in this file.
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "point.h"

using namespace std;

int main() {
    Point p1;
    //p1.x = 1; // This will not work due to x, y are private datas
    p1.set();
    Point *rp = &p1;
    rp -> show();
    cout << "---------------------------------" << endl;
    Point pb[3];
    for(int i = 0; i < 3; i++){
        pb[i].set();
        pb[i].show();
    }
    return 0;
}


