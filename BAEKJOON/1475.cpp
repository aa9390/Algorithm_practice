#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 1;
	int check[9];
	string str;
	cin >> str;

	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			check[i] = 2;
		}
		else {
			check[i] = 1;
		}
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '6' || str[i] == '9') {
			str[i] = '6';
		}

		if (check[str[i] - 48] == 0) {
			cnt++;
			for (int i = 0; i < 9; i++) {
				if (i == 6) {
					check[i] += 2;
				}
				else {
					check[i] += 1;
				}
			}
		}

		if (check[str[i] - 48] > 0) {
			check[str[i] - 48]--;
		}
	}

	cout << cnt;
}