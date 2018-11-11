#include <iostream>
using namespace std;

int main() {
	int cnt = 0;
	int num, first, second, newSecond, newNum;
	cin >> num;

	if (num < 10) {
		first = 0;
		second = num;
	}
	else {
		first = num / 10;
		second = num % 10;
	}

	do {
		newSecond = (first + second) % 10;
		newNum = (second * 10) + newSecond;
		first = newNum / 10;
		second = newNum % 10;
		cnt++;
	} while (newNum != num);

	cout << cnt;
}
