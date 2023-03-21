import sys
input = sys.stdin.readline
num_of_lines = int(input())
now_tab = list(map(int,input().split()))
correct_tab = list(map(int,input().split()))
cnt = 0

diff = []
for i in range(num_of_lines):
  diff.append(correct_tab[i] - now_tab[i])

check = False
pos = []
neg = []

while check == False:
  check_repeat = [False] * num_of_lines
  for i in range(num_of_lines):
    if check_repeat[i]:
      continue
    start = i
    if diff[i] > 0:
      while i < num_of_lines and diff[i] > 0:
        check_repeat[i] = True
        pos.append(diff[i])
        end = i
        i += 1
      tmp = min(pos)
      for j in range(start,end+1):
        diff[j] = diff[j] - tmp
      pos = []

    elif diff[i] < 0:
      while i < num_of_lines and diff[i] < 0:
        check_repeat[i] = True
        neg.append(diff[i])
        end = i
        i += 1
      tmp = abs(max(neg))
      for j in range(start,end+1):
        diff[j] = diff[j] + (tmp)
      neg = []
    else:
      continue
    cnt += tmp

  check = True
  for i in range(num_of_lines):
    if diff[i] != 0:
      check = False
print(cnt)