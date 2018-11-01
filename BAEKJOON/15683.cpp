#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/*
카메라는 90도씩 회전 가능. 
https://blog.naver.com/proability/221298931485 코드 참고함
main에서 for문을 돌리며 CCTV 위치를 탐색하고, switch 문으로 CCTV 번호에 따라 CCTV의 회전 방향을 설정함. 
*/

int N, M;
int ans = 214748347;

// 감시 했는지 여부를 3차원 배열로 저장. 마지막 인덱스는 카메라 방향을 의미.
// 북 동 남 서
bool map[9][9][4];
int tmp[9][9];
int origin[9][9];

// CCTV의 좌표 정보 및 회전 정보 저장
vector<pair<int, int> > v;
vector<int> rotation;

// 북 동 남 서
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };


// 사각지대 탐색 및 감시 전의 상태로 복구 
int recovery() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) cnt++;
			tmp[i][j] = origin[i][j];
		}
	}
	return cnt;
}

// 몇번 카메라가 몇 도 회전했는지
void viewCamera(int num, int flag) {
	int x = v[num].first; int y = v[num].second;
	for (int i = 0; i < 4; i++) {
		if (map[x][y][i]) {
			int newX = x + dx[(i + flag) % 4];
			int newY = y + dy[(i + flag) % 4];
			while (tmp[newX][newY] != 6 && newX >= 0 && newY >= 0 && newX < N && newY < M) {
				if (tmp[newX][newY] == 0) tmp[newX][newY] = 9;
				newX += dx[(i + flag) % 4];
				newY += dy[(i + flag) % 4];
			}
		}
	}
	return;
}

void dfs(int cnt) {
	if (cnt == v.size()) {
		// 회전정보만큼 카메라 회전 
		for (int i = 0; i < rotation.size(); i++) {
			viewCamera(i, rotation[i]);
		}
		ans = min(ans, recovery());
		return;
	}

	// CCTV 회전
	for (int i = 0; i < 4; i++) {
		rotation.push_back(i);
		dfs(cnt + 1);
		rotation.pop_back();
	}
	return;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp[i][j];
			origin[i][j] = tmp[i][j];
		}
	}

	// CCTV 있는 곳 탐색 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//  빈 공간이나 CCTV 있는 곳이 아니면 넘어감 
			if (!tmp[i][j] || tmp[i][j] == 6) {
				continue;
			}
			v.push_back(make_pair(i, j));

			// 초기 방향 정보 저장
			switch (tmp[i][j])
			{
			case 1: 
				map[i][j][1] = true;
				break;
			case 2:
				map[i][j][1] = true;
				map[i][j][3] = true;
				break;
			case 3:
				map[i][j][0] = true;
				map[i][j][1] = true;
				break;
			case 4:
				map[i][j][0] = true;
				map[i][j][1] = true;
				map[i][j][3] = true;
				break;
			case 5:
				map[i][j][0] = true;
				map[i][j][1] = true;
				map[i][j][2] = true;
				map[i][j][3] = true;
				break;
			}
		}
	}
	dfs(0);
	cout << ans;
}
