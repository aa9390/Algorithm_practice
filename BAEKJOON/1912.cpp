// dp로도 풀어보기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	int sum = 0, maxVal = -1000;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 시간초과남 (2중 for문 쓸 필요가 없었음)
	//for (int i = 0; i < n; i++) {
	//	int maxVal = v[i];
	//	int sum = v[i];
	//	for (int j = i + 1; j < n; j++) {
	//		sum += v[j];
	//		maxVal = max(maxVal, sum);
	//	}
	//	result = max(result, maxVal);
	//}

	for (int i = 0; i < n; i++) {
		sum += v[i];
		maxVal = max(sum, maxVal);

		if (sum < 0) {
			sum = 0;
		}
	}

	cout << maxVal;
}
