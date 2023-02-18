import sys
from collections import deque
input = sys.stdin.readline
M, N = map(int, input().split())
queue = deque([])
tomato = []
for _ in range(N):
  tomato.append(list(map(int, input().split())))

for i in range(N):
  for j in range(M):
    if tomato[i][j] == 1:
      queue.append((i,j))

dx = [0,1,0,-1]
dy = [1,0,-1,0]

def BFS():
  while queue:
    (a, b) = queue.popleft()
    for i in range(4):
      temp_a = a + dx[i]
      temp_b = b + dy[i]
      if temp_a >= 0 and temp_b >= 0 and temp_a <= N-1 and temp_b <= M-1:
        if tomato[temp_a][temp_b] == 0:
          queue.append((temp_a,temp_b))
          tomato[temp_a][temp_b] = tomato[a][b] + 1

BFS()
day = 1
for i in range(N):
  for j in range(M):
    if tomato[i][j] == 0:
      print(-1)
      sys.exit()
    temp = tomato[i][j]
    day = max(day, temp)
print(day-1)