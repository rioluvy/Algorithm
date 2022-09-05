import string
S= input()
li = list(S)
for i in string.ascii_lowercase:
  if i in S:
    print(S.index(i), end=' ')
  else:
    print(-1, end=' ')