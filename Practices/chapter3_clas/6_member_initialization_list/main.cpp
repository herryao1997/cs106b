/**
 * - member initialization list is to initialize the member in the class in the constructor
 * - the basic declaration should be as follow:
 * ================================================================================
 * class_name::class_name(parameters_list):member1(parameter_for_initialization),member1(parameter_for_initialization){
 *      the_body_of_the_constructor_function;
 * }
 *
 * ================================================================================
 * - when the member in the private of the class is reference or const, which are all need initialization while declaration
 * need to be assigned the initial value in the way of member_initialization_list here.
 *
 * - however, the comment above shows wrong in this case the members actually can be initialized while declaration in class
 *  of the c++, so this comment should be noticed**********************************
 *
 * - the former comment actually comes from the old version of c++, however in c++11 this shortcome is solved refer to the
 *  link below:
 *              https://blog.csdn.net/weixin_43644231/article/details/88769163
 * ********************************************************************************
 *
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"

using namespace std;


class Sample{
private:
    int x;
    //int &y;
    int &y = x;
    const int z;
public:
    Sample(int x1,int z1):x(x1), y(x),z(z1){
        y = x;
        cout << "the constructor is being called now!" << endl;
    }

    void Print(){
        cout << "The given sample value is " << x << endl;
        cout << "The given sample reference is " << y << endl;
        cout << "The given sample value is " << z << endl;
    }

};

int main() {
    Sample s1(52,88);
    s1.Print();
    /*The reference type variable need to be initialized while declaration*/
    int a = 100;
    int &b = a;
    //int &b;
    //b = a;
    cout << "The value of reference is " << b;
    cout << ", which should be initialized while declaration" << endl;

    return 0;
}

