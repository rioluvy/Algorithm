import sys
n, k = map(int,sys.stdin.readline().split())
one_to_n = [i for i in range(1,n+1)]
idx = 0
print("<", end ="")
while len(one_to_n) != 1:
  idx += k-1
  if idx >= len(one_to_n):
    idx = idx % len(one_to_n)
  print(one_to_n.pop(idx), end = ", ")
print(*one_to_n, end = ">")