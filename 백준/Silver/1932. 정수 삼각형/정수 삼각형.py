import sys
input = sys.stdin.readline
triangle = []
n = int(input())
for _ in range(n):
  triangle.append(list(map(int,input().split())))
maximum = []
for i in range(1, n+1):
  maximum.append([-1 for _ in range(i)])
maximum[0][0] = triangle[0][0]

for i in range(1, n):
  for j in range(i+1):
    if (j-1 > -1) and (j < i):
      maximum[i][j] = max(maximum[i-1][j-1],maximum[i-1][j]) + triangle[i][j]
    elif j >= i:
      maximum[i][j] = maximum[i-1][j-1] + triangle[i][j]
    elif j-1 <= -1:
      maximum[i][j] = maximum[i-1][j] + triangle[i][j]
print(max(maximum[n-1]))