import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(10000)
N,M,V = map(int,input().split())
link = [[] for _ in range(N+1)]
queue = deque([])

def Sol():

  ## 그래프 리스트 생성
  for _ in range(M):
    a, b = map(int,input().split())
    link[a].append(b)
    link[b].append(a)

  for i in range(len(link)):
    link[i].sort()

  visited = [False] * (N+1)
  ## DFS
  def DFS(v):
    print(v, end = " ")
    visited[v] = True
    for e in link[v]:
      if not visited[e]:
        DFS(e)

  ## BFS
  def BFS(v):
    queue.append(v)
    visited[v] = True
    while queue:
      temp = queue.popleft()
      print(temp, end = " ")
      for i in link[temp]:
        if not visited[i]:
          queue.append(i)
          visited[i] = True

  DFS(V)
  print()
  visited = [False] * (N+1)
  BFS(V)

if __name__ == "__main__":
  Sol()