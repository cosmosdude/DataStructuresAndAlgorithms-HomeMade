#include "SinglyLinkedList.h"

#include <iostream>

using namespace std;

int main() {

	SinglyLinkedList<int> list;

	list.add_front(0);
	list.add_front(-1);
	list.print();

	cout << "front: " <<  list.front() << endl;
	cout << "back: " <<  list.back() << endl;
	cout << "size: " <<  list.size() << endl;

	list.add_back(1);
	list.add_back(2);
	list.print();

	cout << "front: " <<  list.front() << endl;
	cout << "back: " <<  list.back() << endl;
	cout << "size: " <<  list.size() << endl;


	for(int i = 0; i < list.size(); i++) {
		cout << endl;
		list.print();
		cout << "insert_at:" << i << endl;
		list.insert_at(i, 10);
		list.print();
		list.remove_at(i);	
	}
	list.print();

	cout << endl;
	cout << "remove front and back" << endl;

	list.insert_at(2, 100);
	list.print();

	list.remove_front();
	list.print();
	list.remove_front();
	list.print();

	list.remove_back();
	list.print();
	list.remove_back();
	list.print();





	return 0;
}