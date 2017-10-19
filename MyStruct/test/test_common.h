#pragma once

#include "MyArray.h"

const char origin_data[5][16] = {
	"abcd", "defgh", "abcde", "chen", "hello"
};

static char buffer[256];

const int max_size = 16;
struct Person {
	char  name[20];
	int   age;
	float score;
};

inline int
get_random_int(int max)
{
	return rand() % max;
}

inline int
get_random_int(int min, int max)
{
	int dis = max - min + 1;
	return rand() % dis + min;
}

inline float
get_random_float(int min, int max)
{
	int prefix = get_random_int(min, max);
	if (prefix == max) --prefix;
	int tail = get_random_int(10, 100);
	return (float)prefix + float(tail) / 100;
}

inline char*
get_random_char(int len = 10)
{
	int diff = 0;
	for (int i = 0; i < len; i++) {
		diff = get_random_int(26);
		if (diff % 5 == 0) {
			buffer[i] = 'A' + diff;
		}
		else {
			buffer[i] = 'a' + diff;
		}
	}
	buffer[len] = '\0';
	return buffer;
}

inline void print_array(MyArray<int> &my_test) {
	for (unsigned int i = 0; i < my_test.size(); i++) {
		printf("%d ", my_test[i]);
	}
	printf("\n");
}