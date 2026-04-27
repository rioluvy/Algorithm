import sys
input = sys.stdin.readline
N = int(input())
num = 0; cnt = 0
while num != N:
  if num == 0:
    num += 1
    cnt += 1
  else:
    if num * 2 < N:
      num *= 2
      cnt += 1
    else:
      num += (N-num)
      cnt += 1
print(cnt)