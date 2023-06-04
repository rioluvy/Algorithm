import sys
input = sys.stdin.readline
bulb = []


dx = [0, 1, 0, -1, 0]
dy = [0, 0, 1, 0, -1]

def Sol(n):
  for i in range(n):
    tmp = list(map(int,input().split()))
    bulb.append(tmp)

  ans = 325
  for f in range(1<<n):
    copy = []
    cnt = 0
    for i in range(n):
      copy.append(bulb[i][:])

    for i in range(n):
      if f & (1<<i):
        cnt += 1
        for j in range(5):
          tmp_x = i + dx[j]
          tmp_y = 0 + dy[j]
          if 0 <= tmp_x < n and 0 <= tmp_y < n:
            copy[tmp_y][tmp_x] = (copy[tmp_y][tmp_x]+1) % 2

    for i in range(1,n):
      for j in range(n):
        if not copy[i-1][j]:
          continue
        for k in range(5):
          tmp_x = j + dx[k]
          tmp_y = i + dy[k]
          if 0 <= tmp_x < n and 0 <= tmp_y < n:
            copy[tmp_y][tmp_x] = (copy[tmp_y][tmp_x]+1) % 2
        cnt += 1

    check = True
    for i in range(n):
      if copy[n-1][i]:
        check = False
    if check:
      ans = min(cnt,ans)

  if ans == 325:
    print(-1)
  else:
    print(ans)

if __name__ == "__main__":
  n = int(input())
  Sol(n)