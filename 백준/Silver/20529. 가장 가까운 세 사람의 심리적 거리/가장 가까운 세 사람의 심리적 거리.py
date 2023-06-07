import sys
from itertools import combinations
input = sys.stdin.readline
t = int(input())
mindDist = 20
while t:
  n = int(input())
  mbti = list(input().rstrip().split())
  if n > 32:
    print(0)
    t -= 1
    continue
  combi = list(combinations(mbti,3))
  for i in range(len(combi)):
    a, b, c = combi[i]
    triple = 0
    for j in range(4):
      if a[j] != b[j]: triple += 1
      if a[j] != c[j]: triple += 1
      if b[j] != c[j]: triple += 1
    mindDist = min(mindDist,triple)
    if not mindDist:
      break
  print(mindDist)
  mindDist = 20
  t -= 1