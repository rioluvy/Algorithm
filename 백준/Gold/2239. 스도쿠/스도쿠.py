import sys

def checkagain():
  global check
  check = []
  for i in range(1,10):
    check.append(i)

def row(x):
  for i in range(9):
    if sudoku[x][i] in check:
      check.remove(sudoku[x][i])

def col(y):
  for i in range(9):
    if sudoku[i][y] in check:
      check.remove(sudoku[i][y])

def box(box_row,box_col):
  for i in range(box_row*3, (box_row+1)*3):
    for j in range(box_col*3, (box_col+1)*3):
      if sudoku[i][j] in check:
        check.remove(sudoku[i][j])

def scan(blank):
  if blank == len(zero):
    for i in sudoku:
      print(*i, sep="")
    sys.exit(0)
  x,y = zero[blank]
  a = x//3
  b = y//3
  box(a,b)
  row(x)
  col(y)
  for i in check:
    sudoku[x][y] = i
    checkagain()
    scan(blank+1)
    sudoku[x][y] = 0

sudoku = []
zero = []
check = [1,2,3,4,5,6,7,8,9]

for i in range(9):
  sudoku.append(list(map(int,sys.stdin.readline().rstrip())))
  for j in range(9):
    if sudoku[i][j] == 0:
      zero.append((i,j))
scan(0)