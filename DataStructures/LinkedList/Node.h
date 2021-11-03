#ifndef NODE_H
#define NODE_H

template<typename T>
struct ForwardNode {
	T element;
	ForwardNode<T> *next;

	ForwardNode(const T& e):
	element(e), next(nullptr) {}
};

#endif