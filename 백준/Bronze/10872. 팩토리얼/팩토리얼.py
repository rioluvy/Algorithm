import sys

N = int(sys.stdin.readline())
start = 1
for i in range(1,N+1):
  start = start * i
print(start)