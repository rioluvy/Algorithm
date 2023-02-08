N,M,V = map(int,input().split())

net = dict()
for _ in range(M):
  s, e = map(int,input().split())
  if not net.get(s) or not net.get(e):
    net.setdefault(s, set())
    net.setdefault(e, set())
  net[s].add(e)
  net[e].add(s)
  
is_travel_dfs = [False for _ in range(N+1)]
is_travel_bfs = [False for _ in range(N+1)]


def dfs(n):
  if is_travel_dfs[n]:
    return 
  is_travel_dfs[n] = True
  print(n,end =' ')
  
  if net.get(n):
    connect = sorted(list(net[n]))
    for item in connect:
      dfs(item)

queue = list()
def bfs(n):
  queue.append(n)
  is_travel_bfs[n] = True
  
  while queue:
    temp = queue.pop(0)
    print(temp, end = " ")
    if net.get(temp):
      connect = sorted(list(net[temp]))
      for item in connect:
        if is_travel_bfs[item]:
          continue
        is_travel_bfs[item] = True
        queue.append(item)
    

dfs(V)
print()
bfs(V)