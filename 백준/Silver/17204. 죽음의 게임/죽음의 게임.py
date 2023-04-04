import sys
input = sys.stdin.readline

def DFS(e):
  global cnt
  visited[e] = True
  cnt += 1
  if e == K:
    print(cnt-1)
    sys.exit(0)
  for i in friends[e]:
    if not visited[i]:
      DFS(i)
    else:
      return

N, K = map(int, input().split())
friends = [[] for _ in range(N)]
visited = [False for _ in range(N)]
cnt = 0
for i in range(N):
  a = int(input())
  friends[i].append(a)
DFS(0)
print(-1)