#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "../SortOrder.h"

// Selection sorting algorithm.
//
// How selection sort works?
//
// For each iteration, the algorithm selects the biggest or lowest
// element from the remaining list and swap with the starting index
// of the remaining array.
//
struct SelectionSort {
public:
	
	// sort the given array in given order.
	template<typename T>
	static void sort(T& array, SortOrder order = SortOrder::ascending) noexcept;

	// Return a sorted copy of given array in given order.
	template<typename T>
	static T sorted(const T& array, SortOrder order = SortOrder::ascending) noexcept;
};

#pragma mark Implementation
template<typename T>
void SelectionSort::sort(T& array, SortOrder order) noexcept {

	// from 0 to n-1
	// select lowest or biggest in i+1 - n
	// and swap with current index
	for(int i = 0; i < array.size()-1; i++) {
		int swap_index = i;
		for(int j = i+1; j < array.size(); j++) {
			// for ascending
			if (order == SortOrder::ascending) {
				// find the lowest value's index
				if(array[j] < array[swap_index]) swap_index = j;
			} else {
				if (array[j] > array[swap_index]) swap_index = j;
			}
		}
		std::swap(array[i], array[swap_index]);
	}
}

template<typename T>
T SelectionSort::sorted(const T& array, SortOrder order) noexcept {
	T copied = array;
	sort(copied, order);
	return copied;
}

#endif