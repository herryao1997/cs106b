#include "complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double r, double i):real(r),image(i){

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

Complex Complex::operator+(const Complex &c){
    Complex temp(0, 0);
    temp.real = this->real + c.real;
    temp.image = this->image + c.image;
    return temp;
}

bool Complex::operator==(const Complex &c1){
    if(this->real == c1.real && this->image == c1.image)
        return true;
    else
        return false;
}
