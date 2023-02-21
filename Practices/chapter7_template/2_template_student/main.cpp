/**
 * - practice for the template -- student class:
 * - a class with student ID and grades for 3 lectures, by comparison of total grades to
 * get the students class with highest scores
 */

#include <iostream>
#include <string>
#include "console.h"
#include "student.h"

using namespace std;

int main() {
    Student s1(20210105, 85, 65, 78);
    Student s2(20210106, 85, 65, 72);

    cout << s1 << s2 << endl;
    cout << "===========================" << endl;
    cout << getMax(s1, s2) << endl;


    return 0;
}
