#ifndef _TEST_LIST_H
#define _TEST_LIST_H

#include <list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdio>	// snprintf()
#include <cstdlib>	// abort()
#include <algorithm>

#include "pub.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::exception;
using std::find;

namespace yao03
{
	void test_list(long& totalCount)
	{
		cout << endl << "test_list()........." << endl;
		list<string> c;
		char buf[10];
		clock_t timeStart = clock();

		for(long i = 0; i < totalCount; ++i)
		{
			try{
				snprintf(buf, 10, "%d", rand()%65535);
				c.push_back(string(buf));
			}catch(std::exception& e){
				cout << "i=" << i << e.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds: " << (clock() - timeStart) << endl;
		cout << "list.size() = " << c.size() << endl;
		cout << "list.front() = " << c.front() << endl;
		cout << "list.back() = " << c.back() << endl;
		cout << "list.max_size() = " << c.max_size() <<endl;

		string target = get_a_target_string();

		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), mili-seconds: " << (clock() - timeStart) << endl;
			if(pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found! " << endl;
		}

		{
			timeStart = clock();
			c.sort();
			cout << "c.sort(), milli-seconds: " << (clock() - timeStart) << endl;
		}
	}
}
#endif
