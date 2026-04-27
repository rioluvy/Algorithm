import sys
input = sys.stdin.readline
T = int(input())
dp = [1,2,4,7,13,24,44,81,149,274]
for _ in range(T):
  N = int(input())
  print(dp[N-1])