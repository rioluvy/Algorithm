while True:
  n = list(input())
  d = []
  if n[0] =='.':
    break
  else:
    a = 0
    b = 0
    c = []
    for i in n:
      if i == '(':
        a += 1
        c.append('(')
      elif i==')':
        a -= 1
        c.append(')')
        if len(c)>=2 and c[-2] == '(':
          c.pop()
          c.pop()
        if a<0:
          break
      elif i=='[':
        b += 1
        c.append('[')
      elif i==']':
        b -= 1
        c.append(']')
        if len(c)>=2 and c[-2] == '[':
          c.pop()
          c.pop()
        if b<0:
          break
    c.append(0)
    for i in range(len(c)):
      if (c[i] == '(' and c[i+1] == ']') or  (c[i] == '[' and c[i+1] == ')'):
        print("no")
        d.append(0)
        break
    if d==[]:
      if a==0 and b==0:
        print("yes")
      else:
        print("no")
    else:
      pass