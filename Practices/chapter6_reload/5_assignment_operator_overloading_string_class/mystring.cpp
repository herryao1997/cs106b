#include "mystring.h"
#include <cstring>
#include <iostream>
using namespace std;

//constructor
MyString::MyString(){
    length = 0;
    pbr = new char[length + 1];
    *pbr = '\0';
}

//constructor with 1 parameter
MyString::MyString(const char *s){
    length = strlen(s);
    pbr = new char[length + 1];
    //*pbr = *s;
    strcpy(pbr, s);
}

//copy constructor
MyString::MyString(const MyString &s){
    length = s.length;
    pbr = new char[s.length+1];
    //*pbr = *s.pbr;
    cout << "here is copy constructor!" << endl;
    strcpy(pbr, s.pbr);
}

MyString &MyString::operator=(const MyString &s){
    length = s.length;
    if(this->pbr == s.pbr){
        cout << "The operator = for same MyString is being called now" << endl;
        return *this;
    }
    delete []pbr;
    pbr = new char[s.length + 1];
    //*pbr = *s.pbr;
    strcpy(pbr, s.pbr);
    cout << "The operator = is being called now" << endl;

    return *this;
}

ostream &operator <<(ostream &my_out, const MyString &s){
    my_out << s.pbr << endl;
    return my_out;
}

MyString::~MyString(){
    delete []pbr;
}

void MyString::show(){
    cout << pbr << endl;
}
