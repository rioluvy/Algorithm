import sys
input = sys.stdin.readline
bulb = []


dx = [0, 1, 0, -1, 0]
dy = [0, 0, 1, 0, -1]

def Sol():
  for i in range(10):
    tmp = list(input().rstrip())
    for j in range(10):
      if tmp[j] == 'O':
        tmp[j] = 1
      else:
        tmp[j] = 0
    bulb.append(tmp)

  ans = 101
  for f in range(1<<10):
    copy = []
    cnt = 0
    for i in range(10):
      copy.append(bulb[i][:])

    for i in range(10):
      if f & (1<<i):
        cnt += 1
        for j in range(5):
          tmp_x = i + dx[j]
          tmp_y = 0 + dy[j]
          if 0 <= tmp_x <= 9 and 0 <= tmp_y <= 9:
            copy[tmp_y][tmp_x] = (copy[tmp_y][tmp_x]+1) % 2

    for i in range(1,10):
      for j in range(10):
        if not copy[i-1][j]:
          continue
        for k in range(5):
          tmp_x = j + dx[k]
          tmp_y = i + dy[k]
          if 0 <= tmp_x <= 9 and 0 <= tmp_y <= 9:
            copy[tmp_y][tmp_x] = (copy[tmp_y][tmp_x]+1) % 2
        cnt += 1

    check = True
    for i in range(10):
      if copy[9][i]:
        check = False
    if check:
      ans = min(cnt,ans)

  if ans == 101:
    print(-1)
  else:
    print(ans)

if __name__ == "__main__":
  Sol()