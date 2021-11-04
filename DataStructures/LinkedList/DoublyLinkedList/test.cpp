#include "DoublyLinkedList.h"

#include <iostream>

using namespace std;

int main() {
	DoublyLinkedList<int> list;

	list.add_front(0);
	list.add_front(-1);
	list.print(); list.printrev();

	cout << "front: " <<  list.front() << endl;
	cout << "back: " <<  list.back() << endl;
	cout << "size: " <<  list.size() << endl;

	list.add_back(1);
	list.add_back(2);
	list.print(); list.printrev();

	cout << "front: " <<  list.front() << endl;
	cout << "back: " <<  list.back() << endl;
	cout << "size: " <<  list.size() << endl;


	for(int i = 0; i < list.size(); i++) {
		cout << endl;
		list.print(); list.printrev();
		cout << "insert_at:" << i << endl;
		list.insert_at(i, 10);
		list.print(); list.printrev();
		cout << "size:" << list.size() << endl;
		list.remove_at(i);	
		cout << "size:" << list.size() << endl;
	}
	list.print(); list.printrev();
	cout << "size:" << list.size() << endl;

	cout << endl;
	cout << "remove front and back" << endl;

	list.insert_at(2, 100);
	list.print(); list.printrev();
	cout << "size:" << list.size() << endl;

	list.remove_front();
	list.print(); list.printrev();
	cout << "size:" << list.size() << endl;

	list.remove_front();
	list.print(); list.printrev();
	cout << "size:" << list.size() << endl;

	list.remove_back();
	list.print(); list.printrev();
	cout << "size:" << list.size() << endl;

	list.remove_back();
	list.print(); list.printrev();
	cout << "size:" << list.size() << endl;

	return 0;
}