#include "test_array.hpp"
#include "test_vector.hpp"
#include "test_list.hpp"
#include "test_forwardlist.hpp"
#include "test_deque.hpp"
#include "test_multiset.hpp"
#include "test_multimap.hpp"

int main(int argc, char* argv[])
{
	int select;
	cout << "select: ";
	cin >> select;
	long totalCount;
	cout << "how many elements:";
	cin >> totalCount;

	srand((unsigned)time(NULL));

	switch(select)
	{
		case 1:
			yao01::test_array();
			break;
		case 2:
			yao02::test_vector(totalCount);
			break;
		case 3:
			yao03::test_list(totalCount);
			break;
		case 4:
			yao04::test_forward_list(totalCount);
			break;
		case 5:
			yao05::test_deque(totalCount);
			break;
		case 6:
			yao06::test_multiset(totalCount);
			break;
		case 7:
			yao07::test_multimap(totalCount);
			break;
		default:
			break;
	}

	getchar();

	return 0;
}

