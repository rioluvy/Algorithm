import sys
from collections import deque
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  A, B = map(int,input().split())
  save = [""]*10000
  queue = deque([])
  queue.append((A,""))
  while True:
    (tmp, com) = queue.popleft()
    D = (tmp*2) % 10000
    if save[D] == "":
      save[D] = com + "D"
      queue.append((D,save[D]))

    if not tmp:
      S = 9999
    else:
      S = (tmp - 1)
    if save[S] == "":
      save[S] = com + "S"
      queue.append((S,save[S]))

    x = tmp * 10
    y = tmp*10//10000
    L = (x - 9999*y)
    if save[L] == "":
      save[L] = com + "L"
      queue.append((L,save[L]))
    
    x = tmp // 10
    y = tmp % 10
    R = x + 1000*y
    if save[R] == "":
      save[R] = com + "R"
      queue.append((R,save[R]))
    
    if save[B] != "":
      print(save[B])
      break