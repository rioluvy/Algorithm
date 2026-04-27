import sys
input = sys.stdin.readline
N = int(input())
fruits = [0, 0, 0, 0]
for _ in range(N):
  s, num = input().split()
  num = int(num)
  if s == 'STRAWBERRY':
    fruits[0] += num
  elif s == 'BANANA':
    fruits[1] += num
  elif s == 'LIME':
    fruits[2] += num
  else:
    fruits[3] += num
if 5 in fruits:
  print("YES")
else:
  print("NO")