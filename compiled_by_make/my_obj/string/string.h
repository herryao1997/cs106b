#ifndef _MY_STRING_H
#define _MY_STRING_H

class String
{
private:
	char* m_data;
public:
	String(const char* ctr);
	String(const String& str);
	virtual ~String();
	String& operator =(const String& str);
	char* get_c_str() const { return m_data; }
};

#include <cstring>
inline
String::String(const char* ctr=0)
{
	if(ctr){
		m_data = new char[strlen(ctr) + 1];
		strcpy(m_data, ctr);
	}
	else{
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline
String::String(const String& str)
{
	//m_data = str->m_data;
	m_data = new char[ strlen(str.m_data) + 1 ];
	strcpy(m_data, str.m_data);
}

inline
String::~String()
{
	delete []m_data;
}

inline String&
String::operator =(const String& str)
{
	if(this == &str)
		return *this;
	delete []m_data;
	m_data = new char[ strlen(str.m_data) + 1 ];
	strcpy(m_data, str.m_data);
	return *this;
}

#include <iostream>
using namespace std;

inline ostream&
operator << (ostream& os, const String& str)
{
	cout << str.get_c_str() << endl;
	return os;
}

#endif
