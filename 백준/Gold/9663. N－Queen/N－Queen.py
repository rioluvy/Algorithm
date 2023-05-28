n = int(input())
board = [[True for _ in range(n)] for _ in range(n)]
cnt = 0

def cant(row,col,tmp2_board):
  copy_board = [k[:] for k in tmp2_board]
  for i in range(1,n-row):
    copy_board[row+i][col] = False
    if col + i < n:
      copy_board[row+i][col+i] = False
    if col - i > -1:
      copy_board[row+i][col-i] = False
  return copy_board

def NQueen(row,tmp_board):
  global cnt
  for i in range(row,n):
    if not sum(tmp_board[i]):
      return
  
  if row == n-1:
    cnt += sum(tmp_board[row])
    return
  
  for i in range(n):
    if tmp_board[row][i]:
      tmp = cant(row,i,tmp_board)
      NQueen(row+1,tmp)

NQueen(0,board)
print(cnt)