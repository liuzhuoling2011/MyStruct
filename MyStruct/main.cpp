#include <stdlib.h>
#include "MyArray.h"
#include "MyHash.h"
#include "MyString.h"
#include "MyQueue.h"
#include "test/test_common.h"

void CHECK(bool flag);
void test_MyArray_base_type();
void test_MyArray_struct_type();
void test_MyHash_base_type();
void test_MyHash_base_type2();
void test_MyHash_struct_type();
void test_MyString();
void test_MyQueue();

int main()
{
	//test_MyArray_base_type();
	//test_MyArray_struct_type();
	test_MyHash_base_type();
	//test_MyHash_base_type2();
	//test_MyHash_struct_type();
	//test_MyString();
	//test_MyQueue();
	return 0;
}

#define CHECK(flag) if((flag) == false) printf("line %d has error, please check!\n", __LINE__)

void test_MyQueue() {
	MyQueue<int> queue;
	for (int i=0; i<2048; i++) {
		queue.push(i);
	}
	for (int i = 0; i<1024; i++) {
		queue.pop();
	}
	for (int i = 0; i<1024; i++) {
		queue.push(i);
	}
	int j = queue.front();
	j = queue.back();
}

void test_MyString() {
	MyString a("jojoaini~");
	MyString b(a);
	MyString c = b;
	a += "1";
	b += "2";
	c += "3";
	c += a + b;
	c[5] = '*';
	printf("%s\n%d\n", c.c_str(), (int)(&c[5] - &c[0]));
	printf("%s\n", c.find("aini"));
}

void test_MyArray_base_type() {
	MyArray<int> my_test(10);
	CHECK(my_test.empty());

	my_test.reserve(5);
	CHECK(my_test.capacity() == 10);
	my_test.reserve(max_size);
	CHECK(my_test.capacity() == max_size);

	for (int i = 0; i < 10; i++) {
		int num = i * i;
		my_test.push_back(num);
	}

	print_array(my_test);

	//check push & get single element
	int count = my_test.size();
	CHECK(count == 10);

	//test push array & dynamic expansion
	int l_array[50];
	for (int i = 0; i < 50; i++) {
		l_array[i] = i;
	}

	my_test.push_back(l_array, 50);

	print_array(my_test);

	count = my_test.size();
	CHECK(count == 60);
	int temp = my_test[5];
	CHECK(temp == 25);
	temp = my_test[9];
	CHECK(temp == 81);
	temp = my_test[10];
	CHECK(temp == 0);
	temp = my_test[15];
	CHECK(temp == 5);
	temp = my_test[30];
	CHECK(temp == 20);

	int result = my_test.front();
	CHECK(result == 0);
	result = my_test.back();
	CHECK(result == 49);
	CHECK(my_test[30] == 20);
	CHECK(my_test[54] == 44);

	my_test.resize(80);
	CHECK(my_test.capacity() == 80);

	print_array(my_test);
	my_test.resize(40);
	CHECK(my_test.capacity() == 40);

	print_array(my_test);
	result = my_test.back();
	CHECK(result == 29);

	my_test.pop_back(5);
	result = my_test.back();
	CHECK(result == 24);

	MyArray<int> test(10);
	test = my_test;

	printf("---------------- test operator = -----------------\n");
	print_array(my_test);
	print_array(test);

	printf("---------------- test insert -----------------\n");
	int number = 99;
	int test_array[8] = { 88, 88,8,8, 8, 88, 8, 888 };
	my_test.insert(1, number);
	print_array(my_test);
	my_test.insert(1, test_array, 8);
	print_array(my_test);

	printf("---------------- test erase -----------------\n");
	my_test.erase(9);
	print_array(my_test);
	my_test.erase(1, 8);
	print_array(my_test);

	//test clear & delete
	my_test.clear();
	CHECK(my_test.empty());
	count = my_test.size();
	CHECK(count == 0);
	temp = my_test[30];
	CHECK(temp == 0);
}

void test_MyArray_struct_type() {
	MyArray<Person> my_test(max_size);

	for (int i = 0; i < max_size; i++) {
		Person& prn = my_test.next();
		char * name = get_random_char(8);
		memcpy(prn.name, name, 10);
		prn.age = i * i;
		prn.score = get_random_float(30, 100);
	}
	//test Copy constructor
	MyArray<Person> new_test(max_size);
	new_test = my_test;
	int count = new_test.size();
	CHECK(count == max_size);

	Person& node = new_test[10];
	CHECK(node.age == 100);
	//attention!! this will change value of new_test[10] 
	node = new_test[12];
	CHECK(node.age == 144);

	//test clear & delete
	new_test.clear();
}

void test_MyHash_base_type() {
	MyHash<int> table(30);

	for (int i = 0; i < 10; i++) {
		char* key = get_random_char(6);
		int value = i * i * i;
		table.insert(key, value);
	}
	CHECK(table.size() == 10);
	table.clear();
	CHECK(table.size() == 0);
	CHECK(table.empty());

	for (int i = 0; i<5; i++) {
		char* key = "key";	 //repeat check
		table.insert(key, i);
	}
	CHECK(table.size() == 1);

	for (auto iter = table.begin(); iter != table.end(); iter++) {
		printf("%s %d\n", iter.first, *iter.second);
	}

	table.clear();

	table["lzl"] = 5299;
	for (int i = 0; i < 5; i++) {
		int value = i * i;
		table.insert(origin_data[i], value);
	}

	CHECK(table.size() == 6);

	for (int i = 0; i < 5; i++) {
		CHECK(table[origin_data[i]] == i*i);
	}

	table.erase("abcde");
	CHECK(table.exist("abcde") == false);
	for (auto iter = table.begin(); iter != table.end(); iter++) {
		printf("%s %d\n", iter.first, *iter.second);
	}
	int i = 0;
}

void test_MyHash_base_type2() {
	MyHash<double> table(1);
	CHECK(table.empty());

	// test expand_size
	for (size_t i = 0; i < 4096; i++) {
		char * l_str = get_random_char();
		double a = i;
		table.insert(l_str, a);
	}

	// access all data in MyHash
	for (auto iter = table.begin(); iter != table.end(); iter++) {
		printf("%s %f\n", iter.first, *iter.second);
	}

	table.clear();
	CHECK(table.size() == 0);
}

void test_MyHash_struct_type() {
	MyHash<Person> table(max_size);
	CHECK(table.empty());

	for (int i = 0; i < max_size; i++) {
		Person& test_person = table.next_free_node();
		char * name = get_random_char(8);
		strlcpy(test_person.name, name, 10);
		test_person.age = i * i;
		test_person.score = get_random_float(30, 100);
		table.insert_current_node(name);
	}

	for (auto iter = table.begin(); iter != table.end(); iter++) {
		printf("%s %d %f\n", iter.first, iter.second->age, iter.second->score);
	}

	table.clear();
	CHECK(table.size() == 0);
}