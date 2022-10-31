import sys
n =list(map(int,sys.stdin.readline().split()))
n.sort()
a = []
for i in range(2):
  a.append(n[i+1]-n[i])
d = min(a)
if n[1]-n[0] > n[2]-n[1]:
  print(n[0]+d)
elif n[1]-n[0] < n[2]-n[1]:
  print(n[1]+d)
else:
  print(n[2]+d)