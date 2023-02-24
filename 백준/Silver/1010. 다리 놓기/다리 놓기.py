import sys
import math
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  r, n = map(int, input().split())
  result = math.factorial(n)/(math.factorial(r)*math.factorial(n-r))
  print(int(result))