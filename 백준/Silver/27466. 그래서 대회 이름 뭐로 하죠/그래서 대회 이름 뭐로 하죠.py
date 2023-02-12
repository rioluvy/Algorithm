import sys
input = sys.stdin.readline
N, M = map(int, input().split())
S = list(input().rstrip())
while True:
  if len(S) < M:
    print("NO")
    sys.exit()

  if S[-1] == 'A' or S[-1] == 'E' or S[-1] == 'I' or S[-1] == 'O' or S[-1] == 'U':
    S.pop()
  elif S[-2] != 'A':
    S.pop(-2)
  elif S[-3] != 'A':
    S.pop(-3)
  else:
    break


if len(S) == M:
  print('YES')
  print(*S,sep="")
  sys.exit()
else:
  while len(S) != M:
    S.pop(0)
  print('YES')
  print(*S, sep = "")