X = int(input())
N = int(input())
total = []
for _ in range(N):
  a, b = map(int,input().split())
  total.append(a*b)
if sum(total) == X:
  print("Yes")
else:
  print("No")