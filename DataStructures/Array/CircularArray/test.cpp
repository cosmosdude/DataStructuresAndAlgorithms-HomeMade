#include "CircularArray.h"

#include <iostream>
#include <string>
#include <functional>

using namespace std;

int main() {

	// normal circular array
	//
	// it inherits from DynamicArray
	CircularArray<int> a;

	// 
	for(int i = 0 ; i < 10; i++)
		a.append(i+1);

	// circular indexing test
	for(int i = 0; i < 21; i++) 
		cout << a[i] << " ";
	cout << endl;

	// constness test
	const CircularArray<int> b = a;
	// negative circular indexing test
	for(int i = -1; i >= -21; i--)
		cout << a[i] << " ";
	cout << endl;		

	return 0;
}