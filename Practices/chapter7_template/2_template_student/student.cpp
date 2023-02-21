#include "student.h"
#include<iostream>

using namespace std;

Student::Student()
{
}

Student::Student(long id, int sc1, int sc2, int sc3):id(id), score1(sc1), score2(sc2), score3(sc3)
{

}

ostream& operator <<(ostream& my_out, const Student &s){
    my_out << "student id is " << s.id << endl;
    my_out << "grades for three lectures are " << s.score1 << " " << s.score2;
    my_out << " " << s.score3 << endl;
    return my_out;
}


void Student::getInf(){
    cout << id << endl;
}

bool Student::operator>(const Student &s1){
    if ((this->score1 + score2 + score3) > (s1.score1 + s1.score2 + s1.score3))
        return true;
    else
        return false;
}
