import sys
import heapq
input = sys.stdin.readline
N = int(input())
snow = list(map(int,input().split()))
heap = []
time = 0
def max_heap():
  for i in snow:
    heapq.heappush(heap,(-i))

def clean():
  global time
  while len(heap) > 1:
    tmp1 = heapq.heappop(heap)
    tmp2 = heapq.heappop(heap)
    tmp1 += 1; tmp2 += 1
    if tmp1 != 0:
      heapq.heappush(heap, tmp1)
    if tmp2 != 0:
      heapq.heappush(heap, tmp2)
    time += 1
  if heap:
    time += -heap[0]
    return

if __name__ == "__main__":
  max_heap()
  clean()
  if time > 1440:
    time = -1
  print(time)