#include "StaticArray.h"

#include <iostream>
#include <array>

using namespace std;

StaticArray<int>& get() {
	StaticArray<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
	return a;
}

int main() {

	StaticArray<int> a = StaticArray<int>({1, 2, 3, 4, 5});
	StaticArray<int> c = a;
	StaticArray<int> b = std::move(c);
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



	return 0;
}