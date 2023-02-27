/**
 * This program is checking the allocator
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "console.h"
#include<algorithm>
#include<vector>


using namespace std;


int main() {
    int arr[6] = {27, 210, 12, 47, 109, 83};
    vector<int, allocator<int> > vi(arr, arr+6);

    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(),40)));
    return 0;
}
