#include "LinearSearch.h"

#include <vector>
#include <iostream>

using namespace std;

int main() {

	vector<int> a = { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

	cout << LinearSearch::first_index_of(3, a) << endl;
	cout << LinearSearch::last_index_of(3, a) << endl;

	return 0;
}