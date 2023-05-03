import sys
from collections import deque
input = sys.stdin.readline
dx = [1,0,-1,0,1,-1,1,-1]
dy = [0,1,0,-1,-1,1,1,-1]

def BFS(i,j):
  queue = deque([])
  queue.append((i,j))
  while queue:
    (x,y) = queue.popleft()
    for i in range(8):
      tmp_x = x + dx[i]
      tmp_y = y + dy[i]
      if 0 <= tmp_x < h and 0 <= tmp_y < w:
        if not visited[tmp_x][tmp_y] and island[tmp_x][tmp_y] == 1:
          queue.append((tmp_x,tmp_y))
          visited[tmp_x][tmp_y] = True

while True:
  w, h = map(int,input().split())
  if w == 0 and h == 0:
    sys.exit()
  island = []
  for _ in range(h):
    island.append(list(map(int,input().split())))
  visited = [[False for _ in range(w)] for _ in range(h)]
  cnt = 0

  for i in range(h):
    for j in range(w):
      if island[i][j] == 1 and not visited[i][j]:
        visited[i][j] = True
        BFS(i,j)
        cnt += 1
  print(cnt)