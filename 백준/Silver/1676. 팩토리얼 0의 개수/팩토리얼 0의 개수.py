import sys
import math
input = sys.stdin.readline
fac = list(map(int, str(math.factorial(int(input())))))
fac.reverse()
cnt_0 = 0

for i in range(len(fac)):
  if fac[i] != 0:
    print(cnt_0)
    break
  else:
    cnt_0 += 1
else:
  print(cnt_0)