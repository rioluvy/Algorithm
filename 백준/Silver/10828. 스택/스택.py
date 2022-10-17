from collections import deque
import sys
N = int(sys.stdin.readline())
dq = deque([])
for _ in range(N):
  a = sys.stdin.readline().rstrip().split()
  if a[0] == 'push':
    dq.append(a[1])
  if a[0] == 'pop':
    if dq != deque([]):
      b = dq.pop()
      print(b)
    else:
      print(-1)
  if a[0] == 'size':
    print(len(dq))
  if a[0] == 'empty':
    if dq == deque([]):
      print(1)
    else:
      print(0)
  if a[0] == 'top':
    if dq == deque([]):
      print(-1)
    else:
      c = dq.pop()
      dq.append(c)
      print(c)