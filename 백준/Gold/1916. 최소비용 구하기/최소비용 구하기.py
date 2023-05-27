import sys
import heapq
INF = int(1e9)
input = sys.stdin.readline
N = int(input())
M = int(input())
adj = [[] for _ in range(N+1)]
for _ in range(M):
  depart, arrive, cost = map(int,input().split())
  adj[depart].append((arrive,cost))
start, end = map(int,input().split())

def dijkstra(start, adj, end):
  queue = []
  heapq.heappush(queue,(0,start))
  distList = [INF] * (N+1)
  distList[start] = 0
  while queue:
    pathLength, node = heapq.heappop(queue)
    if pathLength > distList[node]: continue
    for i in adj[node]:
      distance = pathLength + i[1]
      if distance < distList[i[0]]:
        distList[i[0]] = distance
        heapq.heappush(queue,(distance, i[0]))
  return distList[end]

print(dijkstra(start, adj, end))