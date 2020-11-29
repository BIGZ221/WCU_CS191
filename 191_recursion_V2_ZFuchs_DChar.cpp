/*
	191
	recursion V2
	ZFuchs, DChar
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 7;

double mypower(double num, int pow) {
	if (pow == 0) {
		return 1;
	}
	else {
		return (num * mypower(num, pow - 1));
	}
}

void hailstone(int num) {
	if (num <= 1) {
		return;
	}
	else if ((num % 2) == 0) {
		cout << (num / 2) << endl;
		hailstone(num / 2);
	}
	else {
		cout << (3 * num + 1) << endl;
		hailstone(3 * num + 1);
	}
}

int fibonacci(int num) {
	if (num == 1 || num == 0) {
		return n;
	}
	else {
		return (fibonacci(num - 1) + fibonacci(num - 2));
	}
}

bool isWholeNumber(string str) {
	int leng = str.length() - 1;
	if (leng+1 == 0) {
		return 1;
	}
	if (str[0] >= 48 && str[0] <= 57) {
		return isWholeNumber(str.substr(1));
	} else {
		return 0;
	}
}

int linearSearch(int data[], int targ, int index) {
	if (data[index] == targ) {
		return index;
	} else if (index < MAX) {
		index++;
		return linearSearch(data, targ, index);
	} else {
		return -1;
	}
}

int sumDigits(int num) {
	int num2;
	if (num == 0) {
		return 0;
	}
	num2 = num % 10;
	return num2 + sumDigits(num / 10);
}

bool isPalindrome(string s) {
	int a = s.length() - 1;

	if (s.length() <= 1) {
		return 1;
	}

	if (tolower(s[0]) == tolower(s[a])) {
		return isPalindrome(s.substr(1, a - 1));
	}
	else {
		return 0;
	}
}

int main() {
	int index = 0;
	cout << "mypower(3, 4)" << endl;
	cout << mypower(3, 4) << endl;
	cout << "mypower(7, 0)" << endl;
	cout << mypower(7, 0) << endl << endl;

	cout << "hailstone(50)" << endl;
	hailstone(50);

	cout << "fibonacci(10)" << endl;
	cout << fibonacci(10) << endl << endl;

	cout << "isWholeNumber(\"123\")" << endl;
	cout << isWholeNumber("123") << endl;
	cout << "isWholeNumber(\"12x0\")" << endl;
	cout << isWholeNumber("12x0") << endl << endl;

	int x[] = { 1, 4, 8, 9, 3, -8, 10 };

	cout << "linearSearch(3, 9)" << endl;
	cout << linearSearch(x, 9, index) << endl;
	cout << "linearSearch(-1)" << endl;
	cout << linearSearch(x, -1, index) << endl << endl;

	cout << "sumDigits(88497)" << endl;
	cout << sumDigits(88497) << endl << endl;

	cout << "isPalindrome(\"mom\")" << endl;
	cout << isPalindrome("mom") << endl;
	cout << "isPalindrome(\"momxmom\")" << endl;
	cout << isPalindrome("momxmom") << endl;
	cout << "isPalindrome(\"baker\")" << endl;
	cout << isPalindrome("baker") << endl;
	cout << "isPalindrome(\"bakkaB\")" << endl;
	cout << isPalindrome("bakkaB") << endl;
}

