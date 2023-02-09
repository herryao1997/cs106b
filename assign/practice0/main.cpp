/**
 * This program creates a simple "hash" of
 * a person's name. A hash is an integer that is
 * mathematically derived from another object.
 * In this case, a string (the first and last name)
 * is accessed character by character and the hash
 * is built up from a number generated by each character.
 * While this function does not necessarily produce
 * unique hashes (different names can hash to the
 * same value), there is a relatively low possibility
 * of a "collision" with a class of roughly 400 students.
 *
 * We will learn more about hashing later this quarter!
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

int getInput();
void outPutPinetree(int layer);

int main() {
    int layer_num = getInput();
    outPutPinetree(layer_num);
    return 0;
}

int getInput(){
    int num;
    cout << "please enter a int num: ";
    cin >> num;
    if (num == 0){
        num = 6;
    }
    return num;
}

void outPutPinetree(int layer_num){

    for(int i=1; i<=layer_num; i++){
        int num_of_space = layer_num - i;
        string output = string(num_of_space, ' ');
        for(int j=i; j>0; j--){
            output += "* ";
        }
        cout << output << endl;
    }
}
