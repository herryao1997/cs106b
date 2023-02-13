#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>

using namespace std;

class Complex
{
private:
        double real, image;
public:
    Complex(double r, double i);
    void show();
    /*===========================================================*/
    /*=============The overloading of the + operator=============*/

    Complex Add(const Complex &c1); //this is not same as human's habit
    friend Complex operator+(const Complex &c1, const Complex &c2);

    /*===========================================================*/
    /*============The overloading of the  == operator============*/
    friend bool operator==(const Complex &c1, const Complex &c2);

    /*===========================================================*/
    /*=========The overloading of the stream << operator=========*/
    /*==================without returned value===================*/

    //friend void operator<<(ostream &myout,const Complex &c);

    /*===========================================================*/
    /*=========The overloading of the ostream << operator========*/
    /*====================with returned value====================*/
    friend ostream &operator <<(ostream &my_out, const Complex &c);

    /*===========================================================*/
    /*=========The overloading of the istream << operator========*/
    /*====================with returned value====================*/
    friend istream &operator >>(istream &my_in, Complex &c);
};

#endif // COMPLEX_H
