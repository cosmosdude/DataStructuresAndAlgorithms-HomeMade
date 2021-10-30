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


// Append the contents of another dynamic array at the start of the list.
//
// let a = array
// let b = array
// # Time Complexity
// O(an+bn)
//
template<typename Element>
void DynamicArray<Element>::prepend(const DynamicArray<Element>& items) noexcept {
	// calculate new capacity
	const size_t new_capacity = size()+items.size();
	// allocate big enough buffer
	Element* new_buffer = new Element[new_capacity];

	// copy contents of another array at the start of the buffer
	memcpy(new_buffer, items.elements, sizeof(Element)*items.size());
	// and copy old items into the remaining buffer
	memcpy(new_buffer+items.size(), this->elements, sizeof(Element)*this->size());

	// delete old buffer
	delete[] this->elements;
	// retain new buffer
	this->elements = new_buffer;

	// capacity and size will be the new allocated memory size
	array_capacity = new_capacity;
	array_size = new_capacity;
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


template<typename Element>
void DynamicArray<Element>::append(const DynamicArray<Element>& items) noexcept {
	// calculate new capacity
	const size_t new_capacity = size()+items.size();
	// allocate big enough buffer
	Element* new_buffer = new Element[new_capacity];

	// and copy old items into the start of the buffer.
	memcpy(new_buffer, this->elements, sizeof(Element)*this->size());
	// copy contents from another array into the remaining buffer.
	memcpy(new_buffer+this->size(), items.elements, sizeof(Element)*items.size());

	// delete old buffer
	delete[] this->elements;
	// retain new buffer
	this->elements = new_buffer;

	// capacity and size will be the new allocated memory size
	array_capacity = new_capacity;
	array_size = new_capacity;
}



// insert the element at the given index.
//
// Insertion position should be valid.
// i.e 0 <= position <= size
//
// O(n)
template<typename Element>
void DynamicArray<Element>::insert_at(int position, const Element& item) {
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


// delete the element at the given index.
template<typename Element>
void DynamicArray<Element>::remove_at(int position) {

	// throw if the deletion index is invalid
	throw_if_invalid_indexing(position);

	// if the delete position is the last index
	// just reduce the size.
	if (position == size()-1) array_size--;
	// otherwise, delete the element at the position
	// by shift the array towards the position
	else {
		shift_left_at(position);
		array_size--;
	}
}


template<typename Element>
void DynamicArray<Element>::remove_front() {
	this->remove_at(0);
}

template<typename Element>
void DynamicArray<Element>::remove_back() {
	this->remove_at(this->size()-1);
}


template<typename Element>
void DynamicArray<Element>::resize() {
	// if the array is allocated more than it needs
	// resize it
	if (size() != capacity()) {
		// allocate just enough buffer.
		Element* new_buffer = new Element[size()];
		// copy old contents into the new buffer
		memcpy(new_buffer, this->elements, sizeof(Element)*size());
		// delete old buffer
		delete[] this->elements;
		// retain new buffer
		this->elements = new_buffer;
		// equalize capacity and size
		array_capacity = array_size;
	}
}


template<typename Element>
void DynamicArray<Element>::resize(size_t target_size) {
	if (target_size != size()) {
		// allocate large enough buffer
		Element* new_buffer = new Element[target_size];
		// copy elements from the old buffer to the new buffer.
		// if the new buffer is bigger,
		// let there be vacancies and junk values.
		memcpy(
			new_buffer, this->elements, 
			sizeof(Element)*std::min(target_size, size())
		);

		// if the target size is greater then the previous size
		if (target_size > size())
			// zero initialize the excess memory
			memset(new_buffer+size(), 0, sizeof(Element)*target_size-size());
		// delete old buffer
		delete[] this->elements;
		// retain new buffer
		this->elements = new_buffer;
		array_size = target_size;
		// equalize capacity and size
		array_capacity = target_size;
	}
}