/*
	191
	array1
	ZFuchs, DChar
*/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int * loadArray(int randNumArray[], int& total, int& min, int& max) {
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		randNumArray[i] = rand() % 2001 - 1000;
		if (min > randNumArray[i]) {
			min = randNumArray[i];
		} if (max < randNumArray[i]) {
			max = randNumArray[i];
		}
		total += randNumArray[i];
	}
	return randNumArray;
}
void displayArray(int randNumArray[], int total, int min, int max) {
	for (int i = 0; i < 20; i++) {
		if (i < 10) {
			cout.width(6);	cout << right << randNumArray[i];
		} else if ( i == 10) {
			cout.width(6);  cout << endl << randNumArray[i];
		} else {
			cout.width(6);	cout << right << randNumArray[i];
		}
	}
	cout << endl << "Average: " << (double)total / 20 << endl
				 << "Max: " << max << endl
				 << "Min: " << min << endl;
}
int * searchArray(int num, int arr[]) { 
	int count = 0;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == num) {
			count++;
		}
	}
	if (count >0) {
		cout << "Found " <<  num << " " << count << " time(s) in the array." <<  endl;
	}
	else {
		cout << "That number was not found." << endl;
	}
	return NULL;
}
int main()
{
	int randomNum, randNumArray[20], total = 0, min = 10000, max = -10000, find, findNum = 1;
	loadArray(randNumArray, total, min, max);
	displayArray(randNumArray, total, min, max);

	cout << "Would you like to find a number? 1 = Yes / 0 = No." << endl;
	cin >> find;
	if (find == 1) {
		cout << "What number would you like to find? : " << endl;
		cin >> findNum;
		searchArray(findNum, randNumArray);
	} 
}
