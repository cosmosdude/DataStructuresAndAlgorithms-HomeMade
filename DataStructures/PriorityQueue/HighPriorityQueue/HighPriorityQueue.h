#include "../../Heap/MaxHeap/MaxHeap.h"

#include <string>
#include <exception>

#ifndef LOWPRIORITYQUEUE_H
#define LOWPRIORITYQUEUE_H

template<typename T>
struct HighPriorityQueue {

private:
	MaxHeap<T> heap;

	void throw_if_empty(const std::string& what) const {
		if (is_empty()) throw std::out_of_range(what);
	}

public:

	void enqueue(int priority, const T& element) noexcept;
	
	void dequeue();

	T peek() const;

	size_t size() const noexcept;

	bool is_empty() const noexcept;

};

template<typename T>
void HighPriorityQueue<T>::enqueue(int priority, const T& element) noexcept {
	heap.push(priority, element);
}

template<typename T>
void HighPriorityQueue<T>::dequeue() {
	throw_if_empty("Unable to dequeue empty priority queue.");
	heap.pop();
}

template<typename T>
T HighPriorityQueue<T>::peek() const {
	throw_if_empty("Unable to peek empty priority queue.");
	return heap.peek();
}

template<typename T>
size_t HighPriorityQueue<T>::size() const noexcept {
	return heap.size();
}

template<typename T>
bool HighPriorityQueue<T>::is_empty() const noexcept {
	return heap.is_empty();
}

#endif