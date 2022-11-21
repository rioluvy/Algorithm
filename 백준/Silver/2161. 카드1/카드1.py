import sys
from collections import deque
deck = deque()
throw = []
n = int(sys.stdin.readline())
for i in range(n): ##1~n까지의 카드 덱 생성
  deck.append(i+1)
while len(deck)>1:
  throw.append(deck.popleft())
  deck.append(deck.popleft())
print(*throw, *deck)