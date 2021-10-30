#include "../SortOrder.h"

#include <algorithm>

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

// Simple sort, Bubble sort
//
// O(n^2)
struct BubbleSort {

	template<typename T>
	static void sort(T& array, SortOrder order = SortOrder::ascending);

};

template<typename T>
void BubbleSort::sort(T& array, SortOrder order) {

	for(int i = 0; i < array.size() - 1; i++) {
		for(int j = 0; j < array.size() - 1; j++) {
			if (order == SortOrder::ascending) {
				if (array[j] > array[j+1]) 
					std::swap(array[j], array[j+1]);
			}
			else {
				if (array[j] < array[j+1]) 
					std::swap(array[j], array[j+1]);
			} 
		}
	}

}

#endif