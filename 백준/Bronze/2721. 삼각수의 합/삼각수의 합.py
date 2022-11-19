import sys
test_case = int(sys.stdin.readline())
li = []
def s(a):
  total =0
  for i in range(1,a+1):
    total += i
  return total

for _ in range(test_case):
  n = int(sys.stdin.readline())
  for i in range(1,n+1):
    li.append(i*s(i+1))
  print(sum(li))
  li = []