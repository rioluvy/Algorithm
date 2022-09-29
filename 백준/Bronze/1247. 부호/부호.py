import sys
S =[]
for _ in range(3):
  N = int(sys.stdin.readline())
  for _ in range(N):
    s = int(sys.stdin.readline())
    S.append(s)
  if sum(S)>0:
    print("+")
  elif sum(S)<0:
    print("-")
  else:
    print("0")
  S = []