#include <initializer_list>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <exception>

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

// Dynamic array that can be resized.
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
	void throw_if_invalid_indexing(int index) const {
		// if the index out of bound, throw exception
		if (index < 0 or index >= array_size) 
			throw std::out_of_range("[Exception]: Array access index out of bound");
	}

	size_t remaining_capacity() const noexcept {
		return capacity() - size();
	}

	// check if the current array has reach it's capacity
	bool is_capacity_reached() const noexcept {
		return 0 == remaining_capacity();
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
		// release old memory
		delete[] this->elements;
		// retain the new buffer
		this->elements = new_buffer;
	}


	// shift the remaining partition of the array
	// starting from the index.
	void shift_array_at(int position) {
		for(int i = size()-1; i >= position; i--) 
			this->elements[i+1] = this->elements[i];
	}

	void shift_array() {
		shift_array_at(0);
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

	DynamicArray(const std::initializer_list<Element>& list):
	// firstly of all, allocate and zero initialize
	DynamicArray(list.size())
	{
		std::copy(list.begin(), list.end(), this->elements);
	}

	#pragma mark Copy Constructor
	// Copy everything from the another dynamic array.
	DynamicArray(const DynamicArray<Element>& array):
	// allocate, zero initialize
	DynamicArray(array.size())
	{
		// copy everything
		for(int i = 0; i < array.size(); i++)
			this->elements[i] = array[i];
	}

	#pragma mark Copy Assignment
	// Copy Assignment
	DynamicArray& operator=(const DynamicArray<Element>& rvalue) {
		// if the current array's capacity
		// is not enough to copy everything from the rvalue
		if (capacity() < rvalue.capacity()) {
			// deallocate the elements
			delete[] this->elements;
			// change the capacity
			array_capacity = rvalue.capacity();
			// and reallocate new elements capacity
			this->elements = new Element[rvalue.capacity()];
		}

		// change the size
		array_size = rvalue.size();

		// copy everything from the rvalue
		for(int i = 0; i < rvalue.size(); i++)
			this->elements[i] = rvalue[i];

		// and return current object.
		return *this;
	}


	#pragma mark Move
	// Move constructor
	DynamicArray(DynamicArray<Element>&& array) {
		// steal properties
		this->array_capacity = array.capacity();
		this->array_size = array.size();
		this->elements = array.elements;

		// invalidate rvalue
		// so that the pointer wont get deleted when the
		// rvalue is deallocated.
		array.array_capacity = 0;
		array.array_size = 0;
		array.elements = nullptr;
	}

	#pragma mark Move Constructor
	// Move assignment
	DynamicArray<Element>& operator=(DynamicArray<Element>&& rvalue) {
		this->array_capacity = rvalue.capacity();
		this->array_size = rvalue.size();
		this->elements = rvalue.elements;

		// invalidate rvalue
		// so that the pointer wont get deleted when the
		// rvalue is deallocated.
		rvalue.array_capacity = 0;
		rvalue.array_size = 0;
		rvalue.elements = nullptr;
		return *this;
	}


	#pragma mark Destructor
	~DynamicArray() {
		// delete the elements.
		delete[] this->elements;
	}

	#pragma mark Accessers

	// Mutating accessor.
	// Get the element at the index
	// or mutate the element at the index.
	//
	// Can throw array access index out of bound exception.
	Element& at(int index) {
		throw_if_invalid_indexing(index);
		// return address to the element.
		return this->elements[index];
	}

	// Mutating subscript
	// Get the element at the index
	// or mutate the element at the index.
	//
	// Can throw array access index out of bound exception.
	Element& operator[](int index) {
		return this->at(index);
	}


	// Nonmutating accessor.
	// Get the element at the index.
	//
	// Can throw array access index out of bound exception.
	Element at(int index) const {
		throw_if_invalid_indexing(index);
		// return address to the element.
		return this->elements[index];
	}
	// Nonmutating subscript.
	// Get the element at the index.
	//
	// Can throw array access index out of bound exception.
	Element operator[](int index) const {
		return this->at(index);
	}

	// Return the current size of the array.
	size_t size() const noexcept { 
		return array_size; 
	}

	// Size of the memory allocated by the dynamic array.
	size_t capacity() const noexcept {
		return array_capacity;
	}

	// test if the array is empty
	bool is_empty() const noexcept {
		// if the size is zero, it's true
		return not size();
	}

	#pragma mark Modifiers

	// Append given element at the start of the list.
	//
	// Time Complexity
	// worse: O(n)
	// avg: O(n)
	void prepend(const Element &item) noexcept {
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
	//
	// complexity
	// worst: O(n)
	// avg: O(1)
	void append(const Element &item) noexcept {
		// if the capacity reached, increase it.
		if(is_capacity_reached()) increase_capacity();
		// append the item at the last index
		// and increase the size of the array.
		this->elements[array_size++] = item;
	}

	// insert the element at the given index.
	//
	// Insertion position should be valid.
	// i.e 0 <= position <= size
	//
	// O(n)
	void insert(const Element& item, int position) {
		// throw if the insertion index is invalid
		throw_if_invalid_indexing(position);

		// check if the array has reached it's capacity
		// if so, increase the capacity
		if (is_capacity_reached()) increase_capacity();

		// Shift the array to the right starting from the given position.
		shift_array_at(position);
		// insert the element
		this->elements[position] = item;
		// increase the size
		array_size++;
	}

};

#endif