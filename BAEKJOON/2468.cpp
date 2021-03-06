#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[101][101] = {0};
int check[101][101] = {0};
int map[101][101] = {0};
int heightArr[101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
priority_queue<int> pq;
int maxVal = -1;
int N;
int cnt = 0;

void init() {
  cnt = 0;

  for(int i=0; i<101; i++) {
    for(int j=0; j<101; j++) {
      check[i][j] = 0;
      visited[i][j] = 0;
    }
  }
}

// 0인곳 탐색
void dfs(int x, int y) {
  visited[x][y] = 1;

  for(int i=0; i<4; i++) {
    int newX = x + dx[i];
    int newY = y + dy[i];

    if(newX >= 0 && newY >= 0 && newX < N && newY < N) {
      if(visited[newX][newY] == 0 && check[newX][newY] == 0) {
        dfs(newX, newY);
      }
    }
  }
}

void checking(int height) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(map[i][j]<=height) {
        check[i][j] = 1;
      }
    }
  }
}

void printCheck(int height) {
  cout << height << endl;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << check[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin >> N; 

  // 입력
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> map[i][j];
      maxVal = max(maxVal, map[i][j]);
    }
  }

  // 탐색
  // 틀렸던 이유? 비가 안올 경우도 고려해야함.
    for(int height=0; height<=maxVal; height++) {
      checking(height);
      // printCheck(height);

      for(int k=0; k<N; k++) {
        for(int l=0; l<N; l++) {
          if(visited[k][l] == 0 && check[k][l] == 0) {
            cnt++;
            bfs(k, l);
          }
        }
      }
      // cout << cnt << endl;
      pq.push(cnt);
      init();
      // }
      // heightArr[map[i][j]] = 1;
    // }
  // }
    }

  cout << pq.top();
}
