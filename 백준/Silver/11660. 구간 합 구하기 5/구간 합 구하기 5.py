import sys
input = sys.stdin.readline  ## 빠르게 입력 받기
n,m = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(n)]  ## 표를 2차원 배열로 입력받기
sum_board = [[0]*n for _ in range(n)]

## 합 배열의 1행과 1열에 처리
sum_board[0][0] = board[0][0]
for i in range(1,n):
  sum_board[i][0] = sum_board[i-1][0] + board[i][0]
  sum_board[0][i] = sum_board[0][i-1] + board[0][i]

## 합 배열 완성
for i in range(1,n):
  for j in range(1,n):
    sum_board[i][j] = sum_board[i-1][j] + sum_board[i][j-1] - sum_board[i-1][j-1] + board[i][j]

## 부분합 구하기
for i in range(m):
  x1, y1, x2, y2 = map(int, input().split())
  ## 시작이 (0,0)인 경우
  if x1-1 == 0 and y1-1 == 0:
    print(sum_board[x2-1][y2-1])
  ## 시작이 (0,1이상)인 경우
  elif x1-1 == 0 and y1-1 > 0:
    print(sum_board[x2-1][y2-1] - sum_board[x2-1][y1-2])  ## 전체에서 일부를 뻄
  ## 시작이 (1이상,0)인 경우
  elif x1-1 > 0 and y1-1 == 0:
    print(sum_board[x2-1][y2-1] - sum_board[x1-2][y2-1])  ## 전체에서 일부를 뺌
  ## 시작이 (1이상,1이상)인 경우
  else:
    print(sum_board[x2-1][y2-1] - sum_board[x2-1][y1-2] - sum_board[x1-2][y2-1] + sum_board[x1-2][y1-2])  ##전체에서 일부를 뺴고 겹치는걸 더함
  