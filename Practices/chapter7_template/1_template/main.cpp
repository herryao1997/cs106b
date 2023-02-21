/**
 * - This chapter especially explaining the method of template
 * - template is a tool to achieve the program reusage, different type of data can
 *  be defined as the parameters, as a result, truly reusage of the program
 * - template of function -> function template
 * - template of class -> class template >> objects
 * - typical definition of function template should be as follow:
 * ======================================================================================
 *       template <class type_parameter>
 *       return_type function_name(template_parameter){
 *                  function_body;
 *       }
 * - where the template is a keyword to declare the template
 * - class is different from the commen class in c++, which means the definition of a
 * template. to be noticed here, the class keyword can be changed into typename
 * ======================================================================================
 * - the usage of the function template:
 * - while interpreter identifing a calling for the function:
 * function_name(template_real_parameters_list);
 * the interpreter will generate a function, template function, whose function body same
 *  as the fuction template
 *
 * - calc for maximum out of two numbers(int, double, char, string), using the function
 *  template.
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

//template <typename T>
template <class T>
T getMax(T a, T b){
    T temp = a > b ? a : b;
    cout << "maximum is " << temp << endl;
    cout << "=======================" << endl;
    return temp;
}


int main() {
    getMax(5, 6);       //getMax(int, int);
    getMax('a', 'd');       //getMax(char, char);
    getMax(7.8, 9.9);       //getMax(double, double);
    getMax("7hjkhjkh", "hjkhjkhjkhjk");     //getMax(string, string);

    return 0;
}
