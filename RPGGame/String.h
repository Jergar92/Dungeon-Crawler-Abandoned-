#ifndef _STRING_
#define _STRING_

#include <string.h>
#include <stdio.h>
#include "Vector.h"

class String{
private:
	char* buffer = nullptr;
	unsigned int max_size;
public:
	//Constructors & Destructor
	String();
	String(const char* string);
	String(const String& string);
	~String();
	//--

	//Functions
	//read string
	const char* c_str()const;

	//read lenght
	const unsigned int lenght()const;

	//read size
	const unsigned int capacity()const;

	//string is empty(?)
	bool empty()const;

	//clear string
	const void Clear();

	//write string
	void GetString();

	//string into string
	bool ContainsString(const String& string)const;
	bool ContainsString(const char* string)const;
	//--

	//operator ==
	bool operator==(const String& string)const;
	bool operator==(const char* string)const;
	//--

	//operator =
	void operator=(const String& string);
	void operator=(const char* string);
	//--

	//operator +=
	void operator +=(const String& string);
	void operator +=(const char* string);
	//--

	//operator +
	String operator +(const String& string);
	String operator +(const char* string);
	//--

	//Tokenize
	unsigned int Tokenize(const char* symbols, Vector<String> &tokens);
	//--

	//Remove character
	void RemoveChar(const char character);
	//--
};
#endif //_STRING_