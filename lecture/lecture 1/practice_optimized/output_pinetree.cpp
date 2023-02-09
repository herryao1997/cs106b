#include "output_pinetree.h"
#include <iostream>

using namespace std;

int getInput(){
    int num;
    cout << "please enter a int num: ";
    cin >> num;
    if (num == 0){
        num = 6;
    }
    return num;
}

void outPutPinetreeHollow(int layer_num){
    cout << "This is the hollow case pinetree:" << endl;
    if(layer_num % 2 == 0){
        for(int i = layer_num; i > 0; i--){
            for(int j = -layer_num; j <= layer_num; j++){
                int sum = abs(i) + abs(j);

                if(i==1){
                    if(sum <= layer_num && (sum) % 2 == 0){
                        cout << layer_num;
                    }
                    else{
                        cout << " ";
                    }
                }
                else if(sum == layer_num){
                    cout << layer_num - i + 1;
                }
                else{
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }
    else{
        for(int i = layer_num; i > 0; i--){
            for(int j = -layer_num; j <= layer_num; j++){
                int sum = abs(i) + abs(j);

                if(i==1){
                    if(sum <= layer_num && (sum) % 2 == 1){
                        cout << layer_num;
                    }
                    else{
                        cout << " ";
                    }
                }
                else if(sum == layer_num){
                    cout << layer_num - i + 1;
                }
                else{
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }
}

void outPutPinetree(int layer_num){
    cout << "This is the full case pinetree:" << endl;
    if(layer_num % 2 == 0){
        for(int i = layer_num; i > 0; i--){

            for(int j = -layer_num; j <= layer_num; j++){
                int sum = abs(i) + abs(j);
                if(sum <= layer_num && sum % 2 == 0){
                    cout << layer_num - i + 1;
                }
                else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    else{
        for(int i = layer_num; i > 0; i--){

            for(int j = -layer_num; j <= layer_num; j++){
                int sum = abs(i) + abs(j);
                if(sum <= layer_num && sum % 2 == 1){
                    cout << layer_num - i + 1;
                }
                else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}
