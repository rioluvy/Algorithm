import sys
s = list(input().split('.'))
ans = []
for i in s:
  length = len(i)
  while length >= 4:
    ans.append('AAAA')
    length -= 4
  while length >= 2:
    ans.append('BB')
    length -= 2
  if length:
    print(-1)
    sys.exit()
  ans.append('.')
print(*ans[:-1],sep = "")