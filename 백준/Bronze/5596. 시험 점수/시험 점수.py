import sys
s = list(map(int,sys.stdin.readline().split()))
t = list(map(int,sys.stdin.readline().split()))
if sum(s)>=sum(t):
  print(sum(s))
else:
  print(sum(t))