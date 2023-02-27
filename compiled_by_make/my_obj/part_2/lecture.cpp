// author: Herryao
// date: 2023/02/23
// compiler: g++ 11
// course: c++ oop2

using namespace std;

//----------------------------------------------------------------

#include <iostream>
#include <string>
#include <memory>//shared_ptr

namespace yao01
{
class Base1{};
class Derived1: public Base1{};
class Base2{};
class Derived2: public Base2{};

template <typename T1, typename T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair():first(T1()), second(T2()){}
	pair(const T1& a, const T2& b):first(a), second(b){}
	
	template <typename U1, typename U2>
	pair(const pair<U1, U2>& p): first(p.first), second(p.second){}
};

void test_member_template()
{
	cout << "test_member_template()" << endl;
	pair<Derived1, Derived2> p;
	pair<Base1, Base2> p2(pair<Derived1, Derived2>());
	pair<Base1, Base2> p3(p);
	//Derived1 will be assigned to Base1; same case for Derived2
	//such assignment is allowed since there is "is-a" relationship between them
	//pair<Derived1, Derived2> p4(p3); is not allowed since Based1 is not a object of Derived 1 same for Derived 2
	Base1* ptr = new Derived1; // up-cast
	shared_ptr<Base1> sptr(new Derived1);	//simulate up-cast 
}
}	//namespace
//--------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <list>

namespace yao02
{
template <typename T,
	 template <typename U>
		 class Container
		 >

class XCLS
{
private:
	Container<T> c;
public:
	XCLS()
	{
		for(long i=0; i < 100; ++i)
			c.insert(c.end(), T());
	}
};

template<typename T>
using lst = list<T, allocator<T>>;//This is a new behavior in c++ 2.0

void test_template_template_parameters_1()
{
	cout << "test_template_template/-members_1()" << endl;
	// XCLS<string, list> mylist1; // this is not allowed here, since in the list there are other parameters with default values need to be clarified
	XCLS<string, lst> mylist; // make sure the environment should support c++2.0
}
}  //namespace
 //--------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <memory>	//smart pointer

namespace yao03
{
template <typename T,
	 template <typename U>
		 class SmartPtr
		 >

class XCLS
{
private:
	SmartPtr<T> sp;
public:
	XCLS(): sp(new T) {}
};

void test_template_template_parameters_2()
{
	cout << "test_template_template_parameters_2()" << endl;

	XCLS<string, shared_ptr> p1;	//Note: make sure the environment support c++2.0

	XCLS<double, auto_ptr> p4;
	// XCLS<double, unique_ptr> p2;		//unique_ptr has two template parameters
	// XCLS<int, weak_ptr> p3;	//[Error] no matching function for call to 'std::weak_ptr<int>::weak_ptr(int*)'
}
}  //namespace
 //--------------------------------------------------------------------------------------------------------------

#include <iostream>
namespace yao04
{
void test_object_model()
{
	cout << "test_object_model()" << endl;
}
}  //namespace
 //--------------------------------------------------------------------------------------------------------------
 
#include <iostream>
namespace yao05
{
class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	//Fraction(int num, int den): m_numerator(num), m_denominator(den)  //non-explicit-one-argument ctor
	explicit Fraction(int num, int den=1): m_numerator(num), m_denominator(den)
	{
		cout << m_numerator << ' ' << m_denominator << endl;
	}

	operator double() const
	{
		return (double)m_numerator / m_denominator;
	}

	Fraction operator +(const Fraction& f)
	{
		cout << "operator+(): " << f.m_numerator << ' ' << f.m_denominator << endl;
		//...plus
		
		return f;
	}
};

void test_conversion_functions()
{
	cout << "test_conversion_functions()" << endl;

	Fraction f(3, 5);

	double d = 4+ f;
	cout << d << endl;

	// Fraction e = 4 + f;	//ambiguous
}
}  //namespace
 //-------------------------------------------------------------------------------------------------------------
 
#include <iostream>
namespace yao06
{
void test_reference()
{
	cout << "test_reference()" << endl;
	
	{
		int x = 0;
		int* p = &x;
		int& r = x;	//r is a reference to x. now r==x==0
		int x2 = 5;	
		r = x2;		//r cannot re-reference to another. now r==x==5
		int& r2 = r;	//now r2==5(r2 is a reference to r, i.e. a reference to x)

	}

	{
		typedef struct Stag{ int a, b, c, d; } S;
		double x = 0;
		double* p = &x;	//p is a pointer to x. p's value is same as x's address
		double& r = x;	//r is a reference to x, now r==x==0

		cout << sizeof(x) << endl;	//8
		cout << sizeof(p) << endl;	//4
		cout << sizeof(r) << endl;	//8
		cout << p << endl;	//address
		cout << *p << endl;	//0
		cout << x << endl;	//0
		cout << r << endl;	//0
		cout << &x << endl;	//same address
		cout << &r << endl;	//same address

		S s;
		S& rs = s;
		cout << sizeof(s) << endl;	//16	
		cout << sizeof(rs) << endl;	//16
		cout << &s << endl;	//address
		cout << &rs << endl;	//same address
	}
}
}  //namespace
 //--------------------------------------------------------------------------------------------------------------

int main(int argc, char** argv)
{
	std::cout << __cplusplus << endl;	//199711or201103
	
	yao01::test_member_template();
	yao02::test_template_template_parameters_1();
	yao03::test_template_template_parameters_2();
	yao04::test_object_model();
	yao05::test_conversion_functions();
	yao06::test_reference();
}
