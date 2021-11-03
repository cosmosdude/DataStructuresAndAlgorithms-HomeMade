#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
	T element;
	Node<T> *next;

	Node(const T& e):
	element(e), next(nullptr) {}
};

#endif