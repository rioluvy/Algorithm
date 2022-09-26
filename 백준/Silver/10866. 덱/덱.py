import sys

deque = []
K = int(input())
for _ in range(K):
  N = list(sys.stdin.readline().split())
  if N[0] == "push_front":
    deque.insert(0,int(N[1]))
  elif N[0] == "push_back":
    deque.append(int(N[1]))
  elif N[0] == "pop_front":
    if deque == []:
      print(-1)
    else:
      print(deque[0])
      deque.remove(deque[0])
  elif N[0] == "pop_back":
    if deque == []:
      print(-1)
    else:
      a = len(deque)
      print(deque[a-1])
      deque.pop()  
  elif N[0] == "size":
    print(len(deque))
  elif N[0] == "empty":
    if deque == []:
      print(1)
    else:
      print(0)
  elif N[0] == "front":
    if deque == []:
      print(-1)
    else:
      print(deque[0])
  elif N[0] == "back":
    if deque == []:
      print(-1)
    else:
      a = len(deque)
      print(deque[a-1])