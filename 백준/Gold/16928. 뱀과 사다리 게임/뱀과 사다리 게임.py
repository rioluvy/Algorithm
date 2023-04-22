import sys
from collections import deque
input = sys.stdin.readline
N, M = map(int,input().split())
ladder = {}
snake = {}
for _ in range(N):
  x, y = map(int,input().split())
  ladder[x] = y
for _ in range(M):
  u, v = map(int,input().split())
  snake[u] = v
visited = [False] * 101
visited[1] = True
map = [0] * 101

def BFS(e):
  queue = deque([])
  queue.append(e)
  while queue:
    now_pos = queue.popleft()
    for i in range(1,7):
      tmp_pos = now_pos + i
      if tmp_pos == 100:
        return map[now_pos] + 1
      
      if tmp_pos in ladder:
        tmp_pos = ladder[tmp_pos]
      elif tmp_pos in snake:
        tmp_pos = snake[tmp_pos]
      if not visited[tmp_pos]:
        visited[tmp_pos] = True
        map[tmp_pos] = map[now_pos] + 1
        queue.append(tmp_pos)

print(BFS(1))