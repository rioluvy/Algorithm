M = int(input())
color = list(map(int,input().split()))
K = int(input())
num = sum(color)
ans = 0

for i in range(M):
  if color[i] >= K:
    tmp = 1
    tmp2 = color[i]
    for j in range(K):
      tmp = tmp * (tmp2-j) / (num-j)
    ans += tmp
print(ans)