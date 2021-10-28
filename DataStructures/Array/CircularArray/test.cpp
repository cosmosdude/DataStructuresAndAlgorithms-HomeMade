#include "CircularArray.h"

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
	CircularArray<int> a;

	for(int i = 0 ; i < 10; i++)
		a.append(i+1);

	for(int i = 0; i < 21; i++) 
		cout << a[i] << " ";
	cout << endl;




	return 0;
}