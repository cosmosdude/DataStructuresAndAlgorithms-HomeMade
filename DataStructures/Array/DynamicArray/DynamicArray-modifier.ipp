// Append given element at the start of the list.
//
// Time Complexity
// worse: O(n)
// avg: O(n)
template<typename Element>
void DynamicArray<Element>::prepend(const Element &item) noexcept {
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
template<typename Element>
void DynamicArray<Element>::append(const Element &item) noexcept {
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
template<typename Element>
void DynamicArray<Element>::insert(const Element& item, int position) {
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