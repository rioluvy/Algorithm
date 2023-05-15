import sys
from collections import deque
input = sys.stdin.readline
n = input()
stack = deque([])
s = ''
for i in n:
  if i.isalpha():
    s += i
  if i == '(':
    stack.append(i)
  elif i == '*' or i == '/':
    while stack and (stack[-1] == '*' or stack[-1] == '/'):
      s += stack.pop()
    stack.append(i)
  elif i == '+' or i == '-':
    while stack and stack[-1] != '(':
      s += stack.pop()
    stack.append(i)
  elif i == ')':
    while stack and stack[-1] != '(':
      s += stack.pop()
    stack.pop()
while stack:
  s += stack.pop()
print(s)