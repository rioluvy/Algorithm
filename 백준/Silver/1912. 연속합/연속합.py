import sys
input = sys.stdin.readline
n = int(input())
sequence = list(map(int,input().split()))
maximum = sequence[0]
tmp = 0
for i in range(n):
  tmp += sequence[i]
  maximum = max(maximum,tmp)
  if tmp < 0:
    tmp = 0
print(maximum)