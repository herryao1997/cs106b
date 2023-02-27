/**
 * This program is checking the operation of the qsort function in c
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "console.h"
#include <fstream>


using namespace std;

typedef struct{
    char name[30];
    int Chinese;
    int Math;
    int English;
} Student;

Student students[7];

int compare(const void* a, const void* b);

int main() {
    int arr[8] = {5, 6, 4, 8, 2, 7, 3, 1};
    qsort(arr, 8, sizeof(int), compare);
    for(int i = 0; i < 8; i++){
        cout << arr[i] << endl;
    }

    return 0;
}

int compare(const void* a, const void* b){

    int* pa = (int*)a;
    int* pb = (int*)b;
    int num1 = *pa;
    int num2 = *pb;
    if(num1 - num2 > 0)
        return -1;
    else
        return 1;

    //return num1 - num2;   //from small to large
    //return num2 - num1;    //from large to small
}
