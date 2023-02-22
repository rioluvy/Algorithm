import sys
import heapq
input = sys.stdin.readline

def Sol():
  N = int(input())
  Card = []

  for _ in range(N):
    heapq.heappush(Card, int(input()))

  total = 0
  cnt = 0
  while len(Card) > 1:
    c1, c2 = heapq.heappop(Card), heapq.heappop(Card)
    cnt = c1 + c2
    total += cnt
    heapq.heappush(Card,cnt)
  print(total)

if __name__ == "__main__":
  Sol()