#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int maxVal, minVal;
	string tempA, tempB;
	string a, b;
	cin >> a >> b;

	tempA = a; tempB = b;

	// 최소
	for (int i = 0; i < tempA.length(); i++) {
		if (tempA[i] == '6') {
			tempA[i] = '5';
		}
	}

	for (int i = 0; i < tempB.length(); i++) {
		if (tempB[i] == '6') {
			tempB[i] = '5';
		}
	}

	minVal = stoi(tempA) + stoi(tempB);

	tempA = a; tempB = b;

	// 최대
	for (int i = 0; i < tempA.length(); i++) {
		if (tempA[i] == '5') {
			tempA[i] = '6';
		}
	}

	for (int i = 0; i < tempB.length(); i++) {
		if (tempB[i] == '5') {
			tempB[i] = '6';
		}
	}

	maxVal = stoi(tempA) + stoi(tempB);

	cout << minVal << ' ' << maxVal;
}
