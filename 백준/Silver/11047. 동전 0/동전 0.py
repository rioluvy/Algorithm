import sys
input = sys.stdin.readline
N, K = map(int, input().split())
coin = []
for _ in range(N):
  coin.append(int(input()))

num = 0

for i in range(N-1,-1,-1):
  num +=  K // coin[i]
  K %= coin[i]
print(num)