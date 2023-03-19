import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
N = int(input())
paper = []
for _ in range(N):
  paper.append(list(map(int,input().split())))

kind = [0,0,0] ## 0, 1, -1
def divide_quanquer(a,b,N):
  tmp = paper[a][b]
  for i in range(a,a+N):
    for j in range(b,b+N):
      if paper[i][j] != tmp:
        for k in range(3):
          for h in range(3):
            divide_quanquer(a+N//3*k,b+N//3*h,N//3)
        return
  kind[tmp] += 1

divide_quanquer(0,0,N)
print(kind[-1])
print(kind[0])
print(kind[1])
