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

Complex operator+(const Complex &c1, const Complex &c2){
    Complex temp(0, 0);
    temp.real = c1.real + c2.real;
    temp.image = c1.image + c2.image;
    return temp;
}
