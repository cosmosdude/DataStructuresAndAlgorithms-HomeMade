#include "../LinkedList/DoublyLinkedList/DoublyLinkedList.h"

#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
struct Queue {
private:
	DoublyLinkedList<T> list;

	void throw_if_empty() const {
		if (is_empty()) 
			throw std::out_of_range("Unable to pool or dequeue empty queue.");
	}
public:
	explicit Queue() noexcept;

	T pool() const;
	void dequeue();
	void enqueue(const T& item) noexcept;

	size_t size() const noexcept;
	bool is_empty() const noexcept;
};

template<typename T>
Queue<T>::Queue() noexcept { }

template<typename T>
T Queue<T>::pool() const {
	throw_if_empty(); 
	return list.front();
}

template<typename T>
void Queue<T>::dequeue() { 
	throw_if_empty();
	list.remove_front();
}

template<typename T>
void Queue<T>::enqueue(const T& item) noexcept { 
	list.add_back(item);
}

template<typename T>
size_t Queue<T>::size() const noexcept { 
	return list.size();
}

template<typename T>
bool Queue<T>::is_empty() const noexcept { 
	return size() == 0;
}

#endif