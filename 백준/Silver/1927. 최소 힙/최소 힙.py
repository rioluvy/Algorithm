import sys
import heapq
input = sys.stdin.readline
heap = []
N = int(input())

for i in range(N):
  num = int(input())
  if num != 0:
    heapq.heappush(heap, num)
  else:
    if heap == []:
      print(0)
    else:
      print(heapq.heappop(heap))