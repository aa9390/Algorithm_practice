# 2007년 1월 1일 : MON.
# N월 M일은 무슨 요일인지?


a, b = input().split()
month = int(a)
day = int(b)
count = 0

dayArray = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
monthArray = [31,28,31,30,31,30,31,31,30,31,30,31]

for i in range(1,month) :
  count += monthArray[i-1]

print(dayArray[(count + day)%7])
