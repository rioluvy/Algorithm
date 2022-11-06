import sys
n, m = map(int,sys.stdin.readline().split())
board_entire = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
minimun = []
board_slice = []

def cnt_W(board):
  count =0
  for i in range(8):
    for j in range(8):
      if (i+j) % 2 == 0 and board[i][j] != 'W':
        count +=1 
      elif (i+j) % 2 ==1 and board[i][j] != 'B':
        count +=1 
  return count

def cnt_B(board):
  count =0
  for i in range(8):
    for j in range(8):
      if (i+j) % 2 == 0 and board[i][j] != 'B':
        count +=1 
      elif (i+j) % 2 ==1 and board[i][j] != 'W':
        count +=1 
  return count

for i in range(n-7):
  for j in range(m-7):
    for k in range(8):
      board_slice.append(board_entire[i+k][j:j+8])
    minimun.append(cnt_W(board_slice))
    minimun.append(cnt_B(board_slice))
    board_slice = []
print(min(minimun))