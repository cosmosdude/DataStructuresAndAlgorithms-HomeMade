#include "../SortOrder.h"

#include <vector>
#include <algorithm>

#ifndef HEAPSORT_H
#define HEAPSORT_H

struct HeapSort {

private:
	template<typename T>
	static void max_siftdown(std::vector<T>& array, int i, int size);

	template<typename T>
	static void min_siftdown(std::vector<T>& array, int i, int size);

	template<typename T>
	static void siftdown(std::vector<T>& array, int i, int size, SortOrder order);

	template<typename T>
	static void heapify(std::vector<T>& array, SortOrder order);

	

public:

	template<typename T>
	static void sort(std::vector<T>& array, SortOrder order);

	template<typename T>
	static void sort(std::vector<T>& array);	

};

template<typename T>
void HeapSort::max_siftdown(std::vector<T>& array, int i, int size) {
	int best = i;
	int left = i*2+1;
	int right = i*2+2;
	if (left < size and array[left] > array[best]) best = left;
	if (right < size and array[right] > array[best]) best = right;
	if (best != i) {
		std::swap(array[i], array[best]);
		max_siftdown(array, best, size);
	}
}

template<typename T>
void HeapSort::min_siftdown(std::vector<T>& array, int i, int size) {
	int best = i;
	int left = i*2+1;
	int right = i*2+2;
	if (left < size and array[left] < array[best]) best = left;
	if (right < size and array[right] < array[best]) best = right;
	if (best != i) {
		std::swap(array[i], array[best]);
		min_siftdown(array, best, size);
	}
}

template<typename T>
void HeapSort::siftdown(std::vector<T>& array, int i, int size, SortOrder order) {
	if (order == SortOrder::ascending) max_siftdown(array, i, size);
	else min_siftdown(array, i, size);
}




template<typename T>
void HeapSort::heapify(std::vector<T>& array, SortOrder order) {
	for(int i = array.size()/2-1; i >= 0; i--) {
		siftdown(array, i, array.size(), order);
	}
}


template<typename T>
void HeapSort::sort(std::vector<T>& array, SortOrder order) {
	heapify(array, order);

	for(int i = array.size()-1; i > 0; i--) {
		std::swap(array[0], array[i]);
		siftdown(array, 0, i, order);
	}
}

template<typename T>
void HeapSort::sort(std::vector<T>& array) {
	sort(array, SortOrder::ascending);
}


#endif