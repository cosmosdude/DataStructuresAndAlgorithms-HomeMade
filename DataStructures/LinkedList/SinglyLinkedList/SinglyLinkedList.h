#include "../Node.h"

#include <cstdlib>
#include <iostream>
#include <exception>

using namespace std;

#ifndef SINGLYLINKED_H
#define SINGLYLINKED_H


template<typename T>
class SinglyLinkedList {
private:
	size_t list_size;
	// head pointer
	Node<T>* head;
	// tail pointer
	Node<T>* tail;

	void throw_if_invalid_indexing(int index) const {
		if (index < 0 or index >= size())
			throw out_of_range("Linked List index out of bound.");
	}

	void throw_if_empty() const {
		if (is_empty()) 
			throw out_of_range("Cannot peek front or back on empty linked list.");
	}

public:

	// Default Constructor
	SinglyLinkedList();

	#pragma mark Accessors
	T front() const;
	T back() const;


	void add_front(const T& element);
	void add_back(const T& element);

	void insert_at(int index, const T& element);

	void remove_at(int index);
	void remove_front();
	void remove_back();

	size_t size() const;
	bool is_empty() const;

	void print() {
		Node<T>* ptr = head;
		cout << "[";
		while(ptr) {
			cout << ptr->element;
			ptr = ptr->next;
			if (ptr) cout << ", ";
		}
		cout << "]" << endl;
	}
};


#pragma mark Constructor
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList():
list_size(0), head(nullptr), tail(nullptr)
{ }


#pragma mark Accessors
template<typename T>
T SinglyLinkedList<T>::front() const {
	// TODO: Throw if the list is empty, throw
	throw_if_empty();

	// return the head element
	return head->element;
}

template<typename T>
T SinglyLinkedList<T>::back() const {
	// TODO: Throw if the list is empty, throw
	throw_if_empty();

	// return the head element
	return tail->element;
}


template<typename T>
void SinglyLinkedList<T>::add_front(const T& element) {

	// create a pointer.
	Node<T> * ptr = new Node<T>(element);

	// if the list is empty
	if (is_empty()) {
		// both head and tail will be the ptr.
		head = ptr; tail = ptr;
	} else {
		// make the new element point to the head element
		ptr->next = head;
		// shift the head pointer to the left
		head = ptr;
	}

	list_size++;
}

template<typename T>
void SinglyLinkedList<T>::add_back(const T& element) {

	// create a pointer.
	Node<T> * ptr = new Node<T>(element);
	// if the list is empty
	if (is_empty()) {
		// both head and tail will be the ptr.
		head = ptr; tail = ptr;
	} else {
		// make last element point to the new element
		tail->next = ptr;
		// and shift the tail pointer to the right.
		tail = ptr;
	}	
	// increase list size
	list_size++;
}


template<typename T>
void SinglyLinkedList<T>::insert_at(int index, const T& element) {
	// Throw if the list is empty, throw
	throw_if_invalid_indexing(index);

	// 0 1 2 3
	// 
	Node<T>* left_ptr = nullptr;
	Node<T>* right_ptr = head;

	for(int i = 1; i <= index; i++) {
		left_ptr = right_ptr;
		right_ptr = right_ptr->next;
	}

	Node<T>* new_ptr = new Node<T>(element);

	// put new_ptr between left_ptr and right_ptr
	if (left_ptr) left_ptr->next = new_ptr;
	new_ptr->next = right_ptr;

	if (right_ptr == head) head = new_ptr;

	list_size ++;
}


template<typename T>
void SinglyLinkedList<T>::remove_at(int index) {
	// TODO: Throw if the list is empty, throw
	throw_if_invalid_indexing(index);
	// 0 1 2 3
	// 
	Node<T>* left_ptr = nullptr;
	Node<T>* remove_ptr = head;

	for(int i = 1; i <= index; i++) {
		left_ptr = remove_ptr;
		remove_ptr = remove_ptr->next;
	}

	// if the there is buffer ptr
	if (left_ptr)
		// buffer ptr's next node
		// will be the node from next node's next node
		left_ptr->next = remove_ptr->next;

	// if the left_ptr is empty,
	// it is the head deletion.
	if (left_ptr == nullptr) {
		// so, shift the head to the right
		head = head->next;
	}

	// if the removal ptr is tail
	if (remove_ptr == tail) {
		// shift the tail to the left
		tail = left_ptr;
	}

	// decrement the size
	list_size--;

	// delete the ptr;
	delete remove_ptr;
}

template<typename T>
void SinglyLinkedList<T>::remove_front() {
	remove_at(0);
}

template<typename T>
void SinglyLinkedList<T>::remove_back() {
	remove_at(size() - 1);
}



#pragma mark Query
template<typename T>
size_t SinglyLinkedList<T>::size() const {
	return list_size;
}

template<typename T>
bool SinglyLinkedList<T>::is_empty() const {
	return size() == 0;
}


#endif