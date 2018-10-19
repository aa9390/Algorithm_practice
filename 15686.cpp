#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int map[51][51];
vector<int> ansV(14);

int maxCount;
int ans = 2147483647;

vector<pair<int, int> > chickV;
vector<pair<int, int> > houseV;

// 순열을 위한 벡터
vector<int> v;

void calDistance(vector<pair<int, int> > &pick) {
	int totalDis = 0;

	// 집별로 돌기
	for (int i = 0; i < houseV.size(); i++) {
		int x = houseV[i].first;
		int y = houseV[i].second;
		int dis = 2147483647;

		// 집마다의 치킨 거리 조사
		for (int j = 0; j < pick.size(); j++) {
			int newX = pick[j].first;
			int newY = pick[j].second;
			int newDis = abs(newX - x) + abs(newY - y);

			dis = min(dis, newDis);
		}
		totalDis += dis;
	}
	ans = min(ans, totalDis);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];

			// 집, 치킨집 개수 및 좌표 설정
			if (map[i][j] == 1) {
				houseV.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				chickV.push_back({ i,j });
			}
		}
	}

	maxCount = chickV.size();

	// 순열을 위해 선택할만큼 1, 선택하지 않을 만큼 0 넣어줌
	for (int i = 0; i < M; i++) {
		v.push_back(1);
	}
	
	for (int i = 0; i < maxCount - M; i++) {
		v.push_back(0);
	}

	// 순열 검사
	do {
		vector<pair<int, int> > pickV;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) {
				pickV.push_back({ chickV[i].first, chickV[i].second });
			}
		}

		calDistance(pickV);

	} while (prev_permutation(v.begin(), v.end()));

	cout << ans << endl;
}
