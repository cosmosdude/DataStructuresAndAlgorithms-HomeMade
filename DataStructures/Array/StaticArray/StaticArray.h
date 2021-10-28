#include <initializer_list>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#ifndef STATICARRAY_H
#define STATICARRAY_H

// #Static Array
// This type stores data in continuous sequence.
// Once allocated, it can't be resized.
//
// This static array can also be cast as C array.
// eg. 
// StaticArray<int> arr = {1, 2, 3}; 
// int* arr_ptr = static_cast<int*>(&arr[0]);
//
template<typename Element>
class StaticArray {
protected:
	Element* elements;
	size_t _size;

	void throw_if_invalid_indexing(int index) const {
		if (index < 0 and index >= int(size()))
			throw "Array Index Out Of Bound";
	}
public:

#pragma mark Constructors

	// Initialize a static array with size with elements initialized to zero.
	//
	// @params:
	// - size: Size of the array.
	explicit StaticArray(size_t size):
	// remember the size
	_size{size},
	// allocate require capacity
	elements{new Element[size]}
	{
		// zero initialize the entire list.
		memset(this->elements, 0, size*sizeof(Element));
	}

	// Initialize a static array with size with default elements.
	//
	// @params:
	//	- size: Size of the array
	//	- default_value: Default value for each slot of the array.
	explicit StaticArray(size_t size, Element default_value):
	// allocate and initialize zero
	StaticArray(size) 
	{
		// copy default_value to all slot of the list.
		for(int i = 0; i < size; i++) 
			this->elements[i] = default_value;
	}

	// Initialize a static array with list provided by the compiler.
	//
	StaticArray(std::initializer_list<Element> list):
	// allocate and initialize zero
	StaticArray(list.size())
	{
		// copy values of the initializer list
		std::copy(list.begin(), list.end(), this->elements);
	}

	// Copy Constructor
	// Copy everything from the another static array.
	StaticArray(const StaticArray<Element>& array):
	StaticArray(array.size())
	{
		// copy everything
		for(int i = 0; i < array.size(); i++)
			this->elements[i] = array[i];
	}

	// Copy Assignment
	virtual StaticArray& operator=(const StaticArray<Element>& rvalue) {
		// if the size are not the same.
		if (size() != rvalue.size()) {
			// dealloc old elements
			delete[] this->elements;
			// change the size
			_size = rvalue.size();
			// and reallocate new elements
			this->elements = new Element[rvalue.size()];
		}

		// copy everything
		for(int i = 0; i < rvalue.size(); i++)
			this->elements[i] = rvalue[i];

		// and return current object.
		return *this;
	}

	// Move constructor
	StaticArray(StaticArray<Element>&& array) {
		// steal properties
		this->_size = array.size();
		this->elements = array.elements;

		// invalidate rvalue
		// so that the pointer wont get deleted when the
		// rvalue is deallocated.
		array.elements = nullptr;
	}

	// Move assignment
	virtual StaticArray<Element>& operator=(StaticArray<Element>&& rvalue) {
		std::cout << "Moved =" << std::endl;
		this->_size = rvalue.size();
		this->elements = rvalue.elements;
		rvalue.elements = nullptr;
		return *this;
	}


#pragma mark Destructor

	// Destructor of the static array.
	//
	// Usually delete allocated memory.
	~StaticArray() {
		delete[] this->elements;
	}

#pragma mark Accessors

	// Get the element at the given index.
	// Sams as `at(int)`.
	//
	// @param index: Index of the item inside the array.
	//
	// Return element if and only if -1 < index < size.
	// Otherwise it throws error.
	//
	// Complexity: O(1)
	Element& operator[](int index) { 
		// if the index is invalid, throw index out of bound exception.
		this->throw_if_invalid_indexing(index);
		// Otherwise, return the element
		return this->elements[index];
	}

	// Same as `[int]` but does not allow assignment.
	const Element& operator[](int index) const {
		// if the index is invalid, throw index out of bound exception.
		this->throw_if_invalid_indexing(index);
		// Otherwise, return the element
		return this->elements[index];	
	}

	// Get the element at the given index.
	// Conceptually the same as `operator[int]`.
	// But this method does not allow mutation.
	//
	// @param index: Index of the item inside the array.
	//
	// Return element if and only if -1 < index < size.
	// Otherwise it throws error.
	//
	// Complexity: O(1)
	Element at(int index) const {
		// if the index is invalid, throw index out of bound exception.
		this->throw_if_invalid_indexing(index);
		// Otherwise, return the element
		return this->elements[index];
	}

	// Get the size of the array.
	//
	// Complexity: O(1)
	size_t size() const noexcept {
		return this->_size;
	}
};

#endif