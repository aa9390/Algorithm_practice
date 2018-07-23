#include <iostream>
#include <set>
using namespace std;
set<int> a;
int n, m;
int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x; scanf(" %d", &x);
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; scanf(" %d", &x);
        if (a.count(x)) a.erase(x);
        else a.insert(x);
    }
    printf("%d\n", a.size());
}

// ---------------- 시간초과된 c로 작성된 코드 -------------------------
// #1269 - 대칭 차집합
// arrA의 원소 개수 - arrB와 겹치는 원소 개수 
// arrB의 원소 개수 - arrA와 겹치는 원소 개수 
// 두개 더함.

// #1269 - 대칭 차집합
// // arrA의 원소 개수 - arrB와 겹치는 원소 개수 
// // arrB의 원소 개수 - arrA와 겹치는 원소 개수 
// // 두개 더함.

// #include <stdio.h>
// int main() {
//   int first, second = 0;
//   int sum = 0;
//   int count = 0;

//   // 두 집합의 원소 개수 입력받음 
//   scanf("%d %d", &first, &second);

//   int aArray[first], bArray[second];

//  // 두 집합 입력받음 
//   for(int i=0; i<first; i++) {
//     scanf("%d", &aArray[i]);
//   }

//   for(int i=0; i<second; i++) {
//     scanf("%d", &bArray[i]);
//   }

//   for(int i=0; i<first; i++) {
//     for(int j=0; j<second; j++) {
//       if(aArray[i] == bArray[j]) count++;
//     }
//   }

//   sum += first - count; count = 0;

//   for(int i=0; i<second; i++) {
//     for(int j=0; j<first; j++) {
//       if(bArray[i] == aArray[j]) count++;
//     }
//   }

//   sum += second - count; count = 0;

//   printf("%d", sum);
// }
