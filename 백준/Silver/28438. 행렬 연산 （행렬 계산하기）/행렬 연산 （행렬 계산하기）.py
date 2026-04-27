import sys
input = sys.stdin.readline
N,M,Q = map(int,input().split())
matrix = [[0] * M for _ in range(N)]

command_row = [0]*N
command_col = [0]*M
for i in range(Q):
    check, num, v = map(int,input().split())
    if check == 1:
        command_row[num-1] += v
    else:
        command_col[num-1] += v

for i in range(N):
    if command_row[i] == 0:
        continue
    for j in range(M):
        matrix[i][j] += command_row[i]

for i in range(M):
    if command_col[i] == 0:
        continue
    for j in range(N):
        matrix[j][i] += command_col[i]

for i in range(N):
    print(*matrix[i])