N, X = map(int,input().split())
S = input().split()
for i in S:
  if X>int(i):
    print(int(i), end=' ')