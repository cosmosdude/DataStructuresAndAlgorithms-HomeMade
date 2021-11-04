#include "../Node.h"

#include <cstdlib>
#include <iostream>
#include <exception>

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using namespace std;

template<typename T>
struct DoublyLinkedList {

private:
	size_t list_size;
	// head pointer
	BidirectionalNode<T>* head;
	// tail pointer
	BidirectionalNode<T>* tail;

	void throw_if_invalid_indexing(int index) const {
		if (index < 0 or index >= size())
			throw out_of_range("Linked List index out of bound.");
	}

	void throw_if_empty() const {
		if (is_empty()) 
			throw out_of_range("Cannot peek front or back on empty linked list.");
	}


public:
	DoublyLinkedList();

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
		BidirectionalNode<T>* ptr = head;
		cout << "[";
		while(ptr) {
			cout << ptr->element;
			ptr = ptr->next;
			if (ptr) cout << ", ";
		}
		cout << "]" << endl;
	}

	void printrev() {
		BidirectionalNode<T>* ptr = tail;
		cout << "reverse: [";
		while(ptr) {
			cout << ptr->element;
			ptr = ptr->previous;
			if (ptr) cout << ", ";
		}
		cout << "]" << endl;
	}
};


#pragma mark Constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList():
list_size(0), head(nullptr), tail(nullptr)
{ }


#pragma mark Accessors
template<typename T>
T DoublyLinkedList<T>::front() const {
	// TODO: Throw if the list is empty, throw
	throw_if_empty();

	// return the head element
	return head->element;
}

template<typename T>
T DoublyLinkedList<T>::back() const {
	// TODO: Throw if the list is empty, throw
	throw_if_empty();

	// return the head element
	return tail->element;
}


template<typename T>
void DoublyLinkedList<T>::add_front(const T& element) {

	// create a pointer.
	BidirectionalNode<T> * ptr = new BidirectionalNode<T>(element);

	// if the list is empty
	if (is_empty()) {
		// both head and tail will be the ptr.
		head = ptr; tail = ptr;
	} else {
		// make the new element point to the head element
		ptr->next = head;
		head->previous = ptr;
		// shift the head pointer to the left
		head = ptr;
	}

	list_size++;
}

template<typename T>
void DoublyLinkedList<T>::add_back(const T& element) {

	// create a pointer.
	BidirectionalNode<T> * ptr = new BidirectionalNode<T>(element);
	// if the list is empty
	if (is_empty()) {
		// both head and tail will be the ptr.
		head = ptr; tail = ptr;
	} else {
		// make last element point to the new element
		tail->next = ptr;
		ptr->previous = tail;
		// and shift the tail pointer to the right.
		tail = ptr;
	}	
	// increase list size
	list_size++;
}


template<typename T>
void DoublyLinkedList<T>::insert_at(int index, const T& element) {
	// Throw if the list is empty, throw
	throw_if_invalid_indexing(index);

	BidirectionalNode<T>* node = nullptr;

	// determine if the index is nearer to the left or right
	if (index < size()/2) {
		// if the index is nearer to the head
		// start from the left
		node = head;
		for(int i = 0; i != index; i++)
			node = node->next;
	} else {
		// if the index is nearer to the tail
		// start from the right
		node = tail;
		for(int i = size()-1; i != index; i--)
			node = node->previous;
	}

	// new node
	BidirectionalNode<T>* new_ptr = new BidirectionalNode<T>(element);

	// 100 200 400
	// inset 300 at 2

	// new_ptr = 300

	// node = 400
	// node ->previous = 200
	// node ->next = nullptr

	// 200->next = 300
	if (node->previous) 
		node->previous->next = new_ptr;
	// 300->previous = 200
	new_ptr->previous = node->previous;

	// 300->next = 400
	new_ptr->next = node;
	// 400->previous = 300
	node->previous = new_ptr;

	// head can point to the second element
	// shift if so
	if (node == head) head = new_ptr;	
	// tail will always point to tail

	list_size++;
}


template<typename T>
void DoublyLinkedList<T>::remove_at(int index) {
	// TODO: Throw if the list is empty, throw
	throw_if_invalid_indexing(index);

	BidirectionalNode<T>* node = nullptr;

	// determine if the index is nearer to the left or right
	if (index < size()/2) {
		// if the index is nearer to the head
		// start from the left
		node = head;
		for(int i = 0; i != index; i++)
			node = node->next;
	} else {
		// if the index is nearer to the tail
		// start from the right
		node = tail;
		for(int i = size()-1; i != index; i--)
			node = node->previous;
	}

	// 100 200 300 400
	// delete at 2

	// n = 300
	// n->pr = 200
	// n->nx = 400

	if (node == head) head = head->next;
	if (node == tail) tail = tail->previous;

	if (node->previous)
		node->previous->next = node->next;

	if (node->next) 
		node->next->previous = node->previous;
	
	// delete the node
	delete node;

	// decrement the size
	list_size--;
}

template<typename T>
void DoublyLinkedList<T>::remove_front() {
	remove_at(0);
}

template<typename T>
void DoublyLinkedList<T>::remove_back() {
	remove_at(size() - 1);
}



#pragma mark Query
template<typename T>
size_t DoublyLinkedList<T>::size() const {
	return list_size;
}

template<typename T>
bool DoublyLinkedList<T>::is_empty() const {
	return size() == 0;
}

#endif