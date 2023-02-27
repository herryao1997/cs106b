#ifndef _TEST_MULTIMAP_H
#define _TEST_MULTIMAP_H

#include <map>
#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#include "pub.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::multimap;
using std::find;
using std::sort;
using std::pair;

namespace yao07
{
	void test_multimap(long& totalCount)
	{
		cout << endl << "test_multimap()........." << endl;

		multimap<long, string> c;
		char buf[10];
		clock_t timeStart = clock();

		for (long i = 0; i < totalCount; ++i)
		{
			try{
				snprintf(buf, 10, "%d", rand() % 65535);
				c.insert(pair<long, string>(i, string(buf)));
			}catch(std::exception& e){
				cout << "i = " << i << e.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds: " << (clock() - timeStart) << endl;
		cout << "multimap.size() = " << c.size() << endl;
		cout << "multimap.max_size() = " << c.max_size() << endl;

		long target = get_a_target_long();

		{
			timeStart = clock();
			auto pItem = c.find( target);
			cout << "c.find(), milli-seconds: " << (clock() - timeStart) << endl;

			if(pItem != c.end())
				cout << "found, " << pItem->second  << endl;
			else
				cout << "not found!" << endl;
		}
	}
}
#endif
