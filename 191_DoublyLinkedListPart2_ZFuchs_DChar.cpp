/*
	191
	DoublyLinkedListPart2
	ZFuchs, DChar
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* next, * prev;
};

class DoublyLinkedList {
private:
	Node* top, * bottom;
	int size, workspaceSize;
public:
	//constructors
	DoublyLinkedList();
	//setters
	void insert(int);
	//getters
	int getSize();
	//utility
	void displayFromTop();
	void displayFromBottom();
	bool in(int);
	int count(int);
	Node* find(int);
	int popTop();
	int popBottom();
	void deleteFirstInt(int);
	void deleteLastInt(int);
	void deleteInt(int);
	void deleteNode(Node*);
	void addAll(int*, int);
	void removeAll(int*, int);
};  //DoublyLinkedList

//O(1)
DoublyLinkedList::DoublyLinkedList() {
	top = bottom = nullptr;
	size = 0;
	workspaceSize = 0;
} //DoublyLinkedList

//O(n)
void DoublyLinkedList::insert(int val) {
	Node* p = new Node;
	p->next = p->prev = nullptr;
	p->data = val;
	if (size == 0) {
		top = bottom = p;
	} else if (top->data >= val) {
		p->next = top;
		top->prev = p;
		top = p;
	} else if (bottom->data <= val) {
		p->prev = bottom;
		bottom->next = p;
		bottom = p;
	} else {
		Node* runner = top;
		while (runner->next != nullptr && runner->next->data <= val) {
			runner = runner->next;
		}
		p->next = runner->next;
		runner->next = p;
		p->prev = runner;
		p->next->prev = p;
	}
	size++;
}

//O(n)
bool DoublyLinkedList::in(int val) {
	Node* runner = top;
	while (runner != nullptr) {
		if (runner->data == val) {
			return true;
		} else {
			runner = runner->next;
		}
	}
	return false;
}

//O(n)
int DoublyLinkedList::count(int val) {
	Node* runner = top;
	int count = 0;
	while (runner != nullptr) {
		if (runner->data == val) {
			count++;
			runner = runner->next;
		} else {
			runner = runner->next;
		}
	}
	return count;
}

//O(n)
Node* DoublyLinkedList::find(int val) {
	Node* runner = top;
	while (runner != nullptr) {
		if (runner->data == val) {
			return runner;
		} else {
			runner = runner->next;
		}
	}
	return nullptr;
}

//O(1)
int DoublyLinkedList::popTop() {
	if (size != 0) {
		int val = top->data;
		Node* p = top;
		top = top->next;
		top->prev = nullptr;
		delete p;
		size--;
		return val;
	} else {
		cout << "Cannot delete a node from an empty linked list." << endl;
	}
}

//O(1)
int DoublyLinkedList::popBottom() {
	if (size != 0) {
		int val = bottom->data;
		Node* p = bottom;
		bottom = bottom->prev;
		bottom->next = nullptr;
		delete p;
		size--;
		return val;
	} else {
		cout << "Cannot delete a node from an empty linked list." << endl;
	}
}

//O(n)
void DoublyLinkedList::deleteFirstInt(int val) {
	Node* runner = top;
	if (size == 1) {
		if (runner->data == val) {
			top = bottom = nullptr;
			delete runner;
			size--;
		} else {
			return;
		}
	} else {
		if (top->data == val) {
			top->next->prev = nullptr;
			top = runner->next;
			delete runner;
			size--;
			return;
		} else if (bottom->data == val) {
			runner = bottom;
			runner->prev->next = nullptr;
			bottom = runner->prev;
			delete runner;
			size--;
			return;
		} else {
			while (runner != nullptr) {
				if (runner->data == val) {
					runner->prev->next = runner->next;
					runner->next->prev = runner->prev;
					delete runner;
					size--;
					return;
				} else {
					runner = runner->next;
				}
			}
		}
	}
}

//O(n)
void DoublyLinkedList::deleteLastInt(int val) {
	Node* runner = bottom;
	if (size == 1) {
		if (runner->data == val) {
			top = bottom = nullptr;
			delete runner;
			size--;
		} else {
			return;
		}
	} else {
		if (bottom->data == val) {
			bottom->next->prev = nullptr;
			bottom = runner->prev;
			delete runner;
			size--;
			return;
		} else if (top->data == val) {
			runner = top;
			runner->next->prev = nullptr;
			top = runner->next;
			delete runner;
			size--;
			return;
		} else {
			while (runner != nullptr) {
				if (runner->data == val) {
					runner->prev->next = runner->next;
					runner->next->prev = runner->prev;
					delete runner;
					size--;
					return;
				} else {
					runner = runner->prev;
				}
			}
		}
	}
}

//O(n)
void DoublyLinkedList::deleteInt(int val) {
	Node* runner = top;
	if (size == 1) {
		if (runner->data == val) {
			top = bottom = nullptr;
		} else {
			return;
		}
	} else {
		while (runner != nullptr) {
			if (top->data == val) {
				top = top->next;
				top->prev = nullptr;
				delete runner;
				size--;
				runner = top;
			} else if (bottom->data == val) {
				runner = bottom;
				bottom = bottom->prev;
				bottom->next = nullptr;
				delete runner;
				size--;
				runner = top;
			} else if (runner->data == val) {
				runner->prev->next = runner->next;
				runner->next->prev = runner->prev;
				Node* temp = runner->next;
				delete runner;
				size--;
				runner = temp;
			} else {
				runner = runner->next;
			}
		}
	}
}

//O(1) 
void DoublyLinkedList::deleteNode(Node* p) {
	if (p == top) {
		top = top->next;
		top->prev = nullptr;
	} else if (p == bottom) {
		bottom = bottom->prev;
		bottom->next = nullptr;
	} else {
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	delete p;
}

//O(n)
void DoublyLinkedList::displayFromTop() {
	Node* runner = top;
	while (runner != nullptr) {
		cout << runner->data << " ";
		runner = runner->next;
	}
} //displayFromTop

//O(n)
void DoublyLinkedList::displayFromBottom() {
	Node* runner = bottom;
	while (runner != nullptr) {
		cout << runner->data << " ";
		runner = runner->prev;
	}
} //displayFromBottom

//O(1)
int DoublyLinkedList::getSize() {
	return size;
}

//O(n^2)
void DoublyLinkedList::addAll(int *arr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		insert(arr[i]);
	}
}

//O(n^2)
void DoublyLinkedList::removeAll(int* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		deleteInt(arr[i]);
	}
}

int main()
{
	
}
