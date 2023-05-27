import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize
N, M= map(int,input().split())
start_node = int(input())
adj = [[] for _ in range(N+1)]
for _ in range(M):
  s, e, t = map(int,input().split())
  adj[s].append((e,t))


def dijkstra(start, graph):
  queue = []
  heapq.heappush(queue,(0,start))
  distList = [INF] * (N+1)
  distList[start] = 0
  while queue:
    (pathLength, node) = heapq.heappop(queue)
    if pathLength > distList[node]: continue
    for i in graph[node]:
      distance = pathLength + i[1]
      if distList[i[0]] > distance:
        distList[i[0]] = distance
        heapq.heappush(queue,(distance, i[0]))
  return distList[1:]

dist = dijkstra(start_node,adj)
for i in dist:
  if i == INF:
    i = 'INF'
  print(i)