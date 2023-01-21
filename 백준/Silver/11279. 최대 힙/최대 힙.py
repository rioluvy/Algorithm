import sys
from heapq import heappop, heappush

def Sol():
  input = sys.stdin.readline
  heap = []
  N = int(input())
  for _ in range(N):
    num = int(input())
    if num != 0:
      heappush(heap, (-num))
    else:
      if heap == []:
        print(0)
      else:
        print(-heappop(heap))

if __name__ == "__main__":
  Sol()