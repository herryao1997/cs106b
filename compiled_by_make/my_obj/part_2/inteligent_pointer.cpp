#include <iostream>
using namespace std;

template <typename T>
class shared_ptr
{
private:
	T* px;
public:
	T operator *() const
	{
		return *px;
	}

	T* operator ->() const
	{
		return px;
	}

	shared_ptr(T* p) : px(p) {}
};

class Foo
{
public:
	void output()
	{
		cout << "using method here now!" << endl;
	}
};

int main()
{
	shared_ptr<Foo> sp(new Foo);
	
	Foo f(*sp);
	sp->output();

	return 0;
}
