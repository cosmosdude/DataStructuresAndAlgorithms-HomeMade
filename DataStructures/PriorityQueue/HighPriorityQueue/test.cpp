#include "HighPriorityQueue.h"

#include <iostream>
#include <ctime>

using namespace std;

int main() {

	HighPriorityQueue<int> queue;

	srand(time(NULL));

	cout << "Inputs" "\n";
	for(int i = 0; i < 15; i++) {
		int r = rand() % 1500;
		cout << r << " ";
		queue.enqueue(r, r);
	}
	cout << endl;

	while(not queue.is_empty()) {
		cout << queue.peek() << " ";
		queue.dequeue();
	}
	cout << endl;


	return 0;
}

