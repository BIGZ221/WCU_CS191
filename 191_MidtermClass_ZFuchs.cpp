/*
	191
	Midterm Class
	ZFuchs
*/

#include <iostream>
using namespace std;

void cr(int n = 1) {
	for (int i = 0; i < n; i++) {
		cout << endl;
	}
}

class NumPair {
private:
	double val1, val2;
public:
	NumPair(int, int);
	double average();
	bool ascending();

};
NumPair::NumPair(int x, int y) {
	val1 = x;
	val2 = y;
}
double NumPair::average() {
	return (val1 + val2) / 2.0;
}
bool NumPair::ascending() {
	if (val1 < val2) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	NumPair np1 = NumPair(0, 17);
	NumPair np2 = NumPair(17, 0);
	NumPair np3 = NumPair(8, 9);
	NumPair np4 = NumPair(6, 6);
	NumPair np5 = NumPair(0, -86);
	NumPair np6 = NumPair(-86, 0);
	NumPair np7 = NumPair(-88, -6);
	cout << boolalpha;
	cout << "Averaging: 0, 17" << endl;
	cout << "Expect - Average: 8.5" << endl;
	cout << "Actual - Average: " << np1.average() << endl;
	cr();

	cout << "Averaging: 17, 0" << endl;
	cout << "Expect - Average: 8.5" << endl;
	cout << "Actual - Average: " << np2.average() << endl;
	cr();

	cout << "Averaging: 8, 9" << endl;
	cout << "Expect - Average: 8.5" << endl;
	cout << "Actual - Average: " << np3.average() << endl;
	cr();

	cout << "Averaging: 6, 6" << endl;
	cout << "Expect - Average: 6" << endl;
	cout << "Actual - Average: " << np4.average() << endl;
	cr();

	cout << "Averaging: -88, -6" << endl;
	cout << "Expect - Average: -47" << endl;
	cout << "Actual - Average: " << np7.average() << endl;
	cr();

	cout << "Ascending: 0, 17" << endl;
	cout << "Expect - Ascending: true" << endl;
	cout << "Actual - Ascending: " << np1.ascending() << endl;
	cr();

	cout << "Ascending: 17, 0" << endl;
	cout << "Expect - Ascending: false" << endl;
	cout << "Actual - Ascending: " << np2.ascending() << endl;
	cr();

	cout << "Ascending: 6, 6" << endl;
	cout << "Expect - Ascending: false" << endl;
	cout << "Actual - Ascending: " << np4.ascending() << endl;
	cr();

	cout << "Ascending: 0, -86" << endl;
	cout << "Expect - Ascending: false" << endl;
	cout << "Actual - Ascending: " << np5.ascending() << endl;
	cr();

	cout << "Ascending: -86, 0" << endl;
	cout << "Expect - Ascending: true" << endl;
	cout << "Actual - Ascending: " << np6.ascending() << endl;
	cr();

	cout << "Ascending: -88, -6" << endl;
	cout << "Expect - Ascending: true" << endl;
	cout << "Actual - Ascending: " << np7.ascending() << endl;
	cr();
}
