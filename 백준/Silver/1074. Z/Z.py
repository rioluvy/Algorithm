import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
N, r, c = map(int,input().split())
N = 2**N
num = 0

def divide(x,y,n):
  global num
  if x > r or y > c or x+n<=r or y+n<=c:
    num += n**2
    return
  if n == 2:
    for i in range(x,x+2):
      for j in range(y,y+2):
        if i == r and j == c:
          print(num)
          sys.exit()
        num += 1
  else:
    divide(x,y,n//2)
    divide(x,y+n//2,n//2)
    divide(x+n//2,y,n//2)
    divide(x+n//2,y+n//2,n//2)

divide(0,0,N)
