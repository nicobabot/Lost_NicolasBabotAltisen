#include"MyString.h"

const char* mystring::C_Str() const{//to print buffer in main
	return buffer;
}
mystring::mystring(){
	maxcapacity = 1;
	buffer = new char[maxcapacity];
}

mystring::mystring(const char* STR){
	int len = (strlen(STR)) + 1;
	maxcapacity = len;
	buffer = new char[len];//+1 because '\0'
	strcpy_s(buffer, len, STR);
}

mystring::mystring(const mystring& otherclas){
	int len = (strlen(otherclas.buffer)) + 1;
	maxcapacity = len;
	buffer = new char[len];//+1 because '\0'
	strcpy_s(buffer, len, otherclas.buffer);
}

unsigned int mystring::lenght()const{
	unsigned int i = strlen(buffer);
	return i;
}

bool mystring::empty() const{
	return strlen(buffer) == 0;
}

bool mystring::operator ==(const mystring& otherclas) const{
	return strcmp(buffer, otherclas.buffer) == 0;
}

bool mystring::operator ==(const char* otherstring) const{
	return strcmp(buffer, otherstring) == 0;
}

bool mystring::operator !=(const char* otherstring) const{
	return strcmp(buffer, otherstring) != 0;
}

void mystring::operator =(const mystring& otherclas){
	int lent = (strlen(otherclas.buffer) + 1);
	if (maxcapacity < lent){
		delete[]buffer;
		maxcapacity = lent;
		buffer = new char[maxcapacity];
	}
	strcpy_s(buffer, maxcapacity, otherclas.buffer);
}

void mystring::operator =(const char* otherstring){
	int lent = (strlen(otherstring) + 1);
	if (maxcapacity < lent){
		delete[]buffer;
		maxcapacity = lent;
		buffer = new char[maxcapacity];
	}
	strcpy_s(buffer, maxcapacity, otherstring);
}


void mystring::operator +=(const mystring& otherclas){
	int lent = (strlen(otherclas.buffer) + lenght() + 1);
	if (maxcapacity < lent){
		char *temp = nullptr;
		temp = new char[strlen(buffer) + 1];
		strcpy_s(temp, strlen(buffer) + 1, buffer);
		delete[]buffer;
		lent = strlen(temp) + strlen(otherclas.buffer) + 1;
		maxcapacity = lent;
		buffer = new char[lent];
		strcpy_s(buffer, lent, temp);
		strcat_s(buffer, lent, otherclas.buffer);
		//printf("hola");
	}
	else{
		strcat_s(buffer, strlen(buffer), otherclas.buffer);
	}


}

mystring  mystring::operator+(const mystring &otherclas)
{
	mystring newstring;
	int len = strlen(buffer) + strlen(otherclas.buffer) + 1;
	maxcapacity = len;
	newstring.buffer = new char[len];
	strcpy_s(newstring.buffer, len, buffer);
	strcat_s(newstring.buffer, len, otherclas.buffer);
	return newstring;
}

void  mystring::clear()const
{
	buffer[0] = '\0';
}

uint mystring::capacity()const{
	return maxcapacity;
}

void mystring::set()
{
	char otherstring[50];
	gets_s(otherstring,50);
	int lent = strlen(otherstring)+1;
	if (maxcapacity < lent){
		delete[]buffer;
		maxcapacity = lent;
		buffer = new char[maxcapacity];
	}
	strcpy_s(buffer, maxcapacity, otherstring);
}

Vector<mystring> mystring::Tokenize(const char *parameters, char* option)const{
	
	uint len = strlen(option) + 1;
	Vector<mystring> stringvector;
	char *finalstring, *other, *repeat;
	finalstring = new char[len];
	strcpy_s(finalstring, len, option);

	other=strtok_s(finalstring, parameters, &repeat);
	while (other != NULL){
		stringvector.pushback(other);
		other = strtok_s(NULL, parameters, &repeat);
	}
	delete[] finalstring;
	return stringvector;
}

mystring::~mystring(){
	delete[] buffer;
}