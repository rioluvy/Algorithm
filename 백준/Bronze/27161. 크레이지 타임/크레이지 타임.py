import sys
input = sys.stdin.readline
N = int(input())
start_time = 1
count_hourglass = 0
for i in range(N):
  kind, time = input().split()
  time = int(time)
  if start_time == 0:
    start_time = 12
  elif start_time == 13:
    start_time = 1

  print(start_time, end = " ")
  if time == start_time:
    if kind == 'HOURGLASS':
      print("NO")
      if count_hourglass % 2 == 0:
        start_time += 1
      else:
        start_time -= 1
      continue
    else:
      print("YES")
  else:
    print("NO")

  
  if kind == "HOURGLASS":
    count_hourglass += 1

  if count_hourglass % 2 == 0:
    start_time += 1
  else:
    start_time -= 1