import sys
import heapq
input = sys.stdin.readline
heap1 = []
heap2 = []
N = int(input())
for _ in range(N):
  num = int(input())
  if len(heap1) == len(heap2):
    heapq.heappush(heap1, -num)
  else:
    heapq.heappush(heap2,num)
  
  if heap1 and heap2 and -heap1[0] > heap2[0]:
    big = heapq.heappop(heap1)
    small = heapq.heappop(heap2)

    heapq.heappush(heap1,-small)
    heapq.heappush(heap2,-big)
  print(-heap1[0])