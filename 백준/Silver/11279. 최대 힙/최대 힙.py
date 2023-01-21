import sys
from heapq import heappop, heappush
input = sys.stdin.readline
heap = []
N = int(input())

for _ in range(N):
  num = int(input())
  if num != 0:
    heappush(heap, (-num,num))
  else:
    if heap == []:
      print(0)
    else:
      print(heappop(heap)[1])