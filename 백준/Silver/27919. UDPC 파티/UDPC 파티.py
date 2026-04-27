import sys
input = sys.stdin.readline

ans = []
string = list(input().rstrip())
normal = [0,0,0,0]
abnormal = [0,0,0,0]

for i in range(len(string)):
  if string[i] == 'U':
    normal[0] += 1
  elif string[i] == 'D':
    normal[1] += 1
  elif string[i] == 'P':
    normal[2] += 1
  else:
    normal[3] += 1

max_U = normal[0] + normal[3]
max_D = normal[1] + normal[2]
max_P = normal[2] + normal[1]

tmp_1 = max_D//2
tmp_2 = max_P - tmp_1

if max_U > tmp_2:
  ans.append('U')

tmp_1 = max_U//2
tmp_2 = max_U - tmp_1

if max_D > 0:
  ans.append('D')
  ans.append('P')

print(*ans,sep = "",end = "")