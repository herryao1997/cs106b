#ifndef _TEST_DEQUE_H
#define _TEST_DEQUE_H

#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>
#include <iostream>
#include <cstdio>	// snprintf()
#include <cstdlib>	// abort()
#include <algorithm>

#include "pub.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;
using std::exception;
using std::find;
using std::sort;

namespace yao05
{
	void test_deque(long& totalCount)
	{
		cout << endl << "test_deque()........."  << endl;
		deque<string> c;
		char buf[10];
		clock_t timeStart = clock();

		for (long i = 0; i < totalCount; ++i)
		{
			try{
				snprintf(buf, 10, "%d", rand() % 65535);
				c.push_back(string(buf));
			}catch(std::exception& e){
				cout << "i = " << i << e.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds: " << (clock() - timeStart) << endl;
		cout << "deque.size() = " << c.size() << endl;
		cout << "deque.max_size() = " << c.max_size() << endl;
		cout << "deque.front() = " << c.front() << endl;
		cout << "deque.back() = " << c.back() << endl;

		string target = get_a_target_string();

		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-second: " << (clock() - timeStart) << endl;

			if(pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found!" << endl;
		}

		{
			timeStart = clock();

			::sort(c.begin(), c.end());

			cout << "::sort(), milli-seconds: " << (clock() - timeStart) << endl;
		}
	}
}
#endif
