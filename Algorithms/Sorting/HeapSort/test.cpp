#include "HeapSort.h"

#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	
	vector<int> a;

	for(int i = 0; i < 10; i++)
		a.push_back(rand() % 10000);

	HeapSort::sort(a);
	for(auto e: a) cout << e << " ";
	cout << endl;

	HeapSort::sort(a, SortOrder::descending);
	for(auto e: a) cout << e << " ";
	cout << endl;

	return 0;
}