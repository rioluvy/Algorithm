import sys
T = int(input())
floor_0 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14]
for _ in range(T):
  k = int(sys.stdin.readline())
  n = int(sys.stdin.readline())
  for _ in range(k):
    under_floor = 0
    next_floor = []
    for i in floor_0:
      under_floor += i
      next_floor.append(under_floor)
    floor_0 = next_floor
  print(next_floor[n-1])
  floor_0 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14]