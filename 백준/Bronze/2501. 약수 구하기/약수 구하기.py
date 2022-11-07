import sys
n,k = map(int, sys.stdin.readline().split())
a = []

for i in range(1,n+1):
  if n%i ==0:
    a.append(i)

if k > len(a):
  print(0)
else:
  a.sort()
  print(a[k-1])