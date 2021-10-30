#include "SelectionSort.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> arr = {5, 1, 3, 2, 4, 5, 1, 3, 2, 4, 5, 1, 3, 2, 4};
	SelectionSort::sort(arr, SortOrder::ascending);
	vector<int> desc_arr = SelectionSort::sorted(arr, SortOrder::descending);	

	for(auto& each: desc_arr) 
		cout << each << " ";
	cout << endl;

	for(auto& each: arr) 
		cout << each << " ";
	cout << endl;

	
	return 0;
}