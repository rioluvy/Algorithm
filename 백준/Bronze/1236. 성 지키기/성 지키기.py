import sys
input = sys.stdin.readline
N, M = map(int,input().split())
castle = []
for _ in range(N):
  castle.append(list(input().rstrip()))
num = 0

trans_castle = []
for col in range(M):
  tmp = []
  for row in castle:
    tmp.append(row[col])
  trans_castle.append(tmp)

def cnt(N,M,castle,trans_castle):
  global num
  for i in range(N):
    if 'X' not in castle[i]:
      for j in range(M):
        if 'X' not in trans_castle[j]:
          castle[i][j] = 'X'
          trans_castle[j][i] = 'X'
          num += 1
          break
      else:
        num += 1

cnt(N,M,castle,trans_castle)
cnt(M,N,trans_castle,castle)
print(num)