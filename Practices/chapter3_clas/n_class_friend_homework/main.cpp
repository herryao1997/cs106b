/**
 * This is the homework of class_friend the quiz is:
 * - declare two classes >> ruler and book
 * - both of them have the weight properties
 * -define a friend function totalWeight, to calculate the weight sum of both
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "b_r.h"

using namespace std;




int main() {
    Book b1;
    Ruler r1;
    b1.setWeight(10);
    r1.setWeight(5);
    cout << "The weight for current classes should be " << totalWeight(r1, b1) << endl;

    return 0;
}
