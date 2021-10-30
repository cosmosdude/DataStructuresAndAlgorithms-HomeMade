#include "DynamicArray.h"

#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

class TestObject {
	// TestObject();
public:
	TestObject(int a, int b) { }
	~TestObject() {}
};

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


	prepend_b.resize(3);
	print("resize to 3:", prepend_b);
	prepend_b.append(4);
	print("append:", prepend_b);
	cout << "Capacity after append:" << prepend_b.capacity() << endl;

	prepend_b.resize();
	cout << "Capacity after resize:" << prepend_b.capacity() << endl;	
	prepend_b.resize(10);

	cout << "Capacity after resize(10):" << prepend_b.capacity() << endl;	
	cout << "Size after resize(10):" << prepend_b.size() << endl;
	print("contents after resize(10):", prepend_b);	


	DynamicArray<DynamicArray<int>> array2d;
	for(int i = 0 ; i < 10; i++) array2d.append(DynamicArray<int>());

	for(int i = 0; i < array2d.size(); i++) {
		for(int j = 0; j < 10; j++) {
			array2d[i].append(j*i);
		}
	}

	for(int i = 0; i < array2d.size(); i++) {
		for(int j = 0; j < array2d[i].size(); j++) 
			cout << array2d[i][j] << " ";
		cout << endl;
	}

	return 0;
}