/**
 * - this is the implementation of class which is the .cpp file
 * - the reload of constructor is achieved here
 * - at the same time the declaration should be introduced inside the interface as well
 * - when the parameters type and number is not coresponded with the given construtor
 *  the system will report an error
*/
#include "point.h"
#include<iostream>
using namespace std;


int getSum (int a, int b){
    return a + b;
}

void Point::show(){
    cout << "(" << x << ", " << y << ")" << endl;
}

void Point::set(){
    cout << "please enter the value for x and y: " << endl;
    cin >> x >> y;
}

// This is the constructor
Point::Point(){
    cout << "here the constructor(with no parameters) is being called" << endl;
}

// This is the destructor
Point::~Point(){
    cout << "here the destructor is being called" << endl;
}

// This is the reload of the constructor
Point::Point(int a, int b)
{
    x = a;
    y = b;
    cout << "here the reload constructor(with two parameters) is being called" << endl;
}
