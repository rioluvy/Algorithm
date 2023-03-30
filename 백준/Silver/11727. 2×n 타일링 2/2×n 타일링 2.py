import sys
input = sys.stdin.readline
n = int(input())
dp = [0]*(n+1)
dp[1] = 1
if n >= 2:
  dp[2] = 3
def sol(n):
  if dp[n] != 0:
    return dp[n]

  if n == 1:
    return 1
  elif n == 2:
    return 3
  else:
    dp[n] = sol(n-1) + 2*sol(n-2)
    return dp[n]
sol(n)
print(dp[n] % 10007, end = "")