#include "StaticArray.h"


#pragma mark Accessors
template<typename Element>
Element StaticArray<Element>::at(unsigned int index) {
	// if the index is valid, return value at the index.
	if (index > -1 and index < this->size()) return this->elements[index];
	// otherwise, throw exception
	else throw "Array Index Out Of Bound";
}


template<typename Element>
size_t StaticArray<Element>::size() {
	// Get the size
	return this->_size;
}