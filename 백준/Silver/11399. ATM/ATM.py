import sys
input = sys.stdin.readline
N = int(input())
time = list(map(int,input().split()))
time.sort()
total = []
for i in range(len(time)):
  if i == 0:
    sum_ = time[i]
  else:
    sum_ += time[i]
  total.append(sum_)
print(sum(total))