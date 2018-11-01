#include <stdio.h>
#include <string.h>

int main() {
  int initNum;
  char cmd[14];
  int stack[100000];
  int inputNum;
  int top = -1;

  // 명령의 수 입력
  scanf("%d", &initNum);

  while(initNum--) {
    scanf("%s", cmd); 
    // push
    if(!strcmp(cmd, "push")) {
      scanf("%d", &inputNum);
      stack[++top] = inputNum;
    }
    // top
    if(!strcmp(cmd, "top")) {
      printf("%d\n", stack[top]);
    }
    // size
    if(!strcmp(cmd, "size")) {
      printf("%d\n", top+1);
    }
    // pop
    if(!strcmp(cmd, "pop")) {
      if(top!=-1){
        printf("%d\n",stack[top]);
        top--;
        }else{
          printf("%d\n",top);
          }
    }
    //empty
    if(!strcmp(cmd, "empty")) {
      if(top == -1) printf("%d\n", 1);
      else printf("%d\n", 0);
    }
  }
}
