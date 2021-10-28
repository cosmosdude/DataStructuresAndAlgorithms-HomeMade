#include "DynamicArray.h"

#include <iostream>
#include <string>
#include <functional>

using namespace std;

void assertion_failure(const string &what) {
	cout << "[Assertion]-FAIL: " << what << endl;
	exit(0);
}

void exception_assert(const string& what, function<void()> closure) {

	try {
		closure();	
		assertion_failure("Insertion index checking fail");
	} catch(const exception& e) {
		cout << "[Assertion]: Success" << endl;
		cout << e.what() << endl;
	}
}



void print(const string& name, const DynamicArray<int>& array) {
	cout << name << ": ";
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
	print("a", a);

	// prepend test
	for(int i = -1; i > -11; i--) a.prepend(i);
	print("a", a);
	print("c", c);

	// access index out of bound test
	exception_assert("[fail]: Insertion index checking fail", [&]() {
		a[9999] = 1; 
	});

	// Move constructor test;
	DynamicArray<int> d = std::move(c);

	// c should be empty
	print("c", c);
	print("a", a);

	// initializer list test
	DynamicArray<int> b = {1, 2, 3, 4, 5};
	print("b", b);

	// insertion test
	b.insert(999, 0); // start index
	print("b", b);
	b.insert(999, b.size()-1); // last index
	print("b", b);

	// access index out of bound test
	exception_assert("[fail]: Insertion index checking fail", [&]() {
		b.insert(1000000, -999);
	});

	exception_assert("[fail]: Insertion index checking fail", [&]() {
		b.insert(1000000, 999);
	});




	return 0;
}