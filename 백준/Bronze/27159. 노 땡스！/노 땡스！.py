import sys
input = sys.stdin.readline
N = int(input())
num = list(map(int,input().split()))
min = []
start = 0
end = 1

if N == 1:
  print(num[0])
  sys.exit()

while end < N:
  if num[end] - num[end-1] == 1:
    end += 1
    pass
  else:
    min.append(num[start])
    start = end
    end += 1
min.append(num[start])
print(sum(min))