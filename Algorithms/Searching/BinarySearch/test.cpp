#include "BinarySearch.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& array) {
	for(const auto& each: array) cout << each << " ";
	cout << endl;
}

void print_search_result_of(
	const int item, 
	const vector<int>& array, 
	SortOrder sorted_order = SortOrder::ascending
) {
	cout << "index of " << item << ": " 
	<< BinarySearch::index_of(item, array, sorted_order) << endl;

	cout << "first index of " << item << ": " 
	<< BinarySearch::first_index_of(item, array, sorted_order) << endl;

	cout << "last index of " << item << ": " 
	<< BinarySearch::last_index_of(item, array, sorted_order) << endl;
}

int main() {

	vector<int> a = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
	sort(a.begin(), a.end());
	print(a);

	for(int i = 0; i <= 4; i++) {
		// cout << "index of " << i << ": " << BinarySearch::index_of(i, a) << endl;
		print_search_result_of(i, a);
	}

	


	vector<int> b = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
	sort(b.rbegin(), b.rend());
	cout << endl;
	cout << "reverse sorted" << endl;
	print(b);

	for(int i = 0; i <= 4; i++) {
		print_search_result_of(i, b, SortOrder::descending);
	}


	return 0;
}