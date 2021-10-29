// Return the current size of the array.
template<typename Element>
size_t DynamicArray<Element>::size() const noexcept { 
	return array_size; 
}

// Size of the memory allocated by the dynamic array.
template<typename Element>
size_t DynamicArray<Element>::capacity() const noexcept {
	return array_capacity;
}

// test if the array is empty
template<typename Element>
bool DynamicArray<Element>::is_empty() const noexcept {
	// if the size is zero, it's true
	return not size();
}