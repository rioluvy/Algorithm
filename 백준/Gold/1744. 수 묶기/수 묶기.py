import sys
input = sys.stdin.readline
N = int(input())
sequence = []
for _ in range(N):
  a = int(input())
  sequence.append(a)
sequence.sort()

size = [0 for _ in range(50)]

final = 0
for i in range(len(sequence)):
  if size[i] == 1:
    continue

  if sequence[i] < 0:
    if i+1 < len(sequence) and sequence[i+1] <= 0:
      temp = sequence[i] * sequence[i+1]
      size[i+1] = 1
    else:
      temp = sequence[i]
    size[i] = 1
    final += temp
  else:
    break

for i in range(len(sequence)-1,-1,-1):
  if size[i] == 1:
    continue

  if i-1 >= 0 and sequence[i-1] > 1:
    temp = sequence[i] * sequence[i-1]
    size[i-1] = 1
  else:
    temp = sequence[i]
  final += temp
  size[i] = 1
print(final)