import sys
N = int(input())
a = []
string = [sys.stdin.readline().rstrip() for _ in range(N)]
for i in string:
  if i not in a:
    a.append(i)
S = sorted(a, key=lambda x: (x[0],x))
S.sort(key=len)
for j in S:
  print(j)