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
    Complex operator+(const Complex &c);

    /*===========================================================*/
    /*============The overloading of the  == operator============*/
    bool operator==(const Complex &c1);
};

#endif // COMPLEX_H
