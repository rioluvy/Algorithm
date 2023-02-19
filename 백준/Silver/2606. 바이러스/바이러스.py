import sys
input = sys.stdin.readline
com_num = int(input())
link_num = int(input())
link = [[] for _ in range(com_num+1)]
infection = [False for _ in range(com_num+1)]
count = 0

for _ in range(link_num):
  a, b = map(int,input().split())
  link[a].append(b)
  link[b].append(a)

def DFS(s):
  global count
  infection[s] = True
  for i in link[s]:
    if not infection[i]:
      count += 1
      DFS(i)
DFS(1)
print(count)