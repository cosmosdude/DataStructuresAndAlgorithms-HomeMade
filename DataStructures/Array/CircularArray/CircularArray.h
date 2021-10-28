#include "../DynamicArray/DynamicArray.h"

#include <initializer_list>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <exception>

#ifndef CIRCULARARRAY_H
#define CIRCULARARRAY_H

// Circular array, also known as infinite index array.
//
// Implemented using dynamic array.
template<typename Element>
class CircularArray: public DynamicArray<Element> {
	using DynamicArray<Element>::DynamicArray;
private:
	// check and throw if the array is empty.
	void throw_if_empty() {
		if (this->is_empty()) 
			throw std::out_of_range("Unable to index empty circular array.");
	}
public:

	// Get the item by index
	// 
	// If the array is empty, exception is thrown.
	// Otherwise, element from mod index is returned.
	// Negative index results in elements from the rear.
	Element operator[](int index) const {
		// throw if the array is empty
		throw_if_empty();
		// round up index
		index = index % int(this->size());
		// if the index is negative
		// round again
		if (index < 0) index += int(this->size());
		// return item
		return this->at(index);
	}

	// Get the item by index
	// 
	// If the array is empty, exception is thrown.
	// Otherwise, element from mod index is returned.
	// Negative index results in elements from the rear.
	Element& operator[](int index) {
		// throw if the array is empty
		throw_if_empty();
		// round up index
		index = index % int(this->size());
		// if the index is negative
		// round again
		if (index < 0) index += int(this->size());
		// return item
		return this->at(index);
	}
};


#endif