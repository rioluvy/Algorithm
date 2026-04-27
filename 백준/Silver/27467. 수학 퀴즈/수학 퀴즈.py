import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().split()))
q = 0
w = 0

for i in range(N):
  if A[i] == 0:
    q += 1
  else:
    if A[i] % 3 == 1:
      w += 1
    elif A[i] % 3 == 2:
      w -= 1
      q -= 1
    else:
      q += 1
print(w, q)