import sys
import heapq
input = sys.stdin.readline
n = int(input())
time = []
for _ in range(n):
  time.append(tuple(map(int,input().split())))
time.sort()
heap = []; heapq.heappush(heap,0)
for (start,end) in time:
  tmp = heapq.heappop(heap)
  if tmp <= start:
    heapq.heappush(heap,end)
  else:
    heapq.heappush(heap,tmp)
    heapq.heappush(heap,end)
print(len(heap))