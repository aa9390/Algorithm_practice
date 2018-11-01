#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int testcaseCount = 10;
int x;

int main() {
  int dumpCount;
  for(int i=0; i<testcaseCount; i++) {
    cin >> dumpCount;

    vector<int> v(100);
    int diff;

    // 입력
    for(int j=0; j<100; j++) {
      cin >> x;
      v[j] = x;
    }

    //
    for(int j=1; j<=dumpCount+1; j++) {
      sort(v.begin(), v.end());
      int f = v.front();
      int b = v.back();
      diff = b-f;

      // cout <<"j : " << j << ", f : " << f << ", b : " << b << ", diff : " << diff << endl;

      if(diff > 1) {
        f++;
        b--;

        v.erase(v.begin()); v.pop_back();
        v.push_back(f); v.push_back(b);
      }
      
      else break;
    } 

    cout << "#" << i+1 << ' ' << diff << endl;
  }
}
