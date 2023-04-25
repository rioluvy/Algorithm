import sys
input = sys.stdin.readline
a = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"
while True:
  s = (input().rstrip())
  if s == '':
    break
  ans = ""
  for i in range(len(s)):
    if s[i] == ' ':
      ans += ' '
    else:
      ans += a[a.index(s[i])-1]
  print(ans)