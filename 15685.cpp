#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, x, y, d, g;
int temp;
int ans = 0;
bool breakFlag = false;
vector<pair<int, int> > v;
vector<pair<int, int>> resV;

// 0 1 2 3
// 동 북 서 남
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int checkNemo() {
	// 정렬된 상태임. 참고
	// resV.size() 는 10
	for (int startIdx = 0; startIdx < resV.size()-1; startIdx++) {
		int startX = resV[startIdx].first;
		int startY = resV[startIdx].second;

		for (int compareIdx = startIdx+1; compareIdx < resV.size(); compareIdx++) {
			if (resV[compareIdx].first == startX + 1 && resV[compareIdx].second == startY + 1) {
				//cout << "startIdx : " << startIdx << endl; 
				//cout << "compareIdx : " << compareIdx << endl; // 5

				if (resV[startIdx + 1].first == startX && resV[startIdx + 1].second == startY + 1) {
					//cout << " sdfsaf" << endl;
					
					if (resV[compareIdx-1].first == resV[compareIdx].first && resV[compareIdx-1].second == startY) {
						//cout << " sdfsaf" << endl;
						ans++;
					}
					
				}
			}
		}
	}
	return ans;
}

void sortResVec() {
	//cout << "최종 vector" << endl;

	sort(resV.begin(), resV.end());
	resV.erase(unique(resV.begin(), resV.end()), resV.end());

	/*
	for (int i = 0; i<resV.size(); i++) {
		cout << "i : " << i;
		cout << ", x : " << resV[i].first;
		cout << ", y : " << resV[i].second << endl;
	}
	*/
}

void printVec() {
	for (int i = 0; i<v.size(); i++) {
		cout << "x : " << v[i].first;
		cout << ", y : " << v[i].second << endl;
	}
}

void pushVec() {
	for (int i = 0; i<v.size(); i++) {
		resV.push_back(v[i]);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i<N; i++) {
		cin >> x >> y >> d >> g;

		v.push_back(make_pair(x, y));

		for (int ge = 0; ge <= g; ge++) {
			int dir = d;
			if (ge == 0) { 
				temp = 1;
				x = v.back().first + dx[dir];
				y = v.back().second + dy[dir];
				v.push_back(make_pair(x, y));
			}
			else {
				vector<pair<int, int>> tempV(v);
				temp = v.size() - 1;

				for (int j = 0; j<temp; j++) {
					int backX = tempV.back().first;
					int backY = tempV.back().second;
					tempV.pop_back();

					int backXX = tempV.back().first;
					int backYY = tempV.back().second;

					int diffX = backXX - backX;
					int diffY = backYY - backY;

					for (int k = 0; k<4; k++) {
						if (dx[k] == diffX && dy[k] == diffY) {
							dir = k;
							dir = dir - 1;
							if (dir<0) dir = 3;
							break;
						}
					}
					x = v.back().first + dx[dir];
					y = v.back().second + dy[dir];
					v.push_back(make_pair(x, y));
				}
			}
			//printVec();
			//cout << ge << "세대 끝" << endl << endl;
		}
		pushVec();
		v.clear();
	}
	sortResVec();
	cout << checkNemo();
}
