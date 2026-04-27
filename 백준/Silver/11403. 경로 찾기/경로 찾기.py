import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
N = int(input())
matrix = []
for _ in range(N):
  tmp = list(map(int,input().split()))
  matrix.append(tmp)
save_matirx = matrix
friends = [[] for _ in range(N)]
visited = [False for _ in range(N)]

for i in range(N):
  for j in range(N):
    if matrix[i][j] == 1:
      friends[i].append(j)

Answer = []
for i in range(N):
  Answer.append([0 for _ in range(N)])

def DFS(e):
  global tmp
  for i in friends[e]:
    if Answer[tmp][i] == 0:
      Answer[tmp][i] = 1
      DFS(i)

for i in range(N):
  tmp = i
  DFS(i)
for i in range(N):
  for j in range(N):
    print(Answer[i][j], end = " ")
  print()