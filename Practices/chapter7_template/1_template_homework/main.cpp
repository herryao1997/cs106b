/**
 * - This is the practice for template of function
 * - get the absolute value of one num based on the given main function
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;
//template <class T>
template<typename T>
T getAbs(T a){
    return abs(a);
}


int main() {
    int ia = -5;
    float fa = 3.14f;
    double da = -1.23456;
    int ic = getAbs(ia);
    cout << "getAbs(ia) = " << ic << endl;
    float fc = getAbs(fa);
    cout << "getAbs(fa) = " << fc << endl;
    double dc = getAbs(da);
    cout << "getAbs(da) = " << dc << endl;

    return 0;
}
