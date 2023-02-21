/**
 * - template for class definition should be as followed:
 * ===============================================================
 * template_name_list eg:
 * templat<typename_list>
 * class class_template_name{
 *      body_of_class_template;
 * }
 * ===============================================================
 * - template_name_list eg:
 *      <typename T1, typename T2,......>
 * ===============================================================
 * - the member function of the class template could be placed in the class template
 *  definition, same as the defination of the normal member function, it can be defined
 *  outside of the class template as well, the member functions of the class template
 *  actually are all the function template
 * - the definition of the member function of class template should be as follow:
 * ===============================================================
 * template<typename_parameter_list>
 * return_type class_template_name<typename_list>::function_name(formal_parameters){
 *      body_of_the_member_function_of_class_template;
 * }
 * ===============================================================
 * - the usage of the class template
 * identify the class template object, the template class
 * use the class template to define the object eg:
 * class_template_name<typename_real_parameter_list> object_name
 * ===============================================================
 * practice:
 * - design a class template, with:
 *  member T data[size]
 *  member function getMax()
 *  member function sort()
 *  template
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

//template <typename T>
template <class T, int size>
class Data{
private:
    T data[size];
public:
    Data(){
        cout << "please enter " << size << " datas:" << endl;
        for(int i = 0; i < size; i++){
            cin >> data[i];
        }
    }

    void show(){
        cout << size << " datas: " << endl;
        for(int i = 0; i < size; i++){
            cout << data[i] << "\t";
        }
        cout << endl;
    }
    T getMax();


    void Sort();
};

template<typename T, int size>
T Data<T, size>::getMax(){
    T max = data[0];
    for(int i = 1; i <= size - 1; i++){
        if (data[i] > max)
            max = data[i];
    }
    cout << "the maximum of all is: " << max << endl;
    return max;
}

template<typename T, int size>
void Data<T, size>::Sort(){
    T temp;
    for(int i = 1; i <= size - 1; i++){
        temp = data[i];
        int j;
        for(j = i - 1; j >= 0; j--){
            if(temp < data[j])
                data[j+1] = data[j];
            else
                break;
        }
        data[j+1] = temp;
    }
}
//===============================================================

int main() {
    Data<int, 5> d;
    d.show();
    d.getMax();
    cout << "after ======================= sort" << endl;
    d.Sort();
    d.show();
    return 0;
}
