import sys
from heapq import heappush, heappop

def Sol():
  input = sys.stdin.readline
  abs_heap = []
  N = int(input())
  for _ in range(N):
    x = int(input())
    if x != 0:
      heappush(abs_heap, (abs(x), x))
    else:
      if abs_heap == []:
        print(0)
      else:
        print(heappop(abs_heap)[1])
  
if __name__ == "__main__":
  Sol()