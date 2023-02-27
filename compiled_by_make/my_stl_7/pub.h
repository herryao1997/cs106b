#ifndef _PUB_H_
#define _PUB_H_

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

#include <string>
#include <cstdio>
#include <iostream>
#include <pthread.h>
#include <assert.h>

using std::cout;
using std::cin;
using std::string;

const long ASIZE = 1000000;

long get_a_target_long()
{
	long target = 0;
	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;

	return target;
}

string get_a_target_string()
{
	long target = 0;
	char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);

	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
	long* pa = (long*) a;
	long* pb = (long*) b;
	long num1 = *pa;
	long num2 = *pb;

	return(num1 - num2);
}

int compareStrings(const void* a, const void* b)
{
	string* pa = (string*) a;
	string* pb = (string*) b;
	string num1 = *pa;
	string num2 = *pb;
	if (num1 > num2)
		return 1;
	else if (num1 < num2)
		return -1;
	else
		return 0;

}

#endif
