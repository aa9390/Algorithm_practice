// #1269 - 대칭 차집합
#include <iostream>
#include <set>
using namespace std;

set<int> a;
int n, m;

int main() {
    // 집합의 원소 개수 입력받음
    scanf(" %d %d", &n, &m);
    
    // x 변수는 for문 내부에 선언 후 입력받은 x를 집합에 삽입.
    for (int i = 0; i < n; i++) {
        int x; scanf(" %d", &x);
        a.insert(x);
    }
    
    // 중복 제거
    // 입력받은 x가 집합에 존재하면 (a.count(x) >= 1일 경우) 삭제. -> 입력 받지 않는것과 동일
    // 존재하지 않으면 삽입. 
    for (int i = 0; i < m; i++) {
        int x; scanf(" %d", &x);
        if (a.count(x)) a.erase(x);
        else a.insert(x);
    }
    
    // 중복된 원소가 없는 집합 a의 원소 개수는 즉, 대칭 차집합의 원소 개수. 
    printf("%d\n", a.size());
}

// ---------------- 시간초과된 c로 작성된 코드 -------------------------
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
