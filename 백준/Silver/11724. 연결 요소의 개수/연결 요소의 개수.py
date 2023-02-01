import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
def Sol():
  N, M = map(int,input().split())
  A = [[] for _ in range(N)]
  visited = [False] * N
  count = 0

  def DFS(v):
    visited[v-1] = True
    for i in A[v-1]:
      if not visited[i-1]:
        DFS(i)

  for _ in range(M):
    s, e = map(int,input().split())
    A[s-1].append(e)
    A[e-1].append(s)

  for i in range(N):
    if not visited[i]:
      count += 1
      DFS(i+1)
  
  print(count)

if __name__ == "__main__":
  Sol()