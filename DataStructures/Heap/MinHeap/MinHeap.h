#include "../PriorityItem.h"

#include <vector>
#include <algorithm>
#include <string>
#include <exception>

#ifndef MINHEAP_H
#define MINHEAP_H

template<typename T>
struct MinHeap {

private:
	// underlying contents;
	std::vector<PriorityItem<T>> elements;

	// throw with message if the heap is empty.
	void if_empty_throw_with(const std::string message) const {
		if (is_empty()) throw std::out_of_range(message);
	}

public:

	//
	void push(int priority, const T& element);

	// peek the highest priority element. 
	T peek() const;

	// pop the highest priority element.
	void pop();

	size_t size() const noexcept;

	bool is_empty() const noexcept;
};


template<typename T>
void MinHeap<T>::push(int priority, const T& element) {

	// add element to the last
	elements.push_back(PriorityItem<T>(priority, element));

	// swap until the heap is right
	int index = elements.size()-1;
	int parent_index = (index-1)/2;
	while(
		// make sure it is not the root node
		parent_index > -1 and 
		// compare the priorities and make sure the priority is high
		elements[index].priority < elements[parent_index].priority
	) {
		swap(elements[index], elements[parent_index]);
		index = parent_index;
		parent_index = (index-1)/2;
	}

}

template<typename T>
void MinHeap<T>::pop() {
	// TODO: Throw if empty
	if_empty_throw_with("Unable to pop empty heap.");

	// put last element to the front
	elements[0] = elements[size()-1];

	// remove the last element.
	elements.pop_back();

	// if the element became empty, just simply return
	if (elements.empty()) return;

	// otherwise, maintain heap property
	int index = 0;
	int left = (index*2)+1;
	int right = (index*2)+2;

	bool left_isvalid = left < size();
	bool right_isvalid = right < size();
	bool is_leaf = not left_isvalid and not right_isvalid;

	while(not is_leaf) {

		// double node
		if (right_isvalid) {
			// if both children have better priority
			// swap with the children with best priority
			if (
				elements[left].priority < elements[index].priority and 
				elements[right].priority < elements[index].priority
			) {
				int best_child = index;
				if (elements[left].priority < elements[right].priority) best_child = left;
				else best_child = right;

				swap(elements[index], elements[best_child]);
				index = best_child;
			}
			// if the left child have better priority
			// swap with it
			else if (elements[left].priority < elements[index].priority) {
				swap(elements[index], elements[left]);
				index = left;
			}
			// if the right child have better priority
			// swap with it
			else if (elements[right].priority < elements[index].priority) {
				swap(elements[index], elements[right]);
				index = right;
			}
			// otherwise, stop the process
			else break;
		}
		// left node only
		else {
			// swap if the left element has better priority
			// than the current one
			if (elements[index].priority > elements[left].priority) {
				swap(elements[index], elements[left]);
				// then the current index become the left
				index = left;
			}
			// Otherwise, it's done.
			// just break the process
			else break;
		}

		// calculate next index;
		left = (index*2)+1; right = left+1;
		left_isvalid = left < size();
		right_isvalid = right < size();
		is_leaf = not left_isvalid and not right_isvalid;
	}
}



// peek the highest priority element. 
template<typename T>
T MinHeap<T>::peek() const {
	// TODO: Throw if empty.
	if_empty_throw_with("Unable to peek empty heap.");

	return elements[0].item;
}

template<typename T>
size_t MinHeap<T>::size() const noexcept {
	return elements.size();
}

template<typename T>
bool MinHeap<T>::is_empty() const noexcept {
	return elements.size() == 0;
}

#endif