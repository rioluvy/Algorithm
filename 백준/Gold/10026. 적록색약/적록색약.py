import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
RGB = []
RGB_map = []
red_green = 0
cnt = 0
for _ in range(N):
  color = list(input().rstrip())
  RGB.append(color)

for _ in range(N):
  RGB_map.append([0]*N)

dx = [1,0,-1,0]
dy = [0,1,0,-1]

def BFS(x,y):
  queue = deque([])
  queue.append((x,y))
  while queue:
    (x,y) = queue.popleft()
    for i in range(4):
      tmp_x = x + dx[i]
      tmp_y = y + dy[i]
      if tmp_x >= 0 and tmp_y >= 0 and tmp_x <= N-1 and tmp_y <= N-1:
        if RGB_map[tmp_x][tmp_y] == 0 and RGB[tmp_x][tmp_y] == RGB[x][y]:
          RGB_map[tmp_x][tmp_y] = 1
          queue.append((tmp_x,tmp_y))
for i in range(N):
  for j in range(N):
    if RGB_map[i][j] == 0:
      RGB_map[i][j] = 1
      BFS(i,j)
      cnt += 1
print(cnt, end = " ")

###################################################################

RGB_map = []
for _ in range(N):
  RGB_map.append([0]*N)
cnt = 0

def BFS_1(x,y):
  global red_green
  queue = deque([])
  queue.append((x,y))
  while queue:
    (x,y) = queue.popleft()
    if RGB[x][y] == 'R' or RGB[x][y] == 'G':
      red_green = 1
    else:
      red_green = 0
    for i in range(4):
      tmp_x = x + dx[i]
      tmp_y = y + dy[i]
      if tmp_x >= 0 and tmp_y >= 0 and tmp_x <= N-1 and tmp_y <= N-1:
        if RGB_map[tmp_x][tmp_y] == 0 and RGB[tmp_x][tmp_y] == RGB[x][y]:
          RGB_map[tmp_x][tmp_y] = 1
          queue.append((tmp_x,tmp_y))
        elif RGB_map[tmp_x][tmp_y] == 0 and red_green and  (RGB[tmp_x][tmp_y] == 'R' or RGB[tmp_x][tmp_y] == 'G'):
          RGB_map[tmp_x][tmp_y] = 1
          queue.append((tmp_x,tmp_y))

for i in range(N):
  for j in range(N):
    if RGB_map[i][j] == 0:
      RGB_map[i][j] = 1
      BFS_1(i,j)
      cnt += 1
print(cnt, end = " ")