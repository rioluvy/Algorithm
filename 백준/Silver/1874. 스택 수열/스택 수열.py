import sys
from collections import deque
n = int(sys.stdin.readline())
stack = [1]
result = ["+"]
number = deque([])

for _ in range(n):
  num = int(sys.stdin.readline())
  number.append(num)
j=stack[0]
for i in range(n):
  while True:
    if stack == []:
      j+=1
      stack.append(j)
      result.append("+")
    elif stack[-1] < number[i]:
      j+=1
      result.append("+")
      stack.append(j)
    elif stack[-1] == number[i]:
      result.append("-")
      stack.pop()
      break
    else: 
      print("NO")
      sys.exit(0)

for i in result:
  print(i)