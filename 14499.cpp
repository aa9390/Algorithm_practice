#include <iostream>
using namespace std;

// 맞왜틀???????????????????????
int N, M, x, y, K;
int dir;
int map[21][21];

// 처음에는 주사위 값 모두 0
// 0번째는 안쓸것임! 
// 0 1 2 3 4 5 6
int jusa[7] = { 0 };

int temp;
int sangdanIdx = 1;
int bukIdx = 2;
int dongIdx = 3;
int seoIdx = 4;
int namIdx = 5;
int badakIdx = 6;

// 동 서 북 남 
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

void printjusa() {
	cout << "상단 : " << jusa[sangdanIdx] << endl;
	cout << "바닥 : " << jusa[badakIdx] << endl;
	cout << "동 : " << jusa[dongIdx] << endl;
	cout << "서 : " << jusa[seoIdx] << endl;
	cout << "북 : " << jusa[bukIdx] << endl;
	cout << "남 : " << jusa[namIdx] << endl;
}

void printAnswer() {
	cout << jusa[sangdanIdx] << endl;
}

void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin >> N >> M >> x >> y >> K;

	// 지도 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	// 명령 입력
	for (int i = 0; i < K; i++) {
		cin >> dir;

		// 주사위 위치 이동
		int newX = x + dx[dir-1];
		int newY = y + dy[dir-1];

		//cout << "x : " << x << ", y : " << y << endl;

		// 이동한 위치가 범위를 벗어나는 경우, 해당 명령 무시 
		if (newX < 0 || newY < 0 || newX > M  || newY > N ) {
			continue;
		}
		else {
			x = newX; y = newY;
		}

		// 동
		if (dir == 1) {
			temp = dongIdx;
			dongIdx = sangdanIdx;
			sangdanIdx = seoIdx;
			seoIdx = badakIdx;
			badakIdx = temp;
		}

		// 서
		if (dir == 2) {
			temp = seoIdx;
			seoIdx = sangdanIdx;
			sangdanIdx = dongIdx;
			dongIdx = badakIdx;
			badakIdx = temp;
		}

		// 북
		if (dir == 3) {
			temp = bukIdx;
			bukIdx = sangdanIdx;
			sangdanIdx = namIdx;
			namIdx = badakIdx;
			badakIdx = temp;
		}

		// 남
		if (dir == 4) {
			temp = namIdx;
			namIdx = sangdanIdx;
			sangdanIdx = bukIdx;
			bukIdx = badakIdx;
			badakIdx = temp;
		}
		
		// 칸이 0이면 주사위 바닥의 수가 칸으로 복사됨
		if (map[y][x] == 0) {
			map[y][x] = jusa[badakIdx];
		}
		// 칸이 0이 아니면 칸의 수가 주사위 바닥으로 복사됨
		else if (map[y][x] != 0) {
			jusa[badakIdx] = map[y][x];
			map[y][x] = 0;
		}

		//printjusa();
		printAnswer();
	}

	//printMap();
	return 0;
}
