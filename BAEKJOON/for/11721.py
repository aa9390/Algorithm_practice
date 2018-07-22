a = input()

# 문자의 개수가 10개인지 판별하기 위함 
count = 0

for i in range(len(a)) :
  print(a[i],end='')
  count = count + 1
  if(count % 10 == 0) : print()
