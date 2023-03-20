import sys
input = sys.stdin.readline
T = int(input())
dp = [0] * 101
dp[1] = 1
dp[2] = 1
dp[3] = 1
dp[4] = 2
dp[5] = 2

for _ in range(T):
  N = int(input())
  if N <= 5:
    print(dp[N])
    continue
  else:
    for i in range(6,N+1):
      dp[i] = dp[i-3] + dp[i-2]
    print(dp[N])