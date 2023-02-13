/**
 * - aim:
 * 1.operator reloading concepts
 * 2.operator reloading regulation
 * 3.operator reloaded as friend function
 * 4.operator reloaded as function member
 * 5.overloading of several commen operator(>>, <<, ++, =)
 * - 1. operator reloading concepts:
 * case:
 *      -one complex num class is defined, to achieve the addition of complex num
 *      one function member Add should be defined to achieve return one object of
 *      complex num which is the addition of two complex num object
 *
 * - the reason for introduction of the operator reload is to avoid the function
 *  definiton in class construction which is going against to the human's habit
 *  =============================================================================
 * - the regulation of the operator overloading
 * basic definition should be as follow:
 *  =============================================================================
 * return_type operator @(parameters){
 *      the_body_of_the_overloading_func;
 * }
 *  =============================================================================
 *  - to be noticed there are five operators which cannot be reloaded:
 * |      .      |       *      |     ::       |        ? :         |       sizeof      |
 *  member_access member_pointer field_operator conditional_operator space_calc_operator
 *  - while defining the operator several regulation should be followed:
 *  1. new operator cannot be defined
 *  2. the object num for operation cannot be change
 *  3. the priority or the associativity of the operator cannot be change
 *  4. should be corresponding with the targets, the function of the overloaded operator
 *   should be similar as the oringinal one, aimless definition of the overloaded operator
 *   should be averted
 *  =============================================================================
 * - there are two definition method of the reloading operators
 * 1. member operator function
 * 2. friend operator function
 *  =============================================================================
 * - practice:
 *      to define the complex class, with the definition of the friend function to achieve
 *      the operator + and == operator reloading
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
    Complex c4 = operator+(c1, c3);// explicitly calling
    c4.show();
    cout << "---------------------" << endl;
    Complex c5 = c1.Add(c3);
    c5.show();
    cout << "---------------------" << endl;
    cout << (c5 == c4) << endl;// implicitly calling
    cout << (c5 == c3) << endl;
    cout << operator==(c5, c3) << endl;// explicitly calling

    return 0;
}

bool operator==(const Complex &c1, const Complex &c2){
    if (c1.real == c2.real && c1.image == c2.image)
        return true;
    else
        return false;
}
