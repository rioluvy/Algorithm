import sys
from collections import deque
input = sys.stdin.readline
n,m = map(int,input().split())
dx = [1,0,-1,0]
dy = [0,1,0,-1]
map = []
for _ in range(n):
    map.append(list(input().rstrip()))

cnt = 0
for i in range(n):
    for j in range(m):
        if map[i][j] == '-':
            kind = True
        else:
            kind = False
        
        if kind and j+1 < m:
            if map[i][j+1] == '-':
                cnt += 1
        if (not kind) and i+1 < n:
            if map[i+1][j] == '|':
                cnt += 1
print(n*m-cnt)