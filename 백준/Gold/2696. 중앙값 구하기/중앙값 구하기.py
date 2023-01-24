import sys
import heapq
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  heapleft = []
  heapright = []
  mid = []
  M = int(input())
  sequence = list(map(int,input().split()))
  for i in range(M//10):
    sequence += list(map(int,input().split()))
  for i in range(len(sequence)):
    if len(heapleft) == len(heapright):
      heapq.heappush(heapleft, -sequence[i])
    else:
      heapq.heappush(heapright, sequence[i])

    if heapright and -heapleft[0] > heapright[0]:
      big = heapq.heappop(heapleft)
      small = heapq.heappop(heapright)
      heapq.heappush(heapleft, -small)
      heapq.heappush(heapright, -big)

    if (i+1)%2 == 1:
      mid.append(-heapleft[0])

  
  length = len(mid)
  if length > 10:
    start = 0
    end = 10
    print(length)
    for i in range(length//10):
      print(*mid[start:end])
      start += 10
      end += 10
    else:
      print(*mid[start:])
  else:
    print(length)
    print(*mid)