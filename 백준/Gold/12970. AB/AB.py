import sys
input = sys.stdin.readline
N, K = map(int,input().split())
if (N // 2) * (N - N//2) < K:
  print(-1)

for i in range(1,N//2+1):
  A = i; B = N-A
  if A * B >= K:
    s = 'A' * (A-1) + 'B' * (B+1)
    if (A-1) != 0:
      K -= (A-1) * (B+1) - (A-1)
    else:
      K -= (A-1) * (B+1)
    s = list(s)
    s[-K-1] = 'A'
    print(*s,sep = "")
    break