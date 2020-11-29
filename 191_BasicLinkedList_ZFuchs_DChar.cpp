/*
	191
	BasicLinkedList
	ZFuchs, DChar
*/
#include <iostream>
#include <string>
using namespace std;

void cr(int i = 1) {
	for (int j = 0; j < i; j++)
		cout << endl;
}

struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* top, * bottom;
	int size;
public:
	LinkedList();
	void display();
	int getSize();
	Node* search(int);
	void sortedInsert(int);
	void deleteValue(int);
};  //LinkedList

//O(1)
LinkedList::LinkedList() {
	top = bottom = nullptr;
	size = 0;
} //LinkedList

//O(n)
void LinkedList::sortedInsert(int val) {
	Node* p = new Node;
	p->data = val;
	p->next = nullptr;
	if (size == 0) {
		top = p;
	}else if (size == 1) {
		if (val < top->data) {
			p->next = top;
			top = p;
		}
		else {
			top->next = p;
		}
	} else {
		if (val < top->data) {
			p->next = top;
			top = p;
			size++;
			return;
		}
		Node* front = top->next;
		Node* rear = top;
		while (front != nullptr) {
			if (val >= rear->data && val < front->data) {
				rear->next = p;
				p->next = front;
				break;
			}
			else if (front->next == nullptr) {
				front->next = p;
				break;
			}

			rear = front;
			front = rear->next;
			
		}
	}
	size++;
}

//O(n)
void LinkedList::deleteValue(int val) {
	Node* rear = top;
	Node* front = rear->next;
	if (rear->data == val) {
		top = front;
		delete rear;
		size--;
		return;
	} else {
		while (front!=nullptr) {
			if (front->data == val) {
				rear->next = front->next;
				delete front;
				size--;
				return;
			} else {
				rear = front;
				front = front->next;
			}
		}
	}

	cout << "That value does not exist in the linked list." << endl;
}

//O(n)
Node* LinkedList::search(int target) {
	Node* p = top;
	while (p != nullptr) {
		if (p->data == target)
			return p;
		p = p->next;
	}
	return nullptr;
}

//O(1)
int LinkedList::getSize() {
	return size;
} //getSize

//O(n)
void LinkedList::display() {
	Node* p = top;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
} //display


int main() {
	LinkedList l1 = LinkedList();

	cout << "Inserting a 20" << endl;
	cout << "Expect - 20" << endl;
	cout << "Actual - ";
	l1.sortedInsert(20);
	l1.display();
	cr(2);

	cout << "Inserting a 10" << endl;
	cout << "Expect - 10 20" << endl;
	cout << "Actual - ";
	l1.sortedInsert(10);
	l1.display();
	cr(2);
	
	cout << "Inserting a 30" << endl;
	cout << "Expect - 10 20 30" << endl;
	cout << "Actual - ";
	l1.sortedInsert(30);
	l1.display();
	cr(2);
	
	cout << "Inserting 15, 40, 45, 5, 60, 45, 35" << endl;
	cout << "Expect - 5 10 15 20 30 35 40 45 45 60" << endl;
	cout << "Actual - ";
	l1.sortedInsert(15);
	l1.sortedInsert(40);
	l1.sortedInsert(45);
	l1.sortedInsert(5);
	l1.sortedInsert(60);
	l1.sortedInsert(45);
	l1.sortedInsert(35);
	l1.display();
	cr(2);
	
	cout << "Deleting a 10" << endl;
	cout << "Expect - 5 15 20 30 35 40 45 45 60" << endl;
	cout << "Actual - ";
	l1.deleteValue(10);
	l1.display();
	cr(2);

	cout << "Deleting a 45" << endl;
	cout << "Expect - 5 15 20 30 35 40 45 60" << endl;
	cout << "Actual - ";
	l1.deleteValue(45);
	l1.display();
	cr(2);

	cout << "Deleting a 33" << endl;
	cout << "Expect - That value does not exist in the linked list." << endl;
	cout << "Actual - ";
	l1.deleteValue(33);
	l1.display();
	cr(2);

	cout << "Deleting a 5" << endl;
	cout << "Expect - 15 20 30 35 40 45 60" << endl;
	cout << "Actual - ";
	l1.deleteValue(5);
	l1.display(); 
	cr(2);

	cout << "Deleting a 60" << endl;
	cout << "Expect - 15 20 30 35 40 45" << endl;
	cout << "Actual - ";
	l1.deleteValue(60);
	l1.display();
	cr(2);

	cout << "Deleting a 15" << endl;
	cout << "Expect - 20 30 35 40 45" << endl;
	cout << "Actual - ";
	l1.deleteValue(15);
	l1.display();
	cr(2);

	cout << "Deleting a 77" << endl;
	cout << "Expect - That value does not exist in the linked list." << endl;
	cout << "Actual - ";
	l1.deleteValue(77);
	l1.display();
	cr(2);
	
	cout << "Size: " << l1.getSize() << endl;
} //main
