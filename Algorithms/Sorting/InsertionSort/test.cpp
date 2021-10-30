#include "InsertionSort.h"

#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& array) {
	for(const auto& a: array) cout << a << " ";
	cout << endl;
}

int main() {

	vector<int> array = {5, 1, 3, 2, 4, 5, 1, 3, 2, 4, 5, 1, 3, 2, 4};

	InsertionSort::sort(array);
	print(array);

	InsertionSort::sort(array, SortOrder::descending);
	print(array);


	return 0;
}