import sys
input = sys.stdin.readline
N, M = map(int, input().split())
lecture = list(map(int, input().split()))
save = []

start = max(lecture)
end = sum(lecture)
while start <= end:
  mid = (start + end) // 2
  total = 0
  num = 0
  for i in lecture:
    if total + i > mid:
      num += 1
      total = i
    else:
      total += i
  num += 1
  
  if num > M:
    start = mid + 1
  else:
    end = mid - 1
print(start)