#include "Stack.h"

#include <iostream>

using namespace std;

int main() {
	Stack<int> stack;

	for(int i = 0; i < 10; i ++) {
		stack.push(i);
	}

	while(stack.is_empty() == false) {
		cout << stack.peek() << " ";
		stack.pop();
	}
	cout << endl;

	return 0;
}