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

	// shift everything to the left.
	// The shift start from the given position.
	// The shift results start from the shift_position-shift_count.
	// If the shift result index is invalid, it is silently ignored.
	void shift_left_at(int position, size_t skip_count = 1) {
		// shift items
		for(int i = position; i < size(); i++) {
			// calculate shift index
			int shift_index = i-int(skip_count);
			// if the shift index is valid.
			if (shift_index > -1) 
				// shift item
				this->elements[shift_index] = this->elements[i];
		}
	}

public:

	#pragma mark Constructors

	// DynamicArray with given size.
	// All elements are zero initialized.
	//
	explicit DynamicArray(const size_t sz = 0);

	// initialize the array of given size with default value.
	explicit DynamicArray(const size_t sz, const Element &default_value);

	// initialize the dynamic array from initializer list.
	DynamicArray(const std::initializer_list<Element>& list);

	#pragma mark Copy Constructor
	// Copy everything from the another dynamic array.
	DynamicArray(const DynamicArray<Element>& array);

	#pragma mark Move Constructor
	// Move constructor
	DynamicArray(DynamicArray<Element>&& array);


	#pragma mark Copy Assignment
	// Copy Assignment
	DynamicArray<Element>& operator=(const DynamicArray<Element>& rvalue);

	#pragma mark Move Assignment
	// Move assignment
	DynamicArray<Element>& operator=(DynamicArray<Element>&& rvalue);


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
	Element& at(int index);

	// Mutating subscript
	// Get the element at the index
	// or mutate the element at the index.
	//
	// Can throw array access index out of bound exception.
	Element& operator[](int index);

	// Nonmutating accessor.
	// Get the element at the index.
	//
	// Can throw array access index out of bound exception.
	Element at(int index) const;
	// Nonmutating subscript.
	// Get the element at the index.
	//
	// Can throw array access index out of bound exception.
	Element operator[](int index) const;

	#pragma mark Query
	// Return the current size of the array.
	size_t size() const noexcept;
	// Size of the memory allocated by the dynamic array.
	size_t capacity() const noexcept;
	// test if the array is empty
	bool is_empty() const noexcept;

	#pragma mark Modifiers
	// Append given element at the start of the list.
	//
	// Time Complexity
	// worse: O(n)
	// avg: O(n)
	void prepend(const Element &item) noexcept;

	// Append the contents of another dynamic array at the start of the list.
	void prepend(const DynamicArray<Element>& items) noexcept;

	// append given element at the end of the list.
	//
	// complexity
	// worst: O(n)
	// avg: O(1)
	void append(const Element &item) noexcept;

	// Append the contents of another dynamic array at the end of the list.
	void append(const DynamicArray<Element>& items) noexcept;

	// insert the element at the given index.
	//
	// Insertion position should be valid.
	// i.e 0 <= position <= size
	//
	// O(n)
	void insert_at(int position, const Element& item);

	// delete the element at the given index.
	void remove_at(int position);

	// delete the element at the start of the list.
	void remove_front();
	// delete the elemtn at the end of the list.
	void remove_back();

};

#include "DynamicArray-constructors.ipp"
#include "DynamicArray-accessors.ipp"
#include "DynamicArray-query.ipp"
#include "DynamicArray-modifier.ipp"
#include "DynamicArray-assignment_operator.ipp"

#endif