/**
 * - to achieve self-increasing operator reloading ++
 * - in c++, to achieve the ++ operator in front and rear:
 *  for the rear operator one int need to be added in the parameter to give a
 *  default value int0 to achieve the rear operator the basic definition should be
 *  as follow:
 * ==============================================================================
 * - for the in front:
 * return_type operator++();
 * eg:
 * Complex operator++(){
 *      this->real++;
 *      this->image++;
 *      return *this;
 * }
 * ==============================================================================
 * - for the in rear:
 * return_type operator++(int);
 * eg:
 * Complex operator++(int){
 *      Complex temp = *this;
 *      this->real++;
 *      this->image++;
 *      return temp;
 * }
 * ==============================================================================
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "complex.h"

using namespace std;

int main() {
    Complex c1(17, -3);
    cout << "--------------------------------" << endl;
    cout << c1 << endl;
    cout << "--------------------------------" << endl;
    Complex c4 = ++c1;   //implicitly calling in-front
    cout << c4 << endl;
    cout << c1 << endl;
    cout << "--------------------------------" << endl;
    c4 = c1++;   //explicitly calling in-rear
    cout << c4 << endl;
    cout << c1 << endl;
    return 0;
}
