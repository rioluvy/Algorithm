import sys
from math import factorial
input = sys.stdin.readline
n = int(input())
straw = []
for _ in range(n):
    straw.append(int(input()))
straw.sort(reverse=True)
for i in range(n-2):
    if straw[i] < straw[i+1] + straw[i+2]:
        print(straw[i] + straw[i+1] + straw[i+2])
        break
else:
    print(-1)