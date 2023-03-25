import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
for _ in range(T):
  fcn = input().rstrip()
  num = int(input())
  arr = input().rstrip()
  arr = deque(arr[1:-1].split(','))
  
  check_reverse = False
  right = True
  for i in range(len(fcn)):
    if num == 0:
      arr = []
    if fcn[i] == 'R':
      check_reverse = not check_reverse
    else:
      try:
        if not check_reverse:
          arr.popleft()
        else:
          arr.pop()
      except:
        print('error')
        right = False
        break
  if not right:
    continue

  if not check_reverse:
    print("["+",".join(arr)+"]")
  else:
    arr.reverse()
    print("["+",".join(arr)+"]")