import sys
input = sys.stdin.readline
S = set()
T = int(input())
for _ in range(T):
  command = input().split()
  if len(command) == 1:
    if command[0] == 'all':
      S = set(i for i in range(1,21))
    else:
      S = set()
    continue
  comm, x = command[0], int(command[1])
  if comm == 'add':
    S.add(x)
  elif comm == 'remove':
    S.discard(x)
  elif comm == 'check':
    if x in S:
      print(1)
    else:
      print(0)
  elif comm == 'toggle':
    if x in S:
      S.discard(x)
    else:
      S.add(x)