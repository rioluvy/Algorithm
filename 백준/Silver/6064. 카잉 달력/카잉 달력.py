import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  M, N, x, y = map(int,input().split())
  ans = x
  for i in range(ans,M*N+1,M):
    if (i - x) % M == 0 and (i - y) % N == 0:
      print(i)
      break
  else:
    print(-1)