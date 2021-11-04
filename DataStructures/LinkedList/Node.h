#ifndef NODE_H
#define NODE_H

template<typename T>
struct ForwardNode {
	T element;
	ForwardNode<T> *next;

	ForwardNode(const T& e):
	element(e), next(nullptr) {}
};

template<typename T>
struct BidirectionalNode {
	T element;
	BidirectionalNode<T> *previous;
	BidirectionalNode<T> *next;

	BidirectionalNode(const T& e):
	element(e), next(nullptr), previous(nullptr)
	{}
};

#endif