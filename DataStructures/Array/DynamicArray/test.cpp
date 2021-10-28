#include "DynamicArray.h"

#include <iostream>
using namespace std;

void print(const DynamicArray<int>& array) {
	for(int i = 0; i < array.size(); i++) 
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	DynamicArray<int> a(2, 100);
	// copy test
	DynamicArray<int> c = a;
	// append test
	for(int i = 0; i < 10; i++) a.append(i);
	print(a);

	// prepend test
	for(int i = -1; i > -11; i--) a.prepend(i);
	print(a);
	print(c);

	// Move constructor test;
	DynamicArray<int> d = std::move(c);

	print(c);
	print(a);

	// initializer list test
	DynamicArray<int> b = {1, 2, 3, 4, 5};
	print(b);

	b.insert(999, 0);
	print(b);

	b.insert(999, b.size()-1);
	print(b);


	return 0;
}