import sys
from collections import deque
input = sys.stdin.readline
N, K = map(int,input().split())
queue = deque([])
map = [0]*100001

if N == K:
  print(0)
  sys.exit()
  
def BFS(v):
  queue.append(v)
  while queue:
    temp = queue.popleft()
    way_1 = temp + 1
    way_2 = temp - 1
    way_3 = temp * 2
    if way_1 >= 0 and way_1 <= 100000 and map[way_1] == 0:
      queue.append(way_1)
      map[way_1] = map[temp] + 1
    if way_2 >= 0 and way_2 <= 100000 and map[way_2] == 0:
      queue.append(way_2)
      map[way_2] = map[temp] + 1
    if way_3 >= 0 and way_3 <= 100000 and map[way_3] == 0:
      queue.append(way_3)
      map[way_3] = map[temp] + 1
    if map[K] != 0:
      break
  print(map[K])
BFS(N)