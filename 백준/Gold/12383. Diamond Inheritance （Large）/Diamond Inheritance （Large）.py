import sys
from collections import deque
input = sys.stdin.readline

def BFS(e):
  global Diamond
  queue = deque([])
  queue.append(e)
  while queue:
    tmp = queue.popleft()
    for i in inheritance[tmp]:
      if not visited[i]:
        visited[i] = True
        queue.append(i)
      else:
        Diamond = True
        return


T = int(input())
for tc in range(1,T+1):
  Diamond = False
  class_cnt = int(input())
  inheritance = [[] for _ in range(class_cnt+1)]
  for i in range(1,class_cnt+1):
    tmp = list(map(int,input().split()))
    num = tmp[0]
    if num != 0:
      for j in range(1,num+1):
        inheritance[i].append(tmp[j])

  for i in range(1,class_cnt):
    visited = [False for _ in range(class_cnt+1)]
    BFS(i)
    if Diamond:
      print('Case #{0}: Yes'.format(tc))
      break
  else:
    print('Case #{0}: No'.format(tc))