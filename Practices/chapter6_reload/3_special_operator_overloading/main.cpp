/**
 * - input and output operator overloading << and >>
 * - standard input object cin is an object of iostream class to handle the
 *  standard input operation(keyboard input)
 * - standard output object cout is an object of iostream class to handle the
 *  standard output operation(windows output)
 * - these two object can be only overloaded with the friend function format, since
 *  the object in the iostream class cannot be directly rewrited by user
 * - the basic format of this overloading should be as follow:
 * ==============================================================================
 * ostream &operator<<(ostream &,const class_object); >> const keyword should be added
 * istream &operator>>(istream &,class_object); >> const keyword should not be added
 * - This return void method can only output one time the Complex class object, since
 *  the returned type is void, as a result:
 *  cout << c1 << endl;
 * ==============================================================================
 *  This method to output is not allowed here.
 * - to validate this output method, the return type need to be changed
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "complex.h"

/* ostream &operator<<(ostream &, const class_object); >> const keyword should be added
 * istream &operator>>(istream &, class_object); >> const keyword should not be added
 * currently there is no object to cout the complex class
*/
using namespace std;

int main() {
    cout << 3 << endl;  //implicitly cout calling
    cout.operator << (3) << endl;   //explicitly cout calling
    cout.operator << ('a') << endl;
    Complex c1(17, -3);
    Complex c2(-100, 20);
    cout << c1 << c2 << endl;
    cout << "--------------------------------" << endl;
    cin >> c1 >> c2;
    cout << c1 << c2 << endl;

    return 0;
}
