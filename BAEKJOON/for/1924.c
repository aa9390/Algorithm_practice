#include <stdio.h>

int main(void) {
    int month, day, count = 0;
    int monthArray[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char dayArray[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    scanf("%d %d", &month, &day);

    for(int i=1; i<month; i++) {
      count += monthArray[i-1];
    }
    count += day;
    printf("%s", dayArray[count%7]);
}