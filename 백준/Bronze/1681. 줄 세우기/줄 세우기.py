import sys
N, L = map(int,sys.stdin.readline().split())
L = str(L)
label = []
num = 1
while len(label) != N:
  if L not in str(num):
    label.append(num)
    num += 1
  else:
    num += 1
print(max(label))