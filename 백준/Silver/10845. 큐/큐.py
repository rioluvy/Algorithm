import sys
from collections import deque
N = int(sys.stdin.readline())
dq = deque([])
for _ in range(N):
  q = sys.stdin.readline().rstrip().split()
  if q[0] == 'push':
    dq.append(q[1])
  if q[0] == 'pop':
    if dq == deque([]):
      print(-1)
    else:
      a = dq.popleft()
      print(a)
  if q[0] == 'size':
    print(len(dq))
  if q[0] == 'empty':
    if dq == deque([]):
      print(1)
    else:
      print(0)
  if q[0] == 'front':
    if dq == deque([]):
      print(-1)
    else:
      dq.appendleft(dq[0])
      a = dq.popleft()
      print(a)
  if q[0] == 'back':
    if dq == deque([]):
      print(-1)
    else:
      dq.append(dq[(len(dq)-1)])
      a = dq.pop()
      print(a)
