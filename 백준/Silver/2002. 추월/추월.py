import sys
from collections import deque
def Sol():
  input = sys.stdin.readline
  N = int(input())
  overtake = deque([])
  count = 0
  for i in range(N):
    car = input()
    overtake.append(car)
  for j in range(N):
    car_check = input()
    if car_check != overtake[0]:
      count += 1
    overtake.remove(car_check)
  print(count)

if __name__ == "__main__":
  Sol()