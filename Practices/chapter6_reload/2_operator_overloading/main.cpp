/**
 * - aim:
 * - when reloading the binary operator, only one parameter needing to be set, which
 *  is the right one, while the left object is the operated object itself
 * - if the single operator is reloaded, there is no need to set other parameter, the
 *  operated object is the object itself.
 *  =================================================================================
 * - practice:
 *      to define a class of Complex, using the member function instead of the friend
 *      function to achieve the operator reloading == and +
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "complex.h"

using namespace std;

int main() {
    Complex c1(1,1),c2(2, -4);
    c1.show();
    c2.show();
    cout << "---------------------" << endl;
    Complex c3 = c1 + c2;// implicitly calling
    c3.show();
    Complex c4 = c3.operator+(c1);// explicitly calling
    c4.show();
    cout << "---------------------" << endl;
    Complex c5 = c1.Add(c3);
    c5.show();
    Complex *pc;
    pc = &c5;
    cout << "---------------------" << endl;
    cout << (c5 == c3) << endl;
    cout << (*pc == c5) << endl;
    return 0;
}


