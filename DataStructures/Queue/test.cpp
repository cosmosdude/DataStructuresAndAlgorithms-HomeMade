#include "Queue.h"

#include <iostream>

using namespace std;


int main() {
	Queue<int> q;
	
	for(int i = 0; i < 10; i++) q.enqueue(i);	

	while(q.is_empty() == false) {
		cout << q.pool();
		q.dequeue();
		cout << (q.is_empty() ? '\n' : ' ');
	}
}