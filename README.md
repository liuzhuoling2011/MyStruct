# My-Struct for C++
#### We believe these tools provide an unparalleled combination of performance and memory usage! 
#### Same usage as STL containers

-------

#### Notice:

- ##### Don't point to item in MyArray/MyHash, every reallocate may make pointers invalid.

- ##### Tell MyArray/MyHash the max size you need in constructor to avoid memory reallocated

- ##### You can reference the code in Test folder

-------

#### MyArray

- ##### High performance dynamic array to store POD structs.

- ##### The same usage with std::vector, user friendly.

| func  | explain  |
| :------------ | :------------ |
|resize(size_t count)  |Resize the array to a new capacity.|
|reserve(size_t count) |Expand the array to a new capacity. If the current capacity is greater than the new capacity, nothing is done.|
|size()     |Size of items in array.|
|capacity() |Max size of the array.|
|empty()    |Return true when array is empty.|
|[size_t index]   |Index position item address of the array.|
|at(size_t index) |Index position item address of the array.|
|front()    |First item address of the array.|
|back()     |Last item address of the array.|
|next()     |Point to the next free item, recommand to use!|
|push_back(coonst T& item)  |Copy an item to the end of this array.|
|push_back(T\* item, size_t count = 1)  |Copy an array of items to the end of this array.|
|pop_back(size_t count = 1) |Pop number of items from the end of this array.|
|insert(size_t index, T& item)  |Insert an item in specific position of the array.|
|insert(size_t index, T\* item, size_t count = 1)  |Insert an array of items in specific position of the array.|
|erase(size_t index)  |Erase items in specific position of the array.|
|erase(size_t start, size_t end)  |Erase items in specific position of the array.|
|clear()  |Clear all data.|
|reset()  |Reset counter, not clear data.|

- ###### Example.
```cpp
    MyArray<int> test(10);

    for (int i = 0; i < 10; i++) {
        test.push_back(i * i);
    }
    
    for (unsigned int i = 0; i < test.size(); i++) {
        printf("%d ", test[i]);
    }
    
    /** 
    *  next code is more efficiency, only need copy object once!
    */
    struct Person {
        char  name[20];
        int   age;
        float score;
    };

    MyArray<Person> my_test(16);

    for (int i = 0; i < 16; i++) {
        Person& prn = my_test.get_next_free_node();
        char * name = get_random_char(8);
        strlcpy(prn.name, name, 20);
        prn.age = i * i;
        prn.score = get_random_float(30, 100);
    }  
````

-------

#### MyHash

- ##### Support the (string(char\*)->value) mapping relationship

- ##### Similar usage with std::map, user friendly.
 
| func  | explain  |
| :------------ | :------------ |
|size()  |Size of items in hash.|
|empty() |Return true when array is empty.|
|exist(const char\* key)  |Return true when key is in hash.|
|[const char\* key]  |Get value from the key, if key not exit, return a new one.|
|at(const char\* key)  |Get value from the key, if key not exit, assert fail.|
|insert(const char\* key, const V& value)  |Insert key, value to hash.|
|erase(const char\* key)  |Erase key, value in hash.|
|clear()  |Clear all data.|
|get_next_free_node()  |Get next free node.|
|insert_current_node(const char\* key)  |Call it after next_free_node(), insert the key, value|

- ###### Example.
```cpp
    MyHash<int> table(30);

    for (int i = 0; i < 10; i++) {
        char* key = get_random_char(6);
        table.insert(key, i * i * i);
    }
    
    for (auto iter = table.begin(); iter != table.end(); iter++) {
        printf("%s %d\n", iter->first, iter->second);
    }
    
    /** 
    *  next code is more efficiency, only need copy object once!
    */
    struct Person {
        char  name[20];
        int   age;
        float score;
    };

    MyHash<Person> table(16);

    for (int i = 0; i < 16; i++) {
        Person& test_person = table.get_next_free_node();
        char * name = get_random_char(8);
        strlcpy(test_person.name, name, 20);
        test_person.age = i * i;
        test_person.score = get_random_float(30, 100);
        table.insert_current_node(name);
    }  
````
