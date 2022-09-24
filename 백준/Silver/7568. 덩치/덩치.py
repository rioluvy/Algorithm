N = int(input())
a=[]
rank=1
for i in range(N):
  k = list(map(int, input().split()))
  b=[]
  for j in k:
    b.append(j)
  a.append(b)
for l in range(N):
  for s in range(N):
    if a[l][0] < a[s][0] and a[l][1] < a[s][1]:
      rank += 1
  print(rank, end = ' ')
  rank = 1