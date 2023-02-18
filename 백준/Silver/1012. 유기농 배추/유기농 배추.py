import sys
from collections import deque
input = sys.stdin.readline
T = int(input())

dx = [0,1,0,-1]
dy = [1,0,-1,0]

def BFS(x,y):
  queue.append((x,y))
  visited[x][y] = True
  while queue:
    (a, b) = queue.popleft()
    for i in range(4):
      temp_a = a + dx[i]
      temp_b = b + dy[i]
      if temp_a >= 0 and temp_b >= 0 and temp_a <= M-1 and temp_b <= N-1:
        if farm[temp_a][temp_b] == 1 and not visited[temp_a][temp_b]:
          visited[temp_a][temp_b] = True
          queue.append((temp_a, temp_b))

for _ in range(T):
  M, N, pos = map(int,input().split())
  queue = deque([])
  visited = [[False for _ in range(N)] for _ in range(M)]
  farm = [[0 for _ in range(N)] for _ in range(M)]
  count = 0
  for _ in range(pos):
    x, y = map(int,input().split())
    farm[x][y] = 1
  
  for i in range(M):
    for j in range(N):
      if farm[i][j] == 1 and not visited[i][j]:
        BFS(i,j)
        count += 1
  print(count)