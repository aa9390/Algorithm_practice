#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  vector<pair<int, char> > v(26);
  // vector<int> v(26,0);
  int maxIdx = -1;
  char maxFreq = ' ';
  string str;
  cin >> str;

  // 대문자로 변환
  transform(str.begin(), str.end(), str.begin(), ::toupper);

  for(int i=0; i<26; i++) {
    v[i].second = i + 65;
  }

  for(int i=0; i<str.length(); i++) {
    v[str[i] - 65].first++;
  }

  sort(v.begin(), v.end());

  int temp = v.back().first;
  maxFreq = v.back().second;

  v.pop_back();
  if(v.back().first == temp) {
    cout << '?';
  }
  else {
    cout << maxFreq;
    }

}
