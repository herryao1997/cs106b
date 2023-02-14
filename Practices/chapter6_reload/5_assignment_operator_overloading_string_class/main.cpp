/**
 *  =============================================================================
 * - practice:
 *      to define the MyStrng class, achieving the function of the string class,including:
 *      - constructor of empty string, constructor with a initialized string
 *      - destructor to delete the space from new command
 *      - copy constructor rewriting to avoid the destructor double delete
 *      - rewriting the operator = and change the parameter and return type to reference type
 *       to avoid the calling of copy constructors too much times
 */

#include <iostream>
#include <cmath>
#include "console.h"
#include "mystring.h"

using namespace std;

int main() {
    MyString s;
    s.show();
    cout << "-------------------" << endl;
    MyString a("hello world");
    cout << a << endl;
    MyString b(a);
    cout << b << a << endl;

    s = a = a;
    cout << s << a;

    return 0;
}
