#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str;
  vector<int> check(26,-1);
  cin >> str;

  for(int i=0; i<str.length(); i++) {
    // 값이 이미 있으면 갱신 안함
    if(check[str[i] - 97] != -1) {
      continue;
    }

    check[str[i]- 97] = i;
  }

  for(int i=0;i<26; i++) {
    cout << check[i] << ' ';
  }
}
