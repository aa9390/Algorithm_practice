#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <sstream>
using namespace std;

int testCaseCount;
int N, K;

bool compare(string a, string b) {
  return a>b;
}

int main() {
  cin >> testCaseCount;
  for(int tc=1; tc<=testCaseCount; tc++) {
    int splitCount;
    vector<char> v;
    vector<string> word;
    string input;

    cin >> N >> K;
    cin >> input;

    splitCount = N/4;

    for(int i=0; i<N; i++) {
      v.push_back(input[i]);
    }
  
  for(int h=0; h<splitCount; h++){
    for(int i=0; i<N; i+=splitCount){
      string temp = "";
      for(int j=i; j<i+splitCount; j++) {
        temp += v[j];
      }
      word.push_back(temp);
    }

    for(int k=0; k<splitCount-1; k++) {
      int f = v.front();
      v.erase(v.begin());
      v.push_back(f);
    }
  }

  sort(word.begin(), word.end(), compare);
  word.erase(unique(word.begin(), word.end()), word.end());

  stringstream str;
  str << word[K-1];
  int val;
  str >> hex >> val;

  cout << "#" << tc <<  ' ' << val << endl;
  }
  return 0;
}
