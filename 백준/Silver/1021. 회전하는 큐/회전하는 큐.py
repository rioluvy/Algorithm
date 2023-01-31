import sys
from collections import deque
input = sys.stdin.readline
def Sol():
  N, M = map(int,input().split())
  sequence = list(map(int,input().split()))  ## 뽑아야할 순서
  num = deque([])  ## 순서배열
  for i in range(N):
    num.append(i+1)

  count = 0
  for i in range(len(sequence)):
    if num.index(sequence[i]) < len(num)/2:
      while num[0] != sequence[i]:
        temp = num.popleft()
        num.append(temp)
        count += 1
      num.popleft()
    else:
      while num[0] != sequence[i]:
        temp = num.pop()
        num.appendleft(temp)
        count += 1
      num.popleft()
  print(count)

if __name__ == "__main__":
  Sol()