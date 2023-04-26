import sys
input = sys.stdin.readline
N = int(input())**2
m1 = 1; m2 = N
v1 = 0; v2 = -1
cnt = 0
while not 0<=v1<=v2:
  cnt += 1
  save_v1 = v1
  v1 = ((1-N)/(1+N)*v1 + 2*N/(1+N)*v2)
  v2 = 2/(N+1)*save_v1 - (1-N)/(1+N)*v2
  if v1 < 0:
    cnt += 1
    v1 = -v1
if v1 < 0:
  cnt += 1
print(cnt)