#include "MaxHeap.h"
#include "MinHeap.h"

#include <iostream>
#include <string>

using namespace std;

#define endlstr "\n";
#define endlch '\n'

int main() {
	MaxHeap<string> maxheap;

	maxheap.push(0, "p0");
	maxheap.push(100, "p100");
	maxheap.push(50, "p50");
	maxheap.push(150, "p150");
	maxheap.push(125, "p125");
	maxheap.push(500, "p500");
	maxheap.push(250, "p250");
	maxheap.push(25, "p25");
	maxheap.push(500, "p500");

	while(not maxheap.is_empty()) {
		cout << maxheap.peek() << " ";
		maxheap.pop();
	}
	cout << endl;


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