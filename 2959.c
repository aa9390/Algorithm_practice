// #2959. 거북이.
// 그림을 그려본 결과...(공책에 그렸음ㅠㅠ)
// a b c d 꼴에서, 
// a = 제일 큰 수
// b = 제일 작은 수 
// c = 남은 수 중 큰 수 
// d = 남은 수
// 로 배열 후
// 해당 직사각형의 넓이는 b * c 이다. 

// 위 알고리즘 생각한 시간? 대략 20분?

#include <stdio.h>

int main(void) {
  int numArray[4];
  int max = -1;
  int min = 101; 
  int temp;
  int count;

  // a, b, c, d 입력받음. 
  scanf("%d %d %d %d", &numArray[0], &numArray[1], &numArray[2], &numArray[3]);

  // 순서대로 정렬. 
  // 제일 큰 수 찾기
  for(int i = 0; i<4; i++) {
    if(numArray[i] > max) {
      count = i;
      max = numArray[i];
    }
  }

  temp = numArray[count];
  numArray[count] = numArray[0];
  numArray[0] = max;


  // 제일 작은 수 찾기
  for(int i = 1; i<4; i++) {
    if(numArray[i] < min) {
      count = i;
      min = numArray[i];
    }
  }

  temp = numArray[count];
  numArray[count] = numArray[1];
  numArray[1] = min;

  // 남은 수 중 큰 수 
  if(numArray[2] < numArray[3]) {
    int temp = numArray[2];
    numArray[2] = numArray[3];
    numArray[3] = temp;
  }

 // 결과 출력
  printf("%d", numArray[1] * numArray[2]);
}
