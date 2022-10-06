import sys
N = int(sys.stdin.readline())
join = [sys.stdin.readline().split() for _ in range(N)]
join.sort(key=lambda x:int(x[0]))
data = []
for i in join:
  for j in i:
    data.append(j)
  print(data[0], data[1])
  data = []