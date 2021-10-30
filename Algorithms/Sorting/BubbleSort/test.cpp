#include "BubbleSort.h"

#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& arr) {
	for(const auto& each: arr) cout << each << " ";
	cout << endl;
}

int main() {
	vector<int> a = {5, 3, 1, 4, 2, 5, 3, 1, 4, 2, 5, 3, 1, 4, 2};

	BubbleSort::sort(a);
	print(a);

	BubbleSort::sort(a, SortOrder::descending);
	print(a);


	return 0;
}