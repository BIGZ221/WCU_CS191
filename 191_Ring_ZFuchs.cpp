/*
	191
	Ring
	ZFuchs
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next, * prev;
};

class Ring {
private:
	Node* handle;
	int size;
public:
	Ring();
	void insert(int);
	int count(int);
	bool in(int);
	void displayClockwise();
	void displayCounterClockwise();
};

Ring::Ring() {
	size = 0;
	handle = nullptr;
}

void Ring::insert(int v) {
	Node* p = new Node;
	p->data = v;
	if (size == 0) {
		handle = p;
		p->next = p->prev = p;
	} else if (size == 1) {
		handle->next = p;
		handle->prev = p;
		p->next = handle;
		p->prev = handle;
		handle = p;
	} else {
		p->next = handle->next;
		p->prev = handle;
		p->next->prev = p;
		handle->next = p;
		handle = p;
	}
	size++;
}

int Ring::count(int val) {
	int count = 0;
	Node* runner = handle;
	for (int i = 0; i < size; i++) {
		if (runner->data == val) {
			count++;
		}
		runner = runner->next;
	}
	return count;
}

bool Ring::in(int val) {
	Node* runner = handle;
	for (int i = 0; i < size; i++) {
		if (runner->data == val) {
			return true;
		}
		runner = runner->next;
	}
	return false;
}

void Ring::displayClockwise() {
	cout << "Size: " << size << endl;
	Node* p = handle;
	if (size != 0) {
		for (int i = 0; i < size; i++) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void Ring::displayCounterClockwise() {
	cout << "Size: " << size << endl;
	Node* p = handle;
	if (size != 0) {
		for (int i = 0; i < size; i++) {
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}

int main() {
	cout << boolalpha;
	Ring r1 = Ring();
	r1.displayClockwise();
	r1.displayCounterClockwise();
	r1.insert(17);
	r1.insert(127);
	r1.insert(17);
	r1.insert(137);
	r1.insert(17);
	r1.insert(176);
	r1.insert(1777);
	r1.displayClockwise();
	r1.displayCounterClockwise();
	cout << "Count of 17s: " << r1.count(17) << endl;
	cout << "Count of  2s: " << r1.count(2) << endl;
	cout << "In  176: " << r1.in(176) << endl;
	cout << "In 1222: " << r1.in(1222) << endl;
}