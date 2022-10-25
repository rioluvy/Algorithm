import sys
maximun = []
board = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
for i in range(9):
  for j in range(9):
    a = max(board[i])
    maximun.append(a)
  a = max(maximun)
print(a)
for i in range(9):
  for j in range(9):
    if board[i][j] == a:
      print(i+1, j+1)