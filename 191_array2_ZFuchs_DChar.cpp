/*
	191
	array2
	ZFuchs, DChar
*/
/*
array2 - due 9/27, Friday - we've written in class an example program with multiple functions for manipulating arrays. I've emailed that program to your college email though it appears the ins method disappeared.
Write a program that adds and tests the function prototype and described below.
ins(int data[], int count, int n, int v) - this is what we did in class
del(int data[], int count, int start, int stop) - delete from position start up to, but not including, position stop. If stop is past the last filled value in the array, just delete everything from stop onward.
int findMin(int data[], int count) - returns the least value in the array. Remember that this is an array of any possible integer values.
bool in(int data[], int count, int target) - return true if target is in the array, false otherwise.
int count(int data[], int count, int target) - return the number of instances of target in the array.
int findFirst(int data[], int count, int target) - return the index of the first instance of target. Start at position 0.
int findLast(int data[], int count, int target) - return the index of the last instance of target. Start at position count-1.
void display(int data[], int count) - this is what we did in class and is part of the file I mailed out.
void reset(int data[], int count) - fills the entire array with 0s and sets the count to 0.
Think of an array like a set. If data1 = {5, 9, 7, 10, 3} and data2 = {9, 10, 20, 14}, then data1 ∪ data2 = {9, 10}. (Note: data1 ∪ data2 means the mathematical union of data1 and data1 - the elements in common.) 
Write a function void unionArray(int data1[], int count1, int data2[], int count2, int data3[], int count3) which fills data3 with the elements in common in data1 and data2 and sets the count3 to be the number of elements
in this union. Note that data3 and count3 have to be passed by reference of course. Unfortunately C++ doesn't nicely support returning an array, so instead we pass data3 in by reference.
*/
#include <iostream>
using namespace std;

const int MAX = 20;

void load(int d[], int& count) {
	cout << "How many? ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "? ";
		cin >> d[i];
	}
}

void display(int d[], int count) {
	for (int i = 0; i < count; i++)
		cout << d[i] << " ";
	cout << endl;
} 

int get(int d[], int count, int n) {
	if (n < 0 || n >= count)
		return INT_MAX;
	else
		return d[n];
}

void set(int d[], int count, int pos, int val) {
	if (val >= 0 && pos < count)
		d[pos] = val;
}

void del(int d[], int& count, int pos) {
	if (0 <= pos && pos < count) {
		for (int i = pos; i < count - 1; i++) {
			d[i] = d[i + 1];
		}
		count--;
	}
}

void ins(int d[], int& count, int pos, int val) {
	cout << "What position would you like to insert to?" << endl;
	cin >> pos;
	cout << "What number would you like to insert in position " << pos << endl;
	if (0 <= pos && pos < count) {
		for (int i = pos; i < count - 1; i++) {
			d[i + 1] = d[i];
		}
		d[pos] = val;
	} else {
		cout << "That position is invalid." << endl;
	}
}

int main() {
	int data[MAX];
	int count;
	int position;
	int value;
	load(data, count);
	display(data, count);
	cout << endl << count << endl;
	ins(data, count, position, value);
	display(data, count);
	cout << endl;
}
