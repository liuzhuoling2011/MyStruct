# MyArray-MyHash for C++
#### We believe these tools provide an unparalleled combination of performance and memory usage. Only need copy object once! 

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
|push_back(T& item)  |Copy an item to the end of this array.|
|push_back(T\* item, size_t count = 1)  |Copy an array of items to the end of this array.|
|pop_back(size_t count = 1) |Pop number of items from the end of this array.|
|insert(size_t index, T& item)  |Insert an item in specific position of the array.|
|insert(size_t index, T\* item, size_t count = 1)  |Insert an array of items in specific position of the array.|
|erase(size_t index)  |Erase items in specific position of the array.|
|erase(size_t start, size_t end)  |Erase items in specific position of the array.|
|clear()  |Clear all data.|
|reset()  |Reset counter, not clear data.|

#### MyHash

- ##### Support the (string(char\*)->value) mapping relationship

- ##### Similar usage with std::vector, user friendly.
 
| func  | explain  |
| :------------ | :------------ |
|size()  |Size of items in hash.|
|empty() |Return true when array is empty.|
|exist(const char\* key)  |Return true when key is in hash.|
|[const char\* key]  |Get value from the key.|
|at(const char\* key)  |Get value from the key.|
|insert(const char\* key, V& value)  |Insert key, value to hash.|
|erase(const char\* key)  |Erase key, value in hash.|
|clear()  |Clear all data.|
|init_iterator()  |Init iterator.|
|next_used_node(char\* key, V\* value)  |Return next key, value pair in hash.|
|next_free_node()  |Get next free node.|
|insert_exist_node(const char\* key)  |Call it after next_free_node(), insert the key, value|