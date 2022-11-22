import sys
test = int(sys.stdin.readline())
for _ in range(test):
  result = []
  li = list(map(int,sys.stdin.readline().split()))
  for i in li:
    if i%2==0:
      result.append(i)
  print(sum(result),end = " ")
  print(min(result))