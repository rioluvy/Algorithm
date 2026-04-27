import sys
input = sys.stdin.readline
num = int(input())
cheese = list(input().rstrip().split())
kind = []
for i in range(len(cheese)):
  if cheese[i][len(cheese[i])-6:] == 'Cheese':
    kind.append(cheese[i][:-6])
if len(list(set(kind))) >= 4:
  print('yummy')
else:
  print('sad')