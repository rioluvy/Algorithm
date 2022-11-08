import sys
test_case = int(sys.stdin.readline())
for _ in range(test_case):
  vps = list(sys.stdin.readline())
  count = 0
  for i in vps:
    if i == '(':
      count += 1
    elif i == ')':
      count -= 1
      if count < 0:
        print("NO")
        break
  if count == 0:
    print("YES")
  elif count >0:
    print("NO")