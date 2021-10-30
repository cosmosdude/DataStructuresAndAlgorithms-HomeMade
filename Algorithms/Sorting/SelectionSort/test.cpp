#include "SelectionSort.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> arr = {1, 5, 2, 10, 8};
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