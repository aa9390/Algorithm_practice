#include <iostream>
using namespace std;

char map[102][102];
bool checkFlag = false;
int cnt = 0;
int garo = 0;
int sero = 0; 
int num;

// 핵심 포인트 : "중간에 어정쩡하게 눕는 경우가 없다"
// 벽에 닿아야 함. 

int main() {
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> map[i][j];
		}
		map[i][num] = 'X';
		map[num][i] = 'X';
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			// 짐이나 벽을 만났을 때 누울 수 있는 자리가 2개 연속이면 카운터를 증가시킴
			garo += (map[i][j] == '.' && map[i][j + 1] == '.' && map[i][j + 2] == 'X') ? 1 : 0;
			sero += (map[j][i] == '.' && map[j + 1][i] == '.' && map[j + 2][i] == 'X') ? 1 : 0;
		}
	}

	cout << garo << ' ' << sero;
}
