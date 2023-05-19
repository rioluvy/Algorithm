import sys
input = sys.stdin.readline
n = int(input())
A = [0] * n
B = list(map(int,input().split()))
cnt = 0
while True:
  check_odd = False
  zero = True
  for i in range(n):
    if B[i] != 0:
      zero = False
    if B[i] % 2:
      B[i] -= 1
      check_odd = True
      cnt += 1
  if not check_odd:
    for i in range(n):
      B[i] //= 2
    cnt += 1
  if zero:
    print(cnt - 1)
    break