import sys
n,m = map(int,sys.stdin.readline().split())
tree = list(map(int,sys.stdin.readline().split()))
first, last = 1, max(tree)

while first<=last:
  length = 0
  mid = (first+last) // 2
  for i in tree:
    if i-mid >0:
      length += i-mid
  if length >= m:
    first = mid + 1
  else:
    last = mid - 1
print(last)