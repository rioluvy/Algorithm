import sys
from collections import deque
input = sys.stdin.readline
M, N, H = map(int, input().split())
tomato = []
temp = []
day = 1
queue = deque([])

## 토마토 3차원 배열
for _ in range(H):
  for _ in range(N):
    temp.append(list(map(int,input().split())))
  tomato.append(temp)
  temp = []

## 처음부터 익어있는 토마토
for i in range(H):
  for j in range(N):
    for k in range(M):
      if tomato[i][j][k] == 1:
        queue.append((i,j,k))

## 좌표 탐색을 위한 리스트
dx = [1,-1,0,0,0,0]
dy = [0,0,1,-1,0,0]
dz = [0,0,0,0,1,-1]

def BFS():
  while queue:
    (z, y, x) = queue.popleft()
    for i in range(6):
      temp_z = z + dz[i]
      temp_y = y + dy[i]
      temp_x = x + dx[i]
      if temp_x >= 0 and temp_y >= 0 and temp_z >= 0 and temp_x < M and temp_y < N and temp_z < H:
        if tomato[temp_z][temp_y][temp_x] == 0:
          tomato[temp_z][temp_y][temp_x] = tomato[z][y][x] + 1
          queue.append((temp_z, temp_y, temp_x))

BFS()
for i in range(H):
  for j in range(N):
    for k in range(M):
      if tomato[i][j][k] == 0:
        print(-1)
        sys.exit()
      day = max(day, tomato[i][j][k])
print(day-1)