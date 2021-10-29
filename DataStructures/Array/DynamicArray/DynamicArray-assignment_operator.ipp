#pragma mark Copy Assignment
// Copy Assignment
template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(
	const DynamicArray<Element>& rvalue
) {
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
// Move assignment
template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(
	DynamicArray<Element>&& rvalue
) {
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