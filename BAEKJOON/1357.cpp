#include <iostream>
#include <string>
using namespace std;

string rev(string a) {
	string temp = "";

	for (int i = a.length() - 1; i >= 0; i--) {
		temp += a[i];
	}

	return temp;
}

int main() {
	string x, y;
	cin >> x >> y;

	string tempSum;
	tempSum = to_string(stoi(rev(x)) + stoi(rev(y)));

	cout << stoi(rev(tempSum));
	return 0;
}
