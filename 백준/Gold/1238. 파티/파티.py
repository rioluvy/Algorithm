import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize
N, M, X = map(int,input().split())
adj = [[] for _ in range(N+1)]
for _ in range(M):
  s, e, t = map(int,input().split())
  adj[s].append((e,t))

def dijkstra(start, X):
  queue = []
  heapq.heappush(queue,(0,start))
  distList = [INF] * (N+1)
  visited = [False] * (N+1)
  distList[start] = 0
  while queue:
    (pathLength, node) = heapq.heappop(queue)
    if visited[node]:
      continue
    visited[node] = True
    for i in adj[node]:
      distance = pathLength + i[1]
      if distList[i[0]] > distance:
        distList[i[0]] = distance
        heapq.heappush(queue,(distance, i[0]))
  return distList[X]

ans = 0
for i in range(1,N+1):
  go = dijkstra(i,X)
  comeBack = dijkstra(X,i)
  time = go + comeBack
  if ans < time:
    ans = time
print(ans)