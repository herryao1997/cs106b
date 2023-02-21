/**
 * - a practice for the class template
 * ===============================================================
 * - template class Student, for better adaptivity of the class,change
 * the ID into a parameter template, since it can be achieved as string,
 * int etc.; also the grade into int float and char.
 * ===============================================================
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

//template <class T1, class T2>
//class Student;

//template<class T1, class T2>
//istream& operator >>(istream &my_in, Student<T1, T2> s);

//template<class T1, class T2>
//ostream& operator <<(ostream &my_out, const Student<T1, T2> &s);

template <class T1, class T2>
class Student{
private:
    T1 ID;
    T2 course1, course2,course3;
public:
    Student(T1 id, T2 cs1, T2 cs2, T2 cs3){
        ID = id;
        course1 = cs1;
        course2 = cs2;
        course3 = cs3;
    }

    friend istream& operator >>(istream &my_in, Student<T1, T2> s){
        cout << "===================================" << endl;
        cout << "please enter the ID and grades for course in a sequence: " << endl;
        cin >> s.ID;
        cin >> s.course1 >> s.course2 >> s.course3;
        return my_in;
    }

    friend ostream& operator <<(ostream &my_out, Student<T1, T2> s){
        cout << "student id is " << s.ID << endl;
        cout << "grades are respectively: " << s.course1 << " " << s.course2 << " " << s.course3 << endl;
        return my_out;
    }

//    friend istream& operator >>(istream &my_in, Student<T1, T2> s);
//    friend ostream& operator <<(ostream &my_out, const Student<T1, T2> &s);
};

/*===============================================================*/
/*to be noticed here, while the template combined with the friend, special notice should be paid
 *while declaring in the class and defined out of class it may result in error which is hard to find
 *two method can be used to solve this problem
 *1. put the friend function into the class
 *2. declare the template before the friend function declaration, and define the function out of the class
*/

/*
template<class T1, class T2>
istream& operator >>(istream &my_in, Student<T1, T2> s){
    cout << "===================================" << endl;
    cout << "please enter the ID and grades for course in a sequence: " << endl;
    cin >> s.ID;
    cin >> s.course1 >> s.course2 >> s.course3;
    return my_in;
}

template<class T1, class T2>
ostream& operator <<(ostream &my_out, const Student<T1, T2> &s){
    cout << "student id is " << s.ID << endl;
    cout << "grades are respectively: " << s.course1 << " " << s.course2 << " " << s.course3 << endl;
    return my_out;
}
*/
/*===============================================================*/

int main() {
    Student s1(10502256,52,62,72);
    Student s2(21,'a','a','b');
    cout << s1 << endl;
    cout << s2 << endl;
    cout << hex << 123 <<endl;
    return 0;
}
