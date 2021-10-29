template<typename Element>
DynamicArray<Element>::DynamicArray(const size_t sz):
elements {new Element[sz]}, 
array_size {sz}, 
array_capacity {sz}
{
	// zero initializer the entire array.
	memset(this->elements, 0, sz*sizeof(Element));
}


template<typename Element>
DynamicArray<Element>::DynamicArray(const size_t sz, const Element &default_value):
// firstly of all, allocate and zero initialize
DynamicArray<Element>::DynamicArray(sz)
{
	// assign the value to every elements
	for(int i = 0; i < size(); i++) 
		this->elements[i] = default_value;
}


template<typename Element>
DynamicArray<Element>::DynamicArray(const std::initializer_list<Element>& list):
// firstly of all, allocate and zero initialize
DynamicArray<Element>::DynamicArray(list.size())
{
	std::copy(list.begin(), list.end(), this->elements);
}


#pragma mark Copy
// Copy everything from the another dynamic array.
template<typename Element>
DynamicArray<Element>::DynamicArray(const DynamicArray<Element>& array):
// allocate, zero initialize
DynamicArray<Element>::DynamicArray(array.size())
{
	// copy everything
	for(int i = 0; i < array.size(); i++)
		this->elements[i] = array[i];
}


#pragma mark Move
// Move constructor
template<typename Element>
DynamicArray<Element>::DynamicArray(DynamicArray<Element>&& array) {
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