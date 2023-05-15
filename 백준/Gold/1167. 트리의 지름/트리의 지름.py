import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
tree = [[] for _ in range(n+1)]
diameter = 0
distance = [0] * (n+1)
visited = [False] * (n+1)
for _ in range(n):
  info = list(map(int,input().split()))
  idx = 0
  node = info[idx]
  idx += 1
  while info[idx] != -1:
    tmp_node = info[idx]; tmp_weight = info[idx+1]
    tree[node].append((tmp_node,tmp_weight))
    idx += 2

def BFS(v):
  queue = deque([])
  queue.append(v)
  visited[v] = True
  while queue:
    node = queue.popleft()
    for i in tree[node]:
      n,w = i
      if not visited[n]:
        visited[n] = True
        distance[n] = distance[node] + w
        queue.append(n)
BFS(1)

for i in range(1,n+1):
  if diameter < distance[i]:
    diameter = distance[i]
    longest = i
distance = [0] * (n+1)
visited = [False] * (n+1)
BFS(longest)
tmp = max(distance)
if diameter < tmp:
  diameter = tmp
print(diameter)