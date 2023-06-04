import sys
import heapq
input = sys.stdin.readline
n = int(input())
assignment = []
heap = []
score = 0
for _ in range(n):
  d, w = map(int,input().split())
  assignment.append((d,w))
assignment.sort(key = lambda x : (x[0],-x[1]))
day = 1
(d, w) = assignment.pop(0)
score += w
heapq.heappush(heap,w)
for i in range(len(assignment)):
  (d,w) = assignment.pop(0)
  if day < d:
    heapq.heappush(heap,w)
    score += w
  elif day == d:
    day -= 1
    if w > heap[0]:
      score += (w - heap[0])
      heapq.heappop(heap)
      heapq.heappush(heap,w)
  day += 1
print(score)