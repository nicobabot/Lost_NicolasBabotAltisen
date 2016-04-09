#include"MyString.h"

const char* mystring::C_Str() const{//to print buffer in main
	return buffer;
}
mystring::mystring(){

}

mystring::mystring(const char* STR){
	int len = (strlen(STR)) + 1;
	maxcapacity = len;
	buffer = new char[len];//+1 because '\0'
	strcpy_s(buffer, len, STR);
	printf("La clase sting %s se esta construyendo\n", buffer);
}

mystring::mystring(const mystring& otherclas) : buffer(otherclas.buffer){
	int len = (strlen(otherclas.buffer)) + 1;
	maxcapacity = len;
	buffer = new char[len];//+1 because '\0'
	strcpy_s(buffer, len, otherclas.buffer);
}

unsigned int mystring::lenght(){
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
	if (maxcapacity > lent){
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

void  mystring::clear()
{
	buffer[0] = '\0';
}

mystring::~mystring(){
	delete[] buffer;
	printf("La clase string se ha constuido destruye\n");
}