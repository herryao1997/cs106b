#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>

using namespace std;

class complex
{
public:
	complex(double r = 0, double i = 0): re(r), im(i){ }

	complex& operator += (const complex& r);
	complex& operator -= (const complex& r);
	complex& operator *= (const complex& r);
	complex& operator /= (const complex& r);

	double real() const{return re;}
	double imag() const{return im;}

private:
	double re, im;
	
	friend ostream& operator << (ostream& os, const complex& x);
	friend complex& __doapl(complex* ths, const complex& r);
	friend complex& __doami(complex* ths, const complex& r);
	friend complex& __doaml(complex* ths, const complex& r);
};

inline complex&
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;

	return *ths;
}

inline complex& 
complex::operator += (const complex& r)
{
	return __doapl(this, r);
}

inline complex&
__doami(complex* ths, const complex& r)
{
	ths->re -= r.re;
	ths->im -= r.im;

	return *ths;
}

inline complex&
complex::operator -=(const complex& r)
{
	return __doami(this, r);
}

inline complex&
__doaml(complex* ths, const complex& r)
{
	double f = ths->re * r.re - ths->im * r.im;
	ths->im = ths->re * r.im + ths->im * r.re;
	ths->re = f;

	return *ths;
}



inline complex&
complex::operator *=(const complex& r)
{
	return __doaml(this, r);
}

inline double
imag(const complex& x)
{
	return x.imag();
}

inline double
real(const complex& x)
{
	return x.real();
}

inline complex
operator +(const complex& x, const complex& y)
{
	return complex(real(x) + real(y), imag(x) +imag(y));
}

inline complex
operator +(const complex& x, const double& y)
{
	return complex(real(x) + y, imag(x));
}

inline complex
operator +(const double& x, const complex& y)
{
	return complex(x + real(y), imag(y));
}

inline complex
operator -(const complex& x, const complex& y)
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator -(const complex& x, const double& y)
{
	return complex(real(x) - y, imag(x));
}

inline complex
operator -(const double& x, const complex& y)
{
	return complex(x - real(y), imag(y));
}

inline complex
operator *(const complex& x, const complex& y)
{
	return complex(real(x) * real(y) - imag(x) * imag(y), real(x) * imag(y) + imag(x) * real(y));
}

inline complex
operator *(const complex& x, const double& y)
{
	return complex(real(x) * y, imag(x) * y);
}

inline complex
operator *(const double& x, const complex& y)
{
	return complex(x * real(y), x * imag(y));
}

inline complex
operator / (const complex& x, const double& y)
{
	return complex(real(x) / y, imag(x) / y);
}

inline complex
operator + (const complex& x)
{
	return x;
}

inline complex
operator - (const complex& x)
{
	return complex(-real(x), imag(x));
}

inline bool
operator ==(const complex& x, const complex& y)
{
	return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator !=(const complex& x, const complex& y)
{
	return !operator ==(x, y);
}

inline bool
operator ==(const double& x, const complex& y)
{
	return x == real(y) && imag(y) == 0;
}

inline bool
operator !=(const double& x, const complex& y)
{
	return !operator ==(x, y);
}

inline bool
operator ==(const complex& x, const double& y)
{
	return real(x) == y && imag(x) == 0;
}

inline bool
operator !=(const complex& x, const double& y)
{
	return !operator ==(x, y);
}

#include <cmath>

inline complex
polar(double r, double t)
{
	return complex(r * cos(t), r * sin(t));
}

inline complex
conj(const complex& x)
{
	return complex(real(x), -imag(x));
}

inline double
norm(const complex& x)
{
	return real(x) * real(x) + imag(x) * imag(x);
}

ostream&
operator <<(ostream& os, const complex& x){
	cout << '('  << real(x) << ", " << imag(x) << ')' << endl;
	return os;
}

#endif
