s = input()
a = [0,0]
for i in range(len(s)):
  if s[i] == ':':
    a[0] += 1
  elif s[i] == '_':
    a[1] += 1

print(len(s) + a[1]*5 + a[0])