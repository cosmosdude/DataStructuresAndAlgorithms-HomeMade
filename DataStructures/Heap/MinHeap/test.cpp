#include "MinHeap.h"

#include <iostream>
#include <string>

using namespace std;

#define endlstr "\n";
#define endlch '\n'

int main() {
	MinHeap<string> minheap;

	minheap.push(0, "p0");
	minheap.push(100, "p100");
	minheap.push(50, "p50");
	minheap.push(150, "p150");
	minheap.push(125, "p125");
	minheap.push(500, "p500");
	minheap.push(250, "p250");
	minheap.push(25, "p25");
	minheap.push(500, "p500");

	while(not minheap.is_empty()) {
		cout << minheap.peek() << " ";
		minheap.pop();
	}
	cout << endl;

	return 0;
}