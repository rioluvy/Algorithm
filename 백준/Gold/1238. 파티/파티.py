import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize
N, M, X = map(int,input().split())
adj_go = [[] for _ in range(N+1)]
adj_back = [[] for _ in range(N+1)]
for _ in range(M):
  s, e, t = map(int,input().split())
  adj_go[s].append((e,t))
  adj_back[e].append((s,t))


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

dist_go = dijkstra(X,adj_go)
dist_back = dijkstra(X,adj_back)
ans = 0
for i in range(len(dist_go)):
  ans = max(dist_go[i] + dist_back[i],ans)
print(ans)