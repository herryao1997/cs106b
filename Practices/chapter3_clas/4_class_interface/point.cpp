#include "point.h"
#include<iostream>
using namespace std;
/* - this is the implementation of class which is the .cpp file*/

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

}

// This is the destructor
Point::~Point(){

}
