#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H


// Search given item linearly in the list.
struct LinearSearch {

	// Search given item linearly.
	// returns first found index, otherwise -1.
	template<
		template<typename, typename> typename Array,
		typename Item, typename Allocator
	>
	static int first_index_of(
		const Item& item, const Array<Item, Allocator>& array
	) {
		for(int i = 0; i < array.size(); i++)
			if (array[i] == item) return i;
		return -1;
	}

	// Search given item linearly.
	// returns last found index, otherwise -1.
	template<
		template<typename, typename> typename Array,
		typename Item, typename Allocator
	>
	static int last_index_of(
		const Item& item, const Array<Item, Allocator>& array
	) {
		for(int i = array.size()-1; i > -1; i--)
			if (array[i] == item) return i;
		return -1;
	}

};

#endif