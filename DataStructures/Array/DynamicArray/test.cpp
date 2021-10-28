#include "DynamicArray.h"

#include <iostream>
using namespace std;

int main() {
	DynamicArray<int> a;

	// append test
	for(int i = 0; i < 10; i++) a.append(i);
	for(int i = 0; i < a.size(); i++) 
		cout << a[i] << " ";
	cout << endl;

	// prepend test
	for(int i = -1; i > -11; i--) a.prepend(i);
	for(int i = 0; i < a.size(); i++) 
		cout << a[i] << " ";
	cout << endl;
	return 0;
}