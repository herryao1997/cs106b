#include "couple.h"
#include <string>
#include <iostream>
using namespace std;

Boys::Boys(string nm){
    name = nm;
}

Girls::Girls(string nm){
    name = nm;
}

void Boys::IntroduceOneself(){
    cout << "my name is " << name << endl;
}

void Boys::IntroduceFriend(Girls &x){
    cout << "my girl friend's name is " << x.name << endl;
}

void Girls::IntroduceOneself(){
    cout << "my name is " << name << endl;
}
