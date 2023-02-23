import sys
expression = list(sys.stdin.readline().rstrip().split('-'))
minus = []
for i in expression:
  try:
    minus.append(int(i))
  except:
    i = list(map(int,i.split('+')))
    minus.append(sum(i))

result = minus[0]
for i in minus[1:]:
  result -= i
print(result)