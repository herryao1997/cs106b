#ifndef COMPLEX_H
#define COMPLEX_H


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
};

#endif // COMPLEX_H
