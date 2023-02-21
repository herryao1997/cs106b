#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class Student
{
private:
    long id;
    int score1, score2, score3;
public:
    Student();
    Student(long id, int sc1, int sc2, int sc3);

    void getInf();
    /*the reloading for the << >> iostream can be only by friend declaration*/
    friend ostream& operator << (ostream &my_out, const Student& s);
    bool operator > (const Student &s1);
};

template<typename T>
T getMax(T a, T b){
    if(a > b)
        return a;
    else
        return b;
    //return a > b ? a : b;
}
#endif // STUDENT_H
