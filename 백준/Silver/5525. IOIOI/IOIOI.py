import sys
input = sys.stdin.readline
N = int(input())
M = int(input())
S = list(input().rstrip())

P = []
for i in range(2*N+1):
  if i % 2 == 0:
    P.append('I')
  else:
    P.append('O')

start = 0
end = 0
p_idx = 0
cnt  = 0

while end != M:
  if S[end] == P[p_idx]:
    end += 1
    p_idx += 1
  else:
    if S[end] == 'O':
      end += 1
    start = end
    p_idx = 0
  
  if p_idx == 2*N+1:
    cnt += 1
    p_idx = 0
    start += 2
    end = start
print(cnt)