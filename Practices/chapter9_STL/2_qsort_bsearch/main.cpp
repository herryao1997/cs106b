/**
 * This program is checking the operation of the qsort function in c
 * given a file for transcription, using the qsort to sort the grades based on different subjects.
 * #include<fstream>
 * ifstream infile;
 * infile.open();
 * for(int i = 0; i < 7; i++){
 *      infile >> variables;
 *      ...
 * }
 * infile.close();
 *
 *
 * =======================================================================================
 * bsearch need the sort function calling in advance, it can only handle the data after sort.
 * before besearch the qsort usually needed!
 *
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "console.h"
#include <fstream>
#include <string>

using namespace std;

typedef struct{
    char name[30];
    int Chinese;
    int Math;
    int English;
} Student;

Student students[7];

void readData(const char* path);
void displayData();
int compare(const void* a, const void* b);
int compare4Bsearch(const void* key, const void* e);

int main() {
    readData("mark.txt");
    displayData();
    qsort(students, 7, sizeof(Student), compare);
    cout << "=========================================" << endl << endl;
    displayData();
    cout << "=========================================" << endl << endl;
    int key = 224;
    Student* s = (Student*)bsearch(&key, students, 7, sizeof(Student), compare4Bsearch);
    // cannot be directly assigned the Student* with the void* pointer, a cast is needed
    cout << s->name << "\t";
    cout << s->Math << "\t";
    cout << s->Chinese << "\t";
    cout << s->English << "\t" << endl;
    return 0;
}

void readData(const char* path){
    ifstream infile;
    infile.open(path);
    for(int i = 0; i < 7; i++){
        infile >> students[i].name;
        infile >> students[i].Chinese;
        infile >> students[i].Math;
        infile >> students[i].English;
    }
    infile.close();
}

void displayData(){
    for(int i = 0; i < 7; i++){
        cout << students[i].name << "\t";
        cout << students[i].Chinese << "\t";
        cout << students[i].Math << "\t";
        cout << students[i].English << "\t";
        cout << students[i].English + students[i].Math + students[i].Chinese << endl;
    }
}

int compare(const void* a, const void* b){

    Student* pa = (Student*)a;
    Student* pb = (Student*)b;
    int num1 = pa->Chinese;
    int num2 = pb->Chinese;
    if(num2 - num1 > 0)
        return 1;
    else
        return -1;
}

int compare4Bsearch(const void* key, const void* e){
    int* pnum = (int*) key;
    Student* pS = (Student*) e;
    int num1 = *pnum;
    int num2 = pS->Math + pS->Chinese + pS->English;
    return num2 - num1;
}


