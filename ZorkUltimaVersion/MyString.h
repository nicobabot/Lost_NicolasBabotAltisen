#ifndef _STRING_
#define _STRING_
#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
class mystring{
private:
	char *buffer = nullptr;
	unsigned int maxcapacity;
public:
	const char* C_Str() const;
	mystring();
	mystring(const char* STR);
	mystring(const mystring& otherclas);
	unsigned int lenght();
	bool empty() const;
	bool operator ==(const mystring& otherclas) const;
	bool operator ==(const char* otherstring) const;
	bool operator !=(const char* otherstring) const;
	void operator =(const mystring& otherclas);
	void operator =(const char* otherstring);
	void operator +=(const mystring& otherclas);
	mystring operator+(const mystring &otherclas);
	void clear();
	~mystring();
};
#endif