#ifndef PRIORITYITEM_H
#define PRIORITYITEM_H

template<typename T>
struct PriorityItem {

	int priority;
	T item;

	PriorityItem(int priority, const T& item) {
		this->priority = priority;
		this->item = item;
	}
	
};

#endif