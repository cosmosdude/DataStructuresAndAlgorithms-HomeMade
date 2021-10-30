#include "../SortOrder.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H


// Simple sort. Insertion sort
//
// O(n^2)
struct InsertionSort {

	// Sort the given array in given order.
	template<typename T>
	static void sort(T& array, SortOrder order = SortOrder::ascending);

};


template<typename T>
void InsertionSort::sort(T& array, SortOrder order) {

	// for each element
	for(int i = 1; i < array.size(); i++) {
		int j = i;
		// Hold the element
		auto element = array[i];

		// j will always be the index where the selected element
		// will be inserted after the iteration.

		// if the sort order is ascending
		if (order == SortOrder::ascending) {
			// while insertion index is not yet zero
			// and every element is out of order
			// swap the element from the predecessor index
			// to the current index.
			while(j != 0 and array[j-1] > element) {
				array[j] = array[j-1];
				j--;
			}
		} else {
			// while insertion index is not yet zero
			// and every element is out of order
			// swap the element from the predecessor index
			// to the current index.
			while(j != 0 and array[j-1] < element) {
				array[j] = array[j-1];
				j--;
			}
		}

		array[j] = element;
		

	}

}



#endif