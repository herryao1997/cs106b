#include "b_r.h"

void Ruler::setWeight(int rw){
    weight = rw;
}

void Book::setWeight(int bw){
    weight = bw;
}

int totalWeight(Ruler &r, Book &b){
    return r.weight + b.weight;
}
