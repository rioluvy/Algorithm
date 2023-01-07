import sys
input = sys.stdin.readline
N = int(input())
M = int(input())
num = list(map(int, input().split()))
count = 0
num.sort()
i = 0
j = N-1


while num[i] < num[j]:
  first = num[i]
  second = num[j]
  if first + second < M:
    i += 1
  elif first + second > M:
    j -= 1
  else:
    count += 1
    j -= 1
    i += 1

print(count)