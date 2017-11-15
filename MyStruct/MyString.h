#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/utils.h"

class MyString
{
public:
	MyString(size_t length = 256) {
		data = (char*)calloc(length, sizeof(char));
		len = 0;
		max_size = length;
	}
	MyString(const char* str) {
		len = strlen(str);
		max_size = len * 2 + 1;
		data = (char*)calloc(max_size, sizeof(char));
		strlcpy(data, str, max_size);
	}
	MyString(MyString& str) {
		len = str.length();
		max_size = len * 2 + 1;
		data = (char*)calloc(max_size, sizeof(char));
		strlcpy(data, str.c_str(), max_size);
	}
	void operator= (const MyString &str) {
		len = str.length();
		max_size = len * 2 + 1;
		data = (char*)calloc(max_size, sizeof(char));
		strlcpy(data, str.c_str(), max_size);
	} 
	char& operator[] (size_t index) {
		return data[index];
	}
	MyString& operator+ (const char* str) {
		adjust_space(strlen(str));
		strcat(data, str);
		len += strlen(str);
		return *this;
	}
	MyString& operator+ (const MyString &str) {
		adjust_space(str.length());
		strcat(data, str.c_str());
		len += str.length();
		return *this;
	}
	void operator+= (const char* str) {
		adjust_space(strlen(str));
		strcat(data, str);
		len += strlen(str);
	}
	void operator+= (const MyString &str) {
		adjust_space(str.length());
		strcat(data, str.c_str());
		len += str.length();
	}

	size_t length() const { return strlen(data); }
	char* find(const char* str) { return strstr(data, str); }
	char* c_str() const { return data; }

private:
	void adjust_space(size_t leng) {
		if (leng + len + 1 > max_size) {
			max_size = max_size << 1;
			while (leng + len + 1 > max_size)
				max_size = max_size << 1;
			resize(max_size);
		}
	}
	void resize(size_t new_size) {
		char* tmp = (char*)calloc(new_size, sizeof(char));
		strlcpy(tmp, data, new_size);
		free(data);
		data = tmp;
	}
	
private:
	char *data;
	size_t len;
	size_t max_size;
};

#endif
