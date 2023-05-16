import sys
input = sys.stdin.readline
s = input().rstrip(); t = input().rstrip()
while True:
  if t[-1] == 'B':
    t = t[:-1]
    t = t[::-1]
  elif t[-1] == 'A':
    t = t[:-1]
  if s == t:
    print(1)
    break
  if len(t) < len(s):
    print(0)
    break