#include "../Array/DynamicArray/DynamicArray.h"

#include <exception>

#ifndef STACK_H
#define STACK_H

// Dynamic Array backed stack.
//
// Stacks can also be implemented using linked list.
template<typename T>
class Stack {

private:
	// Backing array.
	DynamicArray<T> array;

	void throw_exception_if_empty() const {
		if (array.is_empty())
			throw std::out_of_range("Unable to peek or pop empty stack.");
	}
public:
	
	// Get the top most element.
	T peek() const {
		// throw if the stack is empty
		throw_exception_if_empty();
		// get last element
		return array.at(array.size() - 1);
	}

	// Remove the top most element.
	void pop() {
		array.remove_back();
	}

	void push(const T& element) noexcept {
		array.append(element);
	}

	size_t size() const noexcept {
		return array.size();
	}

	bool is_empty() const noexcept {
		return array.is_empty();
	}

};



#endif