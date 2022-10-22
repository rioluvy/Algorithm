import sys
from collections import Counter
n = int(sys.stdin.readline())
num_list = [int(sys.stdin.readline().rstrip()) for _ in range(n)]
if len(num_list)==1:
  a = num_list[0]
  for _  in range(3):
    print(a)
  print(0)
else:
  print(round(sum(num_list)/len(num_list)))

  num_list.sort()
  print(num_list[len(num_list)//2])

  dic = Counter(num_list).most_common(2)
  if dic[0][1] == dic[1][1]:
    print(dic[1][0])
  else:
    print(dic[0][0])

  print(num_list[-1]-num_list[0])