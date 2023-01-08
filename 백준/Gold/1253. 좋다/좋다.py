import sys
input = sys.stdin.readline
N = int(input())
num = list(map(int, input().split()))
num.sort()
count = 0

for i in range(len(num)):
  target = num.pop(i)
  a = 0
  b = N-2
  while a < b:
    first = num[a]
    second = num[b]
    if first + second == target:
      count += 1
      num.insert(i,target)
      break
    elif first + second > target:
      b -= 1
    elif first + second < target:
      a += 1

  if len(num) != N:
    num.insert(i,target)
  else:
    pass

print(count)