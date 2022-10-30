import sys
n = int(sys.stdin.readline())
i=0
j=1
while(True):
  j = j+6*i
  if j>=n:
    break
  else:
    i += 1
print(i+1)