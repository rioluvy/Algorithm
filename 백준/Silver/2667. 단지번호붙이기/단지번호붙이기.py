import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
apartment = []
queue = deque([])
num_apart = []
visited = [[False for _ in range(N)] for _ in range(N)]

for _ in range(N):
  tmp = list(map(int, input().rstrip()))
  apartment.append(tmp)

dx = [1,0,-1,0]
dy = [0,1,0,-1]

def BFS(a,b):
  cnt = 1
  queue.append((a,b))
  visited[a][b] = True
  while queue:
    x,y = queue.popleft()
    for i in range(4):
      tmp_x = x + dx[i]
      tmp_y = y + dy[i]
      if tmp_x >= 0 and tmp_y >= 0 and tmp_x < N and tmp_y < N:
        if apartment[tmp_x][tmp_y] == 1 and not visited[tmp_x][tmp_y]:
          queue.append((tmp_x,tmp_y))
          visited[tmp_x][tmp_y] = True
          cnt += 1
  num_apart.append(cnt)

for i in range(N):
  for j in range(N):
    if apartment[i][j] == 1 and not visited[i][j]:
      BFS(i,j)
num_apart.sort()

print(len(num_apart))
for i in range(len(num_apart)):
  print(num_apart[i])
