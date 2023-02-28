#include "vector.h"
#include "testing/SimpleTest.h"
#include "random.h"

int maxOf(Vector<int> elems){
    //edge case
    if(elems.size() == 1)
        return elems[0];
    int first = elems[0];
    int max_of_rest = maxOf(elems.subList(1));

    return first > max_of_rest ? first : max_of_rest;
}

int maxOfDivide(Vector<int> elems){
    if(elems.size() == 1)
        return elems[0];
    int mid = elems.size() / 2;
    Vector<int> first = elems.subList(0, mid);
    Vector<int> last = elems.subList(mid);

    int max1 = maxOfDivide(first);
    int max2 = maxOfDivide(last);

    return max1 > max2 ? max1 : max2;
}

int maxOfDividePro(Vector<int>& elems, int start, int end){
    if(elems.size() == 1)
        return elems[start];
    int mid = (end - start) / 2;

    int max1 = maxOfDividePro(elems, start, mid);
    int max2 = maxOfDividePro(elems, mid, end);

    return max1 > max2 ? max1 : max2;
}

STUDENT_TEST("normal test"){
    Vector<int> list = {1, 3, 9, 8, 5};
    EXPECT_EQUAL(maxOfDivide(list), maxOf(list));
    EXPECT(maxOf(list) == 9);
}

STUDENT_TEST("stress test"){
    Vector<int> elems = {3, 2, 7, 9};
    for(int i = 0; i < 1000; i++){
        elems.add(randomInteger(0, 100));
    }
    for(int i = 0; i < 5; i++){
        elems = elems + elems;
        TIME_OPERATION(elems.size(), maxOf(elems));
    }
    for(int i = 0; i < 10; i++){
        elems = elems + elems;
        TIME_OPERATION(elems.size(), maxOfDivide(elems));
    }

    for(int i = 0; i < 10; i++){
        elems = elems + elems;
        TIME_OPERATION(elems.size(), maxOfDividePro(elems, 0, elems.size()));
    }
}
