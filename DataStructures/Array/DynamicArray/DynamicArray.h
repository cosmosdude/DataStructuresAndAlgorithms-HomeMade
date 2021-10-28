#include <initializer_list>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <exception>

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<typename Element>
class DynamicArray {

private:
	// Underlying array
	Element* elements;
	// Assigned element size
	size_t array_size;
	// Allocated memory size
	size_t array_capacity;

	#pragma mark Validator
	// check and throw if the index is invalid i.e out of valid range
	void throw_if_invalid_indexing(int index) {
		// if the index out of bound, throw exception
		if (index < 0 or index >= array_size) 
			throw std::out_of_range("Array index out of bound");
	}

	// check if the current array has reach it's capacity
	bool is_capacity_reached() {
		return size() == capacity();
	}

	// increase capacity by 2.
	void increase_capacity() {
		// increase capacity
		if (array_capacity == 0) array_capacity = 2;
		else array_capacity *= 2;

		// allocate new buffer with new capacity
		Element* new_buffer = new Element[capacity()];

		// copy old elements into the new buffer
		memcpy(
			new_buffer, 
			this->elements, 
			sizeof(Element)*size()
		);	 
		// retain the new buffer
		this->elements = new_buffer;
	}

	void shift_array() {
		memcpy(
			this->elements+1, 
			this->elements, 
			sizeof(Element)*size()
		);	 
	}

public:

	#pragma mark Constructors

	// DynamicArray with given size.
	// All elements are zero initialized.
	//
	explicit DynamicArray(const size_t sz = 0):
	elements {new Element[sz]}, 
	array_size {sz}, 
	array_capacity {sz}
	{
		// zero initializer the entire array.
		memset(this->elements, 0, sz*sizeof(Element));
	}

	// initialize the array of given size with default value.
	explicit DynamicArray(const size_t sz, const Element &default_value):
	// firstly of all, allocate and zero initialize
	DynamicArray(sz)
	{
		// assign the value to every elements
		for(int i = 0; i < size(); i++) 
			this->elements[i] = default_value;
	}

	#pragma mark Destructor
	~DynamicArray() {
		// delete the elements.
		delete[] this->elements;
	}

	#pragma mark Accessers
	// Mutating subscript
	Element& operator[](int index) {
		throw_if_invalid_indexing(index);
		return this->elements[index];
	}

	// Nonmutating
	Element operator[](int index) const {
		throw_if_invalid_indexing(index);
		return this->elements[index];
	}

	// Return the current size of the array.
	const size_t size() const { 
		return array_size; 
	}

	// Size of the memory allocated by the dynamic array.
	const size_t capacity() const {
		return array_capacity;
	}

	#pragma mark Modifiers
	void prepend(const Element &item) {
		// if the capacity reached, increase it.
		if (is_capacity_reached()) increase_capacity();
		// shift the array by 1.
		shift_array();
		// add the element at the start of the list.
		this->elements[0] = item;
		// increase the size
		array_size++;
	}

	// append given element at the end of the list.
	void append(const Element &item) {
		// if the capacity reached, increase it.
		if(is_capacity_reached()) increase_capacity();
		this->elements[array_size++] = item;
	}
	

};

#endif