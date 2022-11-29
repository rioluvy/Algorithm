import sys
n, m = map(int,sys.stdin.readline().split())
listen = set()
see = set()
for _ in range(n):
  listen.add(sys.stdin.readline())
for _ in range(m):
  see.add(sys.stdin.readline())
not_listen_not_see = list(listen.intersection(see))
not_listen_not_see.sort()
print(len(not_listen_not_see))
for i in not_listen_not_see:
  print(i, end="")