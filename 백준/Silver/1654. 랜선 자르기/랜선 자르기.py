import sys
k, n = map(int,sys.stdin.readline().split())
line = [int(sys.stdin.readline()) for _ in range(k)]
a, z = 1, max(line)

while a<=z:
  count = 0
  mid = (a+z) //2
  for i in line:
    count += i//mid
  if count >= n:
    a = mid+1
  else:
    z = mid-1
print(z)