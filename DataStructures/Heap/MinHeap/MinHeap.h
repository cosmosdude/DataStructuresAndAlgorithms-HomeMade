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

	void siftup(int i);
	
	void siftdown(int i);

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
void MinHeap<T>::siftup(int i) {
	// calculate parent
	int parent = (i-1)/2;
	// if parent is not valid, stop
	if (parent < 0) return;
	// if the current index has better priority
	// than the parent, swap them
	// and sift up again
	if (elements[i].priority < elements[parent].priority) {
		// swap them
		swap(elements[parent], elements[i]);
		// sift up again
		siftup(parent);
	}
}

template<typename T>
void MinHeap<T>::siftdown(int i) {
	//
	int best = i;
	int left = i*2+1;
	int right = i*2+2;

	// if the left index is valid
	// and it's element has better priority than current best
	// let it be the best
	if (left < size() and elements[left].priority < elements[best].priority)
		best = left;

	// if the right index is valid
	// and it's element has better priority than current best
	// let it be the best
	if (right < size() and elements[right].priority < elements[best].priority)
		best = right;

	// if there is any best child found
	// swap them
	// and siftdown again
	if (best != i) {
		swap(elements[i], elements[best]);
		siftdown(best);
	}
}


template<typename T>
void MinHeap<T>::push(int priority, const T& element) {

	// add element to the last
	elements.push_back(PriorityItem<T>(priority, element));

	// swap until the heap is right
	siftup(elements.size()-1);
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
	siftdown(0);
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