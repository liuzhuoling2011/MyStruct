#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template<class T>

class MyQueue {

public:
	/**
	* Create an array to contain items. Preallocate space enough for `count` items.
	*
	* @param[in]  count  initial capacity
	*/
	MyQueue(size_t count = 64) {
		m_elem_size = sizeof(T);
		m_data = (T*)malloc(count * m_elem_size);
		m_use_count = 0;
		m_total_count = count;
		m_first_pos = m_data;
		m_last_pos = m_data;
	}

	void operator= (const MyQueue<T> &other) {
		m_elem_size = other.m_elem_size;
		m_use_count = other.m_use_count;
		m_total_count = other.m_total_count;

		if (m_total_count < other.m_use_count) {
			free(m_data);
			m_data = (T*)malloc(other.m_total_count * m_elem_size);
		}

		m_first_pos = m_data;
		m_last_pos = m_data + m_use_count;
		memcpy(m_data, other.m_first_pos, other.m_use_count * m_elem_size);
	}

	~MyQueue() {
		if (m_data != NULL) {
			free(m_data);
			m_data = NULL;
		}
	}

	/**
	* @return  size of elements in array
	*/
	size_t size() { return m_use_count; }

	/**
	* @return  max size of the array
	*/
	size_t capacity() { return m_total_count; }

	/**
	* @return  return true when array is empty
	*/
	bool empty() { return m_first_pos == m_last_pos; }

	/**
	* @return  first item address of the array
	*/
	T& front() { return *m_first_pos; }

	/**
	* @return  last item address of the array
	*/
	T& back() { return *(m_last_pos - 1); }

	/**
	* @return  point to the next free item, recommand to use!
	*/
	T& next() {
		expand_size();

		m_use_count++;
		m_last_pos++;
		return *(m_last_pos - 1);
	}

	void push(const T item) {
		expand_size();

		*m_last_pos = item;
		m_last_pos++;
		m_use_count++;
	}

	void pop() {
		m_first_pos++;
		m_use_count--;
	}

	void clear() {
		memset(m_data, 0, m_elem_size * m_use_count);
		m_use_count = 0;
		m_last_pos = m_data;
	}

private:
	void expand_size() {
		if (m_last_pos - m_data == m_total_count) {
			if (m_first_pos - m_data > m_total_count / 2)
				reset();
			else
				resize(m_total_count << 1);
		}
	}

	void resize(size_t count) {
		T* new_data = (T*)malloc(count * m_elem_size);
		memcpy(new_data, m_first_pos, m_use_count * m_elem_size);
		free(m_data);
		m_data = new_data;
		m_first_pos = m_data;
		m_last_pos = m_data + m_use_count;
		m_total_count = count;
	}

	void reset() {
		memcpy(m_data, m_first_pos, m_use_count * m_elem_size);
		m_first_pos = m_data;
		m_last_pos = m_data + m_use_count;
	}

private:
	T*     m_data;
	T*     m_first_pos = NULL;
	T*     m_last_pos = NULL;
	size_t m_elem_size = 0;
	size_t m_use_count = 0;
	size_t m_total_count = 0;
};

#endif