import sys
from collections import deque
input = sys.stdin.readline
N = deque(map(int,input().rstrip()))

idx = -1
for i in range(len(N)):
  if N[idx] >= 5:
    if -idx < len(N):
      N[idx-1] += 1
    else:
      N.appendleft(1)
    for j in range(1,-idx+1):
      N[-j] = 0
  idx -= 1
print(*N, sep ="")