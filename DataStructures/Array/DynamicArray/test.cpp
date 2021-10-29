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
	b.insert_at(0, 999); // start index
	print("b", b);
	b.insert_at(b.size()-1, 999); // last index
	print("b", b);

	// access index out of bound test
	exception_assert("[fail]: Insertion index checking fail", [&]() {
		b.insert_at(-999, 1000000);
	});

	exception_assert("[fail]: Insertion index checking fail", [&]() {
		b.insert_at(999, 1000000);
	});


	DynamicArray<int> prepend_a = {1, 2, 3};
	DynamicArray<int> prepend_b = {4, 5, 6};
	prepend_b.prepend(prepend_a);
	print("prepend array", prepend_b);

	prepend_b.append(prepend_a);
	print("append array", prepend_b);

	prepend_b.remove_front();
	prepend_b.remove_back();
	print("remove front + remove back", prepend_b);




	return 0;
}