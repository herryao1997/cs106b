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
#include "vector.h"
#include "set.h"
#include "simpio.h"

using namespace std;

int main() {
//    Vector<string> list;
    Set<string> list;
    int word_frequency = 0;
    while(true){
        string word = getLine("Enter your word");
        if(word == "")
            break;
        list.add(word);
        word_frequency += 1;
    }
    cout << word_frequency << " included " << list << endl;


    return 0;
}
