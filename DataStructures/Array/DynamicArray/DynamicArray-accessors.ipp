// Mutating accessor.
// Get the element at the index
// or mutate the element at the index.
//
// Can throw array access index out of bound exception.
template<typename Element>
Element& DynamicArray<Element>::at(int index) {
	throw_if_invalid_indexing(index);
	// return address to the element.
	return this->elements[index];
}

// Mutating subscript
// Get the element at the index
// or mutate the element at the index.
//
// Can throw array access index out of bound exception.
template<typename Element>
Element& DynamicArray<Element>::operator[](int index) {
	return this->at(index);
}


// Nonmutating accessor.
// Get the element at the index.
//
// Can throw array access index out of bound exception.
template<typename Element>
Element DynamicArray<Element>::at(int index) const {
	throw_if_invalid_indexing(index);
	// return address to the element.
	return this->elements[index];
}
// Nonmutating subscript.
// Get the element at the index.
//
// Can throw array access index out of bound exception.
template<typename Element>
Element DynamicArray<Element>::operator[](int index) const {
	return this->at(index);
}