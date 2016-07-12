#include "String.h"

//Constructors & Destructor
String::String()
{
	buffer = new char[40];
	max_size = 40;
}
String::String(const char* string)
{
	int len = strlen(string);
	buffer = new char[len + 1];
	max_size = len + 1;
	strcpy_s(buffer, max_size, string);
}
String::String(const String& string)
{
	max_size = string.max_size;
	buffer = new char[max_size];
	strcpy_s(buffer, string.max_size, string.buffer);
}
String::~String()
{
	delete[]buffer;
}
//--

//Functions
//read string
const char* String::c_str()const
{
	return buffer;
}
//read lenght
const unsigned int String::lenght()const
{
	return strlen(buffer);
}
//read size
const unsigned int String::capacity()const
{
	return max_size;
}
//string is empty(?)
bool String::empty()const
{
	return strlen(buffer) == 0;
}
//clear string
const void String::Clear()
{
	buffer[0] = '\0';
}
//write string
void String::GetString()
{
	gets_s(buffer, max_size);
}

//string into string
bool String::ContainsString(const String& string)const
{
	return strstr(string.buffer, buffer) != nullptr;
}

bool String::ContainsString(const char* string)const
{
	return strstr(buffer, string) != nullptr;
}
//--

//operator ==
bool String::operator==(const String& string)const
{
	return (strcmp(buffer, string.buffer) == 0);
}
bool String::operator==(const char* string)const
{
	return (strcmp(buffer, string) == 0);
}
//--

//operator =
void String::operator=(const String& string)
{
	unsigned int len = strlen(string.buffer) + 1;
	if (max_size >= len){
		strcpy_s(buffer, len, string.buffer);
	}
	else{
		delete[]buffer;
		buffer = new char[len];
		strcpy_s(buffer, len, string.buffer);
	}
}
void String::operator=(const char* string)
{
	unsigned int len = strlen(string) + 1;
	if (max_size >= len){
		strcpy_s(buffer, len, string);
	}
	else{
		delete[]buffer;
		buffer = new char[len];
		strcpy_s(buffer, len, string);
	}
}
//--

//operator +=
void String::operator +=(const String& string)
{
	if (max_size < lenght() + string.lenght() + 1)
	{
		char* temp = nullptr;
		temp = new char[lenght() + 1];
		strcpy_s(temp, lenght() + 1, buffer);
		delete[]buffer;
		int len = strlen(temp) + 1 + strlen(string.buffer) + 1;
		buffer = new char[len];
		strcpy_s(buffer, len, temp);
		strcat_s(buffer, len, string.buffer);
	}
	else{ strcat_s(buffer, string.lenght() + 1, string.buffer); }
}

void String::operator +=(const char* string)
{
	if (max_size < lenght() + strlen(string) + 1)
	{
		char* temp = nullptr;
		temp = new char[lenght() + 1];
		strcpy_s(temp, lenght() + 1, buffer);
		delete[]buffer;
		int len = strlen(temp) + 1 + strlen(string) + 1;
		buffer = new char[len];
		strcpy_s(buffer, len, temp);
		strcat_s(buffer, len, string);
	}
	else{ strcat_s(buffer, max_size, string); }
}
//--

//operator +
String String::operator +(const String& string)
{
	String new_str;
	unsigned int len = lenght() + string.lenght() + 1;
	new_str.max_size = len;
	new_str.buffer = new char[len];
	strcpy_s(new_str.buffer, len, buffer);
	strcat_s(new_str.buffer, len, string.buffer);
	return new_str;
}
String String::operator +(const char* string)
{
	String new_str;
	unsigned int len = lenght() + strlen(string) + 1;
	new_str.max_size = len;
	new_str.buffer = new char[len];
	strcpy_s(new_str.buffer, len, buffer);
	strcat_s(new_str.buffer, len, buffer);
	return new_str;
}
//--

//Tokenize
unsigned int String::Tokenize(const char* symbols, Vector<String> &tokens)		//, char* string
{
	unsigned int num_words = 0;
	char* context = nullptr;
	char* save = nullptr;
	String item;
	save = strtok_s(buffer, symbols, &context);
	int len = 0;
	while (save != NULL)
	{
		num_words++;
		if (save[0] == '"')
		{
			do{
				if (save[0] == '"')	{ item = save; }
				else		{ item += save; }
				save = strtok_s(NULL, symbols, &context);
				if (save != NULL)
				{
					len = strlen(save);
					if (save[len - 1] == '\"')
					{
						item += " ";
					}
				}
			} while (save != NULL && save[len - 1] == '\"');
			tokens.PushBack(item);
		}
		else
		{
			tokens.PushBack(save);
			save = strtok_s(NULL, symbols, &context);
		}
	}
	return num_words;
}
//--

//Remove character
void String::RemoveChar(const char character)
{
	int num_removed = 0;
	int len = strlen(buffer) + 1;
	for (int i = 0; i < len; i++)
	{
		if (buffer[i] == character)
		{
			int j = i;
			while (buffer[j + 1] != NULL)
			{
				buffer[j] = buffer[j + 1];
				j++;
			}
			num_removed++;
		}
	}
	buffer[len - num_removed] = '\0';
}
//--