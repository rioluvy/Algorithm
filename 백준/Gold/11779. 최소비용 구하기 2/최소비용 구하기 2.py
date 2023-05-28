import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)
n = int(input())
m = int(input())
adj = [[] for _ in range(n+1)]
for _ in range(m):
  depart, arrive, cost = map(int,input().split())
  adj[depart].append((arrive,cost))
start, end = map(int,input().split())

def dijkstra(start):
  route = [[] for _ in range(n+1)]
  queue = []
  heapq.heappush(queue,(0,start,[start]))
  distList = [INF] * (n+1)
  distList[start] = 0
  while queue:
    pathLength, node, path = heapq.heappop(queue)
    if pathLength > distList[node]:
      continue
    for i in adj[node]:
      distance = pathLength + i[1]
      if distance < distList[i[0]]:
        distList[i[0]] = distance
        route[i[0]] = path + [i[0]]
        heapq.heappush(queue,(distance, i[0], route[i[0]]))
  return route, distList
route, cost = dijkstra(start)
print(cost[end])
print(len(route[end]))
print(*route[end])