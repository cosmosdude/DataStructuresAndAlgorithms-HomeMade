#include "StaticArray.h"

#include <iostream>
#include <array>

using namespace std;

int main() {

	StaticArray<int> a = {1, 2, 3, 4, 5};
	StaticArray<int> c = a;
	StaticArray<int> b = std::move(c);

	StaticArray<int> d(5, 100);
	// size
	cout << "Size: " << a.size() << endl;

	// accessing through at();
	for(int i = 0; i < a.size(); i++) 
		cout << a.at(i) << " ";
	cout << endl;

	// change through []
	a[0] = 10;

	// accessing through subscript;
	for(int i = 0; i < a.size(); i++) 
		cout << a[i] << " ";
	cout << endl;

	// testing b;
	for(int i = 0; i < b.size(); i++) 
		cout << b[i] << " ";
	cout << endl;

	int* cint_array = static_cast<int*>(&a[0]);
	for(int i = 0; i < a.size(); i++) 
		cout << cint_array[i] << " ";
	cout << endl;


	return 0;
}