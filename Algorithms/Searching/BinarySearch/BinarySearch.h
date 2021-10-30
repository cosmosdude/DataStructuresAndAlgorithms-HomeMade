#include "../../Sorting/SortOrder.h"

#include <iostream>
using namespace std;

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

struct BinarySearch {

	template<
		template<typename, typename> typename Array,
		typename Item, typename Allocator
	>
	static int index_of(
		const Item& item,
		const Array<Item, Allocator>& array,
		SortOrder sorted_order = SortOrder::ascending
	) {
		int index = -1;

		int left = 0, right = array.size() - 1;
		int mid = (left+right)/2;

		while(left <= right) {
			// if the item at mid is the same as the item
			// return that index.
			if (array[mid] == item) {
				index = mid; break;
			}

			// otherwise, chop the array to next half
			// and proceed finding
			if (sorted_order == SortOrder::ascending) {
				if (item < array[mid]) right = mid - 1;
				else left = mid + 1;
			} else {
				if (item < array[mid]) left = mid + 1;
				else right = mid - 1;
			}

			mid = (left+right)/2;
		}

		return index;
	}




	template<
		template<typename, typename> typename Array,
		typename Item, typename Allocator
	>
	static int first_index_of(
		const Item& item,
		const Array<Item, Allocator>& array,
		SortOrder sorted_order = SortOrder::ascending
	) {
		int index = index_of(item, array, sorted_order);
		while(index > 0 and array[index-1] == item) index--;
		return index;
	}


	template<
		template<typename, typename> typename Array,
		typename Item, typename Allocator
	>
	static int last_index_of(
		const Item& item,
		const Array<Item, Allocator>& array,
		SortOrder sorted_order = SortOrder::ascending
	) {
		int index = index_of(item, array, sorted_order);
		while(index < array.size()-1 and array[index+1] == item) index++;
		return index;
	}

};

#endif