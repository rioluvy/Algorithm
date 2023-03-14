import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
N = int(input())
dp = [0] * 1001
dp[1] = 1
dp[2] = 2

def fibonacci(n):
  if dp[n] != 0:
    return dp[n]
  if n == 1:
    return 1
  if n == 2:
    return 2
  else:
    tmp = fibonacci(n-1) + fibonacci(n-2)
    dp[n] = tmp
    return tmp
print(fibonacci(N)%10007)