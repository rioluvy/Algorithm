import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)
N, M = map(int,input().split())
connect = [[] for _ in range(N)]
way_point = [False]*N
depth = 1

## 친구 관계 리스트 생성
for _ in range(M):
  a, b = map(int,input().split())
  connect[a].append(b)
  connect[b].append(a)

## 재귀 돌리기
def DFS(f):
  global depth
  if depth == 5:
    print(1)
    sys.exit()

  way_point[f] = True
  for i in connect[f]:
    if not way_point[i]:
      depth += 1
      DFS(i)
      depth -= 1
      way_point[i] = False


for i in range(N):
  DFS(i)
  way_point[i] = False
print(0)
