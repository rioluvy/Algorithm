import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
if n == 1:
  print(0)
  sys.exit()
relation = [[] for _ in range(n+1)]
visited = [False] * (n+1)
distance = [0] * (n+1)
diameter = 0
for i in range(1,n):
  a, b, weighted = map(int,input().split())
  relation[a].append((b,weighted))
  relation[b].append((a,weighted))

def BFS(e):
  queue = deque([])
  queue.append(e)
  while queue:
    (node) = queue.popleft()
    visited[node] = True
    for i in relation[node]:
      next_node = i[0]
      w = i[1]
      if not visited[next_node]:
        visited[next_node] = True
        distance[next_node] = distance[node] + w
        queue.append(next_node)
BFS(1)
for i in range(1,n+1):
  if diameter < distance[i]:
    diameter = distance[i]
    longest = i
visited = [False] * (n+1)
distance = [0] * (n+1)
BFS(longest)
print(max(distance))