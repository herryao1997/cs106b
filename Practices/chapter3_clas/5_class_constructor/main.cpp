/**
 *  - constructor is a special member function, the creation of the class object is done by which.
 *  - The basic format of which should be as follow:
 * ==================================================================
 *  class_name :: class_name(list_of_formal_parameters){
 *          function_body;
 *  }
 * ==================================================================
 * - the feature of constructor:
 * 1. should be declared as public member       <*****>
 * 2. the name of constructor should be same as the class_name
 * 3. reload declaration is allowed for the constructor
 * 4. it is illegal to specify a return type for the constructor
 * 5. it is illegal to explicitly call the constructor
 * 6. when the object is declared, the constructor will be called automatically
 *
 * - if the constructor is not defined, it will be defined in default by the system, which is empty.
 * - the format of default constructor should be as follow:
 * ==================================================================
 * class_name::class_name(){
 *
 * }
 * ==================================================================
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
    // This time the pointer declaration doesn't call the constructor.
    rp -> show();
    cout << "---------------------------------" << endl;
    Point p4(1, 2);
    p4.show();
    return 0;
}


