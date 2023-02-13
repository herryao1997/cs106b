#include "string.h"
#include <cstring>
#include <iostream>

using namespace std;
using

String::String(){
    length = 0;
    sbuf = new char;
    sbuf[0] = '\0';
}

String::String(char *s){
    length = strlen(s);

}
