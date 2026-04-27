import sys
input = sys.stdin.readline
remainder = 0
N, K = map(int,input().split())
for i in range(1,N+1):
  exp = len(str(i))
  remainder = (remainder*10**exp+i) % K
print(remainder)