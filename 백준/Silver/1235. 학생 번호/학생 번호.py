import sys
input=sys.stdin.readline
n=int(input())
a=[]
for i in range(n):
  a.append(input().strip())
l=len(a[0])
for i in range(l-1,-1,-1):
  s=set()
  for j in a:
    s.add(j[i:])
  if len(s)==n:
    print(l-i)
    break