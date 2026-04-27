import sys
input = sys.stdin.readline
N = int(input())
dp = [0] * (N+1)

for i in range(N,0,-1):
  if dp[i-1] > dp[i] + 1 or dp[i-1] == 0:
    dp[i-1] = dp[i] + 1
  if (i % 3 == 0) and (dp[i//3] == 0 or dp[i//3] > dp[i]+1):
    dp[i//3] = dp[i] + 1
  if i % 2 == 0 and (dp[i//2] == 0 or dp[i//2] > dp[i]+1):
    dp[i//2] = dp[i] + 1
print(dp[1])