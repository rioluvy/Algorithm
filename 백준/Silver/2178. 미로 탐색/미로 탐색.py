import sys
from collections import deque
input = sys.stdin.readline
N,M = map(int,input().split())
visited = [[False]*M for _ in range(N)]
queue = deque([])
depth_map = [[0]*M for _ in range(N)]
depth_map[0][0] = 1
maze = []
for _ in range(N):
    maze.append(list(map(int,input().rstrip())))

Cross_x = [1,-1,0,0]
Cross_y = [0,0,1,-1]

def BFS(a,b):
    global depth
    queue.append((a,b))
    visited[a][b] = True
    while queue:
        (a, b) = queue.popleft()
        for i in range(4):
            x = a + Cross_x[i]
            y = b + Cross_y[i]
            if x >= 0 and y >= 0 and x <= N-1 and y <= M-1 and maze[x][y] == 1:
                if not visited[x][y]:
                    queue.append((x,y))
                    visited[x][y] = True
                    depth_map[x][y] = depth_map[a][b] + 1
                    if x == N-1 and y == M-1:
                      return 
BFS(0,0)
print(depth_map[N-1][M-1])