/**
 * - assignment operator is a binary operator
 * - without explicitly difinition of the assignment operator, it will be defined
 *  in default by the interpretor
 * - the assignment function must be a member function, which is not allowed to be
 *  reloaded as a friend function
 * - the assignment function cannot be inherited by the derived classes
 * ==============================================================================
 * - the assignment operator reloaded function can be only called in a explicit way
 *  or it will not be called, while the default one will be called instead.
 * ==============================================================================
 * - while declaration the = default keywords should be added to avert the warning
 *  the basic format should be as follow:
 *  ==============================================================================
 *  class_type& operator = (const Complex &c) = default;
 *  eg:
 *      Complex& operator = (const Complex &c) = default;
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "complex.h"

using namespace std;

int main() {
    Complex c1(17, -3);
    cout << c1 << endl;
    cout << "--------------------------------" << endl;
    /*the assignment function is automatically defined by the interpretor*/
    Complex c2(0, 0);
    //c2.operator=(c1);
    c2 = c1;
    cout << c2 << endl;
    return 0;
}


