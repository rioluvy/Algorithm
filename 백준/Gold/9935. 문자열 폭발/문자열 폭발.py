import sys
input = sys.stdin.readline
s = list(input().rstrip())
boom = list(input().rstrip())
boom_length = len(boom)
s_length = len(s)
stack = []
for i in range(s_length):
  stack.append(s[i])
  if len(stack) >= boom_length and stack[-boom_length:] == boom:
    for _ in range(boom_length):
      stack.pop()
if not stack:
  stack = ['F','R','U','L','A']
print(*stack,sep = "")