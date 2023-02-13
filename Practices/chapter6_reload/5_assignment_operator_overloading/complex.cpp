#include "complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double r, double i):real(r),image(i){

}

Complex& Complex::operator = (const Complex &c){
    this->real = c.real;
    this->image = c.image;
    cout << "using defined assignment operator functions now" << endl;
    return *this;
}

void Complex::show()
{
    if(image > 0){
        if(image == 1)
            cout << real << "+" << "i" << endl;
        else
            cout << real << "+" << image << "i" << endl;
    }
    else if(image < 0){
        if(image == -1)
            cout << real << "i" << endl;
        else
            cout << real << image << "i" << endl;
    }
    else
        cout << real << endl;
}
/*traditional method: define a function directly*/

Complex Complex::Add(const Complex &c1){

    Complex temp = c1;
    temp.real += this->real;
    temp.image += this->image;
    return temp;
}

Complex operator+(const Complex &c1, const Complex &c2){
    Complex temp(0, 0);
    temp.real = c1.real + c2.real;
    temp.image = c1.image + c2.image;
    return temp;
}


//the function is actually equal to the show function
/*
void operator<<(ostream &myout,const Complex &c){
    if(c.image > 0){
        if(c.image == 1)
            cout << c.real << "+" << "i" << endl;
        else
            cout << c.real << "+" << c.image << "i" << endl;
    }
    else if(c.image < 0){
        if(c.image == -1)
            cout << c.real << "-" << "i" << endl;
        else
            cout << c.real << c.image << "i" << endl;
    }
    else
        cout << c.real << endl;
}
*/

// to return the ostream type object to achieve continuous output.
// if the returned type is void, then there will be nothing can be output after which
// where my_out is an alias of cout!!!
ostream &operator << (ostream &my_out, const Complex &c){
    if(c.image > 0){
        if(c.image == 1)
            cout << c.real << "+" << "i" << endl;
        else
            my_out << c.real << "+" << c.image << "i" << endl; // this refers that cout == my_out
    }
    else if(c.image < 0){
        if(c.image == -1)
            cout << c.real << "-" << "i" << endl;
        else
            cout << c.real << c.image << "i" << endl;
    }
    else
        cout << c.real << endl;

    return my_out;
}

// when try to do input the const keyword should be avoided
istream &operator >> (istream &my_in, Complex &c){
    cin >> c.real >> c.image;
    return my_in;
}

//to achieve the self-increasing operator ++
Complex Complex::operator++(){
    this->real ++;
    this->image ++;

    return *this;
}

Complex Complex::operator++(int){
    Complex temp = *this;
    this->real++;
    this->image++;
    return temp;
}
