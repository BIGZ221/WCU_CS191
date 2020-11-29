/*
	191
	IntPowerArray
	ZFuchs, DChar
*/
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int MAX = 5;

void cr(int n = 1) {
	for (int i = 0; i < n; i++)
		cout << endl;
} //cr

class IPA {
private:
	int workspace[MAX];
	int size;
	void error(string);
public:
	//constructors, loaders and display
	IPA();
	void loadKeyboard();
	void loadRandom();
	void display();
	//getters
	int find(int);
	bool in(int);
	int findMax();
	int findMin();
	int countTarget(int);
	//setters
	void ins(int, int);
	void del(int);
};

void IPA::error(string msg) {
	//display an error message and stop the program
	cout << msg << endl;
	exit(EXIT_FAILURE);
} //error

//constructors, loaders, display
IPA::IPA() {
	size = 0;
} //IPA

void IPA::loadKeyboard() {
	cout << "Keyboard - How many? ";
	cin >> size;
	if (size > MAX)
		error("--loadKeyboard - can't input that many values.");
	for (int i = 0; i < size; i++) {
		cout << "? ";
		cin >> workspace[i];
	}
} //loadKeyboard

void IPA::loadRandom() {
	cout << "Random - How many? Start of range? End of range? ";
	int rangeStart, rangeEnd;
	srand((int)time(NULL));
	cin >> size >> rangeStart >> rangeEnd;
	if (size > MAX)
		error("--loadRandom - can't input that many values.");
	else if (rangeStart > rangeEnd)
		error("--loadRandom - start must be less than end.");
	for (int i = 0; i < size; i++)
		workspace[i] = (rand() % (rangeEnd - rangeStart + 1))
		+ rangeStart;
} //loadRandom

void IPA::display() {
	cout << "Size: " << size << " | Workspace: ";
	for (int i = 0; i < size; i++)
		cout << workspace[i] << " ";
	cout << endl;
} //display

//getters
int IPA::find(int target) {
	for (int i = 0; i < size; i++) {
		if (workspace[i] == target) {
			return i;
		}
	}
	return -1;
} //find

bool IPA::in(int target) {
	for(int i = 0; i < size; i++){
		if(workspace[i] == target){
			return true; 
		}
	}
	return false;
} //in

int IPA::findMax() {
	int max = workspace[0];
	for (int i = 1; i < size; i++)
		if (workspace[i] > max) max = workspace[i];
	return max;
} //findMax

int IPA::findMin() {
	int min = workspace[0];
	for (int i = 1; i < size; i++) {
		if (min > workspace[i]) {
			min = workspace[i];
		}
	}
	return min;
} //findMin

int IPA::countTarget(int target) {
	int count = 0; 
	for(int i = 0; i < size; i++){
		if(workspace[i] == target){
			count++; 
		}
	}
	return count; 
}

//setters
void IPA::ins(int pos, int v) {
	if (pos > size)
		error("-- ins - pos > size");
	if (size < MAX) { //room to insert without losing values
		for (int i = size; i > pos; i--)
			workspace[i] = workspace[i - 1];
		workspace[pos] = v;
		size++;
	}
	else {
		for (int i = size - 1; i > pos; i--)
			workspace[i] = workspace[i - 1];
		workspace[pos] = v;
	}
} //ins

void IPA::del(int pos) {
	if (pos >= size || pos < 0) {
		error("-- ins - pos >= size or pos < 0");
	}
	if (0 <= pos && pos < size) {
		for (int i = pos; i < size - 1; i++) {
			workspace[i] = workspace[i + 1];
		}
		size--;
	}
} //del

int main() {
	cout << boolalpha;
	cout << "Constructing ipa1" << endl;
	IPA ipa1 = IPA();
	cout << "Expect - Size: 0 | Workspace:" << endl;
	cout << "Actual - ";
	ipa1.display();
	cr();

	cout << "Loading from keyboard - enter 3 then 11, -2, 33"<< endl;
	ipa1.loadKeyboard();
	cout << "Expect - Size: 3 | Workspace: 11 -2 33" << endl;
	cout << "Actual - ";
	ipa1.display();
	cr();

	cout << "Finding max" << endl;
	cout << "Expect - Max: 33" << endl;
	cout << "Actual - Max: " << ipa1.findMax() << endl;
	cr();
	
	cout << "Finding min" << endl;
	cout << "Expect - Min: -2" << endl;
	cout << "Actual - Min: " << ipa1.findMin() << endl;
	cr();

	cout << "Checking in" << endl;
	cout << "Expect - In: true" << endl;
	cout << "Actual - In: " << ipa1.in(11) << endl;
	cr();

	cout << "Checking in" << endl;
	cout << "Expect - In: false" << endl;
	cout << "Actual - In: " << ipa1.in(999) << endl;
	cr();

	cout << "Checking Find" << endl;
	cout << "Expect - Find: 2" << endl;
	cout << "Actual - Find: " << ipa1.find(33) << endl;
	cr();

	cout << "Checking Find" << endl;
	cout << "Expect - Find: -1" << endl;
	cout << "Actual - Find: " << ipa1.find(9999) << endl;
	cr();

	cout << "Insert 44 at position 3" << endl;
	cout << "Expect - Size: 4 | Workspace: 11 -2 33 44" << endl;
	cout << "Actual - ";
	ipa1.ins(3, 44);
	ipa1.display();
	cr();

	cout << "Insert 0 at position 0" << endl;
	cout << "Expect - Size: 5 | Workspace: 0 11 -2 33 44" << endl;
	cout << "Actual - ";
	ipa1.ins(0, 0);
	ipa1.display();
	cr();

	cout << "Insert -1 at position 0" << endl;
	cout << "Expect - Size: 5 | Workspace: -1 0 11 -2 33" << endl;
	cout << "Actual - ";
	ipa1.ins(0, -1);
	ipa1.display();
	cr();

	cout << "Insert 99 at position 4" << endl;
	cout << "Expect - Size: 5 | Workspace: -1 0 11 -2 99" << endl;
	cout << "Actual - ";
	ipa1.ins(4, 99);
	ipa1.display();
	cr();

	cout << "CountTarget" << endl;
	cout << "Expect - 1" << endl;
	cout << "Actual - ";
	cout << ipa1.countTarget(11) << endl;
	cr();

	cout << "CountTarget" << endl;
	cout << "Expect - 0" << endl;
	cout << "Actual - ";
	cout << ipa1.countTarget(999) << endl;
	cr();

	cout << "Delete 11 at position 3" << endl; 
	cout << "Expect - Size: 4 | Workspace: -1 0 -2 99" << endl;
	cout << "Actual - ";
	ipa1.del(2);
	ipa1.display();
	cr(); 

	cout << "Delete -1 at begining position" << endl; 
	cout << "Expect - Size: 3 | Workspace: 0 -2 99" << endl;
	cout << "Actual - ";
	ipa1.del(0);
	ipa1.display();
	cr(); 

	cout << "Delete 99 at end position" << endl;
	cout << "Expect - Size: 2 | Workspace: 0 -2" << endl;
	cout << "Actual - ";
	ipa1.del(2);
	ipa1.display();
	cr(); 
} //main
