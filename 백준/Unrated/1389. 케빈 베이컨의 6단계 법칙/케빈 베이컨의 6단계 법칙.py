import sys
from collections import deque
input = sys.stdin.readline
N, M = map(int,input().split())
friends = [[] for _ in range(N+1)]

## 친구 리스트 생성
for _ in range(M):
  a, b = map(int,input().split())
  friends[a].append(b)
  friends[b].append(a)

def BFS(step,e):
  queue = deque([])
  queue.append((step,e))
  while queue:
    (tmp_step,tmp) = queue.popleft()
    for i in friends[tmp]:
      if not visited[i]:
        visited[i] = True
        queue.append((tmp_step+1,i))
        KB_num[i].append(tmp_step+1)
  KB = 0
  for i in range(1, N+1):
    try:
      KB += KB_num[i][0]
    except:
      pass
  return KB

total = []
for i in range(1,N+1):
  visited = [False for _ in range(N+1)]
  KB_num = [[] for _ in range(N+1)]
  visited[i] = True
  total.append((BFS(0,i),i))
total.sort()
print(total[0][1])