#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class MyString
{
private:
    char * pbr;
    int length;
public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &s);

    virtual ~MyString();

    void show();
    MyString &operator = (const MyString &s);
    friend ostream &operator<<(ostream &myout, const MyString &s);
};

#endif // MYSTRING_H
