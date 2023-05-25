import sys
from queue import PriorityQueue
input = sys.stdin.readline
N, E = map(int,input().split())
adj = [[] for _ in range(N+1)]
for i in range(E):
  a, b, c = map(int,input().split())
  adj[a].append((b,c))
  adj[b].append((a,c))
v1, v2 = map(int,input().split())

def Dijkstra(start, end):
  disList = [sys.maxsize] * (N+1)
  visited = [False] * (N+1)
  disList[start] = 0
  queue = PriorityQueue()
  queue.put((0,start))
  while queue.qsize() != 0:
    (pathLength, node) = queue.get()
    if visited[node]:
      continue
    visited[node] = True
    for i in adj[node]:
      dist = pathLength + i[1]
      if dist < disList[i[0]]:
        disList[i[0]] = dist
        queue.put((dist, i[0]))
  if not visited[end]:
    print(-1)
    sys.exit()
  return disList[end]

ans1 = Dijkstra(1,v1) + Dijkstra(v1, v2) + Dijkstra(v2, N)
ans2 = Dijkstra(1,v2) + Dijkstra(v2,v1) + Dijkstra(v1,N)
print(min(ans1, ans2))